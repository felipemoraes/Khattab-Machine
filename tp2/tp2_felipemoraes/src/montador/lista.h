/*========================================================================================================================================
TRABALHO PRATICO 2 - SOFTWARE BASICO
@FELIPE MORAES GOMES

*LISTA.H - Define as estruturas de dados e cabecalhos de funcoes relacionadas a manipulacao de um TAD lista implementada atraves de apontadores
========================================================================================================================================*/

#ifndef LISTA_H
#define LISTA_H

typedef struct TipoItem {
    char* Chave;
    int ID;
}TipoItem;

typedef struct TipoCelula *TipoApontador;

struct TipoCelula {
    TipoItem Item;
    TipoApontador Prox;
}TipoCelula;

typedef struct TipoLista {
	int ID;
	int Conjuge;
	int Posicao;
	TipoApontador Primeiro, Ultimo;
} TipoLista;

#include <stdio.h>

int Busca(char *Chave, TipoLista Lista);
/*
*Faz a lista vazia
*Parametros:
*	*lista
*/
void FLVazia(TipoLista *Lista);
/*
*Verifica se a lista esta vazia
*Parametros:
*	* lista
*/
short Vazia(TipoLista Lista);
/*
*Insere um item generico na lista
*Parametros:
*	* lista
*	* item - item a ser inserido
*/
void Insere(TipoItem *x, TipoLista *Lista);
/*
*Remove um item da lista, retorna um apontador para o item removido
*Parametros:
*	*lista
*	*item_anterior - apontador para a celula do item anterior ao que deve ser removido
*/
void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item);

/*
 * Desfaz uma lista encadeada por apontadores
 *Parametros:
 * Lista
*/
void DesfazLista(TipoLista *Lista);

/*
*Imprime os items armazenados na fila
*Parametros:
*	* lista
*
*/
void ImprimeLista(TipoLista Lista);

/*
 * Aloca arranjo do TipoLista
 *Parametros
 * n - numero de listas
*/
TipoLista* AlocaListas(int n);

/* Desaloca arranjo do TipoLista
 *Parametros
 * n - numero de listas
 * *Lista - arranjo do tipo lista
*/
void DesalocaListas(int n, TipoLista *Lista);

#endif
