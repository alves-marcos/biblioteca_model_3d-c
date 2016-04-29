/*
 *********************************************************************************
 *
 * Título: arquivo
 *
 * Autor: Marcos Alves
 *
 * Data de Criação: 02/11/2015

 * Última modificação: 04/11/2015
 *
 * Descrição: Implementação do módulo glObjeto3d
 *
 *********************************************************************************
 */

#include "glObjeto3d.h" /* _glObjetoMacaco _ponto */
#include "arquivo.h" /* tFila, cria_fila, insere_fila, remove_fila, carrega_obj */
#include <GL/glut.h> /* funções da GL e glut */
#include <stdlib.h> /* free, calloc, NULL */

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

int listaPontos(char *caminho) {

	tFila vertice;

	int i = 0, tam_lista = 0;

	criaFila(&vertice);

	carregaOBJ(&vertice, 'v', caminho);

	alocandoMemoria(vertice.tamanho);

	tam_lista = vertice.tamanho;

	tNo *aux = vertice.inicio;

	for (i = 0; i < vertice.tamanho; i++) {

		_ponto[i][0] = aux->conteudo[0];

		_ponto[i][1] = aux->conteudo[1];

		_ponto[i][2] = aux->conteudo[2];

		aux = aux->proximo;
	}

	liberaFila(&vertice);

	return tam_lista;
}

/* ====================== FIM DAS FUNCOES NAO DEFINIDAS NO MODULO ============================ */



/* desenha linha do macaco de acordo com os pontos passado */

void glObjeto3dMacaco(float escala) {

	tFila faces;

	int i = 0, j = 0, tamanho_array = 0;

	tamanho_array = listaPontos(MACACO);

	criaFila(&faces);

	carregaOBJ(&faces, 'f', MACACO);

	tNo *auxiliar = faces.inicio;

	glPushMatrix();

		glScalef(escala, escala, escala);

		glPolygonMode(GL_FRONT_AND_BACK , GL_LINE);

		glBegin(GL_TRIANGLES);

			for(i = 0; i < faces.tamanho; i++) {

				for(j = 0; j < _size_conteudo; j++) {

					int indice = (int) auxiliar->conteudo[j] - 1;

					glVertex3f(_ponto[indice][0], _ponto[indice][1], _ponto[indice][2]);

				}

				auxiliar = auxiliar->proximo;
			} 

		glEnd();

	glPopMatrix(); 

	liberandoMemoria(tamanho_array);

	liberaFila(&faces);
}
