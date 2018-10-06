#ifndef CONEXAO_H
#define CONEXAO_H

#include "roteador.h"
#include "terminal.h"


typedef struct conexao Conexao;
typedef struct malha Malha;
typedef struct lista Lista3;

Lista3* criaLista(void);
/* Diz quantos roteadores e treminais existem no programa para
* serem usados na nalocacao dos vertices
*/

Malha* criaMalha(Lista3* l, Router* r, Terminal* t);

Conexao* criaConexao(Conexao* eq, Router* r, Terminal* t);

int Vertices(int roteadores, int terminais);

Conexao* iniciaConexao(int no);

void insereVertice(Conexao* c, void* vertice1, void* vertice2);

#endif // CONEXAO_H
