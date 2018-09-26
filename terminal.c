#include "terminal.h"
#include "roteador.h"
#include "conexao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct terminal{
    char* nome;
    char* local;
    void* rot;
};

struct cell{
    Terminal* ter;
    sentinel* ant;
    sentinel* prox;
};

sentinel* CadastraTerminal(char* nome, char* local){
    sentinel* t;
    t = (sentinel*)malloc(sizeof (sentinel));
    t->ter->nome = (char*)malloc((strlen(nome)+1) * sizeof(char));
    t->ter->local = (char*)malloc((strlen(local)+1) * sizeof(char));
    strcpy(t->ter->nome,nome);
    strcpy(t->ter->local,local);
    t->ter->rot = NULL;
    t->ant = NULL;
    t->prox = t;
    return t;
}

void RemoveTerminal(sentinel *t){
    free(t->ter->local);
    free(t->ter->nome);
    free(t->ter);
    free(t);
}

int FrequenciaTerminal(sentinel* r, char* local){
    if(r != NULL){
        int cont = 0;
        sentinel *op;
        op = r;
        while (op->prox != NULL) {
            if(strcmp(r->ter->local,local) == 0){
                cont++;
            }
            op = op->prox;
        }
        return cont;
    }else return -1;
}
