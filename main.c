#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int legajo;
    char nombreYapellido [30];
    int edad;
    int anio;

} stAlumno;

stAlumno* crearArreDinamico(int cant);
void mostrarArregloAlumnos(stAlumno arreglo[], int validos);
void mostrarDirecciones (int valor, int* pint, int **ppint);
int cantidadDePares (int arreglo[], int validos);
void funcionTraspasoEnMain (int arregloEnteros[], int validos, int* nuevoArreglo);
void mostrarArreglo (int arreglo[], int validos);
int* funcionTraspasoEnFuncion (int arregloEnteros[], int validos);
void funcionTraspasoPunterosDobles(int arreglo[], int validos, int **nuevoArregloDin);
void cargaAlumnos(char archivoAlumnos[]);
stAlumno cargaUnAlumno();
int cuentaRegistrosArchivoFtell(char nombreArchivo[]);
void copiarArchivoAarregloDinamicoEnMain (char nombreArchi[], stAlumno* nuevoArregloDinAlumnos);
void mostrarUnAlumno(stAlumno alumno);
void muestraAlumnosArchi(char archivoAlumnos[]);
stAlumno* copiarArchivoAarregloDinamicoEnFuncion (char nombreArchivo[], int cantidaDeRegistros);
void copiarArchivoAarregloDinamicoPunterosDobles(char nombreArchi[], stAlumno** arregloAlumnosDinamico, int cantDeRegistros);

int main()
{
    ///Codigo ejemplo
    /*
    int cant=2;
    stAlumno* nuevoArreglo = crearArreDinamico(cant);

    if (nuevoArreglo==NULL)
    {
        printf("No se pudo.");
        return 1;
    }
    mostrarArregloAlumnos(nuevoArreglo,cant);*/

    //1)-----------------------------------------------------------------------------------------
    /*int valor=10;
    int * pint = &valor;
    int ** ppint = &pint;

    mostrarDirecciones(valor, pint, ppint);
    printf("Valor nuevo: %i\n", valor);*/

    ///2)A)-----------------------------------------------------------------------------------------
    int arreglo[5]= {3,2,4,7,6};
    int cant= cantidadDePares(arreglo, 5);
    /*int* nuevoArregloMain = (int*)malloc(cant*sizeof(int));
    funcionTraspasoEnMain(arreglo, 5, nuevoArregloMain);*/

    //B)-----------------------------------------------------------------------------------------
    int* nuevoArregloFuncion = funcionTraspasoEnFuncion(arreglo, 5);

    //C)-----------------------------------------------------------------------------------------
    /*int* nuevoArregloPunterosDobles = NULL;
    funcionTraspasoPunterosDobles(arreglo, 5, &nuevoArregloPunterosDobles);
    mostrarArreglo(nuevoArregloPunterosDobles, cant);*/

    ///3)A)-----------------------------------------------------------------------------------------
    char nombreArchi[20]= "alumnos.bin";
    //cargaAlumnos(nombreArchi);
    int cantAlumnos = cuentaRegistrosArchivoFtell(nombreArchi);
    /*stAlumno * arregloAlumnosMain = (stAlumno*)calloc(cantAlumnos, sizeof(stAlumno));
    copiarArchivoAarregloDinamicoEnMain(nombreArchi, arregloAlumnosMain);
    mostrarArregloAlumnos(arregloAlumnosMain, cantAlumnos);*/ //los validos del alumno son los que creamos al declarar el arreglo dinamico.

    //B)-----------------------------------------------------------------------------------------
    /*stAlumno * arregloAlumnosFuncion = copiarArchivoAarregloDinamicoEnFuncion(nombreArchi, cantAlumnos);
    mostrarArregloAlumnos(arregloAlumnosFuncion,cantAlumnos);*/

    //C)------------------------------------------------------------------------------------------
    stAlumno* nuevoArregloDeAlumnos = NULL;
    copiarArchivoAarregloDinamicoPunterosDobles(nombreArchi,&nuevoArregloDeAlumnos, cantAlumnos);
    mostrarArregloAlumnos(nuevoArregloDeAlumnos, cantAlumnos);

    return 0;
}

///Codigo ejemplo
/*
stAlumno* crearArreDinamico(int cant)
{
    stAlumno* nuevo = NULL;

    //nuevo = (stAlumno*)malloc(cant*sizeof(stAlumno));
    nuevo = (stAlumno*)calloc(cant,sizeof(stAlumno));

    return nuevo;
}

NOTAS PARA REALLOC
void *realloc(void *ptr, size_t new_size);
ptr → Es un puntero al bloque de memoria previamente asignado (por malloc, calloc o realloc).*/


/*1. Se desea construir un programa que ilustre la situación que se tiene al emplear punteros y dobles punteros. Para ello, declare un puntero de int y un puntero de puntero del anterior, en la forma:
int valor;
int * pint = &valor;
int ** ppint = &pint;
Se pide construir un programa que muestre las direcciones de valor, pint y ppint, y que asigne distintos valores a la variable valor empleando pint y ppint.
*/

void mostrarDirecciones (int valor, int* pint, int **ppint)
{
    printf("variable valor: %i\n", &valor);
    printf("variable valor: %i\n", &pint);
    printf("variable valor: %i\n", &ppint);

    printf("Valor viejo: %i\n", valor);

    //primero es 3 pero luego lo cambia a 5.
    *pint = 3;
    **ppint = 5;
}

/**2.Se cuenta con un arreglo de números enteros que ya fue cargado.
a)Se pide hacer una función que copie los datos de todos los valores del arreglo mencionado que sean pares en otro arreglo del tamaño justo.
A tal fin, desarrolle una función que cuente la cantidad de elementos pares y otra función que se encargue del traspaso de los datos pares.
El ejercicio deberá ser realizado usando en la función dos parámetros de tipo arreglo (uno para el arreglo original de enteros y otro para el arreglo de pares) y creando el arreglo dinámico utilizando malloc en el Main antes de la invocación de la función de traspaso.
*/

int cantidadDePares (int arreglo[], int validos)
{
    int cant=0;

    for(int i=0; i<validos; i++)
    {
        if (arreglo[i]% 2 == 0)
        {
            cant++;
        }
    }

    return cant;
}

void funcionTraspaso (int arregloEnteros[], int validos, int* nuevoArreglo)
{
    int validosNuevoArreglo =0;
    for(int i=0; i<validos; i++)
    {
        if (arregloEnteros[i]% 2 == 0)
        {
            nuevoArreglo[validosNuevoArreglo] = arregloEnteros[i];
            validosNuevoArreglo++;
        }
    }

}
void mostrarArreglo (int arreglo[], int validos)
{
    for(int i=0; i<validos; i++)
    {
        printf("[%i] ", arreglo[i]);
    }
}

/**b)Ahora deberá realizarse lo mismo del ejercicio anterior pero creando el arreglo dinámico utilizando malloc dentro de la función y retornando el arreglo*/
int* funcionTraspasoEnFuncion (int arregloEnteros[], int validos)
{
    int cant = cantidadDePares(arregloEnteros, validos);

    int* nuevoArreglo = (int*)calloc(cant, sizeof(int));

    int validosNuevoArreglo =0;
    for(int i=0; i<validos; i++)
    {
        if (arregloEnteros[i]% 2 == 0)
        {
            nuevoArreglo[validosNuevoArreglo] = arregloEnteros[i];
            validosNuevoArreglo++;
        }
    }

    return nuevoArreglo;
}

/**c)Ahora deberá realizarse lo mismo del ejercicio anterior pero usando malloc dentro de la función, y en lugar de retornar el arreglo, trabajar con puntero doble*/

void funcionTraspasoPunterosDobles(int arreglo[], int validos, int **nuevoArregloDin)
{
    int cant = cantidadDePares(arreglo, validos);

    *nuevoArregloDin = (int*)malloc(cant*sizeof(int));

    int validosNuevoArreglo =0;
    for(int i=0; i<validos; i++)
    {
        if (arreglo[i]% 2 == 0)
        {
            (*nuevoArregloDin)[validosNuevoArreglo] = arreglo[i];
            validosNuevoArreglo++;
        }
    }
}


/** Utilizar el archivo de alumnos ya generado con el ejercicio 4 de dicho TP e incorporarlo a este TP.
* Utilizar la función ya hecha en el ejercicio 13 de dicho TP para contar la cantidad de alumnos existentes en el archivo
* Y en base a ello realizar lo siguiente:
a)Hacer una función que copie los registros de todos los alumnos existentes en el archivo en un arreglo del tamaño justo, creando el arreglo dinámico en el Main antes de la invocación de la función.
*/


 /// funciones aux de archivos
void cargaAlumnos(char archivoAlumnos[])
{
    int cont= 0;
    stAlumno a;
    FILE* archi;

    archi= fopen(archivoAlumnos,"ab");

    if(archi!=NULL) /// ENTRA EN CUALQUIERA DE LOS CASOS
    {
        printf("Ingreso de 5 alumnos: \n");
        while(cont<5)
        {
            a= cargaUnAlumno();

            fwrite(&a,sizeof(stAlumno),1,archi);

            cont++;
        }
        fclose(archi);
    }
}

stAlumno cargaUnAlumno()
{
    stAlumno a;

    puts("\n----------------------------------");
    printf("\n Ingrese legajo: ");
    scanf("%d", &a.legajo);

    printf("\n Ingrese nombre y apellido: ");
    fflush(stdin);
    gets(a.nombreYapellido);

    printf("\n Ingrese edad: ");
    scanf("%d", &a.edad);

    printf("\n Ingrese a�o que cursa: ");
    scanf("%d", &a.anio);
    puts("----------------------------------\n");

    return a;
}

int cuentaRegistrosArchivoFtell(char nombreArchivo[])
{
    int cantidad =0;
    FILE* archi;

    archi= fopen(nombreArchivo,"rb");

    if(archi!=NULL)
    {
        fseek(archi,0,SEEK_END); // me posiciono al final del archivo

        cantidad = ftell(archi)/ sizeof(stAlumno); // divido la cantidad de bytes totales del archivo por la cantidad de bytes de un registro de alumnos
        fclose(archi);              // si solo llamo a ftell sin dividir tengo que usar long en vez de int porque es un numero largo
    }

    return cantidad;
}

void copiarArchivoAarregloDinamicoEnMain (char nombreArchi[], stAlumno* nuevoArregloDinAlumnos)
{
    stAlumno aux;
    int validosArreglo=0;

    FILE *archi = fopen(nombreArchi, "rb");

    if(archi!=NULL)
    {
        while(fread(&aux, sizeof(stAlumno), 1, archi) == 1)
        {
            nuevoArregloDinAlumnos[validosArreglo] = aux;
            validosArreglo++;
        }
        fclose(archi);
    }

}
void mostrarUnAlumno(stAlumno alumno)
{
    puts("\n---------------------------------------");
    printf("\n           Legajo: %d", alumno.legajo);
    printf("\nNombre y Apellido: %s", alumno.nombreYapellido);
    printf("\n             Edad: %d", alumno.edad);
    printf("\n              Anio: %d", alumno.anio);
    puts("\n---------------------------------------");

}

void mostrarArregloAlumnos(stAlumno arreglo[], int validos)
{
    for(int i=0; i<validos; i++)
    {
      mostrarUnAlumno(arreglo[i]);
    }
}

void muestraAlumnosArchi(char archivoAlumnos[])
{
    FILE *archi;
    stAlumno a;
    archi= fopen(archivoAlumnos, "rb");

    if (archi!=NULL)
    {
        while( (fread(&a,sizeof(stAlumno),1,archi)) >0 )
        {
            mostrarUnAlumno(a);
        }
        fclose(archi);
    }
}

/**b)Ahora deberá realizarse lo mismo del ejercicio anterior pero usando malloc dentro de la función y retornando el arreglo*/
stAlumno* copiarArchivoAarregloDinamicoEnFuncion (char nombreArchivo[], int cantidaDeRegistros)
{
    stAlumno* arregloAlumnos = (stAlumno*)malloc(cantidaDeRegistros*sizeof(stAlumno));

    stAlumno aux;
    int validosArreglo=0;

    FILE *archi = fopen(nombreArchivo, "rb");

    if(archi!=NULL)
    {
        while(fread(&aux, sizeof(stAlumno), 1, archi) == 1)
        {
            arregloAlumnos[validosArreglo] = aux;
            validosArreglo++;
        }
        fclose(archi);
    }

    return arregloAlumnos;
}

/**c)Ahora deberá realizarse lo mismo del ejercicio anterior pero usando malloc dentro de la función, y en lugar de retornar el arreglo, trabajar con puntero doble.*/
void copiarArchivoAarregloDinamicoPunterosDobles(char nombreArchi[], stAlumno** arregloAlumnosDinamico, int cantDeRegistros)
{
    (*arregloAlumnosDinamico) = (stAlumno*)malloc(cantDeRegistros*sizeof(stAlumno));

    stAlumno aux;
    int validosArreglo=0;

    FILE *archi = fopen(nombreArchi, "rb");

    if(archi!=NULL)
    {
        while(fread(&aux, sizeof(stAlumno), 1, archi) == 1)
        {
            (*arregloAlumnosDinamico)[validosArreglo] = aux;
            validosArreglo++;
        }
        fclose(archi);
    }

}
