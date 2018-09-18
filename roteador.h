#ifndef ROTEADOR_H
#define ROTEADOR_H


typedef struct roteador Router;
typedef struct cel Sentry;
typedef struct lista List;



Sentry* CadastraRoteador(Sentry* s,char* roteador, char* operadora);

void ConectaRoteadores(Sentry* r, Sentry* s);

void RemoveRoteador(Sentry* r);

int FrequenciaOperadora(Sentry* r, char* operadora);

void EncerraLista(Sentry* t);


#endif // ROTEADOR_H
