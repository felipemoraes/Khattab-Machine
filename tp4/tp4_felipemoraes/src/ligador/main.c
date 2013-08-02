#include <stdlib.h>
#include "linker.h"
#include "lista.h"

int main(int argc, char * argv[])
{	
	int NumberObjects,i,k;
	FILE *fp;
	char M;
	char K;
	int PC,SP;
	PC = 0;
	SP = 1000;
	M = 'M';
	K = 'K';
	fp = fopen(argv[argc-1],"wb");
	Object *Objects;
	if (argc<5){
		printf("ERRO: ARGUMENTOS INSUFICIENTES\n");
		return 0;
	}
	NumberObjects = argc -4;
	Objects = MakeObjects(argv, argc);
	Allocation(Objects,NumberObjects);
	Reallocation(Objects,NumberObjects);
	
	fwrite (&M , sizeof(char),1, fp);
	fwrite (&K , sizeof(char),1, fp);
	fwrite (&PC , sizeof(int),1, fp);
	fwrite (&SP , sizeof(int),1, fp);
	for (i = NumberObjects-1; i>=0; i--){
		for(k = 0; k<=Objects[i].SizeObject; k++){
			fwrite (&Objects[i].Body[k] , sizeof(int),1, fp);
			//printf("%d\n",Objects[i].Body[k]);
		}
		free(Objects[i].Body);
		DesfazLista(&Objects[i].SymbolTable);
		DesfazLista(&Objects[i].ReferenceTable);
	}
	free(Objects);
	fclose(fp);


    return EXIT_SUCCESS;
}

