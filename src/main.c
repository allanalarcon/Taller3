
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
        if (argc != 3 && argc != 1)
        {
                printf("Debe ingresar la llave y el texto\n");
        }
        else if (argc == 3)
        {
                printf("Mensaje cifrado: ");
                cifradoCiclico(argv[2], atoi(argv[1]));
                printf("\n");
                printf("Mensaje cifrado en morse: ");
                printf("\n");
        }
        else
        {
                char mensaje[1024];
                int llave;
                char llave2[1024];
                puts("CIFRADO CÍCLICO");
                printf("Ingrese mensaje a cifrar: ");
                fgets(mensaje, 1024, stdin);
                printf("Ingrese la llave numérica: ");
                scanf("%d", &llave);
                printf("Mensaje cifrado: %s", cifradoCiclico(mensaje, llave));
                memset(cifrado,0,1024);
                printf("Ingrese la llave: ");
                scanf("%s", llave2);
                printf("Mensaje cifrado: %s", cifradoAutoLlave(mensaje, llave2));
        }
}

