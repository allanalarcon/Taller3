#include "cifrado.h"
#include <string.h>
#include <ctype.h>

char *cifradoCiclico(char *mensaje, int llave)
{
	char cifrado[1024] = "";	
	for (int i = 0; i < strlen(mensaje); i++)
	{
		if (ispunct(toupper(mensaje[i])) || isspace(toupper(mensaje[i])))
			cifrado[i] = toupper(mensaje[i]);
		else
		{
			cifrado[i] = toupper(mensaje[i]) + llave;
			if(llave >= 0)
			{
				if(toupper(mensaje[i]) >= 65 && toupper(mensaje[i]) <= 90)
				{
					while(cifrado[i] < 65 || cifrado[i] > 90)
					{
						cifrado[i] = cifrado[i] - 26;
					}
				}
			}
			else
			{
				if(toupper(mensaje[i]) >= 65 && toupper(mensaje[i]) <= 90)
				{
					while(cifrado[i] < 65 || cifrado[i] > 90)
					{
						cifrado[i] = cifrado[i] + 26;
					}
				}
			}
		}
	}
	char *cif = cifrado;
	return cif;
}

char*  cifradoAutoLlave(char* mensaje,  char* llave){
        int nuevallave = -strlen(llave);
        for (int i = 0; i < strlen(mensaje); i++)
        {
                if (ispunct(mensaje[i]) || isspace(mensaje[i]))
                        cifrado[i] = mensaje[i];
                else if (mensaje[i] < (65 + strlen(llave)))
                        cifrado[i] = 65+i;
                else{
                        cifrado[i] = mensaje[i] + nuevallave;
                         if(mensaje[i]>=65 && mensaje[i]<=90){
                                while(cifrado[i]<65 || cifrado[i]>90){
                                        cifrado[i] = cifrado[i] + 26;
                                }
                         }
                          if(mensaje[i]>=97 && mensaje[i]<=122){
                                while(cifrado[i]<97 || cifrado[i]>122){
                                        cifrado[i] = cifrado[i] + 26;
                                }
                         }
                    }                
        }
        return cifrado;
}

