#include <stdio.h>
#include <stdlib.h>

typedef struct arbol
{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;

void crear (treenode **hoja, int*);
void insertar(treenode **hoja, int elem);
void mostrar (treenode *hoja);
int buscar (treenode *hoja, int n);

int main ()
{
    int n,raiz,resultado;


    printf ("ARBOLES\n");
    treenode* arbol=NULL;


    crear (&arbol,&raiz);
    printf ("**************\n");
    printf ("Mostrar arbol\n");
    printf ("***************\n");

    printf("Introducir el numero que desea buscar: ");
    scanf("%d",&n);

    resultado = buscar(arbol,n);
    if(resultado == 1){
        printf("El numero %d se encuentra en el arbol.\n",n);
        
    }else{
        printf("El numero no esta en el arbol.\n");
    }

    

    return 0;
}
void crear (treenode **hoja,int *raiz)
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
        printf("%d \n",hoja->dato);
        mostrar(hoja->der);
        //printf("%d \n",hoja->dato);
    }
    return;
}

int buscar (treenode *hoja, int n)
{
    if(hoja != NULL)
    {
        if(hoja->dato != n){ //analogia viceversa
            return 1;
        }else{ //si no encuentra n busca en las otras hojas.
            buscar(hoja->izq,n);

            buscar(hoja->der,n);
        }
    }
    return 0;
}



