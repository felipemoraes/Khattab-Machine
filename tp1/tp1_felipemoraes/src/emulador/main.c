/*========================================================================================================================================
TRABALHO PRATICO 1 - SOFTWARE BASICO
@FELIPE MORAES GOMES

*MAIN.C - Algoritmo principal do trabalho pratico
========================================================================================================================================*/

#include <stdlib.h>
#include <stdio.h>
#include "func.h"


int main(int argc, char * argv[])
{
    int halt = 0;
    int code;
    char mode;
    if (argc == 2)
        mode = 's';
    else if (argc<2){
        printf("ERRO: ARGUMENTOS INSUFICIENTES\n");
        return 0;
    }
    else
        mode = argv[2][0];
    Load(argv[1]);
    PSW[0]='0';
    PSW[1]='0';
    while(halt == 0){
        code = memory[PC];
	if (mode == 'v'){
		printf("PC = %d, SP = %d, PSW = %c %c, instruction %d\n",PC,SP,PSW[0],PSW[1],code);
        printf("Register R0 R1 R2 R3 R4 R5 R6 R7\n");
        printf("         %d  %d  %d  %d  %d  %d  %d  %d\n",reg[0],reg[1],reg[2],reg[3],reg[4],reg[5],reg[6], reg[7]);
	}
        PC = PC + 1;
        halt = Execute(code);
    }
    return EXIT_SUCCESS;
}

