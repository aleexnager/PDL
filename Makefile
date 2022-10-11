CC = gcc

programa: main.o accion.o estado.o error.o pal_res.o header.o header.h
	$(CC) -o programa main.o accion.o estado.o error.o pal_res.o header.o

main: main.c header.h
	$(CC) -c main.c

accion: accion.c header.h
	$(CC) -c accion.c

estado: estado.c header.h
	$(CC) -c estado.c

error: error.c header.h
	$(CC) -c error.c

pal_res: pal_res.c header.h
	$(CC) -c pal_res.c

header: header.c header.h
	$(CC) -c header.c
