/*
 *********************************************************************************
 *
 * Título: arquivo
 *
 * Autor: Marcos Alves
 *
 * Data de Criação: 31/10/2015

 * Última modificação: 01/11/2015
 *
 * Descrição: Implmentação do módulo arquivo
 *
 *********************************************************************************
 */

#include "arquivo.h" /* carrega_obj, carrega_3xd, fila.h */
#include <stdlib.h> /* NULL, atof */
#include <stdio.h> /* fopen, fgetc */


/* ====================== INICIO DAS FUNCOES NAO DEFINIDAS NO MODULO ============================ */

/* limpando array char */

void limpando_array(int tamanho, char *vetor) {

	int i = 0;

	for (i = 0 ; i <  tamanho; i++) vetor[i] = '\0';
}

/* ====================== FIM DAS FUNCOES NAO DEFINIDAS NO MODULO ============================ */


/* carrega pontos do arquivo obj */

int carrega_obj(tFila *fila, char tipo, char *caminho) {

	FILE *arq = NULL; /* ponteiro para buscar */

 	arq = fopen(caminho, "r"); /* tentando abrir o arquivo de acordo com tamanho */

	char ch, ponto[10]; /* caractere a ser lido - ponto do arquivo */

 	int condicao = 0, contador = 0, indice_leitura = 0, tamanho_array = 0; /* contador até chegar ponto */

 	float vetor_conteudo[MAX_CONTEUDO];

 	if (arq == NULL) return 0; /* verifica se o arquivo foi encontrado ou não */

	while((ch = fgetc(arq)) != EOF) {

		if (tipo == 'V' && (ch == 'v' || ch == ' ')) contador++; /* caso seja fila de vertice */
		
		else if (tipo == 'F' && (ch == 'f' || ch == ' ')) contador++; /* caso seja fila de faces */

		else contador = 0; /* caso não tenha chegado no dois ultimos caracteres antes do ponto */

		if (contador == 2 || condicao == 1) {
			
			if (ch != ' ') {

				ponto[indice_leitura] = ch; /* prencheendo array char com ponto */

				indice_leitura++; /* incrementando os indices do array de leitura */
			}

			if ((ch == '\n' || ch == ' ') && condicao == 1) { /* espaço e quebra de linha significa fim do ponto vai para o proximo */

 				vetor_conteudo[tamanho_array] = atof(ponto); /* transformando array de char em float */

 				indice_leitura = 0; /* zerando o indice do array de char */

 				limpando_array(10, ponto); /* limpando o array */

 				tamanho_array++; /* incrementando o array de float */
 			}

			condicao = 1; /* condicao indica que estou na linha onde estão os pontos */

			if (ch == '\n') { 

				condicao = 0; /* significa que houve uma quebrra de linha onde devo passar p o proximo ponto */

				_size_conteudo = tamanho_array; /* ajusto o tamanho do array que quero alocar de acordo com a demamanda */

				insere_fila(fila, vetor_conteudo); /* insiro array na fila */

				tamanho_array = 0; /* zero o tamanho do meu conteudo */
			}
		}
	}

	return 1;
}


