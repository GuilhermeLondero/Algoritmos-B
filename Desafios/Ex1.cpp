//1) Fazer um programa em C ou C++ que preencha um vetor de string com n nomes e exiba-os

#include <iostream>
#include <string>

#define TAM 10

using namespace std;

int main() {
    cout << "Sistema de Cadastro de Nomes" << endl;
    string nomes[TAM];
    int quantidadeInseridos = 0;
    int opcao;
    string nome;
    
    do {
        cout << "\n=============== MENU ===============" << endl;
        cout << "1 - Cadastrar nome" << endl;
        cout << "2 - Listar nomes" << endl;
        cout << "3 - Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;
        cin.ignore();
 
        switch (opcao) {
        case 1:
            cout << "\nCadastrar nome..." << endl;
            if (quantidadeInseridos >= TAM) {
                cout << "Vetor lotado! Maximo " << TAM << " nomes." << endl;
            } else {
                cout << "Nome: ";
                getline(cin, nome);
                
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
            cout << "\nSaindo do programa..." << endl;
            break;
            
        default:
            cout << "Opcao invalida! Tente novamente." << endl;
            break;
        }
        
        if (opcao != 3) {
            cout << "\nPressione Enter para continuar...";
            cin.get();
        }
        
    } while (opcao != 3);
    
    return 0;
}
