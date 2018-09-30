#include "conexao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct conexao{
    int no;/*numero de vertices*/
    int ramos;/*numero de arcos ou arestas*/
    Conexao** adjacencias;
};


struct malha{
    void* equipamento;/*roteador ou terminal*/
    Conexao* prox;
    long int id;/*identifica se o equipamento e roteador ou terminal*/
};

/*inicializa o grafo*/
Malha* criaMalha(void* equipamento, Conexao* prox){
    Malha* m;
    m = (Malha*)malloc(sizeof (Malha));
    m->equipamento = equipamento;
    m->prox = prox;
    return m;
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
