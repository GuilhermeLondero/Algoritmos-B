/*
Conceitos Fundamentais C++

#define - Definição de Constantes
#define cria constantes que são substituídas pelo compilador antes da compilação.

#define NOME_CONSTANTE valor */

Exemplos

#define TAM 100        // Define tamanho de vetor
#define PI 3.14159     // Define valor de PI
#define MAXIMO 1000    // Define valor máximo

int vetor[TAM];        // Equivale a: int vetor[100];
float area = PI * r;   // Equivale a: float area = 3.14159 * r;


/* Características Importantes
- **Não usa ponto e vírgula** no final
- **Não ocupa memória** (é substituição textual)
- **Convenção**: nomes em MAIÚSCULO
- **Escopo global** (vale para todo o arquivo) */

Vantagens do #define

#define TAM 50

int nomes[TAM];
int idades[TAM];
int quantidadeAlunos = 0;

/* break - Interrupção de Fluxo
break interrompe imediatamente a execução de loops ou switch-case. */

Uso em Switch-Case

switch (opcao) {
    case 1:
        cout << "Opção 1" << endl;
        break;  // SAI do switch
    case 2:
        cout << "Opção 2" << endl;
        break;  // SAI do switch
    default:
        cout << "Opção inválida" << endl;
        break;  // SAI do switch
}

Sem break - PERIGOSO:
switch (opcao) {
    case 1:
        cout << "Opção 1" << endl;
        // SEM break - continua executando case 2!
    case 2:
        cout << "Opção 2" << endl;  // Executa mesmo se opcao = 1
        break;
}

Uso em Loops

// Interrompe loop ao encontrar condição
for (int i = 0; i < quantidade; i++) {
    if (nomes[i] == nomeProcurado) {
        cout << "Encontrado na posição " << i << endl;
        break;  // SAI do for imediatamente
    }
}

// Interrompe while
while (true) {
    cout << "Digite um número (0 para sair): ";
    cin >> numero;
    if (numero == 0) {
        break;  // SAI do while
    }
    cout << "Você digitou: " << numero << endl;
}

/* Em Métodos COM Retorno */

int somar(int a, int b) {
    return a + b;  // RETORNA o resultado
}

bool ehPar(int numero) {
    return (numero % 2 == 0);  // RETORNA true ou false
}

/* Em Métodos SEM Retorno (void) */

void exibir(int vetor[], int tamanho) {
    if (tamanho <= 0) {
        cout << "Tamanho inválido!" << endl;
        return;  // SAI do método imediatamente
    }
    
    // Só executa se tamanho for válido
    for (int i = 0; i < tamanho; i++) {
        cout << vetor[i] << endl;
    }
}

/* No main() */

int main() {
    // Código do programa
    
    return 0;  // Indica que programa terminou com sucesso
    // return 1; // Indica que programa terminou com erro
}

/* Operadores Importantes */

Operadores de Comparação

==  // Igual a
!=  // Diferente de
<   // Menor que
>   // Maior que
<=  // Menor ou igual
>=  // Maior ou igual

Operadores Lógicos

&&  // E (AND)
||  // OU (OR)
!   // NÃO (NOT)

// Exemplo:
if (idade >= 18 && idade <= 65) {
    cout << "Idade válida para trabalhar" << endl;
}

Operador Módulo (%)

int resto = 10 % 3;  // resto = 1

// Verificar se é par
if (numero % 2 == 0) {
    cout << "Par" << endl;
} else {
    cout << "Ímpar" << endl;
}

Estruturas de Controle (if-else)

if (condição) {
    // Executa se verdadeiro
} else if (outraCondição) {
    // Executa se segunda condição for verdadeira
} else {
    // Executa se nenhuma condição for verdadeira
}

switch-case

switch (variavel) {
    case valor1:
        // Código
        break;
    case valor2:
        // Código
        break;
    default:
        // Código padrão
        break;
}

Loops

for - Quantidade conhecida

for (inicialização; condição; incremento) {
    // Código
}

// Exemplo:
for (int i = 0; i < 10; i++) {
    cout << i << endl;
}

while - Condição no início

while (condição) {
    // Código
}

// Exemplo:
int i = 0;
while (i < 10) {
    cout << i << endl;
    i++;
}

do-while - Condição no final

do {
    // Código (executa pelo menos uma vez)
} while (condição);

// Exemplo: Menu
do {
    cout << "Menu..." << endl;
    cin >> opcao;
} while (opcao != 0);


/* Conversão de Tipos */

String para Número

string texto = "123";
int numero = stoi(texto);      // String to Integer
float decimal = stof(texto);   // String to Float


Número para String

int numero = 123;
string texto = to_string(numero);

Caractere

char letra = 'A';
char minuscula = tolower(letra);  // 'a'
char maiuscula = toupper(letra);  // 'A'

/* Manipulação de Strings */

string frase = "Hello World";

int tamanho = frase.size();        // ou frase.length()
string parte = frase.substr(0, 5); // "Hello"
size_t pos = frase.find("World");  // posição onde encontrou

Verificar se Encontrou

if (frase.find("texto") != string::npos) {
    cout << "Encontrou!" << endl;
} else {
    cout << "Não encontrou!" << endl;
}

/* Arrays/Vetores */

Declaração

int numeros[10];           // Vetor de 10 inteiros
string nomes[TAM];         // Vetor de TAM strings
float notas[100];          // Vetor de 100 floats

Inicialização

int numeros[5] = {1, 2, 3, 4, 5};
string dias[7] = {"Dom", "Seg", "Ter", "Qua", "Qui", "Sex", "Sab"};

Percorrer Vetor

for (int i = 0; i < tamanho; i++) {
    cout << vetor[i] << endl;
}

Boas Práticas

Sempre Inicializar Variáveis

int contador = 0;        // Bom
string nome = "";        // Bom
bool encontrou = false;  // Bom

int valor;  // RUIM, Pode ter valor lixo

Usar Nomes Descritivos

int qtdAlunos;     // ✅ Bom
int x;             // ❌ Ruim

string nomeCompleto;  // ✅ Bom
string s;             // ❌ Ruim


Validar Entrada

do {
    cout << "Digite idade (1-120): ";
    cin >> idade;
    if (idade < 1 || idade > 120) {
        cout << "Idade inválida!" << endl;
    }
} while (idade < 1 || idade > 120);


Comentar Código Complexo

// Algoritmo de ordenação bolha
do {
    houveTroca = false;
    for (int i = 0; i < tamanho - 1; i++) {
        if (vetor[i] > vetor[i + 1]) {
            // Trocar elementos
            int temp = vetor[i];
            vetor[i] = vetor[i + 1];
            vetor[i + 1] = temp;
            houveTroca = true;
        }
    }
} while (houveTroca);

/*Erros Comuns */

Esquecer break no switch

// ERRO
switch (opcao) {
    case 1:
        cout << "Um" << endl;
        // SEM break - executa case 2 também!
    case 2:
        cout << "Dois" << endl;
}

Não limpar buffer

// ERRO
cin >> numero;
getline(cin, texto);  // Pode não funcionar

// CORRETO
cin >> numero;
fflush(stdin);       // Limpa buffer
getline(cin, texto); // Agora funciona

Índices fora do vetor

int vetor[5];
vetor[10] = 100;  // ERRO - índice não existe

Não verificar limites

// ERRO
for (int i = 0; i <= 10; i++) {  // <= pode causar erro
    vetor[i] = i;  // Se vetor tiver tamanho 10, vetor[10] não existe
}

// CORRETO
for (int i = 0; i < 10; i++) {   // < é mais seguro
    vetor[i] = i;
}
// Função para obter data atual
string obterDataAtual() {
    time_t agora = time(nullptr);        // Pega tempo atual
    tm* agora_local = localtime(&agora); // Converte para horário local
    
    string dia = to_string(agora_local->tm_mday);      // Dia do mês
    string mes = to_string(agora_local->tm_mon + 1);   // Mês (0-11, por isso +1)
    string ano = to_string(agora_local->tm_year + 1900); // Ano (desde 1900)
    
    return dia + "/" + mes + "/" + ano;
}

{
    time_t agora = time(nullptr);
    tm* agora_local = localtime(&agora);

    string dia = to_string(agora_local->tm_mday);
    string mes = to_string(agora_local->tm_mon + 1);
    string ano = to_string(agora_local->tm_year + 1900);

    cout << "Data: " << dia << "/" << mes << "/" << ano << endl;

    string hora = to_string(agora_local->tm_hour);
    string minutos = to_string(agora_local->tm_min); 

    cout << "Hora: " << hora << ":" << minutos << endl;
    return 0;
}

// Função para obter hora atual
string obterHoraAtual() {
    time_t agora = time(nullptr);
    tm* agora_local = localtime(&agora);
    
    string hora = to_string(agora_local->tm_hour);
    string minutos = to_string(agora_local->tm_min);
    
    return hora + ":" + minutos;
}

{
    time_t agora = time(nullptr);
    tm* agora_local = localtime(&agora);

    string hora = to_string(agora_local->tm_hour);
    string minutos = to_string(agora_local->tm_min); 

    cout << "Hora: " << hora << ":" << minutos << endl;
    return 0;
}
#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    time_t agora = time(nullptr);
    tm* agora_local = localtime(&agora);

    string dia = to_string(agora_local->tm_mday);
    string mes = to_string(agora_local->tm_mon + 1);
    string ano = to_string(agora_local->tm_year + 1900);

    cout << "Data: " << dia << "/" << mes << "/" << ano << endl;

    string hora = to_string(agora_local->tm_hour);
    string minutos = to_string(agora_local->tm_min); 

    cout << "Hora: " << hora << ":" << minutos << endl;
    return 0;
}
#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    time_t agora = time(nullptr);
    tm* agora_local = localtime(&agora);

    string hora = to_string(agora_local->tm_hour);
    string minutos = to_string(agora_local->tm_min); 

    cout << "Hora: " << hora << ":" << minutos << endl;
    return 0;
}
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