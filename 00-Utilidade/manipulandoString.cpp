#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    string horaE = "19:36";
    string hora = horaE.substr(0,2);
    string minutos = horaE.substr(3,2);
    cout << hora << endl;
    cout << minutos << endl;


    string data = "11/08/2025";
    string dia = data.substr(0,2);
    string mes = data.substr(3,2);
    string ano = data.substr(6,4);

    int tempoPermanencia = stoi(hora) * 60 + stoi(minutos);
    cout << "Permanencia: " << tempoPermanencia << endl;


    string umaFrase = "turma de algoritmos em sistemas de informacao";
    cout << umaFrase.find("algo") << endl;

    return 0;
}


// Extrair partes de uma string
string data = "11/08/2025";
string dia = data.substr(0, 2);    // Pega 2 caracteres a partir da posição 0
string mes = data.substr(3, 2);    // Pega 2 caracteres a partir da posição 3
string ano = data.substr(6, 4);    // Pega 4 caracteres a partir da posição 6

// Procurar texto em string
string frase = "turma de algoritmos";
size_t posicao = frase.find("algo");  // Retorna posição ou string::npos se não encontrar

// Converter string para número
int numero = stoi("123");  // String para Int

// Converter para maiúsculo
string converterMaiusculo(string texto) {
    for (int i = 0; i < texto.length(); i++) {
        texto[i] = toupper(texto[i]);
    }
    return texto;
}


fflush(stdin);  // Limpa buffer de entrada após cin
// Use após cin e antes de getline()


// Para números
int numero;
cin >> numero;

// Para strings com espaços
string frase;
getline(cin, frase);

// Sempre usar fflush(stdin) entre cin e getline!


// Validar data no formato dd/mm/aaaa
bool validarFormatoData(string data) {
    return (data.size() == 10 && data[2] == '/' && data[5] == '/');
}

// Validar range de números
bool validarRange(int valor, int min, int max) {
    return (valor >= min && valor <= max);
}


// Configurar gerador (fazer apenas uma vez no programa)
srand(time(NULL));

// Gerar número aleatório de 0 a 99
int aleatorio = rand() % 100;


// String para int
int numero = stoi("123");

// Int para string
string texto = to_string(123);

//Dicas Importantes

/*Sempre incluir fflush(stdin) após cin e antes de getline()
substr(inicio, tamanho) - início é a posição, tamanho é quantos caracteres
find() retorna string::npos se não encontrar
tm_mon vai de 0-11, sempre somar 1
tm_year é anos desde 1900, sempre somar 1900
#define cria constantes, não usa ponto e vírgula
return 0 ou return 1 no final do main()

Padrões de Nomenclatura

Variáveis: minhaVariavel (camelCase)
Constantes: TAM, MAX_ELEMENTOS (MAIÚSCULO)
Funções: nomeDescritivo() (camelCase)*/