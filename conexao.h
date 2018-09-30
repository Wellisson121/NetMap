#ifndef CONEXAO_H
#define CONEXAO_H

#include "roteador.h"
#include "terminal.h"

#define ROT 1;
#define TER 2;

typedef struct conexao Conexao;
typedef struct malha Malha;


Malha* criaMalha(void* equipamento, Conexao* prox);
/* Diz quantos roteadores e treminais existem no programa para
* serem usados na nalocacao dos vertices
*/
int Vertices(int roteadores, int terminais);

Conexao* iniciaConexao(int no);

void insereVertice(Conexao* c, void* vertice1, void* vertice2);

#endif // CONEXAO_H
