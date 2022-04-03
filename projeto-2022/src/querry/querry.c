#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../geometria/circulo.h"
#include "../geometria/reta.h"
#include "../geometria/retangulo.h"
#include "../geometria/texto.h"
#include "querry.h"
#include "../fila/fila.h"
#include "../lista/lista.h"

FILE *textoarq;


void lequerry(char *entrada, char *saida, char *querry, char *geo, Lista circulo, Lista retangulo, Lista reta, Lista texto){ 
    if (entrada == NULL){
        return;
    }
    if (saida == NULL){
        return;
    }
    if (querry == NULL){
        return;
    }
    if (circulo== NULL){
        return;
    }
    if (retangulo == NULL){
        return;
    }
    if (reta == NULL){
        return;
    }
    if (texto == NULL){
        return;
    }

    int tamanhoquerry = strlen(querry); // Tamanho do nome do querry
    int tamanhogeo = strlen(geo); // Tamanho do nome do geo
    int tamanhoentrada = strlen(entrada);
    int checabarra = entrada[tamanhoentrada-1] == '/';

    char *querrypath = malloc(tamanhoentrada + tamanhoquerry + !checabarra + 1);

    if (querrypath == NULL){
        return;
    }

    if (checabarra){
        sprintf(querrypath, "%s%s", entrada, querry);
    }else{
        sprintf(querrypath, "%s/%s", entrada, querry);
    }


    FILE *querryarquivo = fopen(querrypath, "r"); // Em querryarquivo, se salva o que foi aberto em quarrypath para leitura (r)
    free(querrypath);

    if (querryarquivo == NULL){ // Se querryarquivo está vazio, para
        return;
    }

    geo = strtok(geo, ".");
    querry = strtok(querry, ".");
    querry = strrchr(querry, '/') + 1;

    int tamanhosaida = strlen(saida);
    checabarra = saida[tamanhosaida-1] == '/';

    char *svgpath = malloc(tamanhosaida + tamanhogeo + tamanhoquerry + 6 + !checabarra);

    if (svgpath == NULL){
        return;
    }

    if (checabarra){
        sprintf(svgpath, "%s%s-%s.svg", saida, geo, querry); // Renomeando
    }else{
        sprintf(svgpath, "%s/%s-%s.svg", saida, geo, querry); // Renomeando 
    }

    FILE *svgarquivo = fopen(svgpath, "w"); // Cria um arquivo para escrever svg
    fprintf(svgarquivo, "<svg>\n");
    strtok(svgpath, ".");
    strcat(svgpath, ".txt");
    textoarq = fopen(svgpath, "w");

    Fila fila [10];
    Pilha pilha [10];
    Lista lista [10];
    Listaposicao registradores[10];

    for (int i = 0; i < 10; i++){
        fila[i] = criafila();
        pilha[i] = criapilha();
        lista[i] = crialista();
        registradores[i] = NULL;
    }
    
    char auxiliar[999];

    while (1){
        fgets(auxiliar, 999, querryarquivo);
        if (feof(querryarquivo)){
            break;
        }

        if(auxiliar[strlen(auxiliar)-1] == '\n'){
            auxiliar[strlen(auxiliar)-1] = '\0';
        }

        char *arg = strchr (auxiliar, ' ') + 1;
        strtok(auxiliar, " ");
    }

    Listaposicao posicao = primeirolista(circulo);
    while (posicao){ // Se posição é true (e sempre vai ser)
        Circulo circuloq = getlista(circulo, posicao);
        circulosvg(svgarquivo, circuloq);
        posicao = proximolista(circulo, posicao);
    }

    posicao = primeirolista(reta);
    while (posicao){ // Se posição é true (e sempre vai ser)
        Reta retaq = getlista(reta, posicao);
        retasvg(svgarquivo, retaq);
        posicao = proximolista(reta, posicao);
    }

    posicao = primeirolista(retangulo);
    while (posicao){ // Se posição é true (e sempre vai ser)
        Retangulo retanguloq = getlista(retangulo, posicao);
        retangulosvg(svgarquivo, retanguloq);
        posicao = proximolista(retangulo, posicao);
    }

    posicao = primeirolista(texto);
    while (posicao){ // Se posição é true (e sempre vai ser)
        Texto textoq = getlista(texto, posicao);
        textosvg(svgarquivo, textoq);
        posicao = proximolista(texto, posicao);
    }

    fprintf(svgarquivo, "</svg>");
}