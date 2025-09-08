"Fazer um programa em C++ que preencha um vetor de string com n nomes e exiba-os"

- **Exercício 1**: Cadastro e listagem básicos
- **Exercício 2**: + Pesquisa de nomes
- **Exercício 3**: + Ordenação (preparação)
- **Exercício 4**: + Ordenação completa + Validação duplicatas

Exercício 1 - Base Fundamental

Funcionalidades
- Menu com 3 opções
- Cadastrar nomes (até TAM)
- Listar nomes cadastrados
- Sair do programa

/* Código Base */

#include <iostream>
#include <string>
#define TAM 4
using namespace std;

int main() {
    string nomes[TAM];
    int quantidadeInseridos = 0;
    int opcao;
    
    do {
        cout << "MENU" << endl;
        cout << "1 - Cadastrar nomes" << endl;
        cout << "2 - Listar nomes" << endl;
        cout << "3 - Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;
        fflush(stdin);
        
        switch (opcao) {
            case 1:
                // Cadastro básico
                if (quantidadeInseridos == TAM) {
                    cout << "Vetor lotado..." << endl;
                } else {
                    for (int i = 0; i < TAM; i++) {  // Erro: deveria ser até espaços restantes
                        cout << "Nome: ";
                        getline(cin, nome);
                        nomes[quantidadeInseridos] = nome;
                        quantidadeInseridos++;
                    }
                }
                break;
                
            case 2:
                // Listagem básica
                if (quantidadeInseridos == 0) {
                    cout << "Vetor vazio..." << endl;
                } else {
                    for (int i = 0; i < quantidadeInseridos; i++) {
                        cout << "Nome " << (i+1) << ": " << nomes[i] << endl;
                    }
                    cout << "Total: " << quantidadeInseridos << endl;
                }
                break;
        }
    } while (opcao != 3);
    
    return 1;
}

/* Problemas na Versão 1
- **Loop de cadastro incorreto**: pede TAM nomes mesmo se não há espaço
- **Não valida nomes duplicados**
- **Não permite pesquisa**


Novas Funcionalidades Versão 2
- Pesquisa por nome (opção 3)
- Menu expandido para 4 opções

Versão 2 - Adicionando Pesquisa */

case 3:
    cout << "Pesquisar nome ..." << endl;
    if (quantidadeInseridos == 0) {
        cout << "Vetor vazio... não é possível pesquisar ..." << endl;
    } else {
        cout << "Nome para pesquisa: ";
        getline(cin, nome);
        int quantidadeLocalizados = 0;
        
        for (int i = 0; i < quantidadeInseridos; i++) {
            if (nomes[i].find(nome)) {  // ERRO aqui!
                cout << nomes[i] << endl;
                quantidadeLocalizados++;
            }
        }
        cout << "Total de registros: " << quantidadeLocalizados << endl;
    }
    break;

/* Problema na Versão 2
- **Erro na pesquisa**: 'find()' retorna posição, não booleano
- **Lógica incorreta**: 'if (nomes[i].find(nome))' sempre é true se encontrar na posição 0


Novas Funcionalidades Versão 3
- **Opção de ordenação** (opção 4)
- Menu expandido para 5 opções
- **Correção da pesquisa**

Versão 3 - Correção da Pesquisa */

case 3:
    // ... código anterior ...
    for (int i = 0; i < quantidadeInseridos; i++) {
        if (nomes[i].find(nome) != std::string::npos) {  // CORRIGIDO!
            cout << nomes[i] << endl;
            quantidadeLocalizados++;
        }
    }

Preparação da Ordenação

case 4:
    cout << "Ordenando o vetor de nomes..." << endl;
    // aplicar a rotina de ordenação no vetor nomes usando bubble sort
    // (comentário indicando que será implementado)
    break;

/* Melhoria na Versão 3
- **Pesquisa funcional**: usa '!= string::npos'
- **Estrutura pronta** para ordenação

Exercício 4 - Versão Completa e Robusta

Funcionalidades Finais
- **Ordenação completa** (Bubble Sort)
- **Validação de duplicatas**
- **Sistema robusto e eficiente** 

Versão 4 - Validação de Duplicatas */

case 1:
    cout << "Cadastrar nomes ..." << endl;
    if (quantidadeInseridos == TAM) {
        cout << "Vetor lotado..." << endl;
    } else {
        for (int i = 0; i < TAM; i++) {
            cout << "Nome: ";
            getline(cin, nome);
            fflush(stdin);
            
            // NOVA FUNCIONALIDADE: verificar duplicatas
            bool existe = false;
            for (int j = 0; j < quantidadeInseridos; j++) {
                if (nome == nomes[j]) {
                    existe = true;
                    break;  // Sai do loop interno
                }
            }
            
            if (!existe) {
                nomes[quantidadeInseridos] = nome;
                quantidadeInseridos++;
            } else {
                cout << "Nome já cadastrado..." << endl;
            }
        }
    }
    break;

// Algoritmo de Ordenação (Bubble Sort)

case 4:
    cout << "Ordenando o vetor de nomes..." << endl;
    
    // Variáveis para o método da bolha
    int houveTroca;
    string tmp;
    
    // Algoritmo Bubble Sort
    do {
        houveTroca = 0;  // Flag para verificar se houve troca
        
        for (int i = 0; i < quantidadeInseridos - 1; i++) {
            if (nomes[i] > nomes[i + 1]) {  // Compara strings
                houveTroca = 1;
                
                // Trocar elementos
                tmp = nomes[i];
                nomes[i] = nomes[i + 1];
                nomes[i + 1] = tmp;
            }
        }
    } while (houveTroca == 1);  // Continua até não haver mais trocas
    break;

//Como Recriar a Versão Mais Robusta

// Estrutura Base

#include <iostream>
#include <string>
#define TAM 4
using namespace std;

int main() {
    string nomes[TAM];
    int quantidadeInseridos = 0;
    int opcao;
    string nome;
    
    // Variáveis para ordenação
    int houveTroca;
    string tmp;

// Menu Completo

do {
    cout << "MENU" << endl;
    cout << "1 - Cadastrar nomes" << endl;
    cout << "2 - Listar nomes" << endl;
    cout << "3 - Pesquisar nome" << endl;
    cout << "4 - Ordenar nomes" << endl;
    cout << "5 - Sair" << endl;
    cout << "Opcao: ";
    cin >> opcao;
    fflush(stdin);

// Cadastro com Validação

case 1:
    if (quantidadeInseridos == TAM) {
        cout << "Vetor lotado..." << endl;
    } else {
        for (int i = 0; i < TAM; i++) {
            cout << "Nome: ";
            getline(cin, nome);
            fflush(stdin);
            
            // Verificar duplicatas
            bool existe = false;
            for (int j = 0; j < quantidadeInseridos; j++) {
                if (nome == nomes[j]) {
                    existe = true;
                    break;
                }
            }
            
            if (!existe) {
                nomes[quantidadeInseridos] = nome;
                quantidadeInseridos++;
            } else {
                cout << "Nome já cadastrado..." << endl;
            }
        }
    }
    break;

// Pesquisa Funcional

case 3:
    if (quantidadeInseridos == 0) {
        cout << "Vetor vazio..." << endl;
    } else {
        cout << "Nome para pesquisa: ";
        getline(cin, nome);
        int quantidadeLocalizados = 0;
        
        for (int i = 0; i < quantidadeInseridos; i++) {
            if (nomes[i].find(nome) != string::npos) {
                cout << nomes[i] << endl;
                quantidadeLocalizados++;
            }
        }
        cout << "Total encontrados: " << quantidadeLocalizados << endl;
    }
    break;

// Ordenação Bubble Sort

case 4:
    cout << "Ordenando nomes..." << endl;
    do {
        houveTroca = 0;
        for (int i = 0; i < quantidadeInseridos - 1; i++) {
            if (nomes[i] > nomes[i + 1]) {
                houveTroca = 1;
                tmp = nomes[i];
                nomes[i] = nomes[i + 1];
                nomes[i + 1] = tmp;
            }
        }
    } while (houveTroca == 1);
    cout << "Nomes ordenados!" << endl;
    break;

/* Conceitos Aprendidos na Evolução

Validação de Entrada
- Verificar se vetor está cheio
- Verificar se vetor está vazio
- Validar duplicatas

Pesquisa em Strings
- Uso correto do 'find()'
- Comparação com 'string::npos'
- Contador de resultados

Algoritmo de Ordenação
- **Bubble Sort**: empurra maiores para o final
- **Flag de controle**: 'houveTroca'
- **Troca de elementos**: usar variável temporária

Estrutura de Menu Robusto
- Tratamento de opções inválidas
- Validações antes de executar ações
- Feedback ao usuário

Dicas para Construir do Zero

1. **Comece simples**: Menu básico + cadastro + listagem
2. **Adicione gradualmente**: Uma funcionalidade por vez
3. **Teste cada parte**: Verifique se funciona antes de adicionar nova feature
4. **Valide tudo**: Vetor cheio, vazio, dados duplicados
5. **Organize o código**: Use comentários e organize logicamente */

Padrões de Validação Essenciais

// Verificar se pode cadastrar
if (quantidade >= TAM) {
    cout << "Limite atingido!" << endl;
    return;
}

// Verificar se há dados para processar
if (quantidade == 0) {
    cout << "Nenhum dado cadastrado!" << endl;
    return;
}

// Verificar duplicatas
bool existe = false;
for (int i = 0; i < quantidade; i++) {
    if (dado == dados[i]) {
        existe = true;
        break;
    }
}