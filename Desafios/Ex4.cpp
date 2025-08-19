//4) Tendo como base o menu criado para os códigos anteriores, faça um programa que receba dados de glicemia de um paciente diabetico; calcule e exiba a média da glicemia; calcule e exiba e mediana da glicemia; exiba todos os valores cadastrados

#include <iostream>
#include <string>

#define TAM 4

using namespace std;

typedef struct {
    int valorGlicemia;
    string data;
    string hora;
} Glicemia;

int main() {
    cout << "=== Sistema de Controle de Glicemia ===" << endl;
    Glicemia vetorRegistros[TAM];
    int totalCadastrados = 0;
    int escolha;
    int valorGlicemia;
    string data, hora;
    
    do {
        cout << "\n--- MENU PRINCIPAL ---" << endl;
        cout << "1 - Cadastrar dados glicemicos (45 a 450)" << endl;
        cout << "2 - Mostrar dados glicemicos" << endl;
        cout << "3 - Calcular e exibir media" << endl;
        cout << "4 - Calcular e exibir mediana" << endl;
        cout << "5 - Finalizar" << endl;
        cout << "Digite sua opcao: ";
        cin >> escolha;
        fflush(stdin);

        switch (escolha)
        {
        case 1:
            cout << "\nCadastrar dados glicemicos no sistema..." << endl;
            if (totalCadastrados == TAM) {
                cout << "Sistema cheio! Limite de registros atingido." << endl;
            } else {
                for (int i = 0; i < TAM; i++) {
                    do {
                        cout << "Valor da glicemia (45-450): ";
                        cin >> valorGlicemia;
                        fflush(stdin);
                        if (valorGlicemia < 45 || valorGlicemia > 450) {
                            cout << "ERRO: Valor deve estar entre 45 e 450!" << endl;
                        }
                    } while (valorGlicemia < 45 || valorGlicemia > 450);
                    
                    cout << "Data (dd/mm/aaaa): ";
                    getline(cin, data);
                    fflush(stdin);
                    
                    cout << "Hora (hh:mm): ";
                    getline(cin, hora);
                    fflush(stdin);

                    vetorRegistros[totalCadastrados].valorGlicemia = valorGlicemia;
                    vetorRegistros[totalCadastrados].data = data;
                    vetorRegistros[totalCadastrados].hora = hora;
                    totalCadastrados++;
                    cout << "Registro inserido com sucesso!" << endl;
                }
            }
            break;
            
        case 2:
            cout << "\nExibir dados glicemicos cadastrados..." << endl;
            if (totalCadastrados == 0) {
                cout << "Nenhum registro foi cadastrado ainda." << endl;
            } else {
                cout << "Lista de registros glicemicos:" << endl;
                for (int i = 0; i < totalCadastrados; i++) {
                    cout << (i+1) << "- " << vetorRegistros[i].valorGlicemia 
                         << " mg/dL (" << vetorRegistros[i].data << " - " << vetorRegistros[i].hora << ")" << endl;
                }
                cout << "===================" << endl;
                cout << "Quantidade total: " << totalCadastrados << endl;
            }
            break;
            
        case 3:
            cout << "\nCalcular e exibir media glicemica..." << endl;
            if (totalCadastrados == 0) {
                cout << "Sistema vazio... nao eh possivel calcular media." << endl;
            } else {
                int soma = 0;
                cout << "Valores utilizados: ";
                for (int i = 0; i < totalCadastrados; i++) {
                    soma += vetorRegistros[i].valorGlicemia;
                    cout << vetorRegistros[i].valorGlicemia;
                    if (i < totalCadastrados - 1) cout << " + ";
                }
                
                double media = (double)soma / totalCadastrados;
                
                cout << " = " << soma << endl;
                cout << "Quantidade de registros: " << totalCadastrados << endl;
                cout << "Media glicemica: " << media << " mg/dL" << endl;
                
                cout << "Interpretacao: ";
                if (media < 70) {
                    cout << "BAIXA" << endl;
                } else if (media <= 99) {
                    cout << "NORMAL" << endl;
                } else if (media <= 125) {
                    cout << "ALTERADA" << endl;
                } else {
                    cout << "ALTA" << endl;
                }
                cout << "===================" << endl;
            }
            break;
            
        case 4:
            cout << "\nCalcular e exibir mediana glicemica..." << endl;
            if (totalCadastrados == 0) {
                cout << "Sistema vazio... nao eh possivel calcular mediana." << endl;
            } else {
                int valores[TAM];
                for (int i = 0; i < totalCadastrados; i++) {
                    valores[i] = vetorRegistros[i].valorGlicemia;
                }
                
                cout << "Valores originais: ";
                for (int i = 0; i < totalCadastrados; i++) {
                    cout << valores[i] << " ";
                }
                cout << endl;
                
                for (int i = 0; i < totalCadastrados - 1; i++) {
                    for (int j = 0; j < totalCadastrados - i - 1; j++) {
                        if (valores[j] > valores[j + 1]) {
                            int temp = valores[j];
                            valores[j] = valores[j + 1];
                            valores[j + 1] = temp;
                        }
                    }
                }
                
                cout << "Valores ordenados: ";
                for (int i = 0; i < totalCadastrados; i++) {
                    cout << valores[i] << " ";
                }
                cout << endl;
                
                double mediana;
                if (totalCadastrados % 2 == 1) {
                    int meio = totalCadastrados / 2;
                    mediana = valores[meio];
                    cout << "Quantidade impar, posicao do meio: " << (meio + 1) << endl;
                    cout << "Mediana = " << valores[meio] << endl;
                } else {
                    int meio1 = totalCadastrados / 2 - 1;
                    int meio2 = totalCadastrados / 2;
                    mediana = (double)(valores[meio1] + valores[meio2]) / 2.0;
                    cout << "Quantidade par, posicoes do meio: " << (meio1 + 1) << " e " << (meio2 + 1) << endl;
                    cout << "Mediana = (" << valores[meio1] << " + " << valores[meio2] << ") / 2 = " << mediana << endl;
                }
                
                cout << "Mediana glicemica: " << mediana << " mg/dL" << endl;
                cout << "===================" << endl;
            }
            break;
            
        case 5:
            cout << "\nEncerrando o programa..." << endl;
            break;
            
        default:
            cout << "Opcao nao reconhecida. Tente novamente." << endl;
            break;
        }
    } while (escolha != 5);
    
    return 0;
}
