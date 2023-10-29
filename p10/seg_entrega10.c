#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct arbol
{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;

void crear (treenode **hoja, int*);
void borrar(treenode** hoja);
void insertar(treenode **hoja, int elem);
void mostrarPre (treenode *hoja);
void mostrarOrd(treenode *hoja);
void mostrarPos (treenode *hoja);

void valorMax(treenode *hoja, int * ,int raiz);
void hojasDiv(treenode *hoja, int *, int raiz);
int sumNodosPar(treenode *hoja, int *);

int main ()
{
    int opcion;
    int n,raiz;
    int max, cont, sum=0;

    printf ("ARBOLES\n");
    treenode* arbol=NULL;


    printf("\nMenu\n");
    printf("1. Crear Arbol.\n");
    printf("2. Borrar Arbol.\n");
    printf("3. Mostrar en Preorden.\n");
    printf("4. Mostrar en Orden.\n");
    printf("5. Mostrar en Postorden.\n");
    printf("6. Valor maximo multiplo raiz.\n");
    printf("7. Cantidad de nodos hojas divisores raiz.\n");
    printf("8. Sumatoria nodos pares con un hijo.\n");
    printf("0. Salir.\n");

    printf("\nIntroduzca opcion: ");
    scanf("%d", &opcion);
    while (opcion != 0) {
        switch (opcion)
        {
        case 1:
            crear(&arbol, &raiz);
            break;

        case 2:
            borrar(&arbol);
            arbol = NULL;
            break;

        case 3:

            printf("\n\nEN PREORDEN\n");
            mostrarPre(arbol);
            break;

        case 4:

            printf("\n\nEN ORDEN\n");
            mostrarOrd(arbol);
            break;

        case 5:
            printf("\n\nEN POSTORDEN\n");
            mostrarPos(arbol);
            break;

        case 6:
            max = arbol->dato;
            valorMax(arbol, &max, raiz);
            printf("El valor maximo y multiplo de la raiz es: %d\n", max);
            break;

        case 7:
            cont = 0;
            hojasDiv(arbol, &cont, raiz);
            printf("La cantidad de nodos hojas divisores de la raiz es: %d\n", cont);
            break;
        case 8:

            sumNodosPar(arbol, &sum);
            printf("La sumatoria de aquellos nodos pares con un hijo es: %d\n", sum);
            break;

        }

        printf("\nMenu\n");
        printf("1. Crear Arbol.\n");
        printf("2. Borrar Arbol.\n");
        printf("3. Mostrar en Preorden.\n");
        printf("4. Mostrar en Orden.\n");
        printf("5. Mostrar en Postorden.\n");
        printf("6. Valor maximo multiplo raiz.\n");
        printf("7. Cantidad de nodos hojas divisores raiz.\n");
        printf("8. Sumatoria nodos pares con un hijo.\n");
        printf("0. Salir.\n");

        printf("\nIntroduzca opcion: ");
        scanf("%d", &opcion);
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

void borrar(treenode** hoja) {



    if (*hoja != NULL)
    {
        printf("\nEntro borrar\n");
        printf("nodo: %d \n", (*hoja)->dato);

        borrar(&(*hoja)->izq);
        borrar(&(*hoja)->der);
        printf("\nborrando %d\n", (*hoja)->dato);
        free(*hoja);
        
    }

    return;
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

void mostrarPre (treenode *hoja)
{
    if (hoja!=NULL)
    {
        printf("%d \n",hoja->dato);
        mostrarPre(hoja->izq);
        mostrarPre(hoja->der);
        
    }
    return;
}

void mostrarOrd(treenode *hoja)
{
    if (hoja!=NULL)
    {
        mostrarOrd(hoja->izq);
        printf("%d \n",hoja->dato);
        mostrarOrd(hoja->der);
    }
    return;
}

void mostrarPos (treenode *hoja)
{
    if (hoja!=NULL)
    {
        mostrarPos(hoja->izq);
        mostrarPos(hoja->der);
        printf("%d \n",hoja->dato);
    }
    return;
}

void valorMax(treenode *hoja, int *max, int raiz)
{
    if(hoja != NULL)
    {
        valorMax(hoja->izq,max,raiz);
            if((hoja->dato % raiz == 0)&&(*max % raiz == 0))
            {
                if(hoja->dato > *max)
                {
                    *max=hoja->dato; 
                }
            }
        valorMax(hoja->der,max,raiz);
    }
}

void hojasDiv(treenode *hoja, int *cont, int raiz)
{
    if(hoja != NULL)
    {
        hojasDiv(hoja->izq,cont,raiz);
           if((hoja->izq==NULL && hoja->der==NULL) && 
             (raiz % hoja->dato == 0))
            {
                *cont = *cont + 1;
            }
        hojasDiv(hoja->der,cont,raiz);
    }
}


int sumNodosPar(treenode *hoja, int *sum)
{
    if(hoja != NULL)
    {
        sumNodosPar(hoja->izq,sum);
            if(((hoja->izq!=NULL && hoja->der==NULL)  ||
                (hoja->izq==NULL && hoja->der!=NULL)) &&
                (hoja->dato % 2 == 0))
                {
                    *sum=*sum + hoja->dato;
                }
        sumNodosPar(hoja->der,sum);
    }
}
