#ifndef blista
#define blista

typedef struct lista* Lista; 
typedef struct listaposicao* Listaposicao;
typedef void* Listaelemento;

// Cria a lista
Lista crialista ();

// Retorna o tamanho da lista
int tamanholista (Lista lista);

// Insere um elemento no final da lista
Listaposicao inserelista (Lista lista, Listaelemento elemento);

// Remove o elemento da posição posicao da lista
void removelista (Lista lista, Listaposicao posicao);

// Retorna o elemento da posição posicao da lista
Listaelemento getlista (Lista lista, Listaposicao posicao);

// Insere um elemento antes da posição posicao da lista
Listaposicao insereanteslista (Lista lista, Listaposicao posicao, Listaelemento elemento);

// Insere um elemento depois da posição posicao da lista
Listaposicao inseredepoislista (Lista lista, Listaposicao posicao, Listaelemento elemento);

// Retorna o primeiro elemento da lista
Listaposicao primeirolista (Lista lista);

// Retorna o elemento que está depois da posição posicao
Listaposicao proximolista (Lista lista, Listaposicao posicao);

// Retorna o último elemento da lista
Listaposicao ultimolista (Lista lista);

// Retorna o elemento anterior à posição posicao
Listaposicao anteriorlista (Lista lista, Listaposicao posicao);

// Destrói a lista
void destroilista (Lista lista);

#endif