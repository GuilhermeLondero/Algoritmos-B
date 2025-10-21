#include <iostream>
#include <ctime>
#include <string>
#define TAM 5
using namespace std;

// Método para preencher o vetor com nomes lidos do teclado
void preencherVetor(string vetor[], int tamanho) {
    cout << "===== PREENCHIMENTO DO VETOR =====\n";
    for(int i = 0; i < tamanho; i++) {
        cout << "Digite o " << i+1 << "º nome: ";
        getline(cin, vetor[i]);
    }
    cout << "\nVetor preenchido com sucesso!\n";
}

// Método para exibir os nomes do vetor
void exibirVetor(string vetor[], int tamanho) {
    cout << "\n===== NOMES NO VETOR =====\n";
    for(int i = 0; i < tamanho; i++) {
        cout << "Posição [" << i << "]: " << vetor[i] << endl;
    }
    cout << "==========================\n";
}

// Método para buscar um nome no vetor (retorna posição por referência)
void buscarNome(string vetor[], int tamanho, string nomeBusca, int &posicao) {
    posicao = -1;  // Inicializa com -1 (não encontrado)
    
    for(int i = 0; i < tamanho; i++) {
        if(vetor[i] == nomeBusca) {
            posicao = i;  // Atualiza a posição se encontrar
            break;  // Sai do loop ao encontrar
        }
    }
}

int main() {
    string vetor[TAM];
    int opcao;
    
    do {
        cout << "\n===== MENU =====\n";
        cout << "1 - Preencher vetor\n";
        cout << "2 - Exibir vetor\n";
        cout << "3 - Buscar nome\n";
        cout << "4 - Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cin.ignore(); // Limpa o buffer após ler o número
        
        switch(opcao) {
            case 1:
                preencherVetor(vetor, TAM);
                break;
                
            case 2:
                exibirVetor(vetor, TAM);
                break;
                
            case 3: {
                string nomeProcurado;
                int posicaoEncontrada;
                
                cout << "\nDigite o nome a ser buscado: ";
                getline(cin, nomeProcurado);
                
                buscarNome(vetor, TAM, nomeProcurado, posicaoEncontrada);
                
                if(posicaoEncontrada != -1) {
                    cout << "Nome '" << nomeProcurado << "' encontrado na posição [" 
                         << posicaoEncontrada << "]" << endl;
                } else {
                    cout << "Nome '" << nomeProcurado << "' não foi encontrado no vetor!" << endl;
                }
                break;
            }
                
            case 4:
                cout << "Encerrando o programa...\n";
                break;
                
            default:
                cout << "Opção inválida!\n";
        }
    } while(opcao != 4);
    
    return 0;
}