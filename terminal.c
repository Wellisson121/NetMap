#include "terminal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct terminal{
    char* nome;
    char* local;

};

struct cell{
    Terminal* ter;
    sentinel* prox;
};

struct lista{
    sentinel* primeiro;
    sentinel* ultimo;

};
/*
typedef struct terminal Terminal;
typedef struct cell sentinel;
*/

tlista* carregaListaTerminal(void){
    tlista* l;
    l = (tlista*)malloc(sizeof (tlista));
    l->primeiro = NULL;
    l->ultimo = NULL;

    return l;
}


Terminal* CadastraTerminal(char* nome, char* local){
    Terminal* t;
    t = (Terminal*)malloc(sizeof (Terminal));
    t->nome = (char*)malloc((strlen(nome)+1) * sizeof(char));
    t->local = (char*)malloc((strlen(local)+1) * sizeof(char));
    strcpy(t->nome,nome);
    strcpy(t->local,local);
    return t;
}

/*insere o terminal na lista de terminais*/
void conectaTerminal(tlista* t, Terminal* s){
    sentinel* r;
    r = (sentinel*)malloc(sizeof (sentinel));
    r->ter = s;
    r->prox = t->primeiro;
    t->primeiro = r;
    if(t->ultimo == NULL){
        t->ultimo = r;
    }

}

/*remove o terminal da lista*/
void RemoveTerminal(tlista *t, char* nome){
   sentinel* prim = t->primeiro;
   sentinel* ult = NULL;
   while ((prim != NULL) && ((strcmp(prim->ter->nome, nome) != 0))) {
       ult = prim;
       prim = prim->prox;
   }
   if(prim == t->primeiro && prim == t->ultimo){
        t->primeiro = t->ultimo;
        t->ultimo = NULL;
   }

   if(prim == t->ultimo){
        t->ultimo = ult;
        ult->prox = NULL;
   }

   if(prim == t->primeiro){
       t->primeiro = prim->prox;
   }else{
       ult->prox = prim->prox;
   }

   free(prim->ter->nome);
   free(prim->ter->local);
   free(prim->ter);
   free(prim);

}

Terminal* buscaTerminal(tlista* t,char* nome){
    sentinel* prim = t->primeiro;
    sentinel* ult = NULL;
    while ((prim != NULL) && (strcmp(prim->ter->nome,nome) != 0)) {
         ult = prim;
         prim = prim->prox;
    }
    if(prim == NULL){
        return NULL;
    }
    if(strcmp(prim->ter->nome,nome) == 0){
        return prim->ter;
    }
}


int FrequenciaTerminal(tlista* r, char* local){
    if(r != NULL){
        int cont = 0;
        sentinel *p = r->primeiro;
        sentinel *u = NULL;
        while (p != NULL) {
            if(strcmp(p->ter->local,local) == 0){
                cont++;
            }else{
                u = p;
                p = p->prox;
            }

        }
        return cont;
    }else return -1;
}

char* nomeTerminal(Terminal* t){
  return t->nome;
}

char* localTerminal(Terminal* t){
    return t->local;
}

char* getListFreqT(tlista* l){
    sentinel* m = l->primeiro;
    Terminal* t = m->ter;
    localTerminal(t);
}

void EncerraListaTerminais(tlista* t){
    if(t != NULL){
        sentinel* novo = t->primeiro;
        sentinel* temp;
        while (novo != NULL) {
            temp = novo->prox;
            free(novo->ter->nome);
            free(novo->ter->local);
            free(novo->ter);
            free(novo);
            novo = temp;
        }
        free(t);
    }
}
