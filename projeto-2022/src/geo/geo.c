#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../geometria/circulo.h"
#include "../geometria/reta.h"
#include "../geometria/retangulo.h"
#include "../geometria/texto.h"
#include "geo.h"

void legeo(char *entrada, char *saida, char *geo, Lista circulo, Lista retangulo, Lista reta, Lista texto){
    if (entrada == NULL){
        return;
    }
    if (saida == NULL){
        return;
    }
    if (geo == NULL){
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

    int tamanhogeo = strlen(geo);
    int tamanhoentrada = strlen(entrada);
    int checabarra = entrada[tamanhoentrada-1] == '/';

    char *geopath = malloc(tamanhoentrada + tamanhogeo + 5 + !checabarra);

    if (geopath == NULL){
        return;
    }

    if (checabarra){
        sprintf(geopath, "%s%s", entrada, geo);
    }else{
        sprintf(geopath, "%s/%s", entrada, geo);
    }

    FILE *geoarquivo = fopen(geopath, "r");

    if (geoarquivo == NULL){
        return;
    }

    int tamanhosaida = strlen(saida);
    checabarra = saida[tamanhosaida-1] == '/';

    char *svgpath = malloc(tamanhosaida + tamanhogeo + !checabarra);

    if (svgpath == NULL){
        return;
    }

    *strrchr(geo, '.') = '\0';

    if (checabarra){
        sprintf(svgpath, "%s%s.svg", saida, geo);
    }else{
        sprintf(svgpath, "%s/%s.svg", saida, geo);
    }

    FILE *svgarquivo = fopen(svgpath, "w"); // Cria um arquivo para escrever svg
    fprintf(svgarquivo, "<svg>\n");

    while (!feof(geoarquivo)){
        char comando[9999];
        char id[999];
        char x[999];
        char y[999];
        char x1[999];
        char x2[999];
        char y1[999];
        char y2[999];
        char cor[999];
        char corB[999];
        char corP[999];
        char raio[999];
        char string[999];
        char altura[999];
        char largura[999];
        char ancoratexto[999];

        fscanf(geoarquivo, "%s", comando);

        switch (comando[0]){
            case 'c':
            fscanf(geoarquivo, "%s%s%s%s%s%s", id, raio, x, y, corB, corP);
            Circulo cr = criacirculo (x, y, raio, corB, corP, id);
            inserelista(circulo, cr);
            circulosvg(svgarquivo, cr);
            break;

            case 'l':
            fscanf(geoarquivo, "%s%s%s%s%s%s", id, x1, y1, x2, y2, cor);
            Reta rt = criareta (x1, y1, x2, y2, cor, id);
            inserelista(reta, rt);
            retasvg(svgarquivo, rt);
            break;

            case 'r':
            fscanf(geoarquivo, "%s%s%s%s%s%s%s", id, largura, altura, x, y, corB, corP);
            Retangulo rl = criaretangulo (x, y, altura, largura, corB, corP, id);
            inserelista(retangulo, rl);
            retangulosvg(svgarquivo, rl);
            break;

            case 't':
            fscanf(geoarquivo, "%s%s%s%s%s%s", id, x, y, corB, corP, ancoratexto, string);
            Texto tt = criatexto (x, y, string, corB, corP, ancoratexto, id);
            inserelista(texto, tt);
            textosvg(svgarquivo, tt);
            break;

            default:
            break;
        }
    }

    fprintf(svgarquivo, "</svg>\n");
}