/*Tipos de Métodos

1. Métodos SEM Retorno (void)
- **Executam uma tarefa** mas não devolvem valor
- **Palavra-chave**: `void`
- **Também chamados**: Procedimentos

2. Métodos COM Retorno
- **Executam uma tarefa** E devolvem um valor
- **Tipo do retorno**: int, string, bool, etc.
- **Também chamados**: Funções
- **Palavra-chave**: `return` */

//Estrutura de um Método

TIPO_RETORNO nomeMetodo(TIPO param1, TIPO param2, ...) {
    // Corpo do método
    
    return valor;  // Apenas se não for void
}

//Métodos SEM Retorno (void)
//Exemplo 1: Conversão para Romanos (sem retorno)

void converteRomanos(int numero) {
    cout << "Convertido para romanos: ";
    
    switch (numero) {
        case 1:
            cout << "I" << endl;
            break;
        case 2:
            cout << "II" << endl;
            break;
        case 3:
            cout << "III" << endl;
            break;
        // ... outros casos
        default:
            cout << "Número não suportado" << endl;
            break;
    }
}

// Como usar:
int main() {
    int num = 5;
    converteRomanos(num);  // Chama o método
    return 0;
}

//Exemplo 2: Validação de Data (sem retorno)

void escreverSeValida(int dia, int mes, int ano) {
    // Meses com 31: 1, 3, 5, 7, 8, 10, 12
    // Meses com 30: 4, 6, 9, 11
    // Fevereiro: 28 ou 29 (ano bissexto)
    
    if (dia == 31 && (mes == 2 || mes == 4 || mes == 6 || mes == 9 || mes == 11)) {
        cout << "Data inválida" << endl;
    } else if (dia == 29 && mes == 2 && (ano % 4 != 0)) {
        cout << "Data inválida" << endl;
    } else if (dia > 29 && mes == 2) {
        cout << "Data inválida" << endl;
    } else {
        cout << "Data válida" << endl;
    }
}

//Exemplo 3: Manipulação de Vetores

void popular(int vetor[], int quantidade, int tamanho) {
    if (quantidade > tamanho) {
        cout << "Quantidade não é possível..." << endl;
        return;  // Força saída do método
    }
    
    srand(time(NULL));
    for (int i = 0; i < quantidade; i++) {
        vetor[i] = rand() % 100;  // Números de 0 a 99
    }
}

void exibir(string titulo, int vetor[], int quantidade, int tamanho) {
    if (quantidade > tamanho) {
        cout << "Quantidade não é possível..." << endl;
        return;
    }
    
    cout << titulo << endl;
    for (int i = 0; i < quantidade; i++) {
        cout << vetor[i] << endl;
    }
}

//Métodos COM Retorno
//Exemplo 1: Conversão para Romanos (com retorno)

string converteRomanos(int numero) {
    switch (numero) {
        case 1: return "I";
        case 2: return "II";
        case 3: return "III";
        case 4: return "IV";
        case 5: return "V";
        case 6: return "VI";
        case 7: return "VII";
        case 8: return "VIII";
        case 9: return "IX";
        case 10: return "X";
        default: return "Número não suportado";
    }
}

// Como usar:
int main() {
    int num = 7;
    string romano = converteRomanos(num);  // Recebe o valor retornado
    cout << "Número " << num << " em romano: " << romano << endl;
    return 0;
}

//Exemplo 2: Validação de Data (com retorno)

bool verificarDataValida(string data) {
    // Verifica formato
    if (data.size() != 10 || data[2] != '/' || data[5] != '/') {
        return false;
    }
    
    // Extrai componentes
    int dia = stoi(data.substr(0, 2));
    int mes = stoi(data.substr(3, 2));
    int ano = stoi(data.substr(6, 4));
    
    // Validações
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

// Como usar:
int main() {
    string data;
    
    do {
        cout << "Digite data [dd/mm/aaaa]: ";
        cin >> data;
        
        if (verificarDataValida(data)) {
            break;  // Sai do loop se data for válida
        } else {
            cout << "Data inválida..." << endl;
        }
    } while (true);
    
    cout << "Data válida aceita!" << endl;
    return 0;
}

//Exemplo 3: Contador de Vogais

int contarVogais(string frase) {
    int totalVogais = 0;
    
    for (int i = 0; i < frase.size(); i++) {
        char c = frase[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            totalVogais++;
        }
    }
    
    return totalVogais;
}

// Método que usa outro método
int contarConsoantes(string frase) {
    int totalVogais = contarVogais(frase);  // Chama outro método
    int totalConsoantes = frase.size() - totalVogais;
    return totalConsoantes;
}

//Passagem de Parâmetros
//Por Valor (cópia)

void metodo(int numero) {
    numero = 100;  // Não altera a variável original
}

//Por Referência (modifica original)

void metodo(int& numero) {
    numero = 100;  // ALTERA a variável original
}

//Arrays (sempre por referência)

void metodo(int vetor[], int tamanho) {
    vetor[0] = 999;  // ALTERA o vetor original
}

//Arquivo de Cabeçalho (.h)

// metodos.h
#ifndef METODOS_H
#define METODOS_H

#include <iostream>
#include <string>
using namespace std;

// Declarações das funções
void exibir(string titulo, int vetor[], int quantidade, int tamanho);
void popular(int vetor[], int quantidade, int tamanho);
bool verificarDataValida(string data);
int contarVogais(string frase);

#endif

//Boas Práticas

//Nomes Descritivos

// Ruim
int calc(int a, int b);

// Bom
int calcularMedia(int nota1, int nota2);

//Uma Responsabilidade por Método

// Cada método faz uma coisa
bool validarIdade(int idade);
bool validarNome(string nome);
void exibirPessoa(Pessoa p);

//Validar Parâmetros

void exibir(int vetor[], int quantidade, int tamanho) {
    if (quantidade > tamanho) {
        cout << "Erro: quantidade inválida!" << endl;
        return;  // Sai do método
    }
    // ... resto do código
}

//Usar Return para Saída Antecipada

void processar(int valor) {
    if (valor <= 0) {
        cout << "Valor inválido!" << endl;
        return;  // Sai imediatamente
    }
    
    // Continua processamento apenas se valor for válido
    cout << "Processando: " << valor << endl;
}

//Quando Usar Cada Tipo

/*
Use VOID quando:
- Método apenas **executa ações** (imprimir, salvar, etc.)
- Não precisa devolver informação
- Modifica parâmetros por referência

Use COM RETORNO quando:
- Método **calcula algo** e precisa devolver resultado
- Valida dados (retorna true/false)
- Processa e retorna dados transformados */

//Exemplo Prático Completo

#include <iostream>
#include <string>
using namespace std;

// Método COM retorno - calcula média
float calcularMedia(float nota1, float nota2) {
    return (nota1 + nota2) / 2.0;
}

// Método COM retorno - determina situação
string determinarSituacao(float media) {
    if (media >= 7.0) return "Aprovado";
    else if (media >= 4.0) return "Recuperação";
    else return "Reprovado";
}

// Método SEM retorno - exibe resultado
void exibirResultado(string nome, float media, string situacao) {
    cout << "=== RESULTADO ===" << endl;
    cout << "Aluno: " << nome << endl;
    cout << "Média: " << media << endl;
    cout << "Situação: " << situacao << endl;
}

int main() {
    string nome;
    float nota1, nota2;
    
    cout << "Nome do aluno: ";
    getline(cin, nome);
    cout << "Primeira nota: ";
    cin >> nota1;
    cout << "Segunda nota: ";
    cin >> nota2;
    
    float media = calcularMedia(nota1, nota2);        // Chama método COM retorno
    string situacao = determinarSituacao(media);     // Chama método COM retorno
    exibirResultado(nome, media, situacao);          // Chama método SEM retorno
    
    return 0;
}

/*
Resultado da execução:
1. `calcularMedia()` calcula e retorna a média
2. `determinarSituacao()` avalia e retorna a situação
3. `exibirResultado()` apenas exibe (void - sem retorno)

Resumo das Diferenças

| Aspecto | SEM Retorno (void) | COM Retorno |
|---------|-------------------|-------------|
| **Palavra-chave** | void | int, string, bool, etc. |
| **Return** | Opcional (só para sair) | Obrigatório |
| **Uso** | Ações, modificações | Cálculos, validações |
| **Chamada** | `metodo(params);` | `var = metodo(params);` |
*/