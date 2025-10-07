#include <string>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

void split(string vetor[], string str, string deli = " ")
{        
    int start = 0;
    int end = str.find(deli);
    int i = 0;
    while (end != -1) {
        vetor[i] = str.substr(start, end - start);
        i++;
        start = end + deli.size();
        end = str.find(deli, start);
    }
    vetor[i] = str.substr(start, end - start);
}


bool inserirLista(string nome, string listaNomes[], int *quantidadeNomes, int tamanho) {
    if (*quantidadeNomes == tamanho) {
        return false; //lista lotada
    }

    bool encontrou = false;
    int i;
    for (i = 0; i < *quantidadeNomes; i++) {
        if (nome == listaNomes[i]) {
            encontrou = true;
            break;
        }
    }

    if (encontrou) { //se encontrou o nome, retorna falso pq nao conseguiu inserir
        return false;
    }

    *quantidadeNomes = *quantidadeNomes + 1;
    listaNomes[*quantidadeNomes] = nome;

    //ordenar a lista de nomes
    //...

    return true; //consegui inserir na lista
}

void exibirListaNomes(string listaNomes[], int quantidadeNomes) {
    for (int i = 0; i < quantidadeNomes; i++) {
        cout << listaNomes[i] << endl;
    }
}

int conectarBase(string listaNomes[], string nomeBaseDados, int tamanho) {
    ifstream procuradorArquivo; //tipo de arquivo para leitura
    procuradorArquivo.open(nomeBaseDados); 

    string linha;
    int quantidadeNomes = 0;
    while (!procuradorArquivo.eof() && quantidadeNomes < tamanho) {
		getline(procuradorArquivo,linha); //lendo a linha inteira
        listaNomes[quantidadeNomes] = linha;
        quantidadeNomes++;
	}
  
    procuradorArquivo.close();

    return quantidadeNomes;
}

void listarPessoas(Pessoa vetor[], int qtd_pessoas){
    for(int i=0; i < qtd_pessoas; i++){
        cout << "Nome: " << vetor[i].nome << " - Email: " << vetor[i].email << endl;
    }
}

int cadastrarPessoa(Pessoa vetor[], int tamanho, int qtd_pessoas){
    if(tamanho == qtd_pessoas){
        cout << "Vetor cheio!" << endl;
        return qtd_pessoas;
    }
    string nome;
    string email;
    cout << "Nome: ";
    getline(cin, nome);
    cout << "Email: ";
    cin >> email;
    //validar se nome e email ja estao cadastrados
    vetor[qtd_pessoas].nome = nome;
    vetor[qtd_pessoas].email = email;
    qtd_pessoas++;
    //gravar a pessoa no arquivo
    gravarPessoaBase(nome, email, baseDados);
    return qtd_pessoas;
}

void menu(Pessoa vetor[], int tamanho, int qtd_pessoas){
    int opcao;
    do{
        cout << "MENU\n" << endl;
        cout << "1 - Listar pessoas" << endl;
        cout << "2 - Cadastrar pessoa" << endl;
        cout << "3 - Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch(opcao){
            case 1:
                listarPessoas(vetor, qtd_pessoas);
                break;
            case 2:
                cout << "Cadastrando pessoa..." << endl;
                qtd_pessoas = cadastrarPessoa(vetor, tamanho, qtd_pessoas, baseDados);
                break;
            case 3:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida!";
        }
    } while (opcao != 3);
}

int conectarBaseNomes(string baseDados, Pessoa vetor[], int tamanho){
    int qtd_pessoas = 0;
    ifstream procuradorArquivo; //tipo de arquivo para leitura
    procuradorArquivo.open(baseDados);

    if (!procuradorArquivo) {
        cout << "Erro ao abrir o arquivo." << endl;
        exit(0);
    }
    if (qtd_pessoas == tamanho) {
        cout << "Vetor cheio." << endl;
        exit(0);
    }

    //lendo o arquivo linha a linha
    string linha;
    string vetorLinha[2];
    while (!procuradorArquivo.eof()) {
        getline(procuradorArquivo, linha); //lendo a linha inteira
        //linha = "nome,email"
        split(vetorLinha, linha,",");
        //vetorLinha[0] = nome
        //vetorLinha[1] = email
        vetor[qtd_pessoas].nome = vetorLinha[0];
        vetor[qtd_pessoas].email = vetorLinha[1];
        qtd_pessoas++;
    }
    procuradorArquivo.close();
    return qtd_pessoas;
}

int contarVogais(string frase) {
    int totalVogais = 0;

    for (int i = 0; i < frase.size(); i++) {
        //cout << frase[i] << endl;
        if (frase[i] == 'A' || frase[i] == 'E' || frase[i] == 'I' || frase[i] == 'O' || frase[i] == 'U' || 
            frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == 'u'){
                totalVogais+=1; //totalVogais++;
        }
    }

    return totalVogais;
}

string trocarCaracter(string frase, char letra) {
    for (int i = 0; i < frase.size(); i++) {
        if (toupper(frase[i]) == toupper(letra)) {
            frase[i] = '@';
        }
    }
    return frase;
}

string trocarCaracterOrigemDestino(string frase, char letraOrigem, char letraDestino) {
    for (int i = 0; i < frase.size(); i++) {
        if (toupper(frase[i]) == toupper(letraOrigem)) {
            frase[i] = letraDestino;
        }
    }
    return frase;
}

int contarPalavras(string& frase) {
    istringstream stream(frase);
    string palavra;
    int contagem = 0;
    
    // Enquanto houver palavras na frase
    while (stream >> palavra) {
        cout << palavra << endl;
        contagem++;
    }
    
    return contagem;
}

string paraMaiusculo(string frase) {
    for (int i = 0; i < frase.size(); i++) {
        frase[i] = toupper(frase[i]);
    }
    return frase;
}

bool existeArquivo(string nomeArquivo) {
    ifstream procuradorArquivo; //tipo de arquivo para leitura
    procuradorArquivo.open(nomeArquivo); 
    
    if (procuradorArquivo) { //caso arquivo exista
        procuradorArquivo.close();
        return true;
    } 
    return false; //caso arquivo nao exista
}

string copiarArquivo2String(string nomeArquivo) {
    ifstream procuradorArquivo; //tipo de arquivo para leitura
    procuradorArquivo.open(nomeArquivo); 

    string resposta = "";
    string linha;
    while (!procuradorArquivo.eof()) {
		getline(procuradorArquivo,linha); //lendo a linha inteira
		resposta = resposta + linha + "\n";
	}
  
    procuradorArquivo.close();

    return resposta;
}