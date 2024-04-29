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

struct Persona buscarPersona(FILE *archivo, const char *nombre, const char *apellido, const char *dni) {
    struct Persona persona;
    rewind(archivo);

    while (fscanf(archivo, "%s %s %s", persona.nombre, persona.apellido, persona.dni) != EOF) {
        if ((nombre && apellido && strcmp(persona.nombre, nombre) == 0 && strcmp(persona.apellido, apellido) == 0) ||
            (dni && strcmp(persona.dni, dni) == 0)) {
            return persona; 
        }
    }

    struct Persona personaVacia = {"", "", ""};
    return personaVacia;
}

int compararPorNombreApellido(const void *a, const void *b) {
    const struct Persona *personaA = (const struct Persona *)a;
    const struct Persona *personaB = (const struct Persona *)b;
    int comparacionApellido = strcmp(personaA->apellido, personaB->apellido);
    if (comparacionApellido == 0) {
        return strcmp(personaA->nombre, personaB->nombre);
    }
    return comparacionApellido;
}

int compararPorDNI(const void *a, const void *b) {
    const struct Persona *personaA = (const struct Persona *)a;
    const struct Persona *personaB = (const struct Persona *)b;
    return strcmp(personaA->dni, personaB->dni);
}

int main() {
    FILE *archivo;
    int opcion;
    struct Persona persona;
    char nombreBuscar[50];
    char apellidoBuscar[50];
    char dniBuscar[20];

    archivo = fopen("datos_personas.txt", "a+");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    do {
        printf("\nMENU\n");
        printf("1. Ingresar datos\n");
        printf("2. Buscar persona por nombre y apellido\n");
        printf("3. Buscar persona por DNI\n");
        printf("4. Salir\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);
        fflush(stdin); 

        switch (opcion) {
            case 1:
                printf("Ingrese nombre: ");
                scanf("%s", persona.nombre);
                printf("Ingrese apellido: ");
                scanf("%s", persona.apellido);

                if (buscarPersona(archivo, persona.nombre, persona.apellido, NULL).nombre[0] != '\0') {
                    printf("La persona ya existe en el archivo.\n");
                } else {
                    printf("Ingrese DNI: ");
                    scanf("%s", persona.dni);

                    guardarDatos(archivo, persona);
                    printf("Datos guardados correctamente.\n");
                }
                break;
            case 2:
                printf("Ingrese el nombre y apellido a buscar:\n");
                printf("Nombre: ");
                scanf("%s", nombreBuscar);
                printf("Apellido: ");
                scanf("%s", apellidoBuscar);

                persona = buscarPersona(archivo, nombreBuscar, apellidoBuscar, NULL);
                if (persona.nombre[0] != '\0') {
                    printf("La persona fue encontrada en el archivo:\n");
                    printf("Nombre: %s\nApellido: %s\nDNI: %s\n", persona.nombre, persona.apellido, persona.dni);
                } else {
                    printf("La persona no fue encontrada en el archivo.\n");
                }
                break;
            case 3:
                printf("Ingrese el DNI a buscar:\n");
                printf("DNI: ");
                scanf("%s", dniBuscar);

                persona = buscarPersona(archivo, NULL, NULL, dniBuscar);
                if (persona.nombre[0] != '\0') {
                    printf("La persona fue encontrada en el archivo:\n");
                    printf("Nombre: %s\nApellido: %s\nDNI: %s\n", persona.nombre, persona.apellido, persona.dni);
                } else {
                    printf("La persona no fue encontrada en el archivo.\n");
                }
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida. Intente nuevamente.\n");
        }
    } while (opcion != 4);

    fclose(archivo);

    return 0;
}
