#include "roteador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




struct roteador{
  char* nome;
  char* operadora;

};

struct cel{
    Router* rot;
    Sentry* prox;
};

struct lista{
    Sentry* primeiro;
    Sentry* ultimo;
};

/*typedef struct roteador Router;
typedef struct cel Sentry;
typedef struct lista List;*/

List* carregaLista(){
    List* l;
    l = (List*)malloc(sizeof (List));
    l->primeiro = NULL;
    l->ultimo = NULL;
    return l;
}


/*inicializa um tipo roteador */
Router* CadastraRoteador(char* roteador, char* operadora){
    Router* s;
    s = (Router*)malloc(sizeof(Router));
    s->nome = (char*)malloc((strlen(roteador)+1) * sizeof(char));
    s->operadora = (char*)malloc((strlen(operadora)+1) * sizeof(char));
    strcpy(s->nome,roteador);
    strcpy(s->operadora,operadora);
    return s;
}
/*insere o roteador na lista*/
void ConectaRoteador(Router* r, List* s){
    Sentry* t;
    t = (Sentry*)malloc(sizeof (Sentry));
    t->rot = r;
    t->prox = s->primeiro;
    s->primeiro = t;
    if(s->ultimo == NULL){
        s->ultimo = t;
    }

}


void RemoveRoteador(List* r, char* nome){
   Sentry* prim = r->primeiro;
   Sentry* ult = NULL;
   while ((prim != NULL) && (strcmp(prim->rot->nome,nome) != 0)) {
        ult = prim;
        prim = prim->prox;
   }

   if(prim == r->primeiro && prim == r->ultimo){
        r->primeiro = r->ultimo;
        r->ultimo = NULL;
   }

   if(prim == r->ultimo){
        r->ultimo = ult;
        ult->prox = NULL;
   }

   if(prim == r->primeiro){
       r->primeiro = prim->prox;
   }else{
       ult->prox = prim->prox;
   }

   free(prim->rot->nome);
   free(prim->rot->operadora);
   free(prim->rot);
   free(prim);

}

int FrequenciaOperadora(List* r, char* operadora){
    if(r != NULL){
        int cont = 0;
        Sentry *p = r->primeiro;
        Sentry *u = NULL;
        while (p != NULL) {
            if(strcmp(p->rot->operadora,operadora) == 0){
                cont++;
            }else{
                u = p;
                p = p->prox;
            }

        }
        return cont;
    }else return -1;
}

Router* buscaRoteador(List* t,char* nome){
    Sentry* prim = t->primeiro;
    Sentry* ult = NULL;
    while ((prim != NULL) && (strcmp(prim->rot->nome,nome) != 0)) {
         ult = prim;
         prim = prim->prox;
    }
    if(prim == NULL){
        return NULL;
    }
    if(strcmp(prim->rot->nome,nome) == 0){
        return prim->rot;
    }
}

void LiberaRoteador(Router* r){
    free(r->nome);
    free(r->operadora);
    free(r);
}


void EncerraLista(List* t){
    if(t != NULL){
        Sentry* new = t->primeiro;
        Sentry* tmp;
        while (new !=NULL) {
            tmp = new->prox;
            LiberaRoteador(new->rot);
            new = tmp;
        }
        free(t);

    }
}
