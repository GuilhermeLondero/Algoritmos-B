//3) A partir do programa anterior, pesquise o método de ordenação da bolha ou bubble sort, e aplique no vetor de nomes do código anterior, exibindo os nomes cadastrados.

#include <iostream>
#include <string>

#define TAM 4

using namespace std;

int main() {
    cout << "=== Sistema de Cadastro, Busca e Ordenacao de Nomes ===" << endl;
    string vetorNomes[TAM];
    int totalCadastrados = 0;
    int escolha;
    string nomeDigitado;
    
    do {
        cout << "\n--- MENU PRINCIPAL ---" << endl;
        cout << "1 - Inserir nomes" << endl;
        cout << "2 - Exibir nomes" << endl;
        cout << "3 - Buscar nome" << endl;
        cout << "4 - Ordenar nomes" << endl;
        cout << "5 - Finalizar" << endl;
        cout << "Digite sua opcao: ";
        cin >> escolha;
        fflush(stdin);

        switch (escolha)
        {
        case 1:
            cout << "\nInserir nomes no sistema..." << endl;
            if (totalCadastrados == TAM) {
                cout << "Sistema cheio! Limite de nomes atingido." << endl;
            } else {
                for (int i = 0; i < TAM; i++) {
                    cout << "Digite o nome: ";
                    getline(cin, nomeDigitado);
                    fflush(stdin);
                    
                    if (nomeDigitado.empty()) {
                        cout << "Nome nao pode estar vazio!" << endl;
                        i--;
                        continue;
                    }

                    vetorNomes[totalCadastrados] = nomeDigitado;
                    totalCadastrados++;
                    cout << "Nome inserido com sucesso!" << endl;
                }
            }
            break;
            
        case 2:
            cout << "\nExibir nomes cadastrados..." << endl;
            if (totalCadastrados == 0) {
                cout << "Nenhum nome foi cadastrado ainda." << endl;
            } else {
                cout << "Lista de nomes:" << endl;
                for (int i = 0; i < totalCadastrados; i++) {
                    cout << (i+1) << "- " << vetorNomes[i] << endl;
                }
                cout << "===================" << endl;
                cout << "Quantidade total: " << totalCadastrados << endl;
            }
            break;
            
        case 3:
            cout << "\nBuscar nome no sistema..." << endl;
            if (totalCadastrados == 0) {
                cout << "Sistema vazio... nao eh possivel realizar busca." << endl;
            } else {
                cout << "Nome ou parte do nome para buscar: ";
                getline(cin, nomeDigitado);
                int totalEncontrados = 0;
                
                cout << "Resultados da busca:" << endl;
                for (int i = 0; i < totalCadastrados; i++) {
                    if (vetorNomes[i].find(nomeDigitado) != string::npos) {
                        cout << "-> " << vetorNomes[i] << endl;
                        totalEncontrados++;
                    }
                }
                cout << "===================" << endl;
                if (totalEncontrados == 0) {
                    cout << "Nenhum nome encontrado com: " << nomeDigitado << endl;
                } else {
                    cout << "Quantidade encontrada: " << totalEncontrados << endl;
                }
            }
            break;
            
        case 4:
            cout << "\nOrdenar nomes alfabeticamente..." << endl;
            if (totalCadastrados <= 1) {
                cout << "Precisa de pelo menos 2 nomes para ordenar." << endl;
            } else {
                cout << "Nomes antes da ordenacao:" << endl;
                for (int i = 0; i < totalCadastrados; i++) {
                    cout << (i+1) << "- " << vetorNomes[i] << endl;
                }
                
                cout << "\nAplicando metodo Bubble Sort..." << endl;
                
                for (int i = 0; i < totalCadastrados - 1; i++) {
                    for (int j = 0; j < totalCadastrados - i - 1; j++) {
                        if (vetorNomes[j] > vetorNomes[j + 1]) {
                            string temp = vetorNomes[j];
                            vetorNomes[j] = vetorNomes[j + 1];
                            vetorNomes[j + 1] = temp;
                        }
                    }
                }
                
                cout << "\nNomes ordenados em ordem alfabetica:" << endl;
                for (int i = 0; i < totalCadastrados; i++) {
                    cout << (i+1) << "- " << vetorNomes[i] << endl;
                }
                cout << "===================" << endl;
                cout << "Ordenacao realizada com sucesso!" << endl;
            }
            break;
            
        case 5:
            cout << "\nEncerrando o programa..." << endl;
            break;
            
        default:
            cout << "Opcao nao reconhecida. Tente novamente." << endl;
            break;
        }
    } while (escolha != 5);
    
    return 0;
}
