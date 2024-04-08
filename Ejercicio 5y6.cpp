/* Realiza un programa que determine si una cadena de caracteres ingresadapor el usuario es un anagrama de otra 
cadena también ingresada por elusuario. Un anagrama es una palabra o frase formada por las mismas letras de
otra palabra o frase, pero en un orden diferente, como por ejemplo roma y amor.*/
#include<stdio.h>
#include<string.h>
char palabra[30];
char palabra2[30];
int cont, cont2, i, j, len, len2;
main()
{
	printf("Ingrese la primera palabra: ");
	scanf("%s", & palabra);
	
	printf("Ingrese la segunda palabra: ");
	scanf("%s", palabra2);
	
	len = strlen(palabra);
	
	len2= strlen(palabra2);
	
	if(len == len2)
	{
	    for(i=0;i<len;i++)
	{
		for(j=0;j<len2;j++)
		{
			if(palabra2[j]==palabra[i])
			{
			cont++;
			break;
			}
		}
   }
   }
		    if(cont == len)
		    {
		    	printf("Hay anagrama");
			}
			
			else
			{
		       printf("No hay anagrama");
		    }
}