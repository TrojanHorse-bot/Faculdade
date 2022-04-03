#include "texto.h"
#include <stdlib.h>
#include <string.h>

struct texto{
    char *x;
    char *y;
    char *txt;
    char *cbtexto; 
    char *cptexto;
    char *ancoratexto;
    char *idtexto;
};

Texto criatexto (char *x, char *y, char *txt, char *cbtexto, char *cptexto, char *ancoratexto, char *idtexto){
    Texto texto = malloc(sizeof(struct texto));

    if (texto == NULL){
        return NULL;
        
    }
    
    texto->x = malloc(strlen(x)+1);
    texto->y = malloc(strlen(y)+1);
    texto->txt = malloc(strlen(txt)+1);
    texto->cbtexto = malloc(strlen(cbtexto)+1);
    texto->cptexto = malloc(strlen(cptexto)+1);
    texto->ancoratexto = malloc(strlen(ancoratexto)+1);
    texto->idtexto = malloc(strlen(idtexto)+1);

    strcpy(texto->x,x);
    strcpy(texto->y,y);
    strcpy(texto->txt,txt);
    strcpy(texto->cbtexto,cbtexto);
    strcpy(texto->cptexto,cptexto);
    strcpy(texto->ancoratexto,ancoratexto);
    strcpy(texto->idtexto,idtexto);

    if (texto->x == NULL || texto->y == NULL || texto->txt == NULL || texto->cbtexto == NULL || texto->cptexto == NULL || texto->ancoratexto == NULL || texto->idtexto == NULL){
        destroitexto(texto);
        return NULL;
    }

    return texto;
}

char *getxtexto(Texto texto){
    if (texto == NULL){
        return NULL;
    }

    return texto->x;

}

char *getytexto(Texto texto){
    if (texto == NULL){
        return NULL;
    }

    return texto->y;

}

char *getancoratexto(Texto texto){
    if (texto == NULL){
        return NULL;
    }

    return texto->ancoratexto;

}

char *gettxttexto(Texto texto){
    if (texto == NULL){
        return NULL;
    }

    return texto->txt;

}

char *getcbtexto(Texto texto){
    if (texto == NULL){
        return NULL;
    }

    return texto->cbtexto;

}

char *getcptexto(Texto texto){
    if (texto == NULL){
        return NULL;
    }

    return texto->cptexto;

}

void setcbtexto(Texto texto, char *novacor){ // Atualizando a cor
    if (texto == NULL || novacor == NULL){
        return;
    }
    texto->cbtexto = realloc(texto->cbtexto, strlen(novacor)+1);
    strcpy(texto->cbtexto, novacor);
}

void setcptexto(Texto texto, char *novacor){ // Atualizando a cor
    if (texto == NULL || novacor == NULL){
        return;
    }
    texto->cptexto = realloc(texto->cptexto, strlen(novacor)+1);
    strcpy(texto->cptexto, novacor);
}

char *getidtexto(Texto texto){
    if (texto == NULL){
        return NULL;
    }

    return texto->idtexto;

}

void destroitexto(Texto texto){
    if (texto == NULL){
        return;
    }
    if (texto->x){
        free(texto->x);
    }
    if (texto->y){
        free(texto->y);
    }
    if (texto->txt){
        free(texto->txt);
    }
    if (texto->cbtexto){
        free(texto->cbtexto);
    }
    if (texto->cptexto){
        free(texto->cptexto);
    }
    if (texto->idtexto){
        free(texto->idtexto);
    }
    
    free(texto);

}

void textosvg (FILE *svg, Texto texto){

    char *x = getxtexto(texto);
    char *y = getytexto(texto);
    char *txt = gettxttexto(texto);
    char *corB = getcbtexto(texto);
    char *corP = getcptexto(texto);

    fprintf(svg, "<text x=\"%s\" y=\"%s\" stroke=\"%s\" fill=\"%s\" font-size=\"23\">%s</text>", x, y, corB, corP, txt);
}