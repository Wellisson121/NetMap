### Makefile ###
all: prog

prog: proglista.o lista.o
	gcc proglista.o lista.o -o prog

lista.o: lista.c
	gcc -c lista.c

proglista.o: proglista.c
	gcc -c proglista.c

clean:
	rm -rf *.o

run: prog
	./prog
