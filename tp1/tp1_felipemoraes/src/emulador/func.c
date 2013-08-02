/*========================================================================================================================================
TRABALHO PRATICO 1 - SOFTWARE BASICO
@FELIPE MORAES GOMES

*FUNC.C - Define funcoes basicas do trabalho
========================================================================================================================================*/

#include "func.h"

/*
 *Carrega dados do arquivo de entrada
 Argumentos:
 * file_name - Nome do arquivo binario de entrada padrao do trabalho
*/
int Load(char *file_name){

    FILE *fin;
    fin = fopen(file_name,"rb+");
    char M,K;
    fread(&M,sizeof(char),1,fin);
    fread(&K,sizeof(char),1,fin);
    if (M != 'M'){
        return 0;
    }
    if (K != 'K'){
        return 0;
    }
    fread(&PC,sizeof(int),1,fin);
    fread(&SP,sizeof(int),1,fin);
    int i;
    for (i=0;i<1000;i++){
        fread(&memory[i],sizeof(int),1,fin);
          }
    fclose(fin);
    return 1;
}

/*
 *Executa instrucao do formato code
 Argumentos:
 * code - Instrucao a ser executada
*/
int Execute(int code){
        int op1,op2,input;
        switch( code ){
            case(1):
                op1 = memory[PC];
                PC = PC + 1;
                op2 = memory[PC];
                PC = PC + 1;
                reg[op1] = memory[op2 + PC];
                break;
            case(2):
                op1 = memory[PC];
                PC = PC + 1;
                op2 = memory[PC];
                PC = PC + 1;
                memory[op2 + PC] = reg[op1];
                break;
            case(3):
                op1 = memory[PC];
                PC = PC + 1;
                scanf("%d",&input);
                reg[op1] = input;
                break;
            case(4):
                op1 = memory[PC];
                PC = PC + 1;
                printf("%d\n",reg[op1]);
                break;
            case(5):
                op1 = memory[PC];
                PC = PC + 1;
                op2 = memory[PC];
                PC = PC + 1;
                reg[op1] = reg[op2];
                PSW[0] = '0';
                PSW[1] = '0';
                if (reg[op1] == 0){
                        PSW[0] = '1';
                }
                else if (reg[op1] < 0){
                        PSW[1] = '1';
                }
                break;
            case(6):
                op1 = memory[PC];
                PC = PC + 1;
                op2 = memory[PC];
                PC = PC + 1;
                reg[op1] += reg[op2];
                PSW[0] = '0';
                PSW[1] = '0';
                if (reg[op1] == 0){
                        PSW[0] = '1';
                }
                else if (reg[op1] < 0){
                        PSW[1] = '1';
                }
                break;
            case(7):
                op1 = memory[PC];
                PC = PC + 1;
                op2 = memory[PC];
                PC = PC + 1;
                reg[op1] -= reg[op2];
                PSW[0] = '0';
                PSW[1] = '0';
                if (reg[op1] == 0){
                        PSW[0] = '1';
                }
                else if (reg[op1] < 0){
                        PSW[1] = '1';
                }
                break;
            case(8):
                op1 = memory[PC];
                PC = PC + 1;
                op2 = memory[PC];
                PC = PC + 1;
                reg[op1] = reg[op1] & reg[op2];
                PSW[0] = '0';
                PSW[1] = '0';
                if (reg[op1] == 0){
                        PSW[0] = '1';
                }
                else if (reg[op1] < 0){
                        PSW[1] = '1';
                }
                break;
            case(9):
                op1 = memory[PC];
                PC = PC + 1;
                op2 = memory[PC];
                PC = PC + 1;
                reg[op1] = reg[op1] | reg[op2];
                PSW[0] = '0';
                PSW[1] = '0';
                if (reg[op1] == 0){
                        PSW[0] = '1';
                }
                else if (reg[op1] < 0){
                        PSW[1] = '1';
                }
                break;
            case(10):
                op1 = memory[PC];
                PC = PC + 1;
                op2 = memory[PC];
                PC = PC + 1;
                reg[op1] = reg[op1] ^ reg[op2];
                PSW[0] = '0';
                PSW[1] = '0';
                if (reg[op1] == 0){
                        PSW[0] = '1';
                }
                else if (reg[op1] < 0){
                        PSW[1] = '1';
                }
                break;
            case(11):
                op1 = memory[PC];
                PC = PC + 1;
                reg[op1]= ~(reg[op1]);
                PSW[0] = '0';
                PSW[1] = '0';
                if (reg[op1] == 0){
                        PSW[0] = '1';
                }
                else if (reg[op1] < 0){
                        PSW[1] = '1';
                }
                break;
            case(12):
                op1 = memory[PC];
                PC = PC + 1;
                PC = PC + op1;
                break;
            case(13):
                op1 = memory[PC];
                PC = PC + 1;
                if (PSW[0] == '1'){
                    PC = PC + op1;
                }
                break;
            case(14):
                op1 = memory[PC];
                PC = PC + 1;
                if (PSW[0] != '1'){
                    PC = PC + op1;
                }

                break;
            case(15):
                op1 = memory[PC];
                PC = PC + 1;
                if (PSW[1] == '1'){
                    PC = PC + op1;
                }
                break;
            case(16):
                op1 = memory[PC];
                PC = PC + 1;
                if (PSW[1] != '1'){
                    PC = PC + op1;
                }
                break;
            case(17):
                SP = SP - 1;
                op1 = memory[PC];
                PC = PC +1;
                memory[SP] = reg[op1];
                break;
            case(18):
                op1 = memory[PC];
                PC = PC +1;
                reg[op1] = memory[SP];
                SP = SP +1;
                break;
            case(19):
                op2 = memory[PC];
                PC = PC +1;
                SP = SP -1;
                memory[SP] = PC;
		PC = PC + op2;
                break;
            case(20):
                PC = memory[SP];
                SP = SP + 1;
                break;
            case(21):
                return 1;
        }
    return 0;
}
