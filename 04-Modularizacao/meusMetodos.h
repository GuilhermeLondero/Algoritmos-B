#include <iostream>
#include <string>
using namespace std;

void contarLetra(string palavra, char letra) {
    int contador = 0;
    for (char c : palavra) {
        if (c == letra) {
            contador++;
        }
    }
    cout << "A letra '" << letra << "' aparece " << contador << " vezes na palavra '" << palavra << "'." << endl;
}

void verificarData(string dia, string mes, string ano) {
    int d = stoi(dia);
    int m = stoi(mes);
    int a = stoi(ano);

    int diasNoMes[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    // ano bissexto
    if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)) {
        diasNoMes[1] = 29;
    }

    if (m < 1 || m > 12 || d < 1 || d > diasNoMes[m-1]) {
        cout << "DATA INVALIDA" << endl;
    } else {
        cout << "DATA VALIDA" << endl;
    }
}
