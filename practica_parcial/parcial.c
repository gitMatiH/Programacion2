/*

En la universidad hay dos nuevas carreras:
Inteligencia artificial
Ciberseguridad

Se desea generar un sistema de gestion con la siguiente estructura:
Legajo
Nombre
Edad
Carrera (Seguridad/Inteligencia)
Año que esta cursando

Se pide:
1) Una funcion para cargar la informacion de los estudiantes
2) Crear una nueva lista en la que solo esten aquellos alumnos que están en inteligencia
y mas de dos años.
3) Generar una función que calcule y muestre el promedio de los estudiantes que eligen seguridad
4) Generar una función que permita eliminar a los estudiantes que deseen dejar la carrera. La misma
recibirá por parámetro numero de legajo.
5) Generar un menú para poder gestionar las funciones de la lista.
6) Crear una funcion que permita insertar delante de un alumno determinado (la búsqueda debe realizarse
utilizando un número de legajo que se le solicitará al usuario) los siguientes datos:
Numero de legajo=9999
Nombre = "PEPE"
Edad = 99
Carrera = "Inteligencia"
Año que está cursando = 0

*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct lista {
    int legajo;
    char nombre[30];
    int edad;
    char carrera[15];
    int anio;
    struct lista* sig;
} nodo;

void cargarLista(nodo*);
void mostrar(nodo*);
void generar(nodo*, nodo*);
float promedioSeguridad(nodo* listaEstudiantes);
nodo* eliminar1(nodo* listaEstudiantes, int legajo);
void eliminar2(nodo* listaEstudiantes, int legajo);
nodo* insertar1(nodo* listaEstudiantes, int legajo);
void insertar2(nodo* listaEstudiantes, int legajo);

int main()
{
    nodo* listaEstudiantes;
    nodo* listaIA2do;
    float promedio;
    int legajo;
    int opcion;

    listaEstudiantes = (nodo*)malloc(sizeof(nodo));
    listaIA2do = (nodo*)malloc(sizeof(nodo));

    printf("\n1: cargarLista");
    printf("\n2: generar");
    printf("\n3: promedio de estudiantes Seguridad");
    printf("\n4: eliminar por legajo");
    printf("\n5: insertar");
    printf("\n6: mostrar lista");
    printf("\nelija opcion, 0 para salir:\n");

    scanf("%d", &opcion);
    while (opcion != 0) {
        if (opcion == 1) {
            printf("\nSe carga informacion.\n");
            cargarLista(listaEstudiantes);
            mostrar(listaEstudiantes);
        }
        if (opcion == 2) {
            printf("\nSe crea lista de alumnos de IA y 2do anio.\n");
            generar(listaEstudiantes, listaIA2do);
            mostrar(listaIA2do);
        }
        if (opcion == 3) {
            printf("\nSe calcula el promedio estudiantes que eligen Seguridad sobre el total.\n");
            promedio = promedioSeguridad(listaEstudiantes);
            printf("\nEl promedio de estudiantes que eligen seguridad es: %.2f\n", promedio);
        }
        if (opcion == 4) {
            printf("\nSe eliminan estudiantes de la lista.\n");
            printf("\ningrese el legajo a buscar: ");
            scanf("%d", &legajo);
            listaEstudiantes = eliminar1(listaEstudiantes, legajo);
            eliminar2(listaEstudiantes, legajo);
        }
        if (opcion == 5) {
            printf("\nSe inserta delante de alumno por condicion.\n");
            printf("\ningrese el legajo para la condicion: ");
            scanf("%d", &legajo);
            //listaEstudiantes = insertar1(listaEstudiantes, legajo);   //esto no pide
            insertar2(listaEstudiantes, legajo);
        }
        if (opcion == 6) {
            printf("\nSe muestra la lista total:\n");
            mostrar(listaEstudiantes);
        }


        printf("\n1: cargarLista");
        printf("\n2: generar");
        printf("\n3: promedio de estudiantes Seguridad");
        printf("\n4: eliminar por legajo");
        printf("\n5: insertar");
        printf("\n6: mostrar lista");
        printf("\nelija opcion, 0 para salir:\n");
        scanf("%d", &opcion);
    }

}


void cargarLista(nodo* listaEstudiantes) {

    printf("\nIngrese el numero de legajo, 0 para terminar:\n");
    scanf("%d", &(listaEstudiantes->legajo));

    if (listaEstudiantes->legajo != 0) {

        printf("\nIngrese el nombre del alumno:\n");
        fflush(stdin);
        scanf("%[^\n]", &(listaEstudiantes->nombre));
        //gets(listaEstudiantes->nombre);
        fflush(stdin);

        printf("\nIngrese la edad:\n");
        scanf("%d", &(listaEstudiantes->edad));
        while (listaEstudiantes->edad < 17) {
            printf("\nEdad invalida\n");
            printf("\nIngrese la edad:\n");
            scanf("%d", &(listaEstudiantes->edad));
        }

        printf("\nIngrese la carrera Seguridad/Inteligencia:\n");
        fflush(stdin);
        scanf("%s", &(listaEstudiantes->carrera));  // hacerle un print while != /0 a ver q pasa
        while ( !(strcmp(listaEstudiantes->carrera, "Seguridad") == 0
                || strcmp(listaEstudiantes->carrera, "Inteligencia") == 0) )
        {
            printf("Ingreso invalido\n");
            printf("\nIngrese la carrera Seguridad/Inteligencia:\n");
            fflush(stdin);
            scanf("%s", &(listaEstudiantes->carrera));
        }

        printf("\nIngrese anio:\n");
        scanf("%d", &(listaEstudiantes->anio));
        while (listaEstudiantes->anio < 0) {
            printf("\ninvalido\n");
            printf("\nIngrese anio:\n");
            scanf("%d", &(listaEstudiantes->anio));
        }

        nodo* nuevoNodo = (nodo*)malloc(sizeof(nodo));
        listaEstudiantes->sig = nuevoNodo;
        cargarLista(listaEstudiantes->sig);
    }
    else {
        listaEstudiantes->sig = NULL;
    }
    return;
}

//precond: lista valida (terminada en NULL)
void mostrar(nodo* listaEstudiantes) {

    if (listaEstudiantes->sig != NULL) {
        printf("\n");
        printf("\nlegajo: %d", listaEstudiantes->legajo);
        printf("\nnombre: %s", listaEstudiantes->nombre);
        printf("\nedad: %d", listaEstudiantes->edad);
        printf("\ncarrera: %s", listaEstudiantes->carrera);
        printf("\nanio: %d", listaEstudiantes->anio);
        printf("\n");
        mostrar(listaEstudiantes->sig);
    }

}

void generar(nodo* listaEstudiantes, nodo* listaIA2do) {

    listaIA2do->sig = NULL;
    if (strcmp(listaEstudiantes->carrera, "Inteligencia") == 0
        && listaEstudiantes->anio > 2)
    {
        listaIA2do->legajo = listaEstudiantes->legajo;
        strcpy(listaIA2do->nombre, listaEstudiantes->nombre);
        listaIA2do->edad = listaEstudiantes->edad;
        strcpy(listaIA2do->carrera, listaEstudiantes->carrera);
        listaIA2do->anio = listaEstudiantes->anio;
    }

    if (listaEstudiantes->sig != NULL) {

        if (strcmp(listaEstudiantes->carrera, "Inteligencia") == 0
            && listaEstudiantes->anio > 2)
        {
            nodo* nodoNuevo = (nodo*)malloc(sizeof(nodo));
            listaIA2do->sig = nodoNuevo;
            generar(listaEstudiantes->sig, listaIA2do->sig);
        }
        else {
            generar(listaEstudiantes->sig, listaIA2do);
        }

    }
    return;

}


float promedioSeguridad(nodo* listaEstudiantes) {

    float promedio = 0;
    int contador = 0;
    int estudiantes = 0;
    while (listaEstudiantes->sig != NULL) { //claro esto fallo porque toma el que esta de mas
        //if (!strcmp(listaEstudiantes->carrera, "Seguridad")) {
        if ( strcmp(listaEstudiantes->carrera, "Seguridad") == 0 ) {
            estudiantes = estudiantes + 1;
        }
        contador = contador + 1;

        listaEstudiantes = listaEstudiantes->sig;
    }

    if (contador != 0) {

        promedio = ((float)estudiantes) / contador;
    }
    return promedio;
}


nodo* eliminar1(nodo* listaEstudiantes, int legajo) {
    //elimina de ppio de lista
    nodo* aux;
    if (listaEstudiantes->legajo == legajo) {
        aux = listaEstudiantes->sig;
        free(listaEstudiantes);
        return aux;
    }
    return listaEstudiantes;
}


void eliminar2(nodo* listaEstudiantes, int legajo) {
    //elimina en resto de lista
    while (listaEstudiantes->sig != NULL && listaEstudiantes->sig->sig != NULL) {
        if (listaEstudiantes->legajo == legajo) {
            listaEstudiantes->sig = listaEstudiantes->sig->sig;
            free(listaEstudiantes);
        }

        listaEstudiantes = listaEstudiantes->sig;
    }

}


nodo* insertar1(nodo* listaEstudiantes, int legajo) {
    //inserta al ppio el nodo deseado, si es que el legajo coincide
    if (listaEstudiantes->legajo == legajo) {
        nodo* nuevoNodo = (nodo*)malloc(sizeof(nodo));
        nuevoNodo->legajo = 9999;
        strcpy(nuevoNodo->nombre, "PEPE");
        nuevoNodo->edad = 99;
        strcpy(nuevoNodo->carrera, "Inteligencia");
        nuevoNodo->anio = 0;

        nuevoNodo->sig = listaEstudiantes;
        listaEstudiantes = nuevoNodo;

        return listaEstudiantes;
    }else{
        return listaEstudiantes;
    }

}


void insertar2(nodo* listaEstudiantes, int legajo) {
    // se asume legajo es unico
    // inserta en cualquier lado en medio de la lista
    nodo* nuevoNodo = NULL;
    while (listaEstudiantes->sig != NULL) {
        if (listaEstudiantes->legajo == legajo) {

            nuevoNodo = (nodo*)malloc(sizeof(nodo));
            nuevoNodo->legajo = 9999;
            strcpy(nuevoNodo->nombre, "PEPE");
            nuevoNodo->edad = 99;
            strcpy(nuevoNodo->carrera, "Inteligencia");
            nuevoNodo->anio = 0;

            nuevoNodo->sig = listaEstudiantes->sig;
            listaEstudiantes->sig = nuevoNodo;
        }

        listaEstudiantes = listaEstudiantes->sig;
    }
}