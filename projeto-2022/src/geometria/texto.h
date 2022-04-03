#ifndef btexto
#define btexto

#include <stdio.h>

// Guarda as informações do TEXTO
typedef struct texto* Texto; 

// Cria um novo texto
Texto criatexto (char *x, char *y, char *txt, char *cbtexto, char *cptexto, char *ancoratexto, char *idtexto);

// Retorna o X do texto
char *getxtexto(Texto texto);

// Retorna o Y do texto
char *getytexto(Texto texto);

// Retorna o que está escrito no texto
char *gettxttexto(Texto texto);

// Retorna a cor da borda do texto
char *getcbtexto(Texto texto);

// Retorna a cor de preenchimento do texto
char *getcptexto(Texto texto);

// Retorna a âncora do texto
char *getancoratexto(Texto texto);

// Retorna o ID do texto
char *getidtexto(Texto texto);

// Destrói o texto
void destroitexto(Texto texto);

// Transforma o texto em um SVG
void textosvg (FILE *svg, Texto texto);

// Muda a cor da borda do texto
void setcbtexto(Texto texto, char *novacor);

// Muda a cor de preenchimento do texto
void setcptexto(Texto texto, char *novacor);

#endif