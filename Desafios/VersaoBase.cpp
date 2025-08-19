/*Título: Exercício 4 - Sistema de Controle de Glicemia:

Descrição: 
- Cadastro de dados glicêmicos (45-450);
- Cálculo de média;
- Cálculo de mediana usando Bubble Sort;
- Data e hora automáticas;*/

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <sstream>  // Para stringstream
 
#define TAM 10
 
using namespace std;

// Struct para dados de glicemia
struct Glicemia {
    int valorGlicemia;
    string data;
    string hora;
};

// Função para converter int para string (compatível com versões antigas)
string intParaString(int numero) {
    stringstream ss;
    ss << numero;
    return ss.str();
}

// Função para obter data atual
string obterDataAtual() {
    time_t agora = time(0);
    struct tm* agora_local = localtime(&agora);

    int dia = agora_local->tm_mday;
    int mes = agora_local->tm_mon + 1;
    int ano = agora_local->tm_year + 1900;
    
    string diaStr, mesStr, anoStr;
    
    if (dia < 10) {
        diaStr = "0" + intParaString(dia);
    } else {
        diaStr = intParaString(dia);
    }
    
    if (mes < 10) {
        mesStr = "0" + intParaString(mes);
    } else {
        mesStr = intParaString(mes);
    }
    
    anoStr = intParaString(ano);

    return diaStr + "/" + mesStr + "/" + anoStr;
}

// Função para obter hora atual
string obterHoraAtual() {
    time_t agora = time(0);
    struct tm* agora_local = localtime(&agora);

    int hora = agora_local->tm_hour;
    int minutos = agora_local->tm_min;
    
    string horaStr, minutosStr;
    
    if (hora < 10) {
        horaStr = "0" + intParaString(hora);
    } else {
        horaStr = intParaString(hora);
    }
    
    if (minutos < 10) {
        minutosStr = "0" + intParaString(minutos);
    } else {
        minutosStr = intParaString(minutos);
    }

    return horaStr + ":" + minutosStr;
}

// Função para limpar buffer de entrada
void limparBuffer() {
    cin.clear();
    cin.ignore(1000, '\n');
}
 
int main() {
    cout << "Sistema de Controle de Glicemia" << endl;
    Glicemia registros[TAM];
    int quantidadeInseridos = 0;
    int opcao;
    int valorGlicemia;
    
    do {
        cout << "\n=============== MENU ===============" << endl;
        cout << "1 - Cadastrar dados glicemicos (45 a 450)" << endl;
        cout << "2 - Mostrar dados glicemicos" << endl;
        cout << "3 - Calcular e exibir media" << endl;
        cout << "4 - Calcular e exibir mediana" << endl;
        cout << "5 - Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;
        limparBuffer();
 
        switch (opcao) {
        case 1:
            cout << "\nCadastrar dados glicemicos..." << endl;
            if (quantidadeInseridos >= TAM) {
                cout << "Vetor lotado! Maximo " << TAM << " registros." << endl;
            } else {
                // Validação do valor de glicemia
                do {
                    cout << "Valor da glicemia (45-450): ";
                    cin >> valorGlicemia;
                    
                    if (valorGlicemia < 45 || valorGlicemia > 450) {
                        cout << "ERRO: Valor deve estar entre 45 e 450!" << endl;
                    }
                } while (valorGlicemia < 45 || valorGlicemia > 450);
                
                // Armazena os dados
                registros[quantidadeInseridos].valorGlicemia = valorGlicemia;
                registros[quantidadeInseridos].data = obterDataAtual();
                registros[quantidadeInseridos].hora = obterHoraAtual();
                
                quantidadeInseridos++;
                cout << "Registro cadastrado com sucesso!" << endl;
                cout << "Data/Hora: " << registros[quantidadeInseridos-1].data 
                     << " - " << registros[quantidadeInseridos-1].hora << endl;
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
                
                // Interpretação
                cout << "Interpretacao: ";
                if (media < 70) {
                    cout << "BAIXA (Hipoglicemia)" << endl;
                } else if (media <= 99) {
                    cout << "NORMAL" << endl;
                } else if (media <= 125) {
                    cout << "ALTERADA" << endl;
                } else {
                    cout << "ALTA (Hiperglicemia)" << endl;
                }
            }
            break;
            
        case 4:
            cout << "\nCalcular e exibir mediana..." << endl;
            if (quantidadeInseridos == 0) {
                cout << "Nenhum registro para calcular mediana." << endl;
            } else {
                // Criar vetor auxiliar para ordenar
                int valores[TAM];
                for (int i = 0; i < quantidadeInseridos; i++) {
                    valores[i] = registros[i].valorGlicemia;
                }
                
                cout << "Valores originais: ";
                for (int i = 0; i < quantidadeInseridos; i++) {
                    cout << valores[i] << " ";
                }
                cout << endl;
                
                // Bubble Sort
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
                
                // Calcular mediana
                double mediana;
                if (quantidadeInseridos % 2 == 1) {
                    // Quantidade ímpar
                    int meio = quantidadeInseridos / 2;
                    mediana = valores[meio];
                    cout << "Quantidade impar (" << quantidadeInseridos << "), posicao central: " << (meio + 1) << endl;
                    cout << "Mediana = " << valores[meio] << endl;
                } else {
                    // Quantidade par
                    int meio1 = quantidadeInseridos / 2 - 1;
                    int meio2 = quantidadeInseridos / 2;
                    mediana = (double)(valores[meio1] + valores[meio2]) / 2.0;
                    cout << "Quantidade par (" << quantidadeInseridos << "), posicoes centrais: " << (meio1 + 1) << " e " << (meio2 + 1) << endl;
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
