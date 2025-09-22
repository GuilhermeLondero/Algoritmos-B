#include <iostream>
#include <string>

int main(){
    //receber nome do arquivo
    string nomeArquivo;
    cout << "Digite caminho e nome do arquivo: ";
    cin >> nomeArquivo;

    //testar se o arquivo existe
    if (existeArquivo(nomeArquivo)){
        cout << "Arquivo localizado com sucesso\n";
    } else {
        cout << "Arquivo nao localizado\n";
        exit(0);
    }
}

//receber o conteudo do arquivo em uma string
string resposta = copiarArquivo2String(nomeArquivo);

//exibir o conteudo da string
cout << resposta << endl;

return 1;    
}


// Enquanto houver palavras na frase
while (stream >> palavra){
    cout << palavra << endl;
    contagem++;
}

return contagem;
}

string paraMaiusculo (string frase){
    for (int i = 0; i < frase.size(); i++){
        frase[i] = toupper(frase[i]);
    }
    return frase;
}

bool existeArquivo (string nomeArquivo){
    ifstream procuradorArquivo; // tipo de arquivo para leitura
    procuradorArquivo.open(nomeArquivo);

    if(procuradorArquivo){
        procuradorArquivo.close;
        return true;
    }
    return false;
}

string copiarArquivo2String (string nomeArquivo){
    ifstream procuradorArquivo; // tipo de arquivo para leitura
    procuradorArquivo.open(nomeArquivo);

    string resposta = "";
    string linha;
    while (!procuradorArquivo.eof()){
        getline(procuradorArquivo, linha);
        resposta = resposta + linha + "\n";
    }
    procuradorArquivo.close();
    return resposta;
}