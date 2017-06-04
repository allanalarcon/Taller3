#include <stdio.h>
#include "codificacion.h"

char codMorse[30][5]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--",
		      "-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

char *claveMorse(char *mensaje)
{
	for (int i = 0; i < strlen(mensaje); i++)
	{
		if ispunct(mensaje[i])
			printf("%c ", mensaje[i]);
		else if isspace(mensaje[i])
			printf("/ ");
		else
			printf("%s ", codMorse[toupper(mensaje[i]) - 65]);
	}
}
