#custom makefile by zerodois
#usando CP eh possivel mudar o compilador para clang ou g++ facilmente
CP=gcc
COPT=-c -Wall
c89= -std=c89
c99= -std=c99
c11= -std=c11
objetos:= $(patsubst %.c,%.o,$(wildcard *.c))

target: dependencies
	system command

programa: funcoes.o programa.o
	$(CP) programa.o funcoes.o -o programa
	
programa.o: programa.c
	$(CP) $(COPT) programa.c
	
funcoes.o: funcoes.c 
	$(CP) $(COPT) funcoes.c 
	
objects: $(objetos)
	$(CP) $(COPT) cc -o foo $(objetos)
	
clean:
	rm -rf *o programa

all:
	$(CP) $(COPT) $(wildcard *.c *.h *.o *.a)
	
run:
	./programa

objdump:
	objdump -D -M intel programa.bin | grep main.: -A20

valg:
	valgrind ./programa -v --leak-check=full
	
gdb:
	$(CP) $(COPT) (wildcard *.c *.h *.o *.a) -g
	gdb ./programa -w
	
disas: gdb
	disas main

tar:
	tar cfv programa.tar $(wildcard *.c *.h *.o *.a)

