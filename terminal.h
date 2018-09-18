#ifndef TERMINAL_H
#define TERMINAL_H
#include "roteador.h"

typedef struct terminal Terminal;
typedef struct cell sentinel;

sentinel* CadastraTerminal(char* nome, char* local);

void RemoveTerminal(sentinel *t);

void* conectaTerminal(sentinel* t, void* r, int i);

#endif // TERMINAL_H
