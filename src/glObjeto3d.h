/*
 *********************************************************************************
 *
 * Título: arquivo
 *
 * Autor: Marcos Alves
 *
 * Data de Criação: 02/11/2015

 * Última modificação: 02/11/2015
 *
 * Descrição: Definição do módulo glObjeto3d
 *
 *********************************************************************************
 */

#ifndef GLOBJETO3D_H
#define GLOBJETO3D_H

#define COORDENADAS 3
 
#define MACACO "../objetos_model/monkey_head2.obj"


/* lista de face e vertice que vai ser alocada dinamicamente */

float **_ponto; 

/* ================================== Nota =============================================== 

- As funções a seguir usam a biblioteca glut

  ========================================================================================
*/

void glObjeto3dMacaco(float escala); /* desenha linhas de um cubo */


#endif //GLOBJETO3D_H