#ifndef breta
#define breta

#include <stdio.h>

// Guarda as informações da RETA
typedef struct reta* Reta; 

//Cria uma nova reta
Reta criareta (char *x1, char *y1, char *x2, char *y2, char *cbreta, char *idreta);

//Retorna o x1 da reta
char *getx1reta(Reta reta);

//Retorna o y1 da reta
char *gety1reta(Reta reta);

//Retorna o x2 da reta
char *getx2reta(Reta reta);

//Retorna o y2 da reta
char *gety2reta(Reta reta);

//Retorna a cor da reta
char *getcbreta(Reta reta);

//Retorna o ID da reta
char *getidreta(Reta reta);

//Destrói a reta
void destroireta(Reta reta);

//Transforma a reta em SVG
void retasvg (FILE *svg, Reta reta);

//Muda a cor da reta
void setcbreta(Reta reta, char *novacor);

#endif