#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "cifrado.h"
#include "codificacion.h"

int main(int argc, char *argv[])
{
	if (argc != 4 && argc != 1)
	{
		printf("Debe ingresar la llave, el texto y el tipo de cifrado\n");
	}
	else if (argc == 4)
	{
		printf("Mensaje cifrado: ");
		if (strcmp(argv[3], "-c") == 0)
		{
			char *mensajeCiclico = cifradoCiclico(argv[2], atoi(argv[1]));
			printf("%s", mensajeCiclico);
			printf("\nMensaje cifrado en morse: %s\n", claveMorse(mensajeCiclico));
		}
		else if (strcmp(argv[3], "-a") == 0)
		{
			char *mensajeAuto = cifradoAutoLlave(argv[2], argv[1]);
			printf("%s", mensajeAuto);
			printf("\nMensaje cifrado en morse: %s\n", claveMorse(mensajeAuto));
		}		
		else if (strcmp(argv[3], "-p") == 0)
		{
			char *mensajeContrasena = cifradoContrasena(argv[2], argv[1]);
			printf("%s", mensajeContrasena);
			printf("\nMensaje cifrado en morse: %s\n", claveMorse(mensajeContrasena));
		}
		else
			printf("Ingrese argumentos válidos\n");
	}
	else
	{
		char mensaje[1024];
		int llave;
		char llavetext[1024];

		char tipoCifrado;
		printf("Tipo de cifrado: ");
		scanf("%c", &tipoCifrado);
		while(getchar() != '\n');

		if (toupper(tipoCifrado) == 'C')
		{
			puts("\nCIFRADO CÍCLICO\n");

			printf("Ingrese mensaje a cifrar: ");
			fgets(mensaje, 1024, stdin);
			char *men = mensaje;

			printf("Ingrese la llave numérica: ");
			scanf("%d", &llave);

			char *mensajeCiclico = cifradoCiclico(mensaje, llave);
			printf("\nMensaje cifrado: %s", mensajeCiclico);
			printf("Mensaje cifrado en morse: %s\n", claveMorse(mensajeCiclico));
		}
		else if (toupper(tipoCifrado) == 'A')
		{
			puts("\nCIFRADO AUTOLLAVE\n");

			printf("Ingrese mensaje a cifrar: ");
			fgets(mensaje, 1024, stdin);
			char *men = mensaje;

			printf("Ingrese la llave: ");
			scanf("%s", llavetext);

			char *mensajeAuto = cifradoAutoLlave(mensaje, llavetext);
			printf("\nMensaje cifrado: %s", mensajeAuto);
			printf("Mensaje cifrado en morse: %s\n", claveMorse(mensajeAuto));
		}
		else if (toupper(tipoCifrado) == 'P')
		{
			puts("\nCIFRADO CONTRASEÑA\n");

			printf("Ingrese mensaje a cifrar: ");
			fgets(mensaje, 1024, stdin);
			char *men = mensaje;

			printf("Ingrese la llave: ");
			scanf("%s", llavetext);

			char *mensajeContrasena = cifradoContrasena(mensaje, llavetext);
			printf("\nMensaje cifrado: %s", mensajeContrasena);
			printf("Mensaje cifrado en morse: %s\n", claveMorse(mensajeContrasena));
		}		
		else 
			printf("Opción inválida\n");
	}
	return 0;
}
