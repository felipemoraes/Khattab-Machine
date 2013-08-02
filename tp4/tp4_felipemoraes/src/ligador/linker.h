#include <stdio.h>
#include <string.h>
#include "lista.h"

#define NOTOPTIONS !((strcmp(argv[i],"-m") == 0) || (strcmp(argv[i],"-o") == 0))
#define INDICE Aux->Item.ID
#define UNDEFINED (objects[i].Body[INDICE] == 32767)
#define EXTERN_REFERENCE (Busca(Aux->Item.Chave, objects[i].SymbolTable) == 32767)
#define SEARCH_SYMBOL Busca(label, objects[i].SymbolTable)
#define IS_SYMBOL ILC != 32767
#define INEXISTENT seek == 32767

typedef struct Object {
	int SizeReferenceTable;
	int SizeSymbolTable;
	int SizeObject;
	int *Body;
	int Begin;
	int End;
	TipoLista SymbolTable;
	TipoLista ReferenceTable;
} Object;



void GetObject(char *file, Object *object);

Object* MakeObjects(char **argv, int argc);

void Allocation(Object *object, int NumberObjects);

int Reallocation(Object *object, int NumberObjects);

int SearchExtern(Object *objects, int NumberObjects, char *label, int index, int begin);
