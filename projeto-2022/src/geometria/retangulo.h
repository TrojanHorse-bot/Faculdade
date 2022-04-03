#ifndef bretangulo
#define bretangulo

#include <stdio.h>

// Guarda as informações do RETÂNGULO
typedef struct retangulo* Retangulo; 

//Cria um novo retângulo
Retangulo criaretangulo (char *x, char *y, char *altura, char *largura, char *cbretangulo, char *cpretangulo, char *idretangulo);

//Retorna o X do retângulo
char *getxretangulo(Retangulo retangulo);

//Retorna o Y do retângulo
char *getyretangulo(Retangulo retangulo);

//Retorna a altura do retângulo
char *getalturaretangulo(Retangulo retangulo);

//Retorna a largura do retângulo
char *getlarguraretangulo(Retangulo retangulo);

//Retorna a cor da borda do retângulo
char *getcbretangulo(Retangulo retangulo);

//Retorna a cor de preenchimento do retângulo
char *getcpretangulo(Retangulo retangulo);

//Retorna o ID do retângulo
char *getidretangulo(Retangulo retangulo);

//Destrói o retângulo
void destroiretangulo(Retangulo retangulo);

//Transforma o retângulo em SVG
void retangulosvg (FILE *svg, Retangulo retangulo);

//Muda a cor da borda do retângulo
void setcbretangulo(Retangulo retangulo, char *novacor);

//Muda a cor de preenchimento do retângulo
void setcpretangulo(Retangulo retangulo, char *novacor);

#endif