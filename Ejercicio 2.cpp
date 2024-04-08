// Realiza un programa que cuente cuántas vocales tiene una cadena de caracteres ingresada por el usuario.
#include<stdio.h>
#include<string.h>
int cont, vocales, i, len;

char palabra[30];
main()
{
	printf("Ingrese una palabra: ");
	scanf("%s", & palabra);
	
	len = strlen(palabra);
	
	for(i=0;i<len;i++)
	{
		if(palabra[i] == 'a' ||
		   palabra[i] == 'e' ||
		   palabra[i] == 'i' ||
		   palabra[i] == 'o' ||
		   palabra[i] == 'u')
		   {
		   	  cont++;
		   }
	}
    printf("La cantidad de vocales es de %d", cont);
}