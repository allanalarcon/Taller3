#include "codificacion.h"
#include <string.h>
#include <ctype.h>

char codMorse[30][5]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--",
		      "-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

char *claveMorse(char *mensaje)
{
	char morse[1024*5];
	int count = 0;
	for (int i = 0; i < strlen(mensaje)-1; i++)
	{
		if ispunct(mensaje[i])
		{
			morse[count] = mensaje[i];
			morse[count + 1] = 32;
			count = count + 2;
		}
		else if isspace(mensaje[i])
		{
			morse[count] = 47;
			morse[count + 1] = 32;
			count = count + 2;	
		}
		else
		{
			
			for (int j = 0; j < strlen(codMorse[toupper(mensaje[i]) - 65]); j++)
			{
				morse[count] = codMorse[toupper(mensaje[i]) - 65][j];
				count++;
			}
			if (i != strlen(mensaje)-2)
			{
				morse[count] = 32;
				count++;
			}
		}	
	}
	char *mor = morse;
	return mor;
}
