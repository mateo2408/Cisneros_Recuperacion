#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Leer README.md para entender el problema

//Estructura de datos
struct alumnos
{
    char nombre [60];
    char apellido [60];
    char carrera [60];
    float nota1;
    float nota2;
    float nota3;
};

//Funcion promedio
float promedio (float nota1, float nota2, float nota3)
{
    float promedio;
    promedio = (nota1 + nota2 + nota3) / 3;
    return promedio;
}

int comparacion(const void *a, const void *b)
    {
        struct alumnos *alumnoA = (struct alumnos *)a;
        struct alumnos *alumnoB = (struct alumnos *)b;
        return strcmp(alumnoA->nombre, alumnoB->nombre);
    }

int main()
{
    //Declaracion de variables
    struct alumnos datos[100];
    int opcion;
    int cantidad;
    do
    {
        printf("1. Ingresar datos\n");
        printf("0. Salir\n");
        scanf("%d", &opcion);
        fflush(stdin);
        switch (opcion)
        {
        case 1:
            printf("Ingrese la cantidad de alumnos: ");
            scanf("%d", &cantidad);
            fflush(stdin);

            for (int i = 0; i < cantidad; i++)
            {
                printf("Ingrse los datos del alumno %d\n", i+1);
                //Ingreso de datos
                printf("Ingrese el nombre: ");
                fgets(datos[i].nombre, sizeof(datos[i].nombre), stdin);
                datos[i].nombre[strcspn(datos[i].nombre, "\n")] = '\0';
                printf("Ingrese el apellido: ");
                fgets(datos[i].apellido, sizeof(datos[i].apellido), stdin);
                datos[i].apellido[strcspn(datos[i].apellido, "\n")] = '\0';
                printf("Ingrese la carrera: ");
                fgets(datos[i].carrera, sizeof(datos[i].carrera), stdin);
                datos[i].carrera[strcspn(datos[i].carrera, "\n")] = '\0';
                printf("Ingrese la primera nota: ");
                scanf("%f", &datos[i].nota1);
                fflush(stdin);
                printf("Ingrese la segunda nota: ");
                scanf("%f", &datos[i].nota2);
                fflush(stdin);
                printf("Ingrese la tercera nota: ");
                scanf("%f", &datos[i].nota3);
                fflush(stdin);
            }
            break;
        
        default:
            break;
        }
    } while (opcion != 0);
    //Escritura en archivo

    char archivo[] = "main.txt";
    FILE *alumnos;
    alumnos = fopen(archivo, "a");
    if (alumnos == NULL)
    {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    fseek(alumnos, 0, SEEK_END);
    if (ftell(alumnos) == 0)
    {
        fprintf(alumnos, "Nombre\t\tApellido\t\tCarrera\t\tNota1\t\tNota2\t\tNota3\t\tPromedio\n");
    }

    for (int i = 0; i < cantidad; i++)
    {
        fprintf(alumnos, "%s\t\t%s\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", datos[i].nombre, datos[i].apellido, datos[i].carrera, datos[i].nota1, datos[i].nota2, datos[i].nota3, promedio(datos[i].nota1, datos[i].nota2, datos[i].nota3));
    }
    fclose(alumnos);

    //Ordenar alfabeticamente
    
    qsort(datos, cantidad, sizeof(struct alumnos), comparacion);
    //Nuevo archivo
    FILE *alumnos_ordenados;
    alumnos_ordenados = fopen("alumnos_ordenados.txt", "w");
    if (alumnos_ordenados == NULL)
    {
        printf("Error al abrir el archivo\n");
        return 1;
    }
    fseek(alumnos_ordenados, 0, SEEK_END);
    if (ftell(alumnos_ordenados) == 0)
    {
        fprintf(alumnos_ordenados, "Nombre\t\tApellido\t\tCarrera\t\tNota1\t\tNota2\t\tNota3\t\tPromedio\n");
    }
    for (int i = 0; i < cantidad; i++)
    {
        fprintf(alumnos_ordenados, "%s\t\t%s\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", datos[i].nombre, datos[i].apellido, datos[i].carrera, datos[i].nota1, datos[i].nota2, datos[i].nota3, promedio(datos[i].nota1, datos[i].nota2, datos[i].nota3));
    }
    fclose(alumnos_ordenados);
    return 0;
}

