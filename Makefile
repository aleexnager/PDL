CC = gcc
CFLAGS = -Wall -Werror -Wextra -ansi -pedantic

programa: main.o accion.o estado.o error.o pal_res.o tabla_simbolos.o header.o header.h
	$(CC) $(CFLAGS) -o programa main.o accion.o estado.o error.o pal_res.o tabla_simbolos.o header.o

main: main.c header.h
	$(CC) $(CFLAGS) -c main.c

accion: accion.c header.h
	$(CC) $(CFLAGS) -c accion.c

estado: estado.c header.h
	$(CC) $(CFLAGS) -c estado.c

error: error.c header.h
	$(CC) $(CFLAGS) -c error.c

pal_res: pal_res.c header.h
	$(CC) $(CFLAGS) -c pal_res.c

tabla_simbolos: tabla_simbolos.c header.h
	$(CC) $(CFLAGS) -c tabla_simbolos.c

header: header.c header.h
	$(CC) $(CFLAGS) -c header.c
