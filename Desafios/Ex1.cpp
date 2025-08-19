//1) Fazer um programa em C ou C++ que preencha um vetor de string com n nomes e exiba-os

#include <iostream>
#include <string>

#define TAM 4

using namespace std;

int main() {
    cout << "=== Sistema de Cadastro de Nomes ===" << endl;
    string vetorNomes[TAM];
    int totalCadastrados = 0;
    int escolha;
    
    do {
        cout << "\n--- MENU PRINCIPAL ---" << endl;
        cout << "1 - Inserir nomes" << endl;
        cout << "2 - Exibir nomes" << endl;
        cout << "3 - Finalizar" << endl;
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
                string nomeDigitado;
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
            cout << "\nEncerrando o programa..." << endl;
            break;
            
        default:
            cout << "Opcao nao reconhecida. Tente novamente." << endl;
            break;
        }
    } while (escolha != 3);
    
    return 0;
}
