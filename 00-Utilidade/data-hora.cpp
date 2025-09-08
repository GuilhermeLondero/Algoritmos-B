// Função para obter data atual
string obterDataAtual() {
    time_t agora = time(nullptr);        // Pega tempo atual
    tm* agora_local = localtime(&agora); // Converte para horário local
    
    string dia = to_string(agora_local->tm_mday);      // Dia do mês
    string mes = to_string(agora_local->tm_mon + 1);   // Mês (0-11, por isso +1)
    string ano = to_string(agora_local->tm_year + 1900); // Ano (desde 1900)
    
    return dia + "/" + mes + "/" + ano;
}

{
    time_t agora = time(nullptr);
    tm* agora_local = localtime(&agora);

    string dia = to_string(agora_local->tm_mday);
    string mes = to_string(agora_local->tm_mon + 1);
    string ano = to_string(agora_local->tm_year + 1900);

    cout << "Data: " << dia << "/" << mes << "/" << ano << endl;

    string hora = to_string(agora_local->tm_hour);
    string minutos = to_string(agora_local->tm_min); 

    cout << "Hora: " << hora << ":" << minutos << endl;
    return 0;
}

// Função para obter hora atual
string obterHoraAtual() {
    time_t agora = time(nullptr);
    tm* agora_local = localtime(&agora);
    
    string hora = to_string(agora_local->tm_hour);
    string minutos = to_string(agora_local->tm_min);
    
    return hora + ":" + minutos;
}

{
    time_t agora = time(nullptr);
    tm* agora_local = localtime(&agora);

    string hora = to_string(agora_local->tm_hour);
    string minutos = to_string(agora_local->tm_min); 

    cout << "Hora: " << hora << ":" << minutos << endl;
    return 0;
}