//Autora: Natasha :3
/*a) Mostrar los elementos mayores a la raíz que tengan solo un hijo y que el 
mismo sea menor que supadre.
b) Cantidad de nodos con dos hijos impares.
c) Cree un árbol que cumpla con las condiciones anteriores y grafíquelo.*/


#include <stdio.h>
#include <stdlib.h>

typedef struct arbol
{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;

void crear (treenode **hoja, int *);
void insertar(treenode **hoja, int elem);

void mostrarPre (treenode *hoja);
void mostrar (treenode *hoja);
void mostrarPost (treenode *hoja);

void mostrarMaxRaiz (treenode *hoja, int *); //(a)
void cantNodos (treenode *hoja, int *); //(b)
int main ()
{
    int raiz;
    int cont=0;

    printf ("Arboles\n");
    treenode* arbol=NULL;

    crear (&arbol,&raiz);
    printf ("**************\n");
    printf ("Mostrar Arbol\n");
    printf ("***************\n");

    mostrar (arbol);

    printf("\nMostrar en Preorden:\n");
    mostrarPre(arbol);

    printf("\nMostrar en Post orden:\n");
    mostrarPost(arbol);

    printf("\nElementos mayores a la raiz y menores a su padre son: \n");
    mostrarMaxRaiz(arbol,&raiz);
    
    
    cantNodos(arbol,&cont);
    printf("\nCantidad de elementos con 2 hijos impares es: %d\n", cont);


    return 0;
}
void crear (treenode **hoja, int *raiz)
{
    int numero;

    printf ("Ingrese numero: ");
    scanf ("%d",&numero);
    *raiz=numero;
    while (numero!=-1)
    {

        insertar(&(*hoja),numero);
        printf ("Ingrese numero: ");
        scanf ("%d",&numero);
    }
}

void insertar (treenode **hoja,int elem)
{
    int numero=elem;
    if (elem==-1)
        return;
    if (*hoja==NULL)
    {
        //creo la hoja vacia
        (*hoja)=(treenode*)malloc(sizeof(treenode));
        (*hoja)->dato=elem;
        (*hoja)->der=NULL;
        (*hoja)->izq=NULL;
    }else{




    if (numero>(*hoja)->dato)
    {
        insertar (&(*hoja)->der,elem);
    }
    else
    {
        insertar (&(*hoja)->izq,elem);
    }
    }
    return;
}



void mostrar (treenode *hoja)
{
    if (hoja!=NULL)
    {

        mostrar(hoja->izq);
        printf("%d ",hoja->dato);
        mostrar(hoja->der);

    }
    return;
}

void mostrarPre (treenode *hoja)
{
    if (hoja!=NULL)
    {
        printf("%d ",hoja->dato);
        mostrarPre(hoja->izq);
        mostrarPre(hoja->der);
    }
    return;
}

void mostrarPost (treenode *hoja)
{
    if (hoja!=NULL)
    {
        mostrarPost(hoja->izq);
        mostrarPost(hoja->der);
        printf("%d ",hoja->dato);
    }
    return;
}


//a) Mostrar los elementos mayores a la raíz que tengan solo un hijo y 
//   que el mismo sea menor que supadre.

void mostrarMaxRaiz(treenode *hoja, int *raiz)
{
     if (hoja!=NULL)
    {
        mostrarMaxRaiz(hoja->izq, raiz);
        
        if((hoja->izq != NULL && hoja->der == NULL)&&
            (hoja->dato > *raiz))
            {
              printf("%d ",hoja->dato); 
            }
        mostrarMaxRaiz(hoja->der, raiz);
    }
    return;
}

//b) Cantidad de nodos con dos hijos impares.
void cantNodos (treenode *hoja, int *cont)
{
      if (hoja!=NULL)
    {

        cantNodos(hoja->izq, cont);
        
        if((hoja->izq != NULL && hoja->der != NULL)&&
            (hoja->dato %2 != 0))
            {
              *cont = *cont + 1;
            }
        cantNodos(hoja->der, cont);

    }
    return;
    
}
