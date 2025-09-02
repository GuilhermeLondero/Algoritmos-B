/**
 * Programa: Validação de Data com String
 * Arquivo: metodoSemRetorno4.cpp
 * 
 * Descrição: Solicita uma data no formato dd/mm/aaaa, valida o formato
 * e chama função para verificar se a data é válida
 * 
 * Autor: [Seu Nome]
 * Data: [Data Atual]
 */

#include <iostream>
#include <string>
#include "metodos.h"

using namespace std;

int main() {
    string data;
    
    do {
        cout << "Digite data [dd/mm/aaaa] entre 1980 e 2025: ";
        cin >> data;
        
        // Verifica tamanho e posição das barras
        if (data.size() != 10 || data[2] != '/' || data[5] != '/') {
            cout << "Data com formato invalido..." << endl;
        }
    } while (data.size() != 10 || data[2] != '/' || data[5] != '/');
    
    // Chama função para validar e escrever resultado
    escreverSeValida2(data);
    
    return 0;
}