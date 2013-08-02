/*========================================================================================================================================
TRABALHO PRATICO 3 - SOFTWARE BASICO
@FELIPE MORAES GOMES

*MAIN.C - Algoritmo principal do trabalho pratico
========================================================================================================================================*/

#include <stdlib.h>
#include <string.h>
#include "expander.h"
#include "io.h"




int main(int argc, char * argv[])
{
    //Verifica argumentos
    int N_Macros,i;
    if (argc<2){
        printf("ERRO: ARGUMENTOS INSUFICIENTES\n");
        return 0;
    }
    Macro Macros[1000];
    //Extrai macros - passo um
    N_Macros = ExtractMacros(argv[1],Macros);
    //Expande macros - passo dois
    ExpandMacros(argv[1], argv[2], Macros, N_Macros);
    //Desaloca macros
    for(i = 0; i<N_Macros ; i++){
        free(Macros[i].Label);
        free(Macros[i].Parameter);
    }

    return EXIT_SUCCESS;
}

