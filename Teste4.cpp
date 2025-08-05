#include <iostream>
#include <string>
#define TAM 5

using namespace std;

int main(){
	cout << "Exemplo de vetor de placas que sao strings\n";
	string placa;
	string vetor[TAM];
	
	for(int i = 0; i < TAM; i++){
		cout << "Digite uma placa: ";
		cin >> placa;
		vetor[i] = placa;
	}
	
	cout << "Placas: \n";
	for(int i = 0; i < TAM; i++){
		cout << vetor[i] << "\t";
	}
	cout << "\n";
    
	return 1;
}