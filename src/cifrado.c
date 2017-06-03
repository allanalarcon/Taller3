#include "cifrado.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char cifrado[1024] = "";

char* cifradoCiclico(char* mensaje, int llave){
        for (int i = 0; i < strlen(mensaje); i++)
        {
                if (ispunct(mensaje[i]) || isspace(mensaje[i]))
                        cifrado[i] = mensaje[i];
                else{
                        cifrado[i] = mensaje[i] + llave;
                        if(llave>=0){
                                if(mensaje[i]>=65 && mensaje[i]<=90){
                                        while(cifrado[i]<65 || cifrado[i]>90){
                                                cifrado[i] = cifrado[i] - 26;
                                        }
                                }
                                if(mensaje[i]>=97 && mensaje[i]<=122){
                                        while(cifrado[i]<97 || cifrado[i]>122){
                                                cifrado[i] = cifrado[i] - 26;
                                        }
                                }
                        }
                        else{
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
        }
        //printf("%c", cifrado[i]);
        return cifrado;
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
