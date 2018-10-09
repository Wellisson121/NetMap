#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conexao.h"
#include "roteador.h"
#include "terminal.h"
#include "learquivo.h"


int main(int argc, char const **argv){
    if(argc == 2){
        if(abreArquivoExec(argv[1]) == 1){/*verifica se o arquivo teste existe*/
            char comando[100], var1[20], var2[20];
            int num;
            /*carrega as listas que serao usadas no programa*/
            List* roteador = carregaLista();
            tlista* terminal = carregaLista();
            Lista3* enlace = criaLista();

            FILE* fp = fopen(argv[1],"r");/*abre o arquivo de entrada*/
            do{
                fscanf(fp,"%s",comando);
                if(strcmp(comando,"CADASTRAROTEADOR" == 0)){
                    fscanf(fp,"%s %s",var1,var2);
                    CadastraRoteador(var1,var2);
                }else if (strcmp(comando,"CADASTRATERMINAL") == 0) {
                    fscanf(fp,"%s %s",var1,var2);
                    CadastraTerminal(var1,var2);
                }else if (strcmp(comando,"REMOVEROTEADOR") == 0) {

                }else if (strcmp(comando,"REMOVETERMINAL") == 0) {

                }else if (strcmp(comando,"CONECTAROTEADORES") == 0) {
                    fscanf(fp,"%s %s",var1,var2);
                    Router* r1 = buscaRoteador(roteador,var1);
                    Router* r2 = buscaRoteador(roteador, var2);
                    if((r1 != NULL) && (r2 != NULL)){
                        if((existe(enlace,r1->nome) == 0) && (existe(enlace,r2->nome) == 0)){
                            iniciaConexaoRoteadores(r1,r2,enlace);
                            iniciaConexaoRoteadores(r2,r1,enlace);
                        }else if((existe(enlace,r1->nome) != 0) && (existe(enlace,r2->nome) == 0)){
                            iniciaConexaoRoteadores(r2,r1,enlace);
                            ConectaRoteador(r1,enlace->equipamento->roteador);
                        }else if((existe(enlace,r1->nome) == 0) && (existe(enlace,r2->nome) != 0)){
                           iniciaConexaoRoteadores(r1,r2,enlace);
                           ConectaRoteador(r2,enlace->equipamento->roteador);
                        }
                    }else if(r1 == NULL){
                        abreArquivoLog(var1,1);
                    }else if(r2 == NULL){
                        abreArquivoLog(var2,1);
                    }

                }else if (strcmp(comando,"CONECTATERMINAL") == 0) {
                    fscanf(fp,"%s %s",var1,var2);
                    Terminal* t1 = buscaTerminal(terminal,var1);
                    Router* r2 = buscaRoteador(roteador, var2);
                    if((t1 != NULL) && (r2 != NULL)){
                        if((existe(enlace,t1->nome) == 0) && (existe(enlace,r2->nome) == 0)){
                            iniciaConexaoTerminal(enlace,enlace->equipamento->rot->nome,enlace->equipamento->terminal,t1);
                        }
                    }else if(t1 == NULL){
                        abreArquivoLog(var1,1);
                    }else if(r2 == NULL){
                        abreArquivoLog(var2,1);
                    }
                }else if (strcmp(comando,"IMPRIMENETMAP") == 0) {

                }else if (strcmp(comando,"DESCONECTAROTEADORES") == 0) {
                    fscanf(fp,"%s %s",var1,var2);
                    Router* r1 = buscaRoteador(roteador,var1);
                    Router* r2 = buscaRoteador(roteador, var2);
                    if((r1 != NULL) && (r2 != NULL)){
                        if((existe(enlace,r1->nome) == 1) && (existe(enlace,r2->nome) == 1)){
                            removeConexaoRoteadores(enlace,enlace->eqipamento->roteador,r1->nome);
                            removeConexaoRoteadores(enlace,enlace->eqipamento->roteador,r2->nome);
                        }
                    }
                }else if (strcmp(comando,"DESCONECTATERMINAL") == 0) {

                }else if (strcmp(comando,"FREQUENCIAOPERADORA") == 0) {
                    num = FrequenciaOperadora(roteador,roteador->rot->operadora);
                    abreArquivoSaida(comando,roteador->rot->operadora,num);
                }else if (strcmp(comando,"FREQUENCIATERMINAL") == 0) {
                    num = FrequenciaTerminal(terminal,terminal->ter->local);
                    abreArquivoSaida(comando,terminal->ter->local,num);
                }else if (strcmp(comando,"ENVIARPACOTESDADOS")== 0) {

                }
            }while (strcmp(comando,"FIM")!=0);
            fclose(fp);/*fecha o arquivo de entrada de dados*/

            /*Libera a memoria alocada*/
            EncerraLista(roteador);
            EncerraListaTerminais(terminal);
            EncerraListaConexoes(enlace);

     }
    return 0;
   }
}
