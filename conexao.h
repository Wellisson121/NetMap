#ifndef CONEXAO_H
#define CONEXAO_H

#include "roteador.h"
#include "terminal.h"


typedef struct conexao Conexao;
typedef struct malha Malha;
typedef struct lista Lista3;

Lista3* criaLista(void);

Malha* criaMalha(Lista3* l);

int Vertices(int roteadores, int terminais);

void iniciaConexaoRoteadores(Router* r, Router* s, Lista3* l);

void iniciaConexaoTerminal(Lista3* l, Router *r, tlista* t, Terminal* s);

void removeConexaoRoteadores(Lista3* m,List* rot, char* nome);

#endif // CONEXAO_H
