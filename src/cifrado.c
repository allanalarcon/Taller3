#include "cifrado.h"
#include <string.h>
#include <ctype.h>

char *cifradoCiclico(char *mensaje, int llave)
{
	char cifrado[1024] = "";	
	for (int i = 0; i < strlen(mensaje) - 1; i++)
	{
		if (ispunct(mensaje[i]) || isspace(mensaje[i]))
			cifrado[i] = mensaje[i];
		else
		{
			cifrado[i] = toupper(mensaje[i]) + llave;
			if(llave >= 0)
			{
				while(cifrado[i] < 65 || cifrado[i] > 90)
					cifrado[i] = cifrado[i] - 26;
			}
			else
			{
				while(cifrado[i] < 65 || cifrado[i] > 90)
					cifrado[i] = cifrado[i] + 26;
			}
		}
	}
	char *ciclico = cifrado;
	return ciclico;
}

char *cifradoContrasena(char *mensaje, char *llave)
{
	char cifrado[1024] = "";	
	int nuevallave = -(strlen(llave) - 1);
	for (int i = 0; i < strlen(mensaje) - 1; i++)
	{
		if (ispunct(mensaje[i]) || isspace(mensaje[i]))
			cifrado[i] = mensaje[i];
		else if (toupper(mensaje[i]) < (65 + strlen(llave) - 1))
			cifrado[i] = toupper(llave[toupper(mensaje[i]) - 65]);
		else
		{
			cifrado[i] = toupper(mensaje[i]) + nuevallave;
			while(cifrado[i] < 65 || cifrado[i] > 90)
				cifrado[i] = cifrado[i] + 26;
		}
	}
	char *contrasena = cifrado;
	return contrasena;
}

