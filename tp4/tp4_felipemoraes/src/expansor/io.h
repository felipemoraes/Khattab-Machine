/*========================================================================================================================================
TRABALHO PRATICO 3 - SOFTWARE BASICO
@FELIPE MORAES GOMES

*IO.H - Define cabeçalho das funcoes basicas de Entrada e Saida
========================================================================================================================================*/
#ifndef IO_H
#define IO_H

char* Readline(FILE *file);

char* NextWord(char *line);

char** split_line(char *line);



#endif
