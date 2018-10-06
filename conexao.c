#include "conexao.h"
#include "roteador.h"
#include "terminal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct conexao{
    Router* roteador;
    Terminal* terminal;
};


struct malha{
    Conexao* equipamento;
    Conexao* equipamento2;
    Conexao* prox;
};

struct lista{
    Malha* primeiro;
    Malha* ultimo;
};

/*comentario -> exemplo
int i, j;
int** mat = (int**)malloc(linhas * sizeof(int*));
for(i = 0; i < linhas; i++){
  mat[i] = (int*)malloc(colunas * sizeof(int));
}
*/


Lista3* criaLista(){
    Lista3* l;
    l = (Lista3*)malloc(sizeof (Lista3));
    l->primeiro = NULL;
    l->ultimo = NULL;
    return l;
}


Malha* criaMalha(Lista3* l, Router* r, Terminal* t){
    Malha* m;
    m = (Malha*)malloc(sizeof (Malha));
    m->equipamento = criaConexao(m->equipamento,r,t);
    l->primeiro = m;
    m->prox = NULL;
    if(l->ultimo == NULL){
        l->ultimo = m;
    }
    return m;
}

Conexao* criaConexao(Conexao* eq, Router* r, Terminal* t){
    eq = (Conexao*)malloc(sizeof (Conexao));
    eq->roteador = r;
    eq->terminal = t;
    return eq;
}

int Vertices(int roteadores, int terminais){
    return roteadores + terminais;
}



Conexao* iniciaConexao(int no){
    int i;
    Conexao* c;
    c = (Conexao*)malloc(sizeof (Conexao));
    c->no = no;
    c->ramos = 0;
    c->adjacencias = (Conexao**)malloc(no * sizeof (Conexao*));
    for(i = 0; i < no; i++){
        c->adjacencias[i] = NULL;
    }
    return c;
}

void insereVertice(Conexao* c, void* vertice1, void* vertice2){
    Malha* m;
    m = c->adjacencias[vertice1];
    while (m != NULL) {
        if(m->equipamento == vertice2){
            return;
        }
        c->adjacencias[vertice1] = criaMalha(vertice2,c->adjacencias[vertice1]);
        m = m->prox;
    }
}
