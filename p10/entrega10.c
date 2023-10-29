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
void funciones(treenode *hoja,int *,int *,int *,int *,int raiz);

int main ()
{
    int n,raiz,resultado;
    int max, cont=0, sum=0, c=0;
    float prom = 0;


    printf ("ARBOLES\n");
    treenode* arbol=NULL;


    crear (&arbol,&raiz);
    printf ("**************\n");
    printf ("Mostrar Arbol\n");
    printf ("***************\n");
    mostrar(arbol);

    max = arbol->dato;
    funciones(arbol,&max,&cont,&sum,&c,raiz);
    
    printf("El elemento maximo del arbol es: %d\n",max);
    printf("La cantidad de nodos con dos hijos divisores de la raiz es: %d\n",cont);
    
    //printf("sum: %d\n c: %d\n",sum,c);
    if(c!=0){ prom = (float)sum / c; }
    printf("El promedio de nodos pares con un solo hijo es: %.2f\n", prom);

    /*printf("Introducir el numero que desea buscar: ");
    scanf("%d",&n);

    resultado = buscar(arbol,n);
    if(resultado == 1){
        printf("El numero %d se encuentra en el arbol.\n",n);
        
    }else{
        printf("El numero no esta en el arbol.\n");
    }*/

    

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

/*int buscar (treenode *hoja, int n)
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
}*/

void funciones(treenode *hoja, int *max, int *cont, int *sum, int *c, int raiz){


    if(hoja != NULL){

        funciones(hoja->izq,max,cont,sum,c,raiz);

        //Elemento maximo del arbol;
        if(hoja->dato > *max){
            *max=hoja->dato;
        }
        //Cantidad de nodos con dos hijos de la raiz que sea divisor;
        if(hoja->izq!=NULL && hoja->der!=NULL 
        //&& (raiz % hoja->dato == 0)){
        && (raiz % hoja->izq->dato == 0 
            && raiz % hoja->der->dato == 0)){
            *cont=*cont+1;
        }
        //Promedio de nodos con un valor par con un solo hijo
        if(((hoja->izq!=NULL && hoja->der==NULL)  ||
            (hoja->izq==NULL && hoja->der!=NULL)) &&
            (hoja->dato % 2 == 0))
                {
                    *c=*c + 1;
                    *sum=*sum + hoja->dato;
                }

        funciones(hoja->der,max,cont,sum,c,raiz);
    }
}
