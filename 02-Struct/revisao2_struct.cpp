// Declaração de Struct geralmente feita em arquivo .h (header)
struct NomeStruct {
    tipo campo1;
    tipo campo2;
    tipo campo3;
};

//Exemplo 1: Glicemia (do arquivo revisao2_struct.cpp)

struct Glicemia {
    int valorGlicemia;
    string data;
    string hora;
};

//Exemplo 2: Empréstimo (do arquivo revisao1_menu.cpp)

struct Emprestimo {
    string descricao;  // Item emprestado
    string nome;       // Nome da pessoa
    string celular;    // Telefone da pessoa
    string data;       // Data do empréstimo
};

//Criar uma Variável da Struct

Glicemia medicaoAlexandre;  // Cria uma variável do tipo Glicemia

//Atribuir Valores aos Campos

medicaoAlexandre.valorGlicemia = 133;
medicaoAlexandre.data = "11/08/2025";
medicaoAlexandre.hora = "19:02";

//Usar em Vetores

Glicemia ano2025[365];  // Vetor de 365 medições

// Preenchendo primeira posição
ano2025[0].valorGlicemia = 98;
ano2025[0].data = "11/07/2025";
ano2025[0].hora = "12:34";

//Struct como Parâmetro de Função

//Passagem por Valor

void exibirGlicemia(Glicemia medicao) {
    cout << "Valor: " << medicao.valorGlicemia << endl;
    cout << "Data: " << medicao.data << endl;
    cout << "Hora: " << medicao.hora << endl;
}

void preencherGlicemia(Glicemia& medicao) {
    cout << "Digite o valor da glicemia: ";
    cin >> medicao.valorGlicemia;
    medicao.data = obterDataAtual();
    medicao.hora = obterHoraAtual();
}

//Exemplo Completo: Sistema de Glicemia

#include <iostream>
#include <string>
#define MAX_MEDICOES 100
using namespace std;

struct Glicemia {
    int valor;
    string data;
    string hora;
};

int main() {
    Glicemia medicoes[MAX_MEDICOES];
    int quantidade = 0;
    int opcao;
    
    do {
        cout << "=== CONTROLE DE GLICEMIA ===" << endl;
        cout << "1 - Cadastrar medição" << endl;
        cout << "2 - Listar medições" << endl;
        cout << "3 - Sair" << endl;
        cout << "Opção: ";
        cin >> opcao;
        fflush(stdin);
        
        switch (opcao) {
            case 1:
                if (quantidade < MAX_MEDICOES) {
                    cout << "Valor da glicemia: ";
                    cin >> medicoes[quantidade].valor;
                    cout << "Data (dd/mm/aaaa): ";
                    cin >> medicoes[quantidade].data;
                    cout << "Hora (hh:mm): ";
                    cin >> medicoes[quantidade].hora;
                    quantidade++;
                    cout << "Medição cadastrada!" << endl;
                } else {
                    cout << "Limite de medições atingido!" << endl;
                }
                break;
                
            case 2:
                if (quantidade == 0) {
                    cout << "Nenhuma medição cadastrada." << endl;
                } else {
                    for (int i = 0; i < quantidade; i++) {
                        cout << "Medição " << (i+1) << ":" << endl;
                        cout << "  Valor: " << medicoes[i].valor << endl;
                        cout << "  Data: " << medicoes[i].data << endl;
                        cout << "  Hora: " << medicoes[i].hora << endl;
                        cout << "-------------------" << endl;
                    }
                }
                break;
        }
    } while (opcao != 3);
    
    return 0;
}

//Padrões de Nomenclatura

Nome da Struct: PascalCase (primeira letra maiúscula) - Glicemia, Emprestimo, Pessoa
Campos: camelCase (primeira letra minúscula) - valorGlicemia, dataNascimento, nomeCompleto

//Comparação: Antes e Depois das Structs

//Sem Struct (dados soltos)
string nomePessoa;
string celularPessoa;
string itemEmprestado;
string dataEmprestimo;

//Com Struct (dados organizados)
struct Emprestimo {
    string nome;
    string celular;
    string item;
    string data;
};

Emprestimo emprestimo;  // Todos os dados juntos!

/* Dicas Importantes

1. **Declare structs antes do main()** ou em arquivo .h
2. **Use nomes descritivos** para structs e campos
3. **Agrupe dados relacionados** logicamente
4. **Prefira structs** quando tiver mais de 2-3 variáveis relacionadas
5. **Inicialize campos** para evitar valores lixo */