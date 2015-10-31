#include "fila.h"
#include <stdio.h>
#include <stdlib.h>


int main(void) {

	tFila fila;

	cria_fila(&fila);

	float dado[4];

	dado[0] = 3.3;

	dado[1] = 2.3;

	dado[2] = 1.3;

	dado[3] = 4.3;

	 _size_conteudo = sizeof(dado)/sizeof(int);

	insere_fila(&fila, dado);

	float dado2[4];

	dado2[0] = 1.3;

	dado2[1] = 13;

	dado2[2] = 01.3;

	dado2[3] = 03;


	insere_fila(&fila, dado2);

	elementos_fila(fila, 'F');

	return 0;
}