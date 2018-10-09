#include "learquivo.h"
#include <stdio.h>

#define LEITURA 0
#define ROUTER 1
#define TERMINAL 2

void abreArquivoLog(char const* nome, int id){
    FILE *fp;
    fp = fopen("log.txt","a");
    switch (id) {
        case LEITURA:
            fprintf(fp,"%s ","Erro: I/O, nao foi possivel abrir o arquivo %s",nome);
            break;
        case ROUTER:
            fprintf(fp,"%s","Erro: Roteador %s inexistente no NetMap",nome);
            break;
        case TERMINAL:
           fprintf(fp,"%s","Erro: Terminal %s inexistente no NetMap",nome);
           break;
    }
    fclose(fp);
}

int abreArquivoExec(const char *nome){
    FILE *fp;
    fp = fopen(nome,"r");
    if(!fp){
        abreArquivoLog(nome,0);
        return 0;
    }
    fclose(fp);
    return 1;
}

void abreArquivoSaida(char* comando,char* nome,int num){
    FILE *fp;
    fp = fopen("saida.txt","a");
    fprintf(fp,"%s %s: %d",comando,nome,num);
    fclose(fp);

}
