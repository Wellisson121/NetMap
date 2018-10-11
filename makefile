### Makefile ###
all: netMap

netMap: conexao.o terminal.o roteador.o learquivo.o main.o
	gcc conexao.o terminal.o roteador.o learquivo.o main.o -o netMap

conexao.o: conexao.c
	gcc -c conexao.c

terminal.o: terminal.c
	gcc -c terminal.c

roteador.o: roteador.c
	gcc -c roteador.c

learquivo.o: learquivo.c
	gcc -c learquivo.c

main.o: main.c
	gcc -c main.c 

graph:
	neato -Tpdf saida.dot -o saida.pdf 

clean:
	rm -rf *.o

run:
	./netMap entrada.txt
