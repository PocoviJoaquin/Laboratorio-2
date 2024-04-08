#include<stdio.h>
char nombre[20];
main()
{
	printf("Ingrese su nombre: ");
	scanf("%s", &nombre);
	
	printf("Su nombre es %s", nombre);
}