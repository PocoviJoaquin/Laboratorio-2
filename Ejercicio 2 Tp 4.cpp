#include <stdio.h>
#include <string.h>

struct Persona {
    char nombre[50];
    char apellido[50];
    char dni[20];
};

// Función para guardar los datos de una persona en un archivo
void guardarDatos(FILE *archivo, struct Persona persona) {
    fprintf(archivo, "%s %s %s\n", persona.nombre, persona.apellido, persona.dni);
}

// Función para buscar una persona por nombre y apellido
void buscarPersona(FILE *archivo, const char *nombre, const char *apellido) {
    struct Persona persona;

    rewind(archivo); // Volver al inicio del archivo

    while (fscanf(archivo, "%s %s %s", persona.nombre, persona.apellido, persona.dni) != EOF) {
        if (strcmp(persona.nombre, nombre) == 0 && strcmp(persona.apellido, apellido) == 0) {
            printf("Nombre: %s\nApellido: %s\nDNI: %s\n", persona.nombre, persona.apellido, persona.dni);
            return;
        }
    }

    printf("No se encontraron datos para la persona especificada.\n");
}

int main() {
    FILE *archivo;
    int opcion;
    struct Persona persona;
    char nombreBuscar[50];
    char apellidoBuscar[50];

    archivo = fopen("datos_personas.txt", "a+"); // Abrir el archivo en modo de lectura/escritura (agregar al final)

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    do {
        printf("\nMENU\n");
        printf("1. Ingresar datos\n");
        printf("2. Buscar persona\n");
        printf("3. Salir\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);
        fflush(stdin); // Limpiar el búfer de entrada

        switch (opcion) {
            case 1:
                printf("Ingrese nombre: ");
                scanf("%s", persona.nombre);
                printf("Ingrese apellido: ");
                scanf("%s", persona.apellido);
                printf("Ingrese DNI: ");
                scanf("%s", persona.dni);
                
                guardarDatos(archivo, persona); // Guardar los datos en el archivo
                printf("Datos guardados correctamente.\n");
                break;
            case 2:
                printf("Ingrese el nombre y apellido a buscar:\n");
                printf("Nombre: ");
                scanf("%s", nombreBuscar);
                printf("Apellido: ");
                scanf("%s", apellidoBuscar);

                buscarPersona(archivo, nombreBuscar, apellidoBuscar); // Buscar persona por nombre y apellido
                break;
            case 3:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida. Intente nuevamente.\n");
        }
    } while (opcion != 3);

    fclose(archivo); // Cerrar el archivo al salir del programa

    return 0;
}

