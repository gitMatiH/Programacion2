#include<stdio.h>
#include<stdlib.h>



typedef struct tiponodo
{
    int num;

    struct tiponodo* siguiente;
}nodo;

void mostrar(nodo aux, int ultimo, int * cant_multiplos)

{
    printf("%d \n", aux.num);
    if (aux.num % ultimo == 0) {
        //un numero cualquiera es multiplo de si mismo, por eso lo restamos inicializando en -1
        *cant_multiplos = *cant_multiplos + 1;
    }
}

nodo* crear_nodo(int dato)
{
    nodo* u;
    u = (nodo*)malloc(sizeof(nodo));
    u->num = dato;

    u->siguiente = NULL;

    return u;
}

void apilar(nodo** p, nodo* u)
{
    printf("apilar_nodo\n");


    u->siguiente = *p;
    printf("%d p=%p u=%p\n", u->num, *p, u);
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
    int haydatos;

    int ultimo;
    int cant_multiplos = -1;

    int num;
    nodo* p = NULL;


    printf("\nHay datos? 1/0: ");
    scanf("%d", &haydatos);
    while (haydatos != 0 && haydatos != 1) {
        printf("\nOpcion invalida.");
        printf("\nHay datos? 1/0: ");
        scanf("%d", &haydatos);
    }


    while (haydatos) {
    
        printf("\nIngrese un numero: ");
        scanf("%d", &num);
        apilar(&p, crear_nodo(num));

        ultimo = num;

        printf("\nHay datos? 1/0: ");
        scanf("%d", &haydatos);
        while (haydatos != 0 && haydatos != 1) {
            printf("\nOpcion invalida.");
            printf("\nHay datos? 1/0: ");
            scanf("%d", &haydatos);
        }
    }



    printf("\nVamos a desapilar todo\n");
    while (p != NULL)
    {
        mostrar(desapilar(&p), ultimo, &cant_multiplos);
    }
    
    if (cant_multiplos == -1) {
        printf("\nNo hubo multiplos de %d\n", ultimo);
    }
    else { 
        printf("\nLa cantidad de multiplos de %d fue de %d\n", ultimo, cant_multiplos); 
    }
    

    return 0;
}
