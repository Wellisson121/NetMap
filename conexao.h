#ifndef CONEXAO_H
#define CONEXAO_H

#include "roteador.h"
#include "terminal.h"


typedef struct conexao Conexao;
typedef struct malha Malha;
typedef struct lista Lista3;

/*
Cria uma lista que armazenara os enlaces
Entrada: Nenhuma
Saida: Lista alocada e vazia
*/
Lista3* criaLista(void);

/*
Cria uma celula que armazenara a informacao do roteador
e suas respectivas conexoes
Entrada: A lista vazia
Saida: A celula alocada e inserida na lista
*/
Malha* criaMalha(Lista3* l);

/*
Cria uma conexao entre dois roteadores
Condicao: os dois roteadores devem existir no programa
Entrada:os Roteadores a serem enlacados
Saida: nenhuma
*/
void iniciaConexaoRoteadores(Router* r, Router* s, Lista3* l);

/*Verifica se um determinado roteador existe na lista de enlaces
Entrada: a lista de enlaces e o nome do roteador desejado
Saida: 1, se o roteador existir,0 caso contrario*/
int existe(Lista3* l, char* nome);

/*Conecta um terminal no roteador pedido na lista de enlaces
Entrada: a lista de enlaces, o roteador desejado,a lista de terminais e o terminal desejado
Saida: nenhum*/
void iniciaConexaoTerminal(Lista3* l, Router *r, tlista* t, Terminal* s);
/*Remove o enlace entre dois roteadores do NetMap
Entrada: a Lista de enlaces, a lista de roteadores e
o nome do roteador a ser retirado
Saida: nenhum*/
void removeConexaoRoteadores(Lista3* m,List* rot, char* nome);

char* nomeEnlace(Lista3* c);

tlista* capturaListaTerminal(Lista3* t, char* nome);

List* capturaListaRoteador(Lista3* l, List* l1);

List* capturaListaRoteadorRemocao(Lista3* m);

/*Libera a lista de enlaces do NetMap*/
void EncerraListaConexoes(Lista3* l);

#endif // CONEXAO_H
