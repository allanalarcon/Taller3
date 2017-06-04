#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "cifrado.h"
#include "codificacion.h"

void main(int argc, char *argv[])
{
        if (argc != 4 && argc != 1)
        {
                printf("Debe ingresar la llave, el texto y el tipo de cifrado\n");
        }
        else if (argc == 4)
        {
		if (argv[3] == "-c")
		{
                	char *mensajeCifrado = cifradoCiclico(argv[2], atoi(argv[1]));
                        printf("Mensaje cifrado: %s", mensajeCifrado);
                        printf("Mensaje cifrado en morse: %s", claveMorse(mensajeCifrado));
		}
		else if (argv[3] == "-a")
                        printf("Mensaje cifrado: %s", cifradoAutoLlave(argv[2], argv[1]));
		else if (argv[3] == "-p")
			printf("Mensaje cifrado: %s", cifradoContrasena(argv[2], argv[1]));
		else
			printf("Ingrese argumentos validos");
        }
        else
        {
                char mensaje[1024];
                int llave;
                char llavetext[1024];
		char tipoCifrado;
		printf("Tipo de cifrado: ");
		scanf("%c", &tipoCifrado);
		if (toupper(tipoCifrado) == 'C')
		{
                	puts("CIFRADO CÍCLICO");
			printf("Ingrese mensaje a cifrar: ");
			fgets(mensaje, 1024, stdin);
			printf("Ingrese la llave numérica: ");
			scanf("%d", &llave);
			char *men = mensaje;
			char *mensajeCifrado = cifradoCiclico(mensaje, llave);
			printf("Mensaje cifrado: %s", mensajeCifrado);
			printf("Mensaje cifrado en morse: %s", claveMorse(mensajeCifrado));
		}
		else if (toupper(tipoCifrado) == 'A')
		{
			puts("CIFRADO AUTO LLAVE");
                        printf("Ingrese mensaje a cifrar: ");
                        fgets(mensaje, 1024, stdin);
                        char *men = mensaje;
			printf("Ingrese la llave: ");
	                scanf("%s", llavetext);
        	        printf("Mensaje cifrado: %s", cifradoAutoLlave(men, llavetext));
		}
		else if (toupper(tipoCifrado) == 'P')
		{
			puts("CIFRADO CÍCLICO");
                        printf("Ingrese mensaje a cifrar: ");
                        fgets(mensaje, 1024, stdin);
                        char *men = mensaje;
			printf("Ingrese la llave: ");
                        scanf("%s", llavetext);
                        printf("Mensaje cifrado: %s", cifradoContrasena(men, llavetext));
		}		
		else 
			printf("Opción inválida");
       }
}
