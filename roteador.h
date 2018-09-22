#ifndef ROTEADOR_H
#define ROTEADOR_H


typedef struct roteador Router;
typedef struct cel Sentry;
typedef struct lista List;

List* carregaLista(void);

Router* CadastraRoteador(char* roteador, char* operadora, int id);

void ConectaRoteador(Router* r, List* s);

void RemoveRoteador(List* r, char* nome);

int FrequenciaOperadora(List* r, char* operadora);

void EncerraLista(List* t);


#endif // ROTEADOR_H
