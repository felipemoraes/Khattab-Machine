/*========================================================================================================================================
TRABALHO PRATICO 3 - SOFTWARE BASICO
@FELIPE MORAES GOMES

*EXPANSOR.C - Define as funcoes relacionadas a manipulacao do expansor de Macros
========================================================================================================================================*/

#include <stdlib.h>
#include <string.h>
#include "expander.h"
#include "io.h"

//Liga Palavras
void LinkWords(char *line, char *word, int *seek){
    int len,i,j;
    len = 0;
    len = (int) strlen(word);
    j = 0;
    for(i=(*seek); i<*seek+len;i++){
        line[i] = word[j];
        j++;
    }
    *seek = *seek + len;
}
//Extrai macros
int ExtractMacros(char *fileLabel, Macro *Macros){
    char *line;
    char *word;
    int end, seek, n;
    n = 0;
    seek = 0;
    FILE *fin;
    fin = fopen(fileLabel, "r");
//Enquanto nao for fim de arquivo
    while (!feof(fin)) {
        line = Readline(fin);
        word = NextWord(line);
        if (word == NULL)
            continue;
        else if (END==0){
            free(word);
            break;
        }
        end = (int) strlen(word);
        if (word[end-1] == ':'){
            word[end-1] = '\0';
            Macros[n].Label = word;
            word = NextWord(line);
            if (BEGINMACRO == 0){
		//Se encontrar palavra BEGINMACRO, armazena macro
                word = NextWord(line);
                Macros[n].Parameter = word;
                free(line);
                line = Readline(fin);
                word = NextWord(line);
                while(1){
                    if (word == NULL){
                        free(line);
                        line = Readline(fin);
                        word = NextWord(line);
                        LinkWords(Macros[n].Body, "\n", &seek);
                    }
                    else {
                        if (ENDMACRO == 0){
                            free(word);
                            break;
                        }
                        LinkWords(Macros[n].Body, word, &seek);
                        free(word);
                        LinkWords(Macros[n].Body, " ", &seek);
                        word = NextWord(line);
                    }
                }
                Macros[n].Body[seek] = '\0';
                n++;
                seek=0;
            }
            free(line);
        }
    }
    fclose(fin);
    return n;
}


//Substitui parametros da macro
char* ReplaceParameter(Macro macro, char *Parameter){
    char macro_Body[1000];
    char *word;
    char line[1000];
    int i,j,len, seek;
    seek = 0;
    len = 0;
    len = (int)strlen(macro.Body);
    for(i=0; i<len; i++){
        if (macro.Body[i] == '\n' ){
            line[j] = '\n';
            j=0;
            word = NextWord(line);
            while (word!=NULL){
		//Procura por parametro
                if (strcmp(macro.Parameter,word)==0){
                    LinkWords(macro_Body, Parameter, &seek);
                    LinkWords(macro_Body, " ", &seek);
                }
                else{
                    LinkWords(macro_Body, word, &seek);
                    LinkWords(macro_Body, " \0", &seek);
                }
                word = NextWord(line);
            }
            LinkWords(macro_Body, "\n\0", &seek);
        }
        else {
            line[j] = macro.Body[i];
            j++;
        }
    }
    macro_Body[seek] = '\0';
    return macro_Body;
}

//Procura e retorna macro
char* SearchMacro(char *Label_macro, Macro *Macros, char *Parameter, int num){
    int i;
    for(i=0; i<num; i++){
        if (strcmp(Macros[i].Label, Label_macro) == 0){
            if (Macros[i].Parameter != NULL){
                return ReplaceParameter(Macros[i], Parameter);
            }
            else {
                return Macros[i].Body;
            }

        }
    }
    return NULL;
}
//Expande macros e salva arquivo de saida
void ExpandMacros(char *input, char *output, Macro *Macros, int num){
    char *line;
    char *word;
    char *word_aux;
    char *macro;
    char *Parameter;
    int end;
    FILE *fin,*fout;
    //Abre arquivos
    fin = fopen(input, "r");
    fout = fopen(output,"w");
    while (!feof(fin)) {
	//Le proxima linha
        line = Readline(fin);
        word_aux = NextWord(line);
        if (word_aux == NULL)
            continue;
        else if (strcmp(word_aux,"END\0")==0)
            break;
        end = (int) strlen(word_aux);
	//Se for label
        if (word_aux[end-1] == ':'){
             word = NextWord(line);
             if (BEGINMACRO == 0){
                line = Readline(fin);
                word = NextWord(line);
                 while(1){
                    if (word == NULL){
                        line = Readline(fin);
                        word = NextWord(line);
                    }
                    else {
                        if (ENDMACRO == 0)
                            break;
                        word = NextWord(line);
                    }
                 }
             }
		//Se for uma instrucao ou chamada de macro
             else {
                fprintf(fout,"%s ",word_aux);
                Parameter = NextWord(line);
                macro = SearchMacro(word, Macros, Parameter, num);
                if (macro !=NULL){
                    fprintf(fout,"%s",macro);
                }
		//Se nao for macro imprime linha até o fim
                else {
                    fprintf(fout,"%s ",word);
                    if (Parameter !=NULL)
                        fprintf(fout,"%s ",Parameter);
                    word = NextWord(line);
                    while (word != NULL){
                        fprintf(fout,"%s ",word);
                        word = NextWord(line);
                    }
                    fprintf(fout,"\n");
                }
             }
        }
	//Quando nao for label
        else{
            word = NextWord(line);
            macro = SearchMacro(word_aux, Macros, word, num);
            if (macro !=NULL){
                fprintf(fout,"%s",macro);
            }
	    //Se nao for macro
            else{
                fprintf(fout,"%s ",word_aux);
                if (word !=NULL)
                    fprintf(fout,"%s ",word);
                word = NextWord(line);
                while (word != NULL){
                    fprintf(fout,"%s ",word);
                    word = NextWord(line);
                }
                fprintf(fout,"\n");
            }
        }
    }
    //Fecha arquivos
    fprintf(fout,"END\n");
    fclose(fin);
    fclose(fout);
}

