#ifndef bfila
#define bfila

typedef struct fila* Fila; 
typedef struct filaposicao* Filaposicao;
typedef void* Filaelemento;

// Cria uma fila
Fila criafila ();

// Retorna o tamanho da fila
int tamanhofila (Fila fila);

// Insere um elemento no final da fila
Filaposicao inserefila (Fila fila, Filaelemento elemento);

// Tira um elemento da fila
void removefila (Fila fila);

// Retorna o elemento da posição posicao na lista
Filaelemento getfila (Fila fila, Filaposicao posicao);

// Retorna o elemento na primeira posição na lista
Filaposicao primeirofila (Fila fila);

// Retorna o elemento antes da posição do elemento posicao na lista
Filaposicao proximofila (Fila fila, Filaposicao posicao);

// Retorna o último elemento da lista
Filaposicao ultimofila (Fila fila);

// Destrói a lista
void destroifila (Fila fila);

#endif