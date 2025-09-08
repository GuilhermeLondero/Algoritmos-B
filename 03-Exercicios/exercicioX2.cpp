#include <iostream>
#include <string>
#include <ctime>
#include <sstream>  // Para stringstream
#include <cstdlib>  // Para atoi
#define MAX_PACIENTES 100
#define MAX_UNIDADES 20
#define MAX_PROFISSIONAIS 50
using namespace std;

// Struct para dados do paciente
struct Paciente {
    string nome;
    char sexo;              
    string dataNascimento;  
    float altura;           
    float peso;             
    string dataTriagem;     
    int pontuacaoTotal;     
    string urgencia;        
};

// Struct para sintomas e pontuações
struct Sintoma {
    string nome;
    bool presente;
    int pontuacao;
};

// Struct para unidade de atendimento
struct Unidade {
    string nome;
    string endereco;
    string telefone;
    int capacidade;
};

// Struct para profissional
struct Profissional {
    string nome;
    string especialidade;
    string registro;    
    string unidade;     
};

// FUNÇÃO PARA CONVERTER INT PARA STRING (substitui to_string)
string intParaString(int numero) {
    stringstream ss;
    ss << numero;
    return ss.str();
}

// FUNÇÃO PARA CONVERTER STRING PARA INT (substitui stoi)
int stringParaInt(string texto) {
    return atoi(texto.c_str());
}

#define NUM_SINTOMAS 12

// Configuração dos sintomas (MÉTODO COMPATÍVEL COM C++98)
void configurarSintomas(Sintoma sintomas[]) {
    // Sintoma 0
    sintomas[0].nome = "Febre alta (>38°C)";
    sintomas[0].presente = false;
    sintomas[0].pontuacao = 3;
    
    // Sintoma 1
    sintomas[1].nome = "Febre baixa (37-38°C)";
    sintomas[1].presente = false;
    sintomas[1].pontuacao = 2;
    
    // Sintoma 2
    sintomas[2].nome = "Tosse seca";
    sintomas[2].presente = false;
    sintomas[2].pontuacao = 2;
    
    // Sintoma 3
    sintomas[3].nome = "Tosse com catarro";
    sintomas[3].presente = false;
    sintomas[3].pontuacao = 1;
    
    // Sintoma 4
    sintomas[4].nome = "Dificuldade para respirar";
    sintomas[4].presente = false;
    sintomas[4].pontuacao = 4;
    
    // Sintoma 5
    sintomas[5].nome = "Dores musculares";
    sintomas[5].presente = false;
    sintomas[5].pontuacao = 1;
    
    // Sintoma 6
    sintomas[6].nome = "Dor de cabeça";
    sintomas[6].presente = false;
    sintomas[6].pontuacao = 1;
    
    // Sintoma 7
    sintomas[7].nome = "Coriza";
    sintomas[7].presente = false;
    sintomas[7].pontuacao = 1;
    
    // Sintoma 8
    sintomas[8].nome = "Dor de garganta";
    sintomas[8].presente = false;
    sintomas[8].pontuacao = 1;
    
    // Sintoma 9
    sintomas[9].nome = "Vômito";
    sintomas[9].presente = false;
    sintomas[9].pontuacao = 2;
    
    // Sintoma 10
    sintomas[10].nome = "Diarréia";
    sintomas[10].presente = false;
    sintomas[10].pontuacao = 1;
    
    // Sintoma 11
    sintomas[11].nome = "Perda de olfato/paladar";
    sintomas[11].presente = false;
    sintomas[11].pontuacao = 3;
}

// Obter data atual (CORRIGIDO PARA C++98)
string obterDataAtual() {
    time_t agora = time(0);  // Mudança: 0 ao invés de nullptr
    tm* agora_local = localtime(&agora);
    
    string dia = intParaString(agora_local->tm_mday);    // Mudança: função customizada
    string mes = intParaString(agora_local->tm_mon + 1); // Mudança: função customizada
    string ano = intParaString(agora_local->tm_year + 1900); // Mudança: função customizada
    
    return dia + "/" + mes + "/" + ano;
}

// Determinar urgência baseada na pontuação
string determinarUrgencia(int pontuacao) {
    if (pontuacao >= 8) return "ALTA";
    else if (pontuacao >= 4) return "MEDIA";
    else return "BAIXA";
}

// Validar formato de data (CORRIGIDO PARA C++98)
bool validarData(string data) {
    if (data.size() != 10 || data[2] != '/' || data[5] != '/') {
        return false;
    }
    
    string diaStr = data.substr(0, 2);
    string mesStr = data.substr(3, 2);
    string anoStr = data.substr(6, 4);
    
    int dia = stringParaInt(diaStr);  // Mudança: função customizada
    int mes = stringParaInt(mesStr);  // Mudança: função customizada
    int ano = stringParaInt(anoStr);  // Mudança: função customizada
    
    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 1900 || ano > 2025) {
        return false;
    }
    
    return true;
}

// Cadastrar paciente
void cadastrarPaciente(Paciente pacientes[], int& qtdPacientes) {
    if (qtdPacientes >= MAX_PACIENTES) {
        cout << "Limite de pacientes atingido!" << endl;
        return;
    }
    
    Paciente novoPaciente;
    
    cout << "=== CADASTRO DE PACIENTE ===" << endl;
    
    cout << "Nome completo: ";
    getline(cin, novoPaciente.nome);
    
    do {
        cout << "Sexo (M/F): ";
        cin >> novoPaciente.sexo;
        novoPaciente.sexo = toupper(novoPaciente.sexo);
    } while (novoPaciente.sexo != 'M' && novoPaciente.sexo != 'F');
    
    do {
        cout << "Data de nascimento (dd/mm/aaaa): ";
        cin >> novoPaciente.dataNascimento;
    } while (!validarData(novoPaciente.dataNascimento));
    
    do {
        cout << "Altura (em metros): ";
        cin >> novoPaciente.altura;
    } while (novoPaciente.altura <= 0 || novoPaciente.altura > 3.0);
    
    do {
        cout << "Peso (em kg): ";
        cin >> novoPaciente.peso;
    } while (novoPaciente.peso <= 0 || novoPaciente.peso > 500);
    
    // Inicializar campos de triagem
    novoPaciente.dataTriagem = "";
    novoPaciente.pontuacaoTotal = 0;
    novoPaciente.urgencia = "NAO_TRIADO";
    
    pacientes[qtdPacientes] = novoPaciente;
    qtdPacientes++;
    
    cout << "Paciente cadastrado com sucesso!" << endl;
}

// Realizar triagem de sintomas
void realizarTriagem(Paciente pacientes[], int qtdPacientes) {
    if (qtdPacientes == 0) {
        cout << "Nenhum paciente cadastrado!" << endl;
        return;
    }
    
    // Listar pacientes
    cout << "=== PACIENTES CADASTRADOS ===" << endl;
    for (int i = 0; i < qtdPacientes; i++) {
        cout << i+1 << " - " << pacientes[i].nome;
        if (pacientes[i].urgencia != "NAO_TRIADO") {
            cout << " (JA TRIADO - " << pacientes[i].urgencia << ")";
        }
        cout << endl;
    }
    
    int opcaoPaciente;
    cout << "Selecione o paciente (numero): ";
    cin >> opcaoPaciente;
    opcaoPaciente--; 
    
    if (opcaoPaciente < 0 || opcaoPaciente >= qtdPacientes) {
        cout << "Paciente invalido!" << endl;
        return;
    }
    
    // Configurar sintomas
    Sintoma sintomas[NUM_SINTOMAS];
    configurarSintomas(sintomas);
    
    cout << "=== TRIAGEM: " << pacientes[opcaoPaciente].nome << " ===" << endl;
    cout << "Para cada sintoma, responda S (sim) ou N (nao):" << endl;
    
    int pontuacaoTotal = 0;
    
    for (int i = 0; i < NUM_SINTOMAS; i++) {
        char resposta;
        do {
            cout << sintomas[i].nome << "? (S/N): ";
            cin >> resposta;
            resposta = toupper(resposta);
        } while (resposta != 'S' && resposta != 'N');
        
        if (resposta == 'S') {
            sintomas[i].presente = true;
            pontuacaoTotal += sintomas[i].pontuacao;
            cout << "  + " << sintomas[i].pontuacao << " pontos" << endl;
        }
    }
    
    // Atualizar dados do paciente
    pacientes[opcaoPaciente].pontuacaoTotal = pontuacaoTotal;
    pacientes[opcaoPaciente].dataTriagem = obterDataAtual();
    pacientes[opcaoPaciente].urgencia = determinarUrgencia(pontuacaoTotal);
    
    // Exibir resultado
    cout << "\n=== RESULTADO DA TRIAGEM ===" << endl;
    cout << "Paciente: " << pacientes[opcaoPaciente].nome << endl;
    cout << "Pontuacao total: " << pontuacaoTotal << " pontos" << endl;
    cout << "Urgencia: " << pacientes[opcaoPaciente].urgencia << endl;
    cout << "Data da triagem: " << pacientes[opcaoPaciente].dataTriagem << endl;
    
    if (pacientes[opcaoPaciente].urgencia == "ALTA") {
        cout << "\nATENCAO: Paciente necessita atendimento URGENTE!" << endl;
    } else if (pacientes[opcaoPaciente].urgencia == "MEDIA") {
        cout << "\nPaciente deve ser atendido em breve." << endl;
    } else {
        cout << "\nPaciente pode aguardar atendimento normal." << endl;
    }
}

// Listar pacientes
void listarPacientes(Paciente pacientes[], int qtdPacientes) {
    if (qtdPacientes == 0) {
        cout << "Nenhum paciente cadastrado!" << endl;
        return;
    }
    
    cout << "=== LISTA DE PACIENTES ===" << endl;
    for (int i = 0; i < qtdPacientes; i++) {
        cout << "\nPaciente " << (i+1) << ":" << endl;
        cout << "  Nome: " << pacientes[i].nome << endl;
        cout << "  Sexo: " << pacientes[i].sexo << endl;
        cout << "  Data nascimento: " << pacientes[i].dataNascimento << endl;
        cout << "  Altura: " << pacientes[i].altura << "m" << endl;
        cout << "  Peso: " << pacientes[i].peso << "kg" << endl;
        
        if (pacientes[i].urgencia != "NAO_TRIADO") {
            cout << "  Status: TRIADO" << endl;
            cout << "  Data triagem: " << pacientes[i].dataTriagem << endl;
            cout << "  Pontuacao: " << pacientes[i].pontuacaoTotal << endl;
            cout << "  Urgencia: " << pacientes[i].urgencia << endl;
        } else {
            cout << "  Status: AGUARDANDO TRIAGEM" << endl;
        }
        cout << "  -------------------------" << endl;
    }
}

int main() {
    Paciente pacientes[MAX_PACIENTES];
    int qtdPacientes = 0;
    int opcao;
    
    cout << "=== SISTEMA DE GERENCIAMENTO COVID-19 ===" << endl;
    
    do {
        cout << "\n========== MENU PRINCIPAL ==========" << endl;
        cout << "1 - Cadastrar paciente" << endl;
        cout << "2 - Realizar triagem de sintomas" << endl;
        cout << "3 - Listar todos os pacientes" << endl;
        cout << "4 - Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;
        fflush(stdin);
        
        switch (opcao) {
            case 1:
                cadastrarPaciente(pacientes, qtdPacientes);
                break;
                
            case 2:
                realizarTriagem(pacientes, qtdPacientes);
                break;
                
            case 3:
                listarPacientes(pacientes, qtdPacientes);
                break;
                
            case 4:
                cout << "Encerrando sistema..." << endl;
                break;
                
            default:
                cout << "Opcao invalida!" << endl;
                break;
        }
        
        if (opcao != 4) {
            cout << "\nPressione Enter para continuar...";
            cin.get();
        }
        
    } while (opcao != 4);
    
    cout << "Sistema encerrado com sucesso!" << endl;
    return 0;
}