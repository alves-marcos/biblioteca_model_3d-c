#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include "arquivo.h"
#include "glObjeto3d.h"

int main(void) {

	tFila fila;

	criaFila(&fila);

	float dado[3];

	dado[0] = 3.3;

	dado[1] = 2.3;

	dado[2] = 1.3;


	 _size_conteudo = sizeof(dado)/sizeof(int);

	char cam[200] = "C:\\Users\\Marcos Alves\\Documents\\cube.obj";

	carregaOBJ(&fila, 'v', cam);

	elementosFila(fila, 'v'); 

	listaPontos();

	return 0;
}