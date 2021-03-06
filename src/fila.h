/*
 *********************************************************************************
 *
 * Título: fila
 *
 * Autor: Marcos Alves
 *
 * Data de Criação: 30/10/2015

 * Última modificação: 03/11/2015
 *
 * Descrição: Definição do módulo fila encadeada de vertices/faces
 *
 *********************************************************************************
 */

#ifndef FILA_H
#define FILA_H

/* tamanho do array de conteudo global */

int _size_conteudo;

/* Tipo Estruturado No */

typedef struct no {

 	struct no *proximo; /* referência para o próximo elemento */

	float *conteudo; /* conteudo presente na fila */

} tNo; /* definindo nome para estrutura */


/* Tipo Estruturado Fila */

typedef struct {

 	tNo *inicio; /* referência para o inicio da fila */

 	tNo *final; /* referência para o final já que sempre será inserido no final da fila */

	int tamanho; /* tamanho da fila */

} tFila; /* definindo nome para estrutura */

/* Alusões as funções da Fila */

/* ================================== Nota =============================================== 

- As funções a seguir seguem o padrão de retorna um inteiro:

  [1] - Operação realizada com sucesso

  [0] - Operação falhou

  ========================================================================================
*/

extern int criaFila(tFila *fila); /* cria a fila */

extern int elementosFila(tFila fila, char tipo); /* retorna todos os elementos existentes na fila */

extern int insereFila(tFila *fila, float *conteudo); /* index indica qual fila irá ser feita a inserção insere elemento*/

extern int liberaFila(tFila *fila); /* libera todo espaço alocado para fila */

extern int removeFila(tFila *fila); /* remove o qualquer elemento da fila a partir da posição */

#endif //FILA_H