all : main.o list.o
	gcc -o all main.o list.o
main.o: main.c list.h
	gcc -c main.c
list.o: list.h
	gcc -c list.c
clean: 
	rm -f all main.o list.o