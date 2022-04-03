#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include "geometria/circulo.h"
#include "geometria/reta.h"
#include "geometria/retangulo.h"
#include "geometria/texto.h"
#include "geo/geo.h"
#include "lista/lista.h"
#include "querry/querry.h"
#include "fila/fila.h"

int main (int argc, char* argv[]){
    char leparametro;
    char *entrada = "./";
    char *saida = NULL;
    char *geo = NULL;
    char *querry = NULL;

    while ((leparametro = getopt(argc, argv, "e:f:o:q:")) != -1){
        switch (leparametro){
            case 'e':
            entrada = malloc(strlen(optarg)+1);
            strcpy(entrada, optarg);
            break;

            case 'o':
            saida = malloc(strlen(optarg)+1);
            strcpy(saida, optarg);
            break;

            case 'f':
            geo = malloc(strlen(optarg)+1);
            strcpy(geo, optarg);
            break;

            case 'q':
            querry = malloc(strlen(optarg)+1);
            strcpy(querry, optarg);
            break;

        }
    }

    if(geo == NULL){
        printf("O parametro 'f' e obrigatorio");
        return -1;
    }

    if(saida == NULL){
        printf("O parametro 'o' e obrigatorio");
        return -1;
    }
    
    Lista listac = crialista();
    Lista listal = crialista();
    Lista listar = crialista();
    Lista listat = crialista();
    Lista listaselec = crialista();
    Fila filacorrente = criafila();

    legeo(entrada, saida, geo, listac, listal, listar, listat, listaselec, filacorrente);
    lequerry(entrada, saida, querry, geo, listac, listal, listar, listat, listaselec, filacorrente);

    return 0;
}