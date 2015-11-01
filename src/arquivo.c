/*
 *********************************************************************************
 *
 * Título: arquivo
 *
 * Autor: Marcos Alves
 *
 * Data de Criação: 31/10/2015

 * Última modificação: 01/10/2015
 *
 * Descrição: Implmentação do módulo arquivo
 *
 *********************************************************************************
 */

#include "arquivo.h" /* carrega_obj, carrega_3xd, fila.h */
#include <stdlib.h> /* NULL, atof */
#include <stdio.h> /* fopen, fgetc */


/* limpando array char */

void limpando_array(int tamanho, char *vetor) {

	int i = 0;

	for (i = 0 ; i <  tamanho; i++) vetor[i] = '\0';
}

/* carrega pontos do arquivo obj */

int carrega_obj(tFila *fila, char tipo, char *caminho) {

	FILE *arq = NULL; /* ponteiro para buscar */

 	arq = fopen(caminho, "r"); /* tentando abrir o arquivo de acordo com tamanho */

 	char ch, ponto[10]; /* caractere a ser lido - ponto do arquivo */

 	int condicao = 0, contador = 0, indice_leitura = 0, tamanho_array = 0; /* contador até chegar ponto */

 	float vertice[3]; /* array de coordernadas */

 	if (arq == NULL) return 0; /* verifica se o arquivo foi encontrado ou não */

 	if (tipo == 'V') {

 		while ((ch = fgetc(arq)) != EOF) {

 			if (ch == 'v' || ch == ' ') contador++; /* ultimos caracteres a serem lidos antes de iniciar os pontos */

 			else contador = 0; /* ainda ão chegou nos dois ultimos caracteres */

 			if (contador == 2 || condicao == 1) {

 				if(ch != ' ') {

 					ponto[indice_leitura] = ch; /* passa o caractere do primeiro ponto para o array */

 					indice_leitura++; /* incrementa o indice do array de char com pontos */

 				}

 				if ((ch == '\n' || ch == ' ') && condicao == 1) { /* espaço significa fim do ponto vai para o proximo */

 					vertice[tamanho_array] = atof(ponto);

 					indice_leitura = 0;

 					limpando_array(10, ponto);

 					tamanho_array++;
 				}

 				if (tamanho_array == 3) {

 					_size_conteudo = sizeof(vertice) / sizeof(float);

 					insere_fila(fila, vertice);

 					tamanho_array = 0;
 				}

 				condicao = 1;

 				if (ch == '\n') condicao = 0;
 			}
 		}

 	} else if (tipo == 'F') {


 	} else return 0;
}


