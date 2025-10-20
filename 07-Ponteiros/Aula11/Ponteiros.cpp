#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Função para exibir o vetor
void exibirVetor(int vetor[], int tamanho) {
    cout << "Vetor: ";
    for(int i = 0; i < tamanho; i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;
}

// Função para popular o vetor
void popularVetor(int vetor[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100 + 1;
    }
}

// Função para localizar pares e ímpares
void localizarParesImpares(int vetor[], int tamanho) {
    cout << "\nNúmeros PARES: ";
    for(int i = 0; i < tamanho; i++) {
        if(vetor[i] % 2 == 0) {
            cout << vetor[i] << " ";
        }
    }
    
    cout << "\nNúmeros ÍMPARES: ";
    for(int i = 0; i < tamanho; i++) {
        if(vetor[i] % 2 == 1) {
            cout << vetor[i] << " ";
        }
    }
    
    cout << endl;
}

int main() {
    srand(time(0));  // Inicializa números aleatórios
    
    const int TAMANHO = 10;
    int numeros[TAMANHO];
    
    cout << "=== Programa de Vetores - Pares e Ímpares ===" << endl;
    
    // Passo 1: Popular o vetor
    popularVetor(numeros, TAMANHO);
    
    // Passo 2: Mostrar o vetor gerado
    cout << "\nVetor gerado:" << endl;
    exibirVetor(numeros, TAMANHO);
    
    // Passo 3: Localizar e mostrar pares e ímpares
    localizarParesImpares(numeros, TAMANHO);
    
    return 0;
}