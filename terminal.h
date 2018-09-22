#ifndef TERMINAL_H
#define TERMINAL_H


typedef struct terminal Terminal;
typedef struct cell sentinel;
typedef struct lista tlista;

tlista* carregaLista(void);

Terminal* CadastraTerminal(char* nome, char* local);

void conectaTerminal(tlista* t, Terminal* s);

void RemoveTerminal(tlista *t, char* nome);

int FrequenciaTerminal(tlista* r, char* local);

#endif // TERMINAL_H
