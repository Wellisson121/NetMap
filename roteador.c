#include "roteador.h"
#include "terminal.h"
#include "conexao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 255

struct roteador{
  char* nome;
  char* operadora;
  Terminal *ter[MAX];/*prox*/
  long int qtdTerminais;
};

struct cel{
    Router* rot;
    Sentry* prox;
    Sentry* ant;
};

/*inicializa um tipo roteador e o insere na primeira posicao da lista*/
Sentry* CadastraRoteador(Sentry* s,char* roteador, char* operadora){
    s = (Sentry*)malloc(sizeof(Sentry));
    s->rot = (Router*)malloc(sizeof(Router));//? --> nao entendi isso
    s->rot->nome = (char*)malloc((strlen(roteador)+1) * sizeof(char));
    s->rot->operadora = (char*)malloc((strlen(operadora)+1) * sizeof(char));
    strcpy(s->rot->nome,roteador);
    strcpy(s->rot->operadora,operadora);
    s->rot->qtdTerminais = 0;
    s->ant = NULL;
    s->prox = s;
    return s;
}

void ConectaRoteadores(Sentry* r, Sentry* s){
    if(r != NULL && s != NULL){
        r->prox = s->ant;
        s->ant = r->prox;
    }
}

//na remocao ta dando erro
void RemoveRoteador(Sentry* r){
    long int i;
    free(r->rot->nome);
    free(r->rot->operadora);
    for(i = r->rot->qtdTerminais;i > 0;i--)
       free(r->rot->ter[i]);
    free(r->rot);
    free(r);
}

int FrequenciaOperadora(Sentry* r, char* operadora){
    if(r != NULL){
        int cont = 0;
        Sentry *op;
        op = r;
        while (op->prox != NULL) {
            if(strcmp(r->rot->operadora,operadora) == 0){
                cont++;
            }
            op = op->prox;
        }
        return cont;
    }else return -1;
}

void EncerraLista(Sentry* t){
    if(t != NULL){
        Sentry* new = NULL;
        while (t!=NULL) {
            new = t;
            t=t->prox;
            RemoveRoteador(new);
        }
        free(new);
    }
}
