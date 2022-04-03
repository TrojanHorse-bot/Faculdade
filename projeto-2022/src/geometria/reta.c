#include "reta.h"
#include <stdlib.h>
#include <string.h>

struct reta{
    char *x1;
    char *y1;
    char *x2;
    char *y2;
    char *cbreta; 
    char *idreta;
};

Reta criareta (char *x1, char *y1, char *x2, char *y2, char *cbreta, char *idreta){
    Reta reta = malloc(sizeof(struct reta));

    if (reta == NULL){
        return NULL;
    }
    
    reta->x1 = malloc(strlen(x1)+1);
    reta->y1 = malloc(strlen(y1)+1);
    reta->x2 = malloc(strlen(x2)+1);
    reta->y2 = malloc(strlen(y2)+1);
    reta->cbreta = malloc(strlen(cbreta)+1);
    reta->idreta = malloc(strlen(idreta)+1);

    strcpy(reta->x1,x1);
    strcpy(reta->y1,y1);
    strcpy(reta->x2,x2);
    strcpy(reta->y2,y2);
    strcpy(reta->cbreta,cbreta);
    strcpy(reta->idreta,idreta);

    if (reta->x1 == NULL || reta->y1 == NULL || reta->x2 == NULL || reta->y2 == NULL || reta->cbreta == NULL || reta->idreta == NULL){
        destroireta(reta);
        return NULL;
    }

    return reta;
}

char *getx1reta(Reta reta){
    if (reta == NULL){
        return NULL;
    }
    return reta->x1;
}

char *gety1reta(Reta reta){
    if (reta == NULL){
        return NULL;
    }
    return reta->y1;
}

char *getx2reta(Reta reta){
    if (reta == NULL){
        return NULL;
    }
    return reta->x2;
}

char *gety2reta(Reta reta){
    if (reta == NULL){
        return NULL;
    }
    return reta->y2;
}

char *getcbreta(Reta reta){
    if (reta == NULL){
        return NULL;
    }
    return reta->cbreta;
}

void setcbreta(Reta reta, char *novacor){ // Atualizando a cor
    if (reta == NULL || novacor == NULL){
        return;
    }
    reta->cbreta = realloc(reta->cbreta, strlen(novacor)+1);
    strcpy(reta->cbreta, novacor);
}

char *getidreta(Reta reta){
    if (reta == NULL){
        return NULL;
    }
    return reta->idreta;
}

void destroireta(Reta reta){
    if (reta == NULL){
        return;
        
    }

    if (reta->x1){
        free(reta->x1);

    }

    if (reta->y1){
        free(reta->y1);

    }

    if (reta->x2){
        free(reta->x2);

    }

    if (reta->y2){
        free(reta->y2);

    }

    if (reta->cbreta){
        free(reta->cbreta);

    }

    if (reta->idreta){
        free(reta->idreta);

    }
    
    free(reta);
}

void retasvg (FILE *svg, Reta reta){
    char *x1 = getx1reta(reta);
    char *y1 = gety1reta(reta);
    char *x2 = getx2reta(reta);
    char *y2 = gety2reta(reta);
    char *corB = getcbreta(reta);

    fprintf(svg, "<line x1 = \"%s\" y1 = \"%s\" x2 = \"%s\" y2 = \"%s\" stroke = \"%s\" stroke-width=\"1\" />\n", x1, y1, x2, y2, corB);
}