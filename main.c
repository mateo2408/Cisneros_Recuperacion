#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
int promedio (float nota1, float nota2, float nota3)
{
    float promedio;
    promedio = (nota1 + nota2 + nota3) / 3;
    return promedio;
}

int main()
{
    //Declaracion de variables
    struct alumnos (datos);
    int cantidad;
    //Ingreso de datos
    printf("Ingrese la cantidad de alumnos a ingresar: ");
    scanf("%d", &cantidad);
    fflush(stdin);
    for (int i = 0; i < cantidad; i++)
    {
        //Ingreso de datos
        printf("Ingrese el nombre: ");
        fgets(datos.nombre, sizeof(datos.nombre), stdin);
        datos.nombre[strcspn(datos.nombre, "\n")] = '\0';
        printf("Ingrese el apellido: ");
        fgets(datos.apellido, sizeof(datos.apellido), stdin);
        datos.apellido[strcspn(datos.apellido, "\n")] = '\0';
        printf("Ingrese la carrera: ");
        fgets(datos.carrera, sizeof(datos.carrera), stdin);
        datos.carrera[strcspn(datos.carrera, "\n")] = '\0';
        printf("Ingrese la primera nota: ");
        scanf("%f", &datos.nota1);
        fflush(stdin);
        printf("Ingrese la segunda nota: ");
        scanf("%f", &datos.nota2);
        fflush(stdin);
        printf("Ingrese la tercera nota: ");
        scanf("%f", &datos.nota3);
        fflush(stdin);
    }
    //Escritura en archivo
    FILE *archivo;
    archivo = fopen("origen.txt", "a");
    if (archivo != NULL)
    {
        //Imprimimos todos los datos
        do
        {
            fprintf(archivo,"%s %s , %s, %f, %f, %f", datos.nombre, datos.apellido, datos.carrera, datos.nota1, datos.nota2, datos.nota3);
        } while (cantidad != cantidad);
        
    }
    else
    {
        printf("No se pudo abrir el archivo");
    }
    fclose(archivo);
    
    //Ordenar afabeticamente los datos de origen.txt en nuevo.txt
    return 0;
}

