//2) A partir do programa anterior, fazer uma rotina que pesquise um nome ou parte do nome entre os nomes cadastrados no vetor de nomes

#include <iostream>
#include <string>

#define TAM 4

using namespace std;

int main() {
    cout << "=== Sistema de Cadastro e Busca de Nomes ===" << endl;
    string vetorNomes[TAM];
    int totalCadastrados = 0;
    int escolha;
    string nomeDigitado;
    
    do {
        cout << "\n--- MENU PRINCIPAL ---" << endl;
        cout << "1 - Inserir nomes" << endl;
        cout << "2 - Exibir nomes" << endl;
        cout << "3 - Buscar nome" << endl;
        cout << "4 - Finalizar" << endl;
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
            cout << "\nEncerrando o programa..." << endl;
            break;
            
        default:
            cout << "Opcao nao reconhecida. Tente novamente." << endl;
            break;
        }
    } while (escolha != 4);
    
    return 0;
}
