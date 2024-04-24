#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Persona {
    char nombre[50];
    char apellido[50];
    char dni[20];
};

void guardarDatos(FILE *archivo, struct Persona persona) {
    fprintf(archivo, "%s %s %s\n", persona.nombre, persona.apellido, persona.dni);
}

void buscarPorDNI(FILE *archivo, const char *dni) {
    struct Persona persona;
    rewind(archivo); 

    while (fscanf(archivo, "%s %s %s", persona.nombre, persona.apellido, persona.dni) != EOF) {
        if (strcmp(persona.dni, dni) == 0) {
            printf("Nombre: %s\nApellido: %s\n", persona.nombre, persona.apellido);
            return;
        }
    }
    printf("No se encontraron datos para el DNI especificado.\n");
}
int main() {
    FILE *archivo;
    int opcion;
    struct Persona persona;
    char dniBuscar[20];

    archivo = fopen("datos_personas.txt", "a+"); 

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }
    do {
        printf("\nMENU\n");
        printf("1. Ingresar datos\n");
        printf("2. Buscar por DNI\n");
        printf("3. Salir\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);
        fflush(stdin); 

        switch (opcion) {
            case 1:
                printf("Ingrese nombre: ");
                scanf("%s", persona.nombre);
                
				printf("Ingrese apellido: ");
                scanf("%s", persona.apellido);
                
				printf("Ingrese DNI: ");
                scanf("%s", persona.dni);
                
                guardarDatos(archivo, persona); 
                
				printf("Datos guardados correctamente.\n");
                
				break;
            case 2:
                
				printf("Ingrese el DNI a buscar: ");
               
			    scanf("%s", dniBuscar);
               
			    buscarPorDNI(archivo, dniBuscar); // Buscar y mostrar datos por DNI
               
			    break;
            case 3:
               
			    printf("Saliendo del programa...\n");
              break;
            
			default:
                printf("Opcion no valida. Intente nuevamente.\n"); }
    } while (opcion != 3);

    fclose(archivo); 
	return 0;}



