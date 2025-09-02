#ifndef METODOS_H
#define METODOS_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <string.h>

using namespace std;

void popular(int vetor[], int quantidade, int tamanho) {
    if (quantidade > tamanho) {
        cout << "Essa quantidade nao eh possivel...";
        return; // Forçando a saída do método
    }
    srand(time(NULL));
    for (int i = 0; i < quantidade; i++) {
        vetor[i] = rand() % 100;
    }
}

void exibir(string frase, int vetor[], int quantidade, int tamanho) {
    if (quantidade > tamanho) {
        cout << "Essa quantidade nao eh possivel...";
        return; // Forçando a saída do método
    }
    cout << frase << endl;
    for (int i = 0; i < quantidade; i++) {
        cout << vetor[i] << endl;
    }
}

void menorElemento(int vetor[], int quantidade, int tamanho) {
    int menor = vetor[0];
    if (quantidade > tamanho) {
        cout << "Essa quantidade nao eh possivel...";
        return; // Forçando a saída do método
    }
    for (int i = 1; i < quantidade; i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }
    cout << "Menor elemento.... " << menor << endl;
}

void escreverSeValida(int dia, int mes, int ano) {
    // Meses com 31: 1, 3, 5, 7, 8, 10, 12
    // Meses com 30: 4, 6, 9, 11
    // Mês com 28/29: 2
    if (dia == 31 && (mes == 2 || mes == 4 || mes == 6 || mes == 9 || mes == 11)) {
        cout << "Data invalida" << endl;
    } else if (dia == 29 && mes == 2 && (ano % 4 != 0)) {
        cout << "Data invalida" << endl;
    } else if (dia > 29 && mes == 2) {
        cout << "Data invalida" << endl;
    } else {
        cout << "Data valida" << endl;
    }
}

void escreverSeValida2(string data) {
    // Meses com 31: 1, 3, 5, 7, 8, 10, 12
    // Meses com 30: 4, 6, 9, 11
    // Mês com 28/29: 2
    // data = 01/09/2025
    int dia = stoi(data.substr(0, 2));
    int mes = stoi(data.substr(3, 2));
    int ano = stoi(data.substr(6, 4));
    
    if (dia == 31 && (mes == 2 || mes == 4 || mes == 6 || mes == 9 || mes == 11)) {
        cout << "Data invalida" << endl;
    } else if (dia == 29 && mes == 2 && (ano % 4 != 0)) {
        cout << "Data invalida" << endl;
    } else if (dia > 29 && mes == 2) {
        cout << "Data invalida" << endl;
    } else {
        cout << "Data valida" << endl;
    }
}

bool verificarDataValida(string data) {
    // Verifica formato básico
    if (data.size() != 10 || data[2] != '/' || data[5] != '/') {
        return false;
    }
    
    int dia = stoi(data.substr(0, 2));
    int mes = stoi(data.substr(3, 2));
    int ano = stoi(data.substr(6, 4));
    
    // Validações de data
    if (dia == 31 && (mes == 2 || mes == 4 || mes == 6 || mes == 9 || mes == 11)) {
        return false;
    } else if (dia == 29 && mes == 2 && (ano % 4 != 0)) {
        return false;
    } else if (dia > 29 && mes == 2) {
        return false;
    } else {
        return true;
    }
}

#endif