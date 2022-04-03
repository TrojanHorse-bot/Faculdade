#ifndef bquerry
#define bquerry
#include "../lista/lista.h"
#include "../fila/fila.h"

// Concatena o path, lê o arquivo .qry, salva e altera as formas em listas
void lequerry(char *entrada, char *saida, char *querry, char *geo, Lista circulo, Lista retangulo, Lista reta, Lista texto, Lista listaselec, Fila filacorrente);

#endif