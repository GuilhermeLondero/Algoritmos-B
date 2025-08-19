#include <iostream>
#include <string>
#include <iomanip>
 
#define TAM 10
 
using namespace std;

struct Glicemia {
    int valorGlicemia;
    string data;
    string hora;
};
 
int main() {
    cout << "Sistema de Controle de Glicemia" << endl;
    Glicemia registros[TAM];
    int quantidadeInseridos = 0;
    int opcao;
    int valorGlicemia;
    string data, hora;
    
    do {
        cout << "\n=============== MENU ===============" << endl;
        cout << "1 - Cadastrar dados glicemicos (45 a 450)" << endl;
        cout << "2 - Mostrar dados glicemicos" << endl;
        cout << "3 - Calcular e exibir media" << endl;
        cout << "4 - Calcular e exibir mediana" << endl;
        cout << "5 - Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;
        cin.ignore();
 
        switch (opcao) {
        case 1:
            cout << "\nCadastrar dados glicemicos..." << endl;
            if (quantidadeInseridos >= TAM) {
                cout << "Vetor lotado! Maximo " << TAM << " registros." << endl;
            } else {
                do {
                    cout << "Valor da glicemia (45-450): ";
                    cin >> valorGlicemia;
                    
                    if (valorGlicemia < 45 || valorGlicemia > 450) {
                        cout << "ERRO: Valor deve estar entre 45 e 450!" << endl;
                    }
                } while (valorGlicemia < 45 || valorGlicemia > 450);
                
                cin.ignore();
                
                cout << "Data (dd/mm/aaaa): ";
                getline(cin, data);
                
                cout << "Hora (hh:mm): ";
                getline(cin, hora);
                
                registros[quantidadeInseridos].valorGlicemia = valorGlicemia;
                registros[quantidadeInseridos].data = data;
                registros[quantidadeInseridos].hora = hora;
                
                quantidadeInseridos++;
                cout << "Registro cadastrado com sucesso!" << endl;
            }
            break;
            
        case 2:
            cout << "\nMostrar dados glicemicos..." << endl;
            if (quantidadeInseridos == 0) {
                cout << "Nenhum registro cadastrado." << endl;
            } else {
                cout << "========================================" << endl;
                cout << "| # | Valor |    Data    |  Hora  |" << endl;
                cout << "========================================" << endl;
                for (int i = 0; i < quantidadeInseridos; i++) {
                    cout << "|";
                    if (i+1 < 10) cout << " ";
                    cout << (i+1) << " | ";
                    
                    if (registros[i].valorGlicemia < 100) cout << " ";
                    cout << registros[i].valorGlicemia << "  | ";
                    
                    cout << registros[i].data << " | ";
                    cout << registros[i].hora << " |" << endl;
                }
                cout << "========================================" << endl;
                cout << "Total de registros: " << quantidadeInseridos << endl;
            }
            break;
            
        case 3:
            cout << "\nCalcular e exibir media..." << endl;
            if (quantidadeInseridos == 0) {
                cout << "Nenhum registro para calcular media." << endl;
            } else {
                int soma = 0;
                cout << "Valores utilizados: ";
                for (int i = 0; i < quantidadeInseridos; i++) {
                    soma += registros[i].valorGlicemia;
                    cout << registros[i].valorGlicemia;
                    if (i < quantidadeInseridos - 1) cout << " + ";
                }
                
                double media = (double)soma / quantidadeInseridos;
                
                cout << " = " << soma << endl;
                cout << "Quantidade de registros: " << quantidadeInseridos << endl;
                cout << "Media glicemica: " << fixed << setprecision(2) << media << " mg/dL" << endl;
                
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
            }
            break;
            
        case 4:
            cout << "\nCalcular e exibir mediana..." << endl;
            if (quantidadeInseridos == 0) {
                cout << "Nenhum registro para calcular mediana." << endl;
            } else {
                int valores[TAM];
                for (int i = 0; i < quantidadeInseridos; i++) {
                    valores[i] = registros[i].valorGlicemia;
                }
                
                cout << "Valores originais: ";
                for (int i = 0; i < quantidadeInseridos; i++) {
                    cout << valores[i] << " ";
                }
                cout << endl;
                
                for (int i = 0; i < quantidadeInseridos - 1; i++) {
                    for (int j = 0; j < quantidadeInseridos - i - 1; j++) {
                        if (valores[j] > valores[j + 1]) {
                            int temp = valores[j];
                            valores[j] = valores[j + 1];
                            valores[j + 1] = temp;
                        }
                    }
                }
                
                cout << "Valores ordenados: ";
                for (int i = 0; i < quantidadeInseridos; i++) {
                    cout << valores[i] << " ";
                }
                cout << endl;
                
                double mediana;
                if (quantidadeInseridos % 2 == 1) {
                    int meio = quantidadeInseridos / 2;
                    mediana = valores[meio];
                    cout << "Quantidade impar, posicao do meio: " << (meio + 1) << endl;
                    cout << "Mediana = " << valores[meio] << endl;
                } else {
                    int meio1 = quantidadeInseridos / 2 - 1;
                    int meio2 = quantidadeInseridos / 2;
                    mediana = (double)(valores[meio1] + valores[meio2]) / 2.0;
                    cout << "Quantidade par, posicoes do meio: " << (meio1 + 1) << " e " << (meio2 + 1) << endl;
                    cout << "Mediana = (" << valores[meio1] << " + " << valores[meio2] << ") / 2 = " << mediana << endl;
                }
                
                cout << "Mediana glicemica: " << fixed << setprecision(2) << mediana << " mg/dL" << endl;
            }
            break;
            
        case 5:
            cout << "\nSaindo do programa..." << endl;
            break;
            
        default:
            cout << "Opcao invalida! Tente novamente." << endl;
            break;
        }
        
        if (opcao != 5) {
            cout << "\nPressione Enter para continuar...";
            cin.get();
        }
        
    } while (opcao != 5);
    
    return 0;
}
