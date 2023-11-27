#include <stdio.h>
#include <stdlib.h>

typedef struct arbol
{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;

void crear (treenode **hoja, int *, int *);
void insertar(treenode **hoja, int elem);
void mostrar (treenode *hoja);
int buscarMayor (treenode *hoja, int raiz, int* );
int cantHojaImp (treenode *hoja, int* );

int main ()
{
    int raiz;
    int max;
    int cant=0;

    printf ("arboles\n");
    treenode* arbol=NULL;

    crear (&arbol, &raiz , &max);
    printf ("**************\n");
    printf ("Mostrar Arbol\n");
    printf ("***************\n");

    mostrar (arbol);

    printf("\n");
    //a)
    buscarMayor (arbol,raiz,&max);
    printf("EL mayor elemento del arbol es: %d",max);

    printf("\n");
    //b)
    cantHojaImp(arbol, &cant);
    printf("La cantidad de hojas impares es: %d\n",cant);






    return 0;
}
void crear (treenode **hoja, int *raiz, int *max)
{
    int numero;

    printf ("Ingrese numero: ");
    scanf ("%d",&numero);
    *raiz = numero;
    *max = numero;

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

int buscarMayor (treenode *hoja, int raiz,  int* max)
{
    if(hoja != NULL)
    {
        buscarMayor(hoja->izq, raiz, max);
        if((raiz % hoja->dato == 0) && (hoja->dato != raiz)) // es divisible
        {
            *max = hoja->dato;
            if(hoja->dato > *max) //hallar el mayor.
            {
                *max = hoja->dato;
            }
        }
        buscarMayor(hoja->der, raiz, max);
    }

}

int cantHojaImp (treenode *hoja, int* cant)
{
    if(hoja != NULL)
    {
        cantHojaImp(hoja->izq, cant); 
        if((hoja->dato % 2 != 0) && //impares
            (hoja->izq == NULL && hoja->der == NULL)) //nodos hojas
        {
            *cant = *cant + 1;
        }
        cantHojaImp(hoja->der, cant);
    }

}
