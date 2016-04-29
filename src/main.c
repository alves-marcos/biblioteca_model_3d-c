#include <GL/glut.h> /* funcões da gl e glut */
#include "glObjeto3d.h"

/* definições de constante de matrizes */

#define ORTHO 1
#define PERSPECTIVE 0

/* variaveis globais */

GLfloat angle;

GLuint projection_type; /* definindo tipo de projeção para a camera */

/* prototipando funções callback a serem implementada */

void drawWindow(void); /* fazer o redesenho de toda janela */

void renderWindow(GLsizei width, GLsizei height); /* altera a matriz projeção de acordo com o tamanho da tela */

/* prototipando funçoes auxiliares */

void init(void); /* inicializar padroes de cor angulo etc. */


/* função principal */

int main(int argc, char **argv) {

	glutInit(&argc, argv); /* inicializando a biblioteca glut */

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); /* avisa o mode de exibição que vai ser criada com a janela criada */

	glutInitWindowSize(500, 300); /* especifica o tamanho em pixels da janela GLUT */

	glutInitWindowPosition(50, 50); /* indica onde a janela deve ser criada */

	glutCreateWindow("Exercise"); /* criando a janela com titulo passado por parametro */

	glutDisplayFunc(drawWindow); /* função que chama uma rotina que faz o deseneho */

//	glutReshapeFunc(renderWindow); /* alteração na janela */

	init(); /* inicializar padrões de cor angulo e qual projecao */

	glutMainLoop(); /* começa a maquina de estados, processando msg especificas do SO */
}


/* implementação das funções calback */

void drawWindow(void) {

 	glClear(GL_COLOR_BUFFER_BIT); /* limpando a janela de acordo com a cor especificada acima */

	glColor3f(1.0f, 0.41f, 0.71f); /* definindo cor Rosa forte */

	//glutWireTeapot(30.0f); /* desenha um decagono */

	glMatrixMode(GL_PROJECTION); /* inicializa sistema de coordenadas, todas as alteracoes irão afetar na camera */

	glLoadIdentity(); /* reinicia  a localização e a orientação do sistema de coordenadas */ 

	glViewport(-100, 0, 500, 300); /* janela onde será feito o desenho */

	glOrtho(100.0f, -100.0f, 100.0f, -100.0f, 0.1f, 100);

	glMatrixMode(GL_MODELVIEW); /* matriz que vai sofrer todas as alteraççoes feita na cena */

	glLoadIdentity(); /* reinicia o sistema de coordenadas do modelo */

	glTranslated(0, 0, -10);  /* sempre fazer isso */
	
	glObjeto3dMacaco(100);

//	glutWireTeapot(30.0f); /* desenha um decagono */

	//glMatrixMode(GL_PROJECTION); /* inicializa sistema de coordenadas, todas as alteracoes irão afetar na camera */

	//glLoadIdentity(); /* reinicia  a localização e a orientação do sistema de coordenadas */ 

	//glMatrixMode(GL_PROJECTION); /* inicializa sistema de coordenadas, todas as alteracoes irão afetar na camera */

	//glLoadIdentity(); /* reinicia  a localização e a orientação do sistema de coordenadas */ 

	//glViewport(120, 0, 500, 300); /* janela onde será feito o desenho */
	
	//gluPerspective(angle, (float) 500/300, 1, 100); /* modo de visualização com perspective */

	//glFrustum (-1, 1, -1, 1, 1, 50);

	//glObjeto3dMacaco(20); 

	//glutWireTeapot(30.0f); /* desenha um decagono */


	glutSwapBuffers(); /* mesma função da glFlush diferença que estamos tratando com mais de um tela logo mais um buffer de Imagem*/
}

void renderWindow(GLsizei width, GLsizei height) {

	if (height == 0) height = 1; /* evitando a divisão por 0 */

	glViewport(0, 0, width, height); /* janela onde será feito o desenho */

	glMatrixMode(GL_PROJECTION); /* inicializa sistema de coordenadas, todas as alteracoes irão afetar na camera */

	glLoadIdentity(); /* reinicia  a localização e a orientação do sistema de coordenadas */ 

	GLfloat aspect_correction = (GLfloat) width / (GLfloat) height; /* calculo da correção de aspecto */

	switch(projection_type) {

		case ORTHO: 

			glOrtho(100.0f, -100.0f, 100.0f, -100.0f, 0.1f, 100);

			break;

		case PERSPECTIVE:

			gluPerspective(angle, aspect_correction, 1, 500); /* modo de visualização com perspective */

			break;

		default: projection_type = 0;
	}

	glMatrixMode(GL_MODELVIEW); /* matriz que vai sofrer todas as alteraççoes feita na cena */

	glLoadIdentity(); /* reinicia o sistema de coordenadas do modelo */

	gluLookAt(0, 0, -50, 0, 0, 0, 0, 1, 0); /* parametros onde o observador está (eixox, eixoy, eixoz) = (0, 50, -150),
										
										     para onde ele está olhando (centerx, centery, centerz) = (0, 0, 0) (ORIGEM), 

										     vetor que aponta para cima é (upx, upy, upz) = ( 0, 1, 0), alinhado com o eixo y. */
}

/* implementação das funções auxiliares */

void init(void) {

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); /* definindo a cor do fundo da janela R G B (A) */

	angle = 45; /* definindo o angulo */

	projection_type = ORTHO; /* definindo qual tipo de projeção vai iniciar */
}