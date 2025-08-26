#include <iostream>
#include <string>
using namespace std;

#include "meusMetodos.h"

int main() {
    string palavra, dia, mes, ano;
    char letra;

    cout << "Digite uma palavra: ";
    cin >> palavra;
    cout << "Digite uma letra: ";
    cin >> letra;
    contarLetra(palavra, letra);

    cout << "Digite o dia: ";
    cin >> dia;
    cout << "Digite o mes: ";
    cin >> mes;
    cout << "Digite o ano: ";
    cin >> ano;
    verificarData(dia, mes, ano);

    return 0;
}
