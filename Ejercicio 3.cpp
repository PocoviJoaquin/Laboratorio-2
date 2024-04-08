#include <stdio.h>
#include <string.h>
            
char palindromo[40];
int longitud;
int inicio=0,fin;
         
main()
{
    printf("\nIngrese una palabra: ");
    gets(palindromo);


    longitud=strlen(palindromo);

    for(fin=longitud-1; palindromo[fin]==palindromo[inicio] && fin>=0; inicio++,fin--);

    if(inicio==longitud){
        printf("Es un palindromo");
      }else{
        printf ("No es palindromo");
    }        
}
