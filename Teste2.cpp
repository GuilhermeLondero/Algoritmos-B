#include <iostream>
#define TAM 5

using namespace std;

int main(){
	cout << "Exemplo de vetor de numeros inteiros\n";
	int i, numero;
	int vetor[TAM];
	
	//rotina que o usuario digita TAM numeros inteiros.
	
	for(i = 0; i < TAM; i++){
		cout << "Digite um numero inteiro: ";
		cin >> numero;
		
		vetor[i] = numero;
	}
	
	//rotina que o programa exibe os numeros inteiros um depois do outro.
	
	cout << "Numeros: ";
	for(int i = 0; i < TAM; i++){
		cout << vetor[i] << "\t";
	}
	
	cout << "\n";
	
	return 1;
}