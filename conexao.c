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
    Conexao* prox;
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
    m = (Malha*)malloc(sizeof (Malha));
    m->equipamento->roteador = carregaLista();
    m->equipamento->terminal = carregaLista();
    m->prox = l->primeiro;
    l->primeiro = m;
    if(l->ultimo == NULL){
        l->ultimo = m;
    }
    return m;
}



int Vertices(int roteadores, int terminais){
    return roteadores + terminais;
}


void iniciaConexaoRoteadores(Router* r, Router* s, Lista3* l){
    Malha* m = l->primeiro;
    if(m == NULL){
        m->equipamento->rot = r;
    }
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
    if(m ==NULL){
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
    if(m == NULL){
        printf("Roteador nao existe!\n");
    }
    if(m->equipamento->rot == r){
        conectaTerminal(t,s);
    }
}


void removeConexaoRoteadores(Lista3* m,List* rot, char* nome){
    Malha* prim = m->primeiro;
    Malha* ult = NULL;
    while (m != NULL && prim->equipamento->rot != rot) {
        ult = prim;
        prim = prim->prox;
    }
    if(prim->equipamento->rot == rot){
        RemoveRoteador(rot,nome);
    }
}
