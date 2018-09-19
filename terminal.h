#ifndef TERMINAL_H
#define TERMINAL_H


typedef struct terminal Terminal;
typedef struct cell sentinel;

sentinel* CadastraTerminal(char* nome, char* local);

void RemoveTerminal(sentinel *t);

int FrequenciaTerminal(sentinel* r, char* local);

#endif // TERMINAL_H
