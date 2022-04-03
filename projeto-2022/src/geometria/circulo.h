#ifndef bcirculo
#define bcirculo

#include <stdio.h>

// Guarda as informações do CÍRCULO
typedef struct circulo* Circulo; 

// Cria um círculo
Circulo criacirculo (char *x, char *y, char *raio, char *cbcirculo, char *cpcirculo, char *idcirculo);

//Retorna o X do círculo
char *getxcirculo(Circulo circulo);

//Retorna o Y do círculo
char *getycirculo(Circulo circulo);

//Retorna o raio do círculo
char *getraiocirculo(Circulo circulo);

//Retorna a cor base do círculo
char *getcbcirculo(Circulo circulo);

//Retorna a cor de preenchimento o círculo
char *getcpcirculo(Circulo circulo);

//Retorna o ID do círculo
char *getidcirculo(Circulo circulo);

//Destrói o círculo
void destroicirculo(Circulo circulo);

//Transforma o círculo em SVG
void circulosvg (FILE *svg, Circulo circulo);

//Muda a cor da borda do círculo
void setcbcirculo(Circulo circulo, char *novacor);

//Muda a cor de preenchimento do círculo
void setcpcirculo(Circulo circulo, char *novacor);

#endif