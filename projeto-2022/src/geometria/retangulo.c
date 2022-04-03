#include "retangulo.h"
#include <stdlib.h>
#include <string.h>

struct retangulo{
    char *x;
    char *y;
    char *altura;
    char *largura;
    char *cbretangulo; 
    char *cpretangulo;
    char *idretangulo;
};

Retangulo criaretangulo (char *x, char *y, char *altura, char *largura, char *cbretangulo, char *cpretangulo, char *idretangulo){
    Retangulo retangulo = malloc(sizeof(struct retangulo));

    if (retangulo == NULL){
        return NULL;
    }
    
    retangulo->x = malloc(strlen(x)+1);
    retangulo->y = malloc(strlen(y)+1);
    retangulo->altura = malloc(strlen(altura)+1);
    retangulo->largura = malloc(strlen(largura)+1);
    retangulo->cbretangulo = malloc(strlen(cbretangulo)+1);
    retangulo->cpretangulo = malloc(strlen(cpretangulo)+1);
    retangulo->idretangulo = malloc(strlen(idretangulo)+1);

    strcpy(retangulo->x,x);
    strcpy(retangulo->y,y);
    strcpy(retangulo->altura,altura);
    strcpy(retangulo->largura,largura);
    strcpy(retangulo->cbretangulo,cbretangulo);
    strcpy(retangulo->cpretangulo,cpretangulo);
    strcpy(retangulo->idretangulo,idretangulo);

    if (retangulo->x == NULL || retangulo->y == NULL || retangulo->altura == NULL || retangulo->largura == NULL || retangulo->cbretangulo == NULL || retangulo->cpretangulo == NULL || retangulo->idretangulo == NULL){
        destroiretangulo(retangulo);
        return NULL;
    }

    return retangulo;
}

char *getxretangulo(Retangulo retangulo){
    if (retangulo == NULL){
        return NULL;
    }
    return retangulo->x;
}

char *getyretangulo(Retangulo retangulo){
    if (retangulo == NULL){
        return NULL;
    }
    return retangulo->y;
}

char *getalturaretangulo(Retangulo retangulo){
    if (retangulo == NULL){
        return NULL;
    }
    return retangulo->altura;
}

char *getlarguraretangulo(Retangulo retangulo){
    if (retangulo == NULL){
        return NULL;
    }
    return retangulo->largura;
}

char *getcbretangulo(Retangulo retangulo){
    if (retangulo == NULL){
        return NULL;
    }
    return retangulo->cbretangulo;
}

char *getcpretangulo(Retangulo retangulo){
    if (retangulo == NULL){
        return NULL;
    }
    return retangulo->cpretangulo;
}

void setcbretangulo(Retangulo retangulo, char *novacor){ // Atualizando a cor
    if (retangulo == NULL || novacor == NULL){
        return;
    }
    retangulo->cbretangulo = realloc(retangulo->cbretangulo, strlen(novacor)+1);
    strcpy(retangulo->cbretangulo, novacor);
}

void setcpretangulo(Retangulo retangulo, char *novacor){ // Atualizando a cor
    if (retangulo == NULL || novacor == NULL){
        return;
    }
    retangulo->cpretangulo = realloc(retangulo->cpretangulo, strlen(novacor)+1);
    strcpy(retangulo->cpretangulo, novacor);
}

char *getidretangulo(Retangulo retangulo){
    if (retangulo == NULL){
        return NULL;
    }
    return retangulo->idretangulo;
}

void destroiretangulo(Retangulo retangulo){
    if (retangulo == NULL){
        return;
    }
    
    if (retangulo->x){
        free(retangulo->x);
    }

    if (retangulo->y){
        free(retangulo->y);
    }

    if (retangulo->altura){
        free(retangulo->altura);
    }

    if (retangulo->largura){
        free(retangulo->largura);
    }

    if (retangulo->cbretangulo){
        free(retangulo->cbretangulo);
    }

    if (retangulo->cpretangulo){
        free(retangulo->cpretangulo);
    }

    if (retangulo->idretangulo){
        free(retangulo->idretangulo);
    }
    
    free(retangulo);
}

void retangulosvg (FILE *svg, Retangulo retangulo){

    char *x = getxretangulo(retangulo);
    char *y = getyretangulo(retangulo);
    char *altura = getalturaretangulo(retangulo);
    char *largura = getlarguraretangulo(retangulo);
    char *corB = getcbretangulo(retangulo);
    char *corP = getcpretangulo(retangulo);

    fprintf(svg, "<rect x = \"%s\" y = \"%s\" width = \"%s\" height = \"%s\" fill=\"%s\" stroke = \"%s\" />\n" , x, y, largura, altura, corP, corB);
}