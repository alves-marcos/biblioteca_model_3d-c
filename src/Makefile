all: main

main: main.o glObjeto3d.o fila.o arquivo.o
	gcc -O2 -std=c99 main.o glObjeto3d.o fila.o arquivo.o -lGL -lGLU -lglut -o main

main.o: main.c
	gcc -O2 -std=c99 -c -lGl -lGLU -lglut main.c

glObjeto3d.o: glObjeto3d.c
	gcc -O2 -std=c99 -c -lGl -lGLU -lglut glObjeto3d.c

fila.o: fila.c
	gcc -O2 -std=c99 -c fila.c

arquivo.o: arquivo.c
	gcc -O2 -std=c99 -c arquivo.c

clean:
	rm main *.o
 
