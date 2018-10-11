#include "conexao.h"
#include "roteador.h"
#include "terminal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct conexao{
    Router* rot;
    List* roteador;
    tlista* terminal;
};


struct malha{
    Conexao* equipamento;
    Malha* prox;
};

struct lista{
    Malha* primeiro;
    Malha* ultimo;
};


Lista3* criaLista(){
    Lista3* l;
    l = (Lista3*)malloc(sizeof (Lista3));
    l->primeiro = NULL;
    l->ultimo = NULL;
    return l;
}


Malha* criaMalha(Lista3* l){
    Malha* m;
    Conexao* eq;
    m = (Malha*)malloc(sizeof (Malha));
    eq = (Conexao*)malloc(sizeof(Conexao));
    eq->roteador = carregaLista();
    eq->terminal = carregaListaTerminal();
    eq->rot = NULL;
    m->equipamento = eq;
    m->prox = l->primeiro;
    l->primeiro = m;
    if(l->ultimo == NULL){
        l->ultimo = m;
    }
    return m;
}



void iniciaConexaoRoteadores(Router* r, Router* s, Lista3* l){
    Malha* m = criaMalha(l);
    m->equipamento->rot = r;
    ConectaRoteador(s,m->equipamento->roteador);
}

/*verifica se um dado roteador existe na lista de enlaces*/
int existe(Lista3* l, char* nome){
    Malha* m = l->primeiro;
    Malha* u = NULL;
    while (m != NULL && buscaRoteador(m->equipamento->roteador,nome)!=m->equipamento->rot) {
        u = m;
        m = m->prox;
    }
    if(m == NULL){
        return 0;
    }else{
        return 1;
    }
}


void iniciaConexaoTerminal(Lista3* l, Router *r, tlista* t, Terminal* s){
    Malha* m = l->primeiro;
    Malha* u = NULL;
    while (m != NULL && m->equipamento->rot != r) {
        u = m;
        m = m->prox;
    }

    if(m->equipamento->rot == r){
        conectaTerminal(t,s);
    }
}


void removeConexaoRoteadores(Lista3* m,List* rot, char* nome){
    Malha* prim = m->primeiro;
    Malha* ult = NULL;
    Conexao* c;
    Router* r;
    char nome2[10];
    while (m != NULL) {
        c = m->primeiro->equipamento;
        c->rot= buscaRoteador(rot,nome);
        r = c->rot;
        strcpy(nome2,nomeRoteador(r));
        if(strcmp(nome2 ,nome)==0){
          RemoveRoteador(rot,nome);
          break;
        }
        ult = prim;
        prim = prim->prox;
    }

}

char* nomeEnlace(Lista3* c){
  Malha* con;
  Conexao* eq;
  con = c->primeiro;
  eq = con->equipamento;
  Router* r = eq->rot;
  return nomeRoteador(r);
}

tlista* capturaListaTerminal(Lista3* t, char* nome){
    Malha *m = t->primeiro;
    Conexao *c = m->equipamento;
    tlista *t1 = c->terminal;
    buscaTerminal(t1,nome);
}

List* capturaListaRoteador(Lista3* l, List* l1){
  Malha* m = l->primeiro;
  Conexao* c = m->equipamento;
  Router* r = c->rot;
  return buscaRoteador(l1,nomeRoteador(r));
 }

List* capturaListaRoteadorRemocao(Lista3* m){
    Malha* n = m->primeiro;
    Conexao* c = n->equipamento;
    List* l = c->roteador;
    return l;
}

void EncerraListaConexoes(Lista3* l){
    if(l != NULL){
        Malha* novo = l->primeiro;
        Malha* t;
        while (novo != NULL) {
            t = novo->prox;
            EncerraLista(novo->equipamento->roteador);
            EncerraListaTerminais(novo->equipamento->terminal);
            free(novo->equipamento);
            free(novo);
            novo = t;
        }
        free(l);
    }
}
