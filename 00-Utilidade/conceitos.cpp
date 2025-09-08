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