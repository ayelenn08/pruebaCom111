#include "prueba.h"
#include <stdio.h>

alumnos crearUnAlumno ()
{
    alumnos nuevo;
    printf("ingrese un nombre");
    fflush(stdin);
    scanf("%s", nuevo.nombre);

    return nuevo;
}
