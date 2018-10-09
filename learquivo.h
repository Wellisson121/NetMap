#ifndef LEARQUIVO_H
#define LEARQUIVO_H

/*
Abre um arquivo chamado log.txt, onde ficam os erros de execucao
do programa
Entrada: Nome do arquivo e o codigo de erro
Retorno: void
*/
void abreArquivoLog(const char *nome, int id);

/*
Testa se consegue ler o arquivo de execucao
Entada: Nome do arquivo
Saida:1, se conseguiu ler, 0 caso contrario
*/
int abreArquivoExec(char const* nome);

/*Abre um arquivo para onde serao redirecionadas as saidas
do programa.Se ele nao existir, cria um
Entrada: Nome do comando executado,nome do roteador ou terminal,
quantidade de roteadores ou terminais
Saida: nenhuma*/
void abreArquivoSaida(char* comando,char* nome,int num);

#endif // LEARQUIVO_H
