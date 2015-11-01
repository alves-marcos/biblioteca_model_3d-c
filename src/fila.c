/*
 *********************************************************************************
 *
 * Título: fila
 *
 * Autor: Marcos Alves
 *
 * Data de Criação: 30/10/2015

 * Última modificação: 01/10/2015
 *
 * Descrição: Implementação do módulo fila encadeada de vertices/faces
 *
 *********************************************************************************
 */

#include "fila.h" /* tFila, tNo, cria_fila, elementos_fila, insere_fila, remove_fila */
#include <stdlib.h> /* NULL, malloc, calloc, free */
#include <stdio.h> /* printf */

/* copia um array do conteudo da fila - OBS: Função auxiliar não definida no fila.h */

void copia_array(float *original, float *conteudo) {

	int i = 0; /* indice p ofor */

	for (i = 0; i < _size_conteudo; i++) original[i] = conteudo[i]; /* copiando o array passado por parametro para o da fila */
}

/* Criando fila */

int cria_fila(tFila *fila) {

	fila->inicio = NULL; /* inicio da fila */

	fila->tamanho = 0; /* tamanho da fila inicializa */

	return 1; /* retorna 1 informando que conseguiu criar */
}

/* mostra todos os elementos da fila */

int elementos_fila(tFila fila, char tipo) {

	tNo *aux; /* auxiliar para nao perder a referência para o ínicio */

	aux = fila.inicio; /* indico o inicio da fila */

	int i = 0; /* indice para o for */

	printf("\n@@@ FILA @@@\n");

	printf("\n$ TAMANHO: %d\n", fila.tamanho);

	while (aux != NULL) { /* enquanto não chegar ao fim da fila */

		if (tipo == 'F') {

			printf("\nf ");

			for (i = 0; i <  _size_conteudo; i++) printf("%d ", (int) aux->conteudo[i]);
		
		} else if (tipo == 'V') {

			printf("\nv %.6f %.6f %.6f", aux->conteudo[0],aux->conteudo[1], aux->conteudo[2]);
		
		} else return 0;

		printf("\n");

		aux = aux->proximo; /* aponte sempre para o próxim até o fim */
	}

	return 1;
}

/* insere elemento na fila */ 

int insere_fila(tFila *fila, float *conteudo) {

	tNo *novoNo; /* ponteiro com novoNo a ser alocado */

	novoNo = (tNo *) malloc(sizeof(tNo)); /* alocando memória para novoNo */

	if (novoNo == NULL) return 0; /* não conseguiu alocar memória */

	novoNo->conteudo = calloc( _size_conteudo, sizeof(float)); /* alocando espaço para o array de conteúdo */

	copia_array(novoNo->conteudo, conteudo); /* adiciona ao array de conteúdo o valor passado por parametro */

	/* ##### Caso a Fila estiver vazia ##### */

	if (fila->tamanho == 0) fila->inicio = novoNo; /* insira no na lista vazia */

	/* ##### Senão a Fila estiver vazia ##### */

	else fila->final->proximo = novoNo; /* insira no final */

	fila->final = novoNo; /* o ultimo elemento da fila aponta para novoNo */

	novoNo->proximo = NULL; /* sempre o proximo vai apontar para null */

	fila->tamanho++; /* incremento o tamanho */

	return 1; /* retorna 1 informando que conseguiu criar */
}


/* remove elemento da fila */

int remove_fila(tFila *fila) {

	tNo *aux = fila->inicio; /* referência para incio da lista */

	if (aux == NULL) return 0; /* quando a fila não tiver nenhum elemento */

	fila->inicio = aux->proximo; /* o inicio recebe o proximo dele mesmo */

	fila->tamanho--; /* decrementa até chegar a 0 */

	free(aux); /* liberando espaço da memória */

	return 1; /* retorna 1 informando que conseguiu criar */
}