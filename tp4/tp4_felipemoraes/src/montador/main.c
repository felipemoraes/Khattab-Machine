/*========================================================================================================================================
TRABALHO PRATICO 2 - SOFTWARE BASICO
@FELIPE MORAES GOMES

*MAIN.C - Algoritmo principal do trabalho pratico
========================================================================================================================================*/

#include <stdlib.h>
#include "lista.h"
#include "assembler.h"
#include <string.h>



int main(int argc, char * argv[])
{
    //Verifica argumentos
    char mode;
    if (argc == 3)
        mode = 's';
    else if (argc<3){
        printf("ERRO: ARGUMENTOS INSUFICIENTES\n");
        return 0;
    }
    else
        mode = argv[3][0];
    TipoLista symbol_table,opcode_table,size_table, reference_table;
    // Carrega tabelas
    FLVazia(&symbol_table);
    FLVazia(&opcode_table);
    FLVazia(&size_table);
    FLVazia(&reference_table);
    create_opcode_table(&opcode_table);
    create_size_table(&size_table);
    //Realiza o primeiro passo do montador
    Primeiro_Passo(argv[1],&symbol_table,&opcode_table,&size_table);
    //Realiza o segundo passo do montador
    Segundo_Passo(argv[1],argv[2], &symbol_table,&opcode_table, &size_table, &reference_table);
    //Imprime Tabela de Simbolos se o modo de saida for verbose
    if  (mode == 'v'){
        printf("Simbolo ILC\n");
        //ImprimeLista(symbol_table);
    }
    //Desfaz listas
    DesfazLista(&symbol_table);
    DesfazLista(&opcode_table);
    DesfazLista(&size_table);
    DesfazLista(&reference_table);
    return EXIT_SUCCESS;
}

