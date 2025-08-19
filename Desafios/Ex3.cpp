//3) A partir do programa anterior, pesquise o método de ordenação da bolha ou bubble sort, e aplique no vetor de nomes do código anterior, exibindo os nomes cadastrados.

#include <iostream>
#include <string>

#define TAM 10

using namespace std;

int main() {
    cout << "Sistema de Cadastro, Pesquisa e Ordenacao de Nomes" << endl;
    string nomes[TAM];
    int quantidadeInseridos = 0;
    int opcao;
    string nome;
    
    do {
        cout << "\n=============== MENU ===============" << endl;
        cout << "1 - Cadastrar nome" << endl;
        cout << "2 - Listar nomes" << endl;
        cout << "3 - Pesquisar nome" << endl;
        cout << "4 - Ordenar nomes" << endl;
        cout << "5 - Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;
        cin.ignore(); // Limpa buffer
 
        switch (opcao) {
        case 1:
            cout << "\nCadastrar nome..." << endl;
            if (quantidadeInseridos >= TAM) {
                cout << "Vetor lotado! Maximo " << TAM << " nomes." << endl;
            } else {
                cout << "Nome: ";
                getline(cin, nome);
                
                // Verifica se o nome já existe
                bool jaExiste = false;
                for (int i = 0; i < quantidadeInseridos; i++) {
                    if (nomes[i] == nome) {
                        jaExiste = true;
                        break;
                    }
                }
                
                if (jaExiste) {
                    cout << "Nome ja cadastrado!" << endl;
                } else {
                    nomes[quantidadeInseridos] = nome;
                    quantidadeInseridos++;
                    cout << "Nome cadastrado com sucesso!" << endl;
                }
            }
            break;
            
        case 2:
            cout << "\nListar nomes..." << endl;
            if (quantidadeInseridos == 0) {
                cout << "Nenhum nome cadastrado." << endl;
            } else {
                cout << "========================" << endl;
                cout << "     LISTA DE NOMES     " << endl;
                cout << "========================" << endl;
                for (int i = 0; i < quantidadeInseridos; i++) {
                    cout << (i + 1) << ". " << nomes[i] << endl;
                }
                cout << "========================" << endl;
                cout << "Total de registros: " << quantidadeInseridos << endl;
            }
            break;
            
        case 3:
            cout << "\nPesquisar nome..." << endl;
            if (quantidadeInseridos == 0) {
                cout << "Nenhum nome cadastrado para pesquisar." << endl;
            } else {
                cout << "Digite o nome ou parte do nome: ";
                getline(cin, nome);
                
                int quantidadeEncontrados = 0;
                cout << "\nResultados da pesquisa por '" << nome << "':" << endl;
                cout << "================================" << endl;
                
                for (int i = 0; i < quantidadeInseridos; i++) {
                    // Verifica se find() NÃO retorna npos
                    if (nomes[i].find(nome) != string::npos) {
                        cout << (quantidadeEncontrados + 1) << ". " << nomes[i] << endl;
                        quantidadeEncontrados++;
                    }
                }
                
                cout << "================================" << endl;
                if (quantidadeEncontrados == 0) {
                    cout << "Nenhum nome encontrado com '" << nome << "'" << endl;
                } else {
                    cout << "Total encontrado: " << quantidadeEncontrados << " nomes" << endl;
                }
            }
            break;
            
        case 4:
            cout << "\nOrdenar nomes usando Bubble Sort..." << endl;
            if (quantidadeInseridos <= 1) {
                cout << "Precisa de pelo menos 2 nomes para ordenar." << endl;
            } else {
                cout << "Nomes antes da ordenacao:" << endl;
                for (int i = 0; i < quantidadeInseridos; i++) {
                    cout << (i + 1) << ". " << nomes[i] << endl;
                }
                
                cout << "\nAplicando Bubble Sort..." << endl;
                
                // ALGORITMO BUBBLE SORT
                for (int i = 0; i < quantidadeInseridos - 1; i++) {
                    for (int j = 0; j < quantidadeInseridos - i - 1; j++) {
                        // Compara nomes[j] com nomes[j+1]
                        if (nomes[j] > nomes[j + 1]) {
                            // Troca os elementos
                            string temp = nomes[j];
                            nomes[j] = nomes[j + 1];
                            nomes[j + 1] = temp;
                        }
                    }
                }
                
                cout << "\nNomes ordenados em ordem alfabetica:" << endl;
                cout << "====================================" << endl;
                for (int i = 0; i < quantidadeInseridos; i++) {
                    cout << (i + 1) << ". " << nomes[i] << endl;
                }
                cout << "====================================" << endl;
                cout << "Ordenacao concluida com sucesso!" << endl;
            }
            break;
            
        case 5:
            cout << "\nSaindo do programa..." << endl;
            break;
            
        default:
            cout << "Opcao invalida! Tente novamente." << endl;
            break;
        }
        
        if (opcao != 5) {
            cout << "\nPressione Enter para continuar...";
            cin.get();
        }
        
    } while (opcao != 5);
    
    return 0;
}
