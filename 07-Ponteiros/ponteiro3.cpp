#include <iostream>
#include <ctime>

#define TAM 10
using namespace std;

void popula(int *v, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 100 + 1;
    }
}

void exibe(int *v, int n) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << endl;
    }
}

void ParesImpares(int *v, int n, int *pares, int *impares) {
    *pares = 0;
    *impares = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 0) {
            *pares == *pares + 1;
        } else {
            *impares == *impares + 1;
        }
    }
}

int main() {
    int vetor[TAM];
    popula(vetor, TAM);
    exibe(vetor, TAM);
    
    int pares;
    int impares;
    ParesImpares(vetor, TAM, &pares, &impares);
    
    cout << "Pares: " << pares << endl;
    cout << "Ímpares: " << impares << endl;
    
    return 0;
}