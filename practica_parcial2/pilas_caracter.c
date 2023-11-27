#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR 20 

typedef struct tiponodo
{
    char nomAr[MAX_STR];
    int pesoAr;
    struct tiponodo* siguiente;
} nodo;



void mostrarMay(nodo aux)
{
    if(aux.pesoAr > 35)
    {
        printf("%s \n", aux.nomAr);

    }
}

void mostrar(nodo aux)
{
    printf("%s \n", aux.nomAr);
    printf("%d \n", aux.pesoAr);
}

nodo* crear_nodo(char nombre[MAX_STR], int peso)
{
    nodo* u;
    u = (nodo*)malloc(sizeof(nodo));

    strcpy(u->nomAr, nombre);
    u->pesoAr = peso;

    u->siguiente = NULL;

    return u;
}

void apilar(nodo** p, nodo* u)
{
    printf("apilar_nodo\n");
    u->siguiente = *p;
    *p = u;
}

nodo desapilar(nodo** p)
{
    nodo* aux;
    nodo datos;

    datos = **p;
    aux = *p;
    *p = (*p)->siguiente;
    free(aux);

    return datos;
}

int main()
{
    char nombre[MAX_STR];
    int peso;
    nodo* p = NULL;

    printf("Ingrese nombre de archivo: ");
    scanf("%s",nombre);

    while(strcmp(nombre,"ESTRUCTURAS") != 0)
    {
        printf("Ingrese peso del archivo: ");
        scanf("%d", &peso);

        apilar(&p, crear_nodo(nombre, peso));

        printf("Ingrese nombre de archivo: ");
        scanf("%s",nombre);

    }
    //ojo con el break;

    // printf("\nVamos a desapilar todo\n");
    // while (p != NULL)
    // {
    //     mostrar(desapilar(&p));
    // }

    printf("\nLos archivos con peso mayor a 35Kb son:\n");
    while (p != NULL)
    {
        mostrarMay(desapilar(&p));
    }

    return 0;
}

