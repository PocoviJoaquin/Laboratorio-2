/* Realiza un programa que reemplace todas las apariciones de un carácter
en una cadena de caracteres ingresada por el usuario por otro carácter
también ingresado por el usuario */
#include<stdio.h>
#include<string.h>
char palabra[30];
int i, j, len;
main()
{
	printf("Ingrese una palabra: ");
	scanf("%s", & palabra);
	len = strlen(palabra);
	for(i=0;i<len;i++)
	{
		if(palabra[i] == 'i')
		{
			for(j=0;j<len;j++)
			{
				if(palabra[j] != 'i')
				{
					palabra[i]=palabra[j];
		        }
		    }
	    }
    }
	printf("Ingrese la palabra modificada: %s", palabra);}