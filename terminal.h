#ifndef TERMINAL_H
#define TERMINAL_H


typedef struct terminal Terminal;
typedef struct cell sentinel;
typedef struct lista tlista;

tlista* carregaListaTerminal(void);

Terminal* CadastraTerminal(char* nome, char* local);

void conectaTerminal(tlista* t, Terminal* s);

void RemoveTerminal(tlista *t, char* nome);

Terminal* buscaTerminal(tlista* t,char* nome);

int FrequenciaTerminal(tlista* r, char* local);

char* nomeTerminal(Terminal* t);

void EncerraListaTerminais(tlista* t);

#endif // TERMINAL_H
