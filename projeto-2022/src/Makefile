CC = gcc
CFLAGS = -std=c99 -fstack-protector-all

siguel: main.c circulo.o reta.o retangulo.o texto.o fila.o lista.o pilha.o geo.o querry.o
	$(CC) $(CFLAGS) -g -o siguel main.c circulo.o reta.o retangulo.o texto.o fila.o lista.o pilha.o geo.o querry.o -lm

circulo.o: geometria/circulo.c geometria/circulo.h
	$(CC) $(CFLAGS) -c geometria/circulo.c

reta.o: geometria/reta.c geometria/reta.h
	$(CC) $(CFLAGS) -c geometria/reta.c

retangulo.o: geometria/retangulo.c geometria/retangulo.h
	$(CC) $(CFLAGS) -c geometria/retangulo.c

texto.o: geometria/texto.c geometria/texto.h
	$(CC) $(CFLAGS) -c geometria/texto.c

fila.o: fila/fila.c fila/fila.h
	$(CC) $(CFLAGS) -c fila/fila.c

lista.o: lista/lista.c lista/lista.h
	$(CC) $(CFLAGS) -c lista/lista.c

pilha.o: pilha/pilha.c pilha/pilha.h
	$(CC) $(CFLAGS) -c pilha/pilha.c

geo.o: geo/geo.c geo/geo.h
	$(CC) $(CFLAGS) -c geo/geo.c

querry.o: querry/querry.c querry/querry.h
	$(CC) $(CFLAGS) -c querry/querry.c

clean:
	rm -r -f *.o
	rm siguel