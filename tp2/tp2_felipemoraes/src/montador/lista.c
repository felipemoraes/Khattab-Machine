/*========================================================================================================================================
TRABALHO PRATICO 2 - SOFTWARE BASICO
@FELIPE MORAES GOMES

*LISTA.C - Define funcoes relacionadas a manipulacao de um TAD lista implementada atraves de apontadores
========================================================================================================================================*/

#include "lista.h"
#include <stdlib.h>
#include <string.h>
/*
*Faz a lista vazia
*Parametros:
*	*lista
*/

void FLVazia(TipoLista *Lista)
{ Lista->Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
  Lista->Ultimo = Lista->Primeiro;
  Lista->Primeiro->Prox = NULL;
}

/*
*Verifica se a lista esta vazia
*Parametros:
*	* lista
*/

short Vazia(TipoLista Lista)
{ return (Lista.Primeiro == Lista.Ultimo);
}

/*
*Insere um item generico na lista
*Parametros:
*	* lista
*	* item - item a ser inserido
*/

void Insere(TipoItem *x, TipoLista *Lista)
{ /*-- Insere depois do ultimo item da lista --*/
  Lista->Ultimo->Prox = (TipoApontador)malloc(sizeof(TipoCelula));
  Lista->Ultimo = Lista->Ultimo->Prox;
  Lista->Ultimo->Item = *x;
  Lista->Ultimo->Prox = NULL;
}

/*
*Remove um item da lista, retorna um apontador para o item removido
*Parametros:
*	*lista
*	*item_anterior - apontador para a celula do item anterior ao que deve ser removido
*/

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item)
{ /*--Obs.: item a ser retirado e o seguinte ao apontado por p--*/
  TipoApontador q;
  if (Vazia(*Lista) || p == NULL || p->Prox == NULL)
  { printf("Erro: Lista vazia ou posicao nao existe\n");
    return;
  }
  q = p->Prox;
  *Item = q->Item;
  p->Prox = q->Prox;
  if (p->Prox == NULL) Lista->Ultimo = p;
  free(q);
}
/*
 *Desfaz uma lista encadeada por apontadores
 *Parametros:
 * Lista
*/

int Busca(char *Chave, TipoLista Lista){
    TipoApontador Aux;
    Aux = Lista.Primeiro->Prox;
    while (Aux != NULL){
        if(strcmp(Aux->Item.Chave, Chave)==0)
            return Aux->Item.ID;
      Aux = Aux->Prox;
    }
    return 0;
}
void DesfazLista(TipoLista *Lista){
	TipoApontador Aux;
	TipoItem Item;
	Aux=Lista->Primeiro;
	while(!Vazia(*Lista)){
		if(Aux!=NULL){
		while(Aux->Prox->Prox!=NULL){
		Aux=Aux->Prox;
		}
		Retira(Aux,Lista,&Item);
		Aux=Lista->Primeiro;
		}
	}
	free(Lista->Primeiro);
}


/*
 * Aloca arranjo do TipoLista
 *Parametros
 * n - numero de listas
*/

TipoLista* AlocaListas(int n){
	int i;
	TipoLista *Lista;
	Lista=(TipoLista*)calloc(n,sizeof(TipoLista));
	for(i=0;i<n;i++)
		FLVazia(&Lista[i]);

	return Lista;

}

/* Desaloca arranjo do TipoLista
 *Parametros
 * n - numero de listas
 * *Lista - arranjo do tipo lista
*/

void DesalocaListas(int n, TipoLista *Lista){
	int i;
	for(i=0;i<n;i++)
		DesfazLista(&Lista[i]);

	free(Lista);
}


/*
*Imprime os items armazenados na fila
*Parametros:
*	* lista
*
*/

void ImprimeLista(TipoLista Lista)
{ TipoApontador Aux;
  Aux = Lista.Primeiro->Prox;
  while (Aux != NULL)
    { printf("%s    %d\n", Aux->Item.Chave, Aux->Item.ID);
      Aux = Aux->Prox;
    }
}
