#ifndef ROTEADOR_H
#define ROTEADOR_H


typedef struct roteador Router;
typedef struct cel Sentry;
typedef struct lista List;

/*cria uma lista de roteadores vazia
Entrada: nenhuma
Saida: lista vazia e alocada*/
List* carregaLista(void);

/*Recebe os parametros do Roteador e os insere no mesmo
Entrada: nome do roteador e nome da operadora
Saida: o roteador com todas as imformacoes*/
Router* CadastraRoteador(char* roteador, char* operadora);

/*insere o roteador na lista de roteadores
Entrada: o roteador e a lista de roteadores
Saida: nenhuma*/
void ConectaRoteador(Router* r, List* s);

/*Remove o roteador da lista
Entrada: a lista de roteadores e o nome do roteador
Saida: nenhuma*/
void RemoveRoteador(List* r, char* nome);

/*Diz quantos  roteadores de uma determinada operadora tem na lista
Entrada: A lista de roteadores e a operadora
Saida: o numero de roteadores da operadora*/
int FrequenciaOperadora(List* r, char* operadora);

/*Pesquisa um roteador por nome
Entrada: a lista e o nome do roteador procurado
Saida: o roteador encontrado*/
Router* buscaRoteador(List* t,char* nome);

/*Retorna o nome do roteador
Entrada: o Roteador
Saida: o nome do roteador*/
char* nomeRoteador(Router* r);

/*Retorna o nome do terminal
Entrada: o Roteador
Saida: o nome do terminal*/
char* operadoraRoteador(Router *s);

/*Retorna a lista para ser usada no programa
Entrada: a lista de roteadores
Saida: o nome para referencia*/
char* getListFreq(List* l);

/*Remove o roteador da lista
Entrada: o Roteador
Saida: Nenhum*/
void LiberaRoteador(Router* r);

/*Libera a lista
Entrada: a lsita de roteadores
Saida: nenhum*/
void EncerraLista(List* t);


#endif // ROTEADOR_H
