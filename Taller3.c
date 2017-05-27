#include <stdio.h>
#include <string.h>
#include <ctype.h>

char cifrado[1024] = "";

void cifradoCiclico(char mensaje[], int llave)
{
	char cadena[1024] = "";
	for (int i = 0; i < strlen(mensaje); i++)
	{
		if (ispunct(mensaje[i]) || isspace(mensaje[i]))
			cifrado[i] = mensaje[i];
		else if ((mensaje[i] < 91) && ((mensaje[i] + llave) > 90))
			cifrado[i] = mensaje[i] + llave - (26*((mensaje[i] + llave - 65)/26));
		else if ((mensaje[i] > 96) && ((mensaje[i] + llave) > 122))
			cifrado[i] = mensaje[i] + llave - (26*((mensaje[i] + llave - 97)/26));
		else
			cifrado[i] = mensaje[i] + llave;
		printf("%c", cifrado[i]);
	}
}

void main(int argc, char *argv[])
{
	char mensaje[1024];
	int llave;
	puts("CIFRADO CÍCLICO");
	printf("Ingrese mensaje a cifrar: ");
	fgets(mensaje, 1024, stdin);
	printf("Ingrese la llave numérica: ");
	scanf("%d", &llave);
	printf("Mensaje cifrado: ");
	cifradoCiclico(mensaje, llave);
}
