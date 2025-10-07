#include <iostream>
#include <string>
#define TAM 1000

using namespace std;

#include "../00-Utilidade/meusTipos.h"
#include "../00-Utilidade/meusMetodos.h"


int main() {
    Pessoa vetor[TAM];
    int qtd_pessoas = 0;
    string baseDados = "base.csv";

    qtd_pessoas = conectarBaseNomes(baseDados, vetor, TAM);
    menu(vetor, TAM, qtd_pessoas);

    return 1;
}