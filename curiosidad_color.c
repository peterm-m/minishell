#include <stdio.h>

/*
Por lo visto las cosas estas raras que represen el color al imprimir 
se llaman secuencias de escape. Estas secuencias de escape.

Las secuencias de escape, como
	muchas de las propiedades de una terminal no son portables entre terminales,
	por eso nacio la libreria termcap 
	que trabajan en cualquier terminal
	bla bla bla ya lo hablamos si quieres TODO

Un tema interesante es que estas secuencias se buscan en el buffer que mandas a imprimir por pantalla, 
por eso puede incorporarlas como numeros a tus cadenas de texto. Mira el ejmplo, se añade como numero a la cadenas y
se recorren muchas prosibilidades.

Como color de texto, color de fondo, tipo de subrayado, etc etc

De momento, el tema color en la shell deberiamos quitarlos temporalmente. hasta que sepamos como manejarlos y como
manejarlos.
*/

int main(void)
{
	int i, j, n;

	for (i = 0; i < 11; i++)
	{
		for (j = 0; j < 10; j++)
		{
			n = 10 * i + j;
			if (n > 108)
				break;
			printf("\033[%dm %3d\033[m", n, n);
		}
		printf("\n");
	}
	return 0;
}
