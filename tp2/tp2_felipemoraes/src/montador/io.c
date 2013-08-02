/*========================================================================================================================================
TRABALHO PRATICO 2 - SOFTWARE BASICO
@FELIPE MORAES GOMES

*IO.C - Define funcoes basicas de Entrada e Saida
========================================================================================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* readline(FILE *file){
    int CUR_MAX = 4095;
    char *buffer = (char*) calloc(CUR_MAX,sizeof(char)); // allocate buffer.
    int count = 0;
    int length = 0;
    char ch='A';
    while ( (ch != '\n') && (ch != EOF) ) {
        if(count ==CUR_MAX) { // time to expand ?
            CUR_MAX *= 2; // expand to double the current size of anything similar.
            count = 0;
            buffer = realloc(buffer, CUR_MAX); // re allocate memory.
        }
        ch = getc(file); // read from stream.
        buffer[length] = ch; // stuff in buffer.
        length++;
        count++;
    }
    return buffer;
}

char* next_word(char *line){
    char *word;
    int i,j,count;
    i = 0;
    while (1){
        if (line[i]==' ' || line[i]=='\t' || line[i]=='\0' || line[i]=='\r'){
            line[i] = ' ';
            i++;
        }
        else if (line[i]=='\n' || line[i]==';' || line[i] == EOF){
            if (line[i] == ';'){
                while (line[i]!='\n'){
                    line[i] = ' ';
                    i++;
                }
            }
            word = (char*) calloc (1,sizeof(char));
            word = '\0';
            break;
        }
        else{
            count = 0;
            while (line[i]!=' ' && line[i]!='\t' && line[i]!='\n' && line[i]!='\r' ){
                i++;
                count++;
            }
            i -= count;
            word = (char*)calloc(count+1,sizeof(char));
            j = 0;
            while (line[i]!=' ' && line[i]!='\t' && line[i]!='\n' && line[i]!='\r' ){
                word[j] = line[i];
                line[i] = ' ';
                i++;
                j++;
            }
            word[j] = '\0';
            break;
        }

    }
    return word;
}


char** split_line(char *line){
    char *split;
    char **list;
    int i=0;
    int n;
    list = (char**) calloc(10,sizeof(char*));
    split = strtok(line,"\n\t");
    split = strtok(split," ");
    while (split != NULL){
        if (split[0] !=';'){
            if ((split[0] !='\n')&&(split[0] !=EOF)){
                n = strlen(split);
                list[i] = (char*) calloc(n, sizeof(char));
                strcpy(list[i], split);
                i++;
            }
        }
        else {
            break;
        }
        split = strtok (NULL, " ");
    }
    return list;
}
