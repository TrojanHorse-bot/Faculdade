#include "lista.h"
#include <stdlib.h>

struct lista{
    Listaposicao primeiro;
    Listaposicao ultimo;
    int tamanho;
};

struct listaposicao{
    Listaposicao proximo;
    Listaposicao anterior;
    Listaelemento elemento;
};

Lista crialista (){
    Lista lista = malloc(sizeof(struct lista));
    if (lista == NULL){
        return NULL;
    }
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    lista->tamanho = 0;
    return lista;
}

int tamanholista (Lista lista){
    if (lista == NULL){
        return -1;
    }
    return lista->tamanho;
}

Listaposicao inserelista (Lista lista, Listaelemento elemento){
    if (lista == NULL || elemento == NULL){
        return NULL;
    }

    Listaposicao posicao = malloc(sizeof(struct listaposicao));
    if (posicao == NULL ){
        return NULL;
    }

    posicao->proximo = NULL;
    posicao->anterior = ultimolista(lista);
    posicao->elemento = elemento;

    Listaposicao ultimo = ultimolista(lista);
    lista->ultimo = posicao;

    if (ultimo != NULL){
        ultimo->proximo = posicao;
    }else{
        lista->primeiro = posicao;
    }

    lista->tamanho++;
    return posicao;
}

void removelista (Lista lista, Listaposicao posicao){
    if (lista == NULL || posicao == NULL){
        return;
    }
    Listaposicao guardaanterior = anteriorlista(lista, posicao);
    Listaposicao guardaproximo = proximolista(lista, posicao);
    if (guardaproximo != NULL){
        guardaproximo->anterior = guardaanterior;
    }
    if (guardaanterior != NULL){
        guardaanterior->proximo = guardaproximo;
    }
    if (posicao == primeirolista(lista)){
        lista->primeiro = guardaproximo;
    }
    if (posicao == ultimolista(lista)){
        lista->ultimo = guardaanterior;
    }
    free(posicao);
    lista->tamanho--;
}

Listaelemento getlista (Lista lista, Listaposicao posicao){
    if (lista == NULL || posicao == NULL){
        return NULL;
    }
    return posicao->elemento;
}

Listaposicao insereanteslista (Lista lista, Listaposicao posicao, Listaelemento elemento){
    if (lista == NULL || posicao == NULL || elemento == NULL){
        return NULL;
    }

    Listaposicao novaposicao = malloc(sizeof(struct listaposicao));
    if (novaposicao == NULL ){
        return NULL;
    }

    novaposicao->elemento = elemento;
    novaposicao->proximo = posicao;
    Listaposicao anterior = anteriorlista(lista, posicao);
    posicao->anterior = novaposicao;
    if (posicao == primeirolista(lista)){
        lista->primeiro = novaposicao;
        novaposicao->anterior = NULL;
    }else{
        anterior->proximo = novaposicao;
        novaposicao->anterior = anterior;
    }

    lista->tamanho++;
    return novaposicao;
}

Listaposicao inseredepoislista (Lista lista, Listaposicao posicao, Listaelemento elemento){
    if (lista == NULL || posicao == NULL || elemento == NULL){
        return NULL;
    }

    Listaposicao novaposicao = malloc(sizeof(struct listaposicao));
    if (novaposicao == NULL ){
        return NULL;
    }

    novaposicao->elemento = elemento;
    novaposicao->anterior = posicao;
    Listaposicao proximo = proximolista(lista, posicao);
    posicao->proximo = novaposicao;
    if (posicao == ultimolista(lista)){
        lista->ultimo = novaposicao;
        novaposicao->proximo = NULL;
    }else{
        proximo->anterior = novaposicao;
        novaposicao->proximo = proximo;
    }

    lista->tamanho++;
    return novaposicao;
}

Listaposicao primeirolista (Lista lista){
    if (lista == NULL){
        return NULL;
    }
    return lista->primeiro;
}

Listaposicao proximolista (Lista lista, Listaposicao posicao){
    if (lista == NULL || posicao == NULL){
        return NULL;
    }
    return posicao->proximo;
}

Listaposicao ultimolista (Lista lista){
    if (lista == NULL){
        return NULL;
    }
    return lista->ultimo;
}

Listaposicao anteriorlista (Lista lista, Listaposicao posicao){
    if (lista == NULL || posicao == NULL){
        return NULL;
    }
    return posicao->anterior;
}

void destroilista (Lista lista){
    if (lista == NULL){
        return;
    }

    Listaposicao auxiliar = primeirolista(lista);
    while (auxiliar != NULL){
        removelista (lista, auxiliar);
        auxiliar = primeirolista (lista);
    }
     
    free (lista);
}
