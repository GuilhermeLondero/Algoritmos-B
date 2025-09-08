/*Menu Interativo em C++ - Guia Prático

Estrutura Básica de Menu

Um menu interativo é composto por:
1. **Loop principal** (do-while)
2. **Exibição das opções**
3. **Leitura da escolha do usuário**
4. **Estrutura switch-case** para executar ações
5. **Condição de saída** */

//Exemplo Base (5 opções)

#include <iostream>
#include <string>
using namespace std;

int main() {
    int opcao;
    
    do {
        // === EXIBIÇÃO DO MENU ===
        cout << "========== M E N U ==========" << endl;
        cout << "1 - Primeira opção" << endl;
        cout << "2 - Segunda opção" << endl;
        cout << "3 - Terceira opção" << endl;
        cout << "4 - Quarta opção" << endl;
        cout << "5 - Sair" << endl;
        cout << "Opção: ";
        
        // === LEITURA DA OPÇÃO ===
        cin >> opcao;
        fflush(stdin);  // Limpa buffer
        
        // === PROCESSAMENTO ===
        switch (opcao) {
            case 1:
                cout << "Executando primeira opção..." << endl;
                // Seu código aqui
                break;
                
            case 2:
                cout << "Executando segunda opção..." << endl;
                // Seu código aqui
                break;
                
            case 3:
                cout << "Executando terceira opção..." << endl;
                // Seu código aqui
                break;
                
            case 4:
                cout << "Executando quarta opção..." << endl;
                // Seu código aqui
                break;
                
            case 5:
                cout << "Encerrando programa..." << endl;
                break;
                
            default:
                cout << "Opção inválida!" << endl;
                break;
        }
        
        cout << endl;  // Linha em branco para organização
        
    } while (opcao != 5);  // Continua até escolher sair
    
    cout << "Programa encerrado." << endl;
    return 0;
}

//Exemplo Prático: Sistema de Empréstimos

#include <iostream>
#include <string>
#define TAM 4
using namespace std;

struct Emprestimo {
    string descricao;
    string nome;
    string celular;
    string data;
};

int main() {
    int opcao;
    Emprestimo meusItens[TAM];
    int qtdEmprestimos = 0;
    
    do {
        cout << "=== SISTEMA DE EMPRÉSTIMOS ===" << endl;
        cout << "1 - Emprestar item" << endl;
        cout << "2 - Devolver item" << endl;
        cout << "3 - Listar empréstimos" << endl;
        cout << "4 - Sair" << endl;
        cout << "Opção: ";
        cin >> opcao;
        fflush(stdin);
        
        switch (opcao) {
            case 1:
                cout << "=== ÁREA DE EMPRÉSTIMO ===" << endl;
                if (qtdEmprestimos >= TAM) {
                    cout << "Limite de empréstimos atingido!" << endl;
                } else {
                    cout << "Descrição do item: ";
                    getline(cin, meusItens[qtdEmprestimos].descricao);
                    cout << "Nome da pessoa: ";
                    getline(cin, meusItens[qtdEmprestimos].nome);
                    cout << "Celular: ";
                    getline(cin, meusItens[qtdEmprestimos].celular);
                    cout << "Data (dd/mm/aaaa): ";
                    getline(cin, meusItens[qtdEmprestimos].data);
                    
                    qtdEmprestimos++;
                    cout << "Empréstimo registrado!" << endl;
                }
                break;
                
            case 2:
                cout << "=== ÁREA DE DEVOLUÇÃO ===" << endl;
                if (qtdEmprestimos == 0) {
                    cout << "Nenhum item está emprestado." << endl;
                } else {
                    // Implementar lógica de devolução
                    cout << "Funcionalidade em desenvolvimento..." << endl;
                }
                break;
                
            case 3:
                cout << "=== LISTAGEM DE EMPRÉSTIMOS ===" << endl;
                if (qtdEmprestimos == 0) {
                    cout << "Nenhum item está emprestado." << endl;
                } else {
                    for (int i = 0; i < qtdEmprestimos; i++) {
                        cout << "Empréstimo " << (i+1) << ":" << endl;
                        cout << "  Item: " << meusItens[i].descricao << endl;
                        cout << "  Pessoa: " << meusItens[i].nome << endl;
                        cout << "  Celular: " << meusItens[i].celular << endl;
                        cout << "  Data: " << meusItens[i].data << endl;
                        cout << "----------------------------" << endl;
                    }
                }
                break;
                
            case 4:
                cout << "Encerrando sistema..." << endl;
                break;
                
            default:
                cout << "Opção inválida!" << endl;
                break;
        }
        
        cout << endl;
        
    } while (opcao != 4);
    
    cout << "Sistema encerrado." << endl;
    return 0;
}

//Elementos Importantes do Menu

/* 
1. Loop do-while

do {
    // Código do menu
} while (opcao != OPCAO_SAIR);

**Executa pelo menos uma vez**
**Continua enquanto** a condição for verdadeira
**Para quando** usuário escolhe sair 


2. Limpeza de Buffer

cin >> opcao;
fflush(stdin);  // SEMPRE após cin!

- **Obrigatório** após `cin` e antes de `getline()`
- **Evita problemas** de entrada de dados


3. Switch-Case

switch (opcao) {
    case 1:
        // Código
        break;  // SEMPRE incluir break!
    case 2:
        // Código
        break;
    default:
        cout << "Opção inválida!" << endl;
        break;
}

4. Validação de Limites

if (quantidade >= TAM) {
    cout << "Limite atingido!" << endl;
} else {
    // Processar
}

5. Verificação de Dados Vazios

if (quantidade == 0) {
    cout << "Nenhum dado cadastrado." << endl;
} else {
    // Exibir dados
}

Padrão de Organização Visual

cout << "======= TÍTULO SEÇÃO =======" << endl;
cout << "Mensagem informativa" << endl;
cout << "----------------------------" << endl;
cout << endl;  // Linha em branco

Dicas de Boas Práticas

1. **Sempre incluir opção "Sair"** como última opção
2. **Usar default** no switch para opções inválidas
3. **Validar limites** antes de adicionar dados
4. **Verificar se há dados** antes de exibir/processar
5. **Limpar buffer** após cin
6. **Organizar visualmente** com linhas e espaços
7. **Dar feedback** ao usuário ("Cadastrado!", "Erro!", etc.)

Estruturas de Controle Essenciais

Validação de Range

do {
    cout << "Digite um número entre 1 e 5: ";
    cin >> numero;
    if (numero < 1 || numero > 5) {
        cout << "Número fora da faixa!" << endl;
    }
} while (numero < 1 || numero > 5);

Confirmação de Ação

char confirma;
cout << "Tem certeza? (s/n): ";
cin >> confirma;
if (confirma == 's' || confirma == 'S') {
    // Executar ação
}

Fluxo de Execução Típico

1. **Exibe menu** → 2. **Lê opção** → 3. **Processa escolha** → 4. **Volta ao menu** (se não for sair)

O menu é o **coração** da interação com o usuário em programas console!*/