#include <stdio.h>
#include <ctype.h>

char cifrado[200] = ""

void cifradoCiclico(char mensaje[], int llave)
{
	char cadena[200] = ""
	if (strlen(mensaje > 200)
		printf("El mensaje no debe tener más de 200 caracteres");
	else
	{
		for (int i = 0; i < strlen(mensaje); i++)
		{
			if (ispunct(mensaje[i]) || isspace(mensaje[i]))
				cifrado[i] = mensaje[i];
			else if (((mensaje[i] < 91) && ((mensaje[i] + llave) > 90) || ((mensaje[i] + llave) > 122))
				cifrado[i] = mensaje[i] + llave - 26;
			else
				cifrado[i] = mensaje[i] + llave;
		}
	}
}
