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
                fscanf(fp,"%s ",comando);
                if(strcmp(comando,"CADASTRAROTEADOR") == 0){
                    fscanf(fp,"%s %s",var1,var2);
                    ConectaRoteador(CadastraRoteador(var1,var2),roteador);
                }else if (strcmp(comando,"CADASTRATERMINAL") == 0) {
                    fscanf(fp,"%s %s",var1,var2);
                    conectaTerminal(terminal,CadastraTerminal(var1,var2));
                }else if (strcmp(comando,"REMOVEROTEADOR") == 0) {
                    fscanf(fp,"%s",var1);
                    RemoveRoteador(roteador,var1);
                }else if (strcmp(comando,"REMOVETERMINAL") == 0) {
                    fscanf(fp,"%s",var1);
                    RemoveTerminal(terminal,var1);
                }else if (strcmp(comando,"CONECTAROTEADORES") == 0) {
                    fscanf(fp,"%s %s",var1,var2);
                    Router* r1 = buscaRoteador(roteador,var1);
                    Router* r2 = buscaRoteador(roteador,var2);
                    if((r1 != NULL) && (r2 != NULL)){
                        if((existe(enlace,nomeRoteador(r1)) == 0) && (existe(enlace,nomeRoteador(r2)) == 0)){
                            iniciaConexaoRoteadores(r1,r2,enlace);
                            iniciaConexaoRoteadores(r2,r1,enlace);
                        }else if((existe(enlace,nomeRoteador(r1)) != 0) && (existe(enlace,nomeRoteador(r2)) == 0)){
                            iniciaConexaoRoteadores(r2,r1,enlace);
                            ConectaRoteador(r1,capturaListaRoteador(enlace,roteador));
                        }else if((existe(enlace,nomeRoteador(r1)) == 0) && (existe(enlace,nomeRoteador(r2)) != 0)){
                            iniciaConexaoRoteadores(r1,r2,enlace);
                            ConectaRoteador(r2,capturaListaRoteador(enlace,roteador));
                        }
                    }else if(r1 == NULL){
                        abreArquivoLog(var1,1);
                    }else if(r2 == NULL){
                        abreArquivoLog(var2,1);
                    }

                }/*else if (strcmp(comando,"CONECTATERMINAL") == 0) {
                    fscanf(fp,"%s %s",var1,var2);
                    Terminal* t1 = buscaTerminal(terminal,var1);
                    Router* r2 = buscaRoteador(roteador, var2);
                    if((t1 != NULL) && (r2 != NULL)){
                        if((existe(enlace,nomeTerminal(t1)) == 0) && (existe(enlace,nomeRoteador(r2)) == 0)){
                            iniciaConexaoTerminal(enlace,capturaListaRoteador(enlace,roteador),capturaListaTerminal(enlace, var1),t1);
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
                        if((existe(enlace,nomeRoteador(r1)) == 1) && (existe(enlace,nomeRoteador(r2)) == 1)){
                            removeConexaoRoteadores(enlace,capturaListaRoteadorRemocao(enlace),nomeRoteador(r1));
                            removeConexaoRoteadores(enlace,capturaListaRoteadorRemocao(enlace),nomeRoteador(r2));
                        }
                    }
                }else if (strcmp(comando,"DESCONECTATERMINAL") == 0) {

                }else if (strcmp(comando,"FREQUENCIAOPERADORA") == 0) {
                    num = FrequenciaOperadora(roteador,getListFreq(roteador));
                    abreArquivoSaida(comando,getListFreq(roteador),num);
                }else if (strcmp(comando,"FREQUENCIATERMINAL") == 0) {
                    num = FrequenciaTerminal(terminal,getListFreqT(terminal));
                    abreArquivoSaida(comando,getListFreqT(terminal),num);
                }else if (strcmp(comando,"ENVIARPACOTESDADOS")== 0) {

                }*/
            }while (strcmp(comando,"FIM")!=0);
            fclose(fp);/*fecha o arquivo de entrada de dados*/
            fechaArquivoGraphViz();/*encerra as entradas pro graphviz*/
            /*Libera a memoria alocada*/
            EncerraLista(roteador);
            EncerraListaTerminais(terminal);
            //EncerraListaConexoes(enlace);

     }
   }
    return 0;
}
