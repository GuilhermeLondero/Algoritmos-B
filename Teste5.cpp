#include <iostream>
#include <string>
#define TAM 5

using namespace std;

int main(){
	cout << "Exemplo de vetor de nomes de alunos\n";
	string nome;
	string vetorAlunos[TAM];
	
	for(int i = 0; i < TAM; i++){
		cout << "Digite um nome: ";
		getline(cin,nome);
		vetorAlunos[i] = nome;
	}
	
	cout << "Nomes: \n";
	for(int i = 0; i < TAM; i++){
		cout << vetorAlunos[i] << "\t";
	}
	cout << "\n";
    
	return 1;
}