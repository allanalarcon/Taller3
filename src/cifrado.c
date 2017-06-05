#include "cifrado.h"
#include <string.h>
#include <ctype.h>

char *cifradoCiclico(char *mensaje, int llave)
{
	char cifrado[1024] = "";	
	for (int i = 0; i < strlen(mensaje); i++)
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
	int nuevallave = -(strlen(llave));
	for (int i = 0; i < strlen(mensaje); i++)
	{
		if (ispunct(mensaje[i]) || isspace(mensaje[i]))
			cifrado[i] = mensaje[i];
		else if (toupper(mensaje[i]) < (65 + strlen(llave)))
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

char *cifradoAutoLlave(char *mensaje, char *llave)
{
	int i, j;
	char cifrado[1024] = "";
	char mnsSinEpc[1024] = "";
	char concatenar[1024] = "";     
	char contrasena[1024] = "";
	for (i = j = 0; mensaje[i] != '\0'; i++) 
	{
		if (mensaje[i] != 32) 
			mnsSinEpc[j++] = mensaje[i];
	}

	strcat(concatenar, llave);
	strcat(concatenar, mnsSinEpc);

	for (int i = 0; i < (strlen(concatenar)); i++)
	{
		if (isspace(mensaje[i]))
		{
			contrasena[i] = toupper(mensaje[i]);
 			contrasena[i+1] = toupper(concatenar[i]);
		}
		else if (!(isalpha(contrasena[i])))
			contrasena[i] = toupper(concatenar[i]);
		else
			contrasena[i+1] = toupper(concatenar[i]);
	} 

	for(int i = 0; i < (strlen(mensaje)); i++)
	{
		if isspace(mensaje[i])
			cifrado[i] = mensaje[i];
		else
		{
			cifrado[i] = toupper(mensaje[i]) + contrasena[i] - 65;
			while(cifrado[i] < 65 || cifrado[i] > 90)
				cifrado[i] = cifrado[i] - 26;
		}
	}
	char *autoLlave = cifrado;
	return autoLlave;
}


