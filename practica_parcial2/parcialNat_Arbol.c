#include <stdio.h>
#include <stdlib.h>

typedef struct arbol
{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;

void crear (treenode **hoja, int* );
void insertar(treenode **hoja, int elem);
void mostrar (treenode *hoja);
int cantElemPar (treenode *hoja, int *cant);
int minElemImpar (treenode *hoja, int *min);

int main ()
{
    int raiz;
    int cant = 0;
    int min;

    printf ("Arboles\n");
    treenode* arbol=NULL;

    crear (&arbol,&min);
    printf ("**************\n");
    printf ("Mostrar Arbol\n");
    printf ("***************\n");

    mostrar (arbol);

    printf("\n");
    //a)
    cantElemPar (arbol,&cant);
    printf("La cantidad de elementos pares con un hijo es: %d",cant);

    printf("\n");
    //b)
    minElemImpar(arbol, &min);
    printf("El elemento minimo impar del arbol es: %d\n",min);






    return 0;
}
void crear (treenode **hoja, int *min)
{
    int numero;

    printf ("Ingrese numero: ");
    scanf ("%d",&numero);
    *min = numero;

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

int cantElemPar (treenode *hoja, int *cant)
{
    if(hoja != NULL)
    {
        cantElemPar(hoja->izq,cant);

        if  ((hoja->dato % 2 == 0) && //si son pares
            ((hoja->izq != NULL) && (hoja->der == NULL)|| //solo un hijo
             (hoja->izq == NULL) && (hoja->der != NULL)))
        {
            *cant = *cant + 1;
        }
        cantElemPar(hoja->der,cant);
    }

}

int minElemImpar (treenode *hoja, int *min)
{
    if(hoja != NULL)
    {
        minElemImpar(hoja->izq, min); 
        if((hoja->dato % 2 != 0)&&(hoja->dato < *min))
        {
            *min = hoja->dato;
        }
        minElemImpar(hoja->der, min);
    }

}
