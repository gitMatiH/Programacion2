

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct arbol
{
    int dato;
    struct arbol* izq;
    struct arbol* der;
}treenode;

void crear(treenode** hoja, int* raiz);
void insertar(treenode** hoja, int elem);
void mostrar(treenode* hoja, int raiz, int* mayor, int* cantidadImpares);

int main()
{
    int raiz;
    int mayor;
    int cantidadImpares;

    printf("arboles\n");
    treenode* arbol = NULL;

    crear(&arbol, &raiz);
    printf("**************\n");
    printf("mostrar arbol\n");
    printf("***************\n");

    mayor = -2;
    cantidadImpares = 0;
    mostrar(arbol, raiz, &mayor, &cantidadImpares);

    if (mayor == -2) {
        printf("\nNo hubo divisores de la raiz.\n");
    }
    else if(mayor == -1){
        printf("\nArbol vacio.\n");
    }
    else {
        printf("\nEl mayor elemento del arbol divisor de la raiz fue: %d\n", mayor);
    }


    printf("\nLa cantidad de nodos hojas impares fue: %d\n", cantidadImpares);


    return 0;
}
void crear(treenode** hoja, int* raiz)
{
    int numero;

    printf("ingrese numero\n");
    scanf("%d", &numero);
    *raiz = numero;


    while (numero != -1)
    {

        insertar(&(*hoja), numero);
        printf("ingrese numero\n");
        scanf("%d", &numero);
    }
}

void insertar(treenode** hoja, int elem)
{
    int numero = elem;
    if (elem == -1)
        return;
    if (*hoja == NULL)
    {
        //creo la hoja vacia
        (*hoja) = (treenode*)malloc(sizeof(treenode));
        (*hoja)->dato = elem;
        (*hoja)->der = NULL;
        (*hoja)->izq = NULL;
    }
    else {

        if (numero > (*hoja)->dato)
        {
            insertar(&(*hoja)->der, elem);
        }
        else
        {
            insertar(&(*hoja)->izq, elem);
        }
    }
    return;
}



void mostrar(treenode* hoja, int raiz, int * mayor, int *cantidadImpares)
{
    if (hoja != NULL)
    {


        mostrar(hoja->izq, raiz, mayor, cantidadImpares);
        printf("%d ", hoja->dato);
        
        //funcion a
        if (raiz % hoja->dato == 0 && 
            hoja->dato != raiz) {
            
            if (hoja->dato > *mayor) {
                *mayor = hoja->dato;
            }
        }

        //funcion b
        if (hoja->izq == NULL && hoja->der == NULL) {
            if (hoja->dato % 2 != 0) {
                *cantidadImpares = *cantidadImpares+1;
            }
        }

        mostrar(hoja->der, raiz, mayor, cantidadImpares);

    }
    return;
}

