/*
 *********************************************************************************
 *
 * Título: arquivo
 *
 * Autor: Marcos Alves
 *
 * Data de Criação: 02/11/2015

 * Última modificação: 03/11/2015
 *
 * Descrição: Implementação do módulo glObjeto3d
 *
 *********************************************************************************
 */

#include "glObjeto3d.h"
#include "arquivo.h" /* tFila, cria_fila, insere_fila, remove_fila, carrega_obj */
//#include <GL/glut.h> /* funções da GL e glut */
#include <stdlib.h> /* free, calloc, NULL */
#include <stdio.h>

/* ====================== INICIO DAS FUNCOES NAO DEFINIDAS NO MODULO ============================ */

void alocandoMemoria(int tamanho_array) {

	int i = 0;

	_ponto = calloc(tamanho_array, sizeof(float *));

	for (i = 0; i < tamanho_array; i++) _ponto[i] = calloc(COORDENADAS, sizeof(float));
}


void liberandoMemoria(int tamanho_array) {

	int i = 0;

	for (i = 0 ; i < tamanho_array; i++) free(_ponto[i]);

	free(_ponto);
}

void listaPontos(void) {

	tFila vertice;

	int i = 0;

	criaFila(&vertice);

	carregaOBJ(&vertice, 'V', CAMINHO);

	alocandoMemoria(vertice.tamanho);

	tNo *aux = vertice.inicio;

	for (i = 0; i < vertice.tamanho; i++) {

		_ponto[i][0] = aux->conteudo[0];

		_ponto[i][1] = aux->conteudo[1];

		_ponto[i][2] = aux->conteudo[2];

		printf("\nFace (%d) # %.6f %.6f %.6f", i+1, _ponto[i][0], _ponto[i][1], _ponto[i][2]);

		aux = aux->proximo;
	}

	liberaFila(&vertice);
}

/* ====================== FIM DAS FUNCOES NAO DEFINIDAS NO MODULO ============================ */



/* desenha linha do cubo de acordo com os pontos passado */

void glObjeto3dCubo(float escala) {
/*
	tFila faces;

	int i = 0, j = 0;

	listaPontos();

	criaFila(&faces);

	carregaOBJ(&faces, 'F', CAMINHO);

	tNo *auxiliar = faces.inicio;

	glPushMatrix();

		glScalef(escala, escala, escala);

		glBegin(GL_LINES);

		*	for(i = 0; i < faces.tamanho; i++) {

				for(j = 0; j < _size_conteudo; j++) {

					int indice = (int) auxiliar->conteudo[j] - 1;

					glVertex3f(_ponto[indice][0], _ponto[indice][1], _ponto[indice][2]);

					auxiliar = auxiliar->proximo;
				}
			} *

		glEnd();

	glPopMatrix(); */
}
