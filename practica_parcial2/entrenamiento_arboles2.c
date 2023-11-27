#include <stdio.h>
#include <stdlib.h>

typedef struct arbol
{
    int dato;
    struct arbol* izq;
    struct arbol* der;
}treenode;

void crear(treenode** hoja, int * min_impar);
void insertar(treenode** hoja, int elem);
void mostrar(treenode* hoja);
void puntoA(treenode* hoja, int* cant_a);
void puntoB(treenode* hoja, int* min_impar);

int main()
{
    //punto a
    int cant_a = 0;

    //punto b
    int min_impar = -1;

    printf("arboles\n");
    treenode* arbol = NULL;

    crear(&arbol, &min_impar);
    printf("**************\n");
    printf("mostrar arbol\n");
    printf("***************\n");

    puntoA(arbol, &cant_a);
    puntoB(arbol, &min_impar);
    mostrar(arbol);
    if (arbol != NULL) {
        printf("\nLa cantidad de elementos pares con un hijo es de: %d\n", cant_a);
    }
    else {
        printf("\narbol vacio\n");
    }
    
    if (min_impar != -1) {
        printf("\nEl minimo elemento impar del arbol es: %d\n", min_impar);
    }
    else {
        printf("\nNo hubo elementos impares en el arbol.\n");
    }


    return 0;
}
void crear(treenode** hoja, int* min_impar)
{
    int numero;

    printf("ingrese numero\n");
    scanf("%d", &numero);

    while (numero != -1)
    {
        if (numero % 2 != 0) {
            *min_impar = numero;
        }

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



void mostrar(treenode* hoja)
{
    if (hoja != NULL)
    {
        mostrar(hoja->izq);
        printf("%d", hoja->dato);
        mostrar(hoja->der);
    }
    return;
}


void puntoA(treenode* hoja, int *cant_a) 
{
    if (hoja != NULL)
    {
        puntoA(hoja->izq, cant_a);
        //procesa a
        if (hoja->dato % 2 == 0 &&
            ((hoja->izq == NULL && hoja->der != NULL) ||
                (hoja->izq != NULL && hoja->der == NULL)) )
        {
            *cant_a = *cant_a + 1;
        }
        puntoA(hoja->der, cant_a);
    }
    return;
}

void puntoB(treenode* hoja, int * min_impar)
{
    if (hoja != NULL)
    {
        puntoB(hoja->izq, min_impar);
        //procesa b
        if (hoja->dato % 2 != 0 &&
            hoja->dato < *min_impar) {
            *min_impar = hoja->dato;
        }
        puntoB(hoja->der, min_impar);
    }
    return;
}