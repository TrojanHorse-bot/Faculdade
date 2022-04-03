#include "circulo.h"
#include <stdlib.h>
#include <string.h>

struct circulo{
    char *x;
    char *y;
    char *raio;
    char *cbcirculo; 
    char *cpcirculo;
    char *idcirculo;
};

Circulo criacirculo (char *x, char *y, char *raio, char *cbcirculo, char *cpcirculo, char *idcirculo){
    Circulo circulo = malloc(sizeof(struct circulo));

    if (circulo == NULL){
        return NULL;
    }
    
    circulo->x = malloc(strlen(x)+1);
    circulo->y = malloc(strlen(y)+1);
    circulo->raio = malloc(strlen(raio)+1);
    circulo->cbcirculo = malloc(strlen(cbcirculo)+1);
    circulo->cpcirculo = malloc(strlen(cpcirculo)+1);
    circulo->idcirculo = malloc(strlen(idcirculo)+1);

    strcpy(circulo->x,x);
    strcpy(circulo->y,y);
    strcpy(circulo->raio,raio);
    strcpy(circulo->cbcirculo,cbcirculo);
    strcpy(circulo->cpcirculo,cpcirculo);
    strcpy(circulo->idcirculo,idcirculo);

    if (circulo->x == NULL || circulo->y == NULL || circulo->raio == NULL || circulo->cbcirculo == NULL || circulo->cpcirculo == NULL || circulo->idcirculo == NULL){
        destroicirculo(circulo);
        return NULL;
    }

    return circulo;
}

char *getxcirculo(Circulo circulo){
    if (circulo == NULL){
        return NULL;
    }
    return circulo->x;
}

char *getycirculo(Circulo circulo){
    if (circulo == NULL){
        return NULL;
    }
    return circulo->y;
}

char *getraiocirculo(Circulo circulo){
    if (circulo == NULL){
        return NULL;
    }
    return circulo->raio;
}

char *getcbcirculo(Circulo circulo){
    if (circulo == NULL){
        return NULL;
    }
    return circulo->cbcirculo;
}

void setcbcirculo(Circulo circulo, char *novacor){ // Atualizando a cor
    if (circulo == NULL || novacor == NULL){
        return;
    }
    circulo->cbcirculo = realloc(circulo->cbcirculo, strlen(novacor)+1);
    strcpy(circulo->cbcirculo, novacor);
}

void setcpcirculo(Circulo circulo, char *novacor){ // Atualizando a cor
    if (circulo == NULL || novacor == NULL){
        return;
    }
    circulo->cpcirculo = realloc(circulo->cpcirculo, strlen(novacor)+1);
    strcpy(circulo->cpcirculo, novacor);
}

char *getcpcirculo(Circulo circulo){
    if (circulo == NULL){
        return NULL;
    }
    return circulo->cpcirculo;
}

char *getidcirculo(Circulo circulo){
    if (circulo == NULL){
        return NULL;
    }
    return circulo->idcirculo;
}

void destroicirculo(Circulo circulo){
    if (circulo == NULL){
        return;

    }
    
    if (circulo->x){
        free(circulo->x);

    }

    if (circulo->y){
        free(circulo->y);

    }

    if (circulo->raio){
        free(circulo->raio);

    }

    if (circulo->cbcirculo){
        free(circulo->cbcirculo);

    }

    if (circulo->cpcirculo){
        free(circulo->cpcirculo);

    }

    if (circulo->idcirculo){
        free(circulo->idcirculo);

    }
    
    free(circulo);
}

void circulosvg (FILE *svg, Circulo circulo){
    char *x = getxcirculo(circulo);
    char *y = getycirculo(circulo);
    char *raio = getraiocirculo(circulo);
    char *corB = getcbcirculo(circulo);
    char *corP = getcpcirculo(circulo);

    fprintf(svg, "<circle cx=\"%s\" cy=\"%s\" r=\"%s\" stroke=\"%s\" fill=\"%s\" stroke-width=\"1\" />\n", x, y, raio, corB, corP);
}