#include <iostream>
#include <string>
#include <ctime>
#define MAX_PACIENTES 100
#define MAX_UNIDADES 20
#define MAX_PROFISSIONAIS 50
using namespace std;

// Struct para dados do paciente
struct Paciente {
    string nome;
    char sexo;              // 'M' ou 'F'
    string dataNascimento;  // dd/mm/aaaa
    float altura;           // em metros
    float peso;             // em kg
    string dataTriagem;     // data da triagem
    int pontuacaoTotal;     // pontuação dos sintomas
    string urgencia;        // "BAIXA", "MEDIA", "ALTA"
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
    string registro;    // CRM, CRE, etc.
    string unidade;     // unidade onde trabalha
};

// Sistema de Pontuação de Sintomas

// Configuração dos sintomas e suas pontuações
// (Pontuações exemplo - Referência a ser alterada)
void configurarSintomas(Sintoma sintomas[]) {
    sintomas[0] = {"Febre alta (>38°C)", false, 3};
    sintomas[1] = {"Febre baixa (37-38°C)", false, 2};
    sintomas[2] = {"Tosse seca", false, 2};
    sintomas[3] = {"Tosse com catarro", false, 1};
    sintomas[4] = {"Dificuldade para respirar", false, 4};
    sintomas[5] = {"Dores musculares", false, 1};
    sintomas[6] = {"Dor de cabeça", false, 1};
    sintomas[7] = {"Coriza", false, 1};
    sintomas[8] = {"Dor de garganta", false, 1};
    sintomas[9] = {"Vômito", false, 2};
    sintomas[10] = {"Diarréia", false, 1};
    sintomas[11] = {"Perda de olfato/paladar", false, 3};
}

#define NUM_SINTOMAS 12

// Métodos de Utilidade

// Obter data atual
string obterDataAtual() {
    time_t agora = time(nullptr);
    tm* agora_local = localtime(&agora);
    
    string dia = to_string(agora_local->tm_mday);
    string mes = to_string(agora_local->tm_mon + 1);
    string ano = to_string(agora_local->tm_year + 1900);
    
    return dia + "/" + mes + "/" + ano;
}

// Determinar urgência baseada na pontuação
string determinarUrgencia(int pontuacao) {
    if (pontuacao >= 8) return "ALTA";
    else if (pontuacao >= 4) return "MEDIA";
    else return "BAIXA";
}

// Validar formato de data
bool validarData(string data) {
    if (data.size() != 10 || data[2] != '/' || data[5] != '/') {
        return false;
    }
    
    int dia = stoi(data.substr(0, 2));
    int mes = stoi(data.substr(3, 2));
    int ano = stoi(data.substr(6, 4));
    
    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 1900 || ano > 2025) {
        return false;
    }
    
    return true;
}

// Métodos de Cadastro

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

// Cadastrar unidade
void cadastrarUnidade(Unidade unidades[], int& qtdUnidades) {
    if (qtdUnidades >= MAX_UNIDADES) {
        cout << "Limite de unidades atingido!" << endl;
        return;
    }
    
    Unidade novaUnidade;
    
    cout << "=== CADASTRO DE UNIDADE ===" << endl;
    
    cout << "Nome da unidade: ";
    getline(cin, novaUnidade.nome);
    
    cout << "Endereço: ";
    getline(cin, novaUnidade.endereco);
    
    cout << "Telefone: ";
    getline(cin, novaUnidade.telefone);
    
    cout << "Capacidade: ";
    cin >> novaUnidade.capacidade;
    
    unidades[qtdUnidades] = novaUnidade;
    qtdUnidades++;
    
    cout << "Unidade cadastrada com sucesso!" << endl;
}

// Cadastrar profissional
void cadastrarProfissional(Profissional profissionais[], int& qtdProfissionais) {
    if (qtdProfissionais >= MAX_PROFISSIONAIS) {
        cout << "Limite de profissionais atingido!" << endl;
        return;
    }
    
    Profissional novoProfissional;
    
    cout << "=== CADASTRO DE PROFISSIONAL ===" << endl;
    
    cout << "Nome completo: ";
    getline(cin, novoProfissional.nome);
    
    cout << "Especialidade: ";
    getline(cin, novoProfissional.especialidade);
    
    cout << "Número de registro (CRM, CRE, etc.): ";
    getline(cin, novoProfissional.registro);
    
    cout << "Unidade onde trabalha: ";
    getline(cin, novoProfissional.unidade);
    
    profissionais[qtdProfissionais] = novoProfissional;
    qtdProfissionais++;
    
    cout << "Profissional cadastrado com sucesso!" << endl;
}

// Sistema de Triagem

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
            cout << " (JÁ TRIADO - " << pacientes[i].urgencia << ")";
        }
        cout << endl;
    }
    
    int opcaoPaciente;
    cout << "Selecione o paciente (número): ";
    cin >> opcaoPaciente;
    opcaoPaciente--; // Ajustar para índice do array
    
    if (opcaoPaciente < 0 || opcaoPaciente >= qtdPacientes) {
        cout << "Paciente inválido!" << endl;
        return;
    }
    
    // Configurar sintomas
    Sintoma sintomas[NUM_SINTOMAS];
    configurarSintomas(sintomas);
    
    cout << "=== TRIAGEM: " << pacientes[opcaoPaciente].nome << " ===" << endl;
    cout << "Para cada sintoma, responda S (sim) ou N (não):" << endl;
    
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
    cout << "Pontuação total: " << pontuacaoTotal << " pontos" << endl;
    cout << "Urgência: " << pacientes[opcaoPaciente].urgencia << endl;
    cout << "Data da triagem: " << pacientes[opcaoPaciente].dataTriagem << endl;
    
    if (pacientes[opcaoPaciente].urgencia == "ALTA") {
        cout << "\n ATENÇÃO: Paciente necessita atendimento URGENTE!" << endl;
    } else if (pacientes[opcaoPaciente].urgencia == "MEDIA") {
        cout << "\n Paciente deve ser atendido em breve." << endl;
    } else {
        cout << "\n Paciente pode aguardar atendimento normal." << endl;
    }
}

// Métodos de Listagem

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
            cout << "  Pontuação: " << pacientes[i].pontuacaoTotal << endl;
            cout << "  Urgência: " << pacientes[i].urgencia << endl;
        } else {
            cout << "  Status: AGUARDANDO TRIAGEM" << endl;
        }
        cout << "  -------------------------" << endl;
    }
}

// Listar por urgência
void listarPorUrgencia(Paciente pacientes[], int qtdPacientes) {
    cout << "=== PACIENTES POR URGÊNCIA ===" << endl;
    
    // Urgência ALTA
    cout << "\n URGÊNCIA ALTA:" << endl;
    for (int i = 0; i < qtdPacientes; i++) {
        if (pacientes[i].urgencia == "ALTA") {
            cout << "  - " << pacientes[i].nome << " (Pontuação: " << pacientes[i].pontuacaoTotal << ")" << endl;
        }
    }
    
    // Urgência MÉDIA
    cout << "\n URGÊNCIA MÉDIA:" << endl;
    for (int i = 0; i < qtdPacientes; i++) {
        if (pacientes[i].urgencia == "MEDIA") {
            cout << "  - " << pacientes[i].nome << " (Pontuação: " << pacientes[i].pontuacaoTotal << ")" << endl;
        }
    }
    
    // Urgência BAIXA
    cout << "\n URGÊNCIA BAIXA:" << endl;
    for (int i = 0; i < qtdPacientes; i++) {
        if (pacientes[i].urgencia == "BAIXA") {
            cout << "  - " << pacientes[i].nome << " (Pontuação: " << pacientes[i].pontuacaoTotal << ")" << endl;
        }
    }
    
    // Não triados
    cout << "\n AGUARDANDO TRIAGEM:" << endl;
    for (int i = 0; i < qtdPacientes; i++) {
        if (pacientes[i].urgencia == "NAO_TRIADO") {
            cout << "  - " << pacientes[i].nome << endl;
        }
    }
}

// Programa Principal

int main() {
    // Arrays para armazenar dados
    Paciente pacientes[MAX_PACIENTES];
    Unidade unidades[MAX_UNIDADES];
    Profissional profissionais[MAX_PROFISSIONAIS];
    
    // Contadores
    int qtdPacientes = 0;
    int qtdUnidades = 0;
    int qtdProfissionais = 0;
    
    int opcao;
    
    cout << "=== SISTEMA DE GERENCIAMENTO COVID-19 ===" << endl;
    
    do {
        cout << "\n========== MENU PRINCIPAL ==========" << endl;
        cout << "1  - Cadastrar paciente" << endl;
        cout << "2  - Cadastrar unidade de atendimento" << endl;
        cout << "3  - Cadastrar profissional da saúde" << endl;
        cout << "4  - Realizar triagem de sintomas" << endl;
        cout << "5  - Listar todos os pacientes" << endl;
        cout << "6  - Listar pacientes por urgência" << endl;
        cout << "7  - Listar unidades" << endl;
        cout << "8  - Listar profissionais" << endl;
        cout << "9  - Relatório de estatísticas" << endl;
        cout << "10 - Sair" << endl;
        cout << "Opção: ";
        cin >> opcao;
        fflush(stdin);
        
        switch (opcao) {
            case 1:
                cadastrarPaciente(pacientes, qtdPacientes);
                break;
                
            case 2:
                cadastrarUnidade(unidades, qtdUnidades);
                break;
                
            case 3:
                cadastrarProfissional(profissionais, qtdProfissionais);
                break;
                
            case 4:
                realizarTriagem(pacientes, qtdPacientes);
                break;
                
            case 5:
                listarPacientes(pacientes, qtdPacientes);
                break;
                
            case 6:
                listarPorUrgencia(pacientes, qtdPacientes);
                break;
                
            case 7:
                // Implementar listagem de unidades
                cout << "Funcionalidade em desenvolvimento..." << endl;
                break;
                
            case 8:
                // Implementar listagem de profissionais
                cout << "Funcionalidade em desenvolvimento..." << endl;
                break;
                
            case 9:
                // Implementar relatório de estatísticas
                cout << "Funcionalidade em desenvolvimento..." << endl;
                break;
                
            case 10:
                cout << "Encerrando sistema..." << endl;
                break;
                
            default:
                cout << "Opção inválida!" << endl;
                break;
        }
        
        if (opcao != 10) {
            cout << "\nPressione Enter para continuar...";
            cin.get();
        }
        
    } while (opcao != 10);
    
    cout << "Sistema encerrado com sucesso!" << endl;
    return 0;
}

/* Fluxo de Execução do Sistema

### 1. **Inicialização**
- Declara arrays para pacientes, unidades e profissionais
- Inicializa contadores em 0
- Exibe menu principal

### 2. **Cadastros**
- **Pacientes**: coleta dados pessoais básicos
- **Unidades**: cadastra locais de atendimento
- **Profissionais**: registra equipe médica

### 3. **Triagem**
- Lista pacientes cadastrados
- Permite seleção de paciente
- Aplica questionário de sintomas
- Calcula pontuação total
- Determina urgência automaticamente
- Atualiza dados do paciente

### 4. **Relatórios**
- Lista todos os pacientes
- Lista por categoria de urgência
- Mostra status de triagem

### 5. **Validações**
- Verifica limites de arrays
- Valida formatos de data
- Valida ranges de valores (altura, peso)
- Confirma opções de menu