/*========================================================================================================================================
TRABALHO PRATICO 3 - SOFTWARE BASICO
@FELIPE MORAES GOMES

*EXPANSOR.H - Define as estruturas de dados e cabecalhos de funcoes relacionadas a manipulacao do expansor de Macros
========================================================================================================================================*/

#ifndef EXPANSOR_H
#define EXPANSOR_H
#define ENDMACRO strcmp(word,"ENDMACRO\0")
#define BEGINMACRO strcmp(word, "BEGINMACRO\0")
#define END strcmp(word,"END\0")


#include <stdio.h>

typedef struct Macro {
    char *Label;
    char *Parameter;
    char Body[1000];
} Macro;





void LinkWords(char *line, char *word, int *seek);

int ExtractMacros(char *filename, Macro *Macros);

char* SearchMacro(char *Label_macro, Macro *Macros, char *Parameter, int num);

char* ReplaceParameter(Macro macro, char *Parameter);

void ExpandMacros(char *input, char *output, Macro *Macros, int num);


#endif
