#include "fila.h"
#include <stdlib.h>

struct fila{
    Filaposicao primeiro;
    Filaposicao ultimo;
    int tamanho;
};

struct filaposicao{
    Filaposicao proximo;
    Filaelemento elemento;
};

Fila criafila (){
    Fila fila = malloc(sizeof(struct fila));
    if (fila == NULL){
        return NULL;
    }
    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->tamanho = 0;
}

int tamanhofila (Fila fila){
    if (fila == NULL){
        return -1;
    }
    return fila->tamanho;
}

Filaposicao inserefila (Fila fila, Filaelemento elemento){
    if (fila == NULL || elemento == NULL){
        return NULL;
    }

    Filaposicao posicao = malloc(sizeof(struct filaposicao)); // Aloca espaço
    if (posicao == NULL ){
        return NULL;
    }

    posicao->proximo = NULL;
    posicao->elemento = elemento;

    Filaposicao ultimo = ultimofila(fila);

    if (ultimo != NULL){
        ultimo->proximo = posicao;
    }else{
        fila->primeiro = posicao;
    }
    
    fila->ultimo = posicao;
    fila->tamanho++;
    return posicao;
}

void removefila (Fila fila){
    if (fila == NULL || tamanhofila(fila) == 0){
        return;
    }
    Filaposicao guardaprimeiro = primeirofila(fila);
    Filaposicao guardaproximo = proximofila(fila, guardaprimeiro);
    fila->primeiro = guardaproximo;
    if (guardaproximo == NULL){
        fila->ultimo = NULL;
    }
    free(guardaprimeiro);
    fila->tamanho--;
}

Filaelemento getfila (Fila fila, Filaposicao posicao){
    if (fila == NULL || posicao == NULL){
        return NULL;
    }
    return posicao->elemento;
}

Filaposicao primeirofila (Fila fila){
    if (fila == NULL){
        return NULL;
    }
    return fila->primeiro;
}

Filaposicao proximofila (Fila fila, Filaposicao posicao){
    if (fila == NULL || posicao == NULL){
        return NULL;
    }
    return posicao->proximo;
}

Filaposicao ultimofila (Fila fila){
    if (fila == NULL){
        return NULL;
    }
    return fila->ultimo;
}

void destroifila (Fila fila){
    if (fila == NULL){
        return;
    }

    while (tamanhofila(fila) != 0){
        removefila(fila);
    }
    
    free (fila);
}
