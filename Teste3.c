#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5

int main(){
	printf("Exemplo de vetor de placas que sao strings\n");
	char placa[7];
	char vetor[TAM][7];
	
	for(int i = 0; i < TAM; i++){
		printf("Digite uma placa: ");
		scanf("%s", placa);
		
		strcpy(vetor[i], placa);
	}
	
	printf("Placas: \n");
	for(int i = 0; i < TAM; i++){
		printf("%s\n", vetor[i]);
	}
	printf("\n");
    
	return 1;
}