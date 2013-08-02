/*========================================================================================================================================
TRABALHO PRATICO 2 - SOFTWARE BASICO
@FELIPE MORAES GOMES

*ASSEMBLER.H - Define cabeçalho das funcoes do Montador
========================================================================================================================================*/

#include <stdio.h>
#include "lista.h"
#ifndef ASSEMBLER_H
#define ASSEMBLER_H

void insert_opcode(TipoLista *opcode_table, char* opcode, int code);

void create_opcode_table(TipoLista *opcode_table);

void create_size_table(TipoLista *opcode_table);

void Primeiro_Passo(char* filename, TipoLista *symbol_table, TipoLista *opcode_table, TipoLista *size_table);


void Segundo_Passo(char* filename, char* output, TipoLista *symbol_table, TipoLista *opcode_table, TipoLista *size_table);

int Decode(char *line, TipoLista symbol_table, TipoLista opcode_table, int *PC, int *memory);
#endif
