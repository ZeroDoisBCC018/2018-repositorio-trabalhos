#custom makefile by zerodois-bcc
#usando CP eh possivel mudar o compilador para g++, clang, tinycc e outros facilmente (apenas checar as flags COPT)

CP=gcc
COPT=-c -Wall
c89= -std=c89
c99= -std=c99
c11= -std=c11
ext=<extensão>
objetos:= $(patsubst %.c,%.o,$(wildcard *.c))
nome=<insira_nome_aqui>

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
	find . -print0 -type f -o -type d -not -name '\.' | xargs -0 rm -rf

all:
	$(CP) $(wildcard *.c *.h *.o *.a) -o $(nome) -Wall $(c11)
	
run:
	./$(nome)

objdump:
	objdump -D -M intel programa.bin | grep main.: -A20

valg:
	valgrind ./$(nome) -v --leak-check=full
	
gdb:
	$(CP) $(COPT) (wildcard *.c *.h *.o *.a) -g
	gdb ./$(nome) -w
	
disas: gdb
	disas main

tar:
	tar cfv $(nome).tar $(wildcard *.c *.h *.o *.a)
	
hexdump:
	hexdump -Cv programa.c | less
	
zip:
	zip $(nome) $(wildcard *.c *.h *.o *.a)

ignore:
	rm -rf *$(ext)


