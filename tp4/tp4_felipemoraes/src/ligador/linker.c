#include "linker.h"
#include <stdlib.h>

Object* MakeObjects(char **argv, int argc){
	int i,j;
	int NumberObjects;
	Object *Objects;
	NumberObjects = argc -4;
	j = 0;
	Objects = (Object*) calloc (NumberObjects ,sizeof(Object));
	for (i = 1; i<argc-1; i++){
		if (NOTOPTIONS){
			GetObject(argv[i], &Objects[j]);
			j++;
		}
		else {
			continue;
		}
	}
	return Objects;
}




void GetObject(char *file, Object *object){
	int i;
	FILE *fp;
	TipoItem label;
	FLVazia(&object->SymbolTable);
	FLVazia(&object->ReferenceTable);
	fp = fopen(file, "r");
	fscanf(fp, "%d", &object->SizeSymbolTable);
	for(i = 0; i<object->SizeSymbolTable; i++){
		fscanf(fp, "%s", label.Chave);
		fscanf(fp, "%d", &label.ID);
		Insere(label.Chave,label.ID, &object->SymbolTable);
	}
	fscanf(fp, "%d", &object->SizeReferenceTable);
	for(i = 0; i<object->SizeReferenceTable; i++){
		fscanf(fp, "%s", label.Chave);
		fscanf(fp, "%d", &label.ID);
		Insere(label.Chave,label.ID, &object->ReferenceTable);
	}
	fscanf(fp, "%d", &object->SizeObject);
	object->Body = (int*) calloc (object->SizeObject+1 ,sizeof(int));
	for(i=0;i<=object->SizeObject;i++){
		fscanf(fp, "%d", &object->Body[i]);
	}
	fclose(fp);	
}	


void Allocation(Object *objects, int NumberObjects){
	int i, aux;
	aux = 0;
	for(i = NumberObjects-1; i>=0; i--){
		objects[i].Begin = aux;
		objects[i].End = aux + objects[i].SizeObject;
		aux = objects[i].End + 1;
	}
}

int Reallocation(Object *objects, int NumberObjects){
	int i, seek;
	TipoApontador Aux;/*
	for(i = NumberObjects-1; i>=0; i--){
		Aux = objects[i].ReferenceTable.Primeiro->Prox;
		while (Aux != NULL){
			if (UNDEFINED){
				Aux = Aux->Prox;
			}
			else {
				objects[i].Body[INDICE]+= objects[i].Begin;
				Aux = Aux->Prox;
			}
	    	}
	}*/
	for(i = NumberObjects-1; i>=0; i--){
		Aux = objects[i].ReferenceTable.Primeiro->Prox;
		while (Aux != NULL){
			if (EXTERN_REFERENCE){
				//Procura Nos outros Modulos
				seek = SearchExtern(objects,NumberObjects,Aux->Item.Chave, i, objects[i].Begin);
				if (INEXISTENT){
					printf("ERRO: NAO EXISTE REFERENCIA A %s\n",Aux->Item.Chave);
					return 0;
				}
				else {
					objects[i].Body[INDICE] =  seek - INDICE -1;
					//printf("%s %d\n", Aux->Item.Chave, objects[i].Body[INDICE]);
				}
				
			}
			Aux = Aux->Prox;
	    	}
	}
	return EXIT_SUCCESS;
}

int SearchExtern(Object *objects, int NumberObjects, char *label, int index, int begin){
	int i,ILC;
	for(i = NumberObjects-1; i>=0; i--){
		ILC = SEARCH_SYMBOL;
		if (IS_SYMBOL){
			if (index < i){
				return (ILC + objects[i].Begin - begin);
			}
			else if (index > i){
				return (ILC + objects[i].Begin);
			}
		}
	}
	return 32767;
}

