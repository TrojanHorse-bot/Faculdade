#ifndef bgeo
#define bgeo
#include "../lista/lista.h"
#include "../fila/fila.h"

//Concatena o path, lê o arquivo .geo do path concatenado, e salva as formas em listas.
void legeo(char *entrada, char *saida, char *geo, Lista circulo, Lista retangulo, Lista reta, Lista texto, Lista listaselec, Fila filacorrente);

#endif