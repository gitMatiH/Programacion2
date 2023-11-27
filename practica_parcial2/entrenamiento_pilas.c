

#include<stdio.h>
#include<stdlib.h>



typedef struct tiponodo
{
    int dato;

    struct tiponodo* siguiente;
}nodo;

void mostrar(nodo aux, int primer_elemento, int * sumatoria)

{
    if (aux.dato > primer_elemento) {
        *sumatoria = *sumatoria + aux.dato;
    }
    printf("%d \n", aux.dato);
}

nodo* crear_nodo(int dato)
{
    nodo* u;
    u = (nodo*)malloc(sizeof(nodo));
    u->dato = dato;

    u->siguiente = NULL;

    return u;
}

void apilar(nodo** p, nodo* u)
{
    printf("apilar_nodo\n");


    u->siguiente = *p;
    printf("%d p=%p u=%p\n", u->dato, *p, u);
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
    int num;
    int primer_elemento;
    int sumatoria = 0;
    int haydatos;
    int contdatos = 0;
    
    
    nodo* p = NULL;

    printf("\nHay datos? 1/0 : ");    
    scanf("%d", &haydatos);
    while (haydatos != 1 && haydatos != 0) {
        printf("\nopcion invalida");
        printf("\nHay datos? 1/0 : ");
        scanf("%d", &haydatos);
    }
    fflush(stdin);

    printf("\nIngrese un numero: ");
    scanf("%d", &num);
    fflush(stdin);

    primer_elemento = num;


    while (haydatos)
    {
        contdatos = contdatos + 1;

        apilar(&p, crear_nodo(num));

        printf("\nHay datos? 1/0 : ");
        scanf("%d", &haydatos);
        while (haydatos != 1 && haydatos != 0) {
            printf("\nopcion invalida");
                printf("\nHay datos? 1/0 : ");
            scanf("%d", &haydatos);
        }
        fflush(stdin);

        printf("\nIngrese un numero: ");
        scanf("%d", &num);
        fflush(stdin);
    }


    printf("\nVamos a desapilar todo:\n");

    while (p != NULL)
    {
        mostrar(desapilar(&p), primer_elemento, &sumatoria);
    }

    if (contdatos == 0) {
        printf("\nNo hubo mayores elementos al primer elemento de la pila\n");
    }
    else {
        printf("\nLa sumatoria de los elementos mayores al primer elemento es: %d\n", sumatoria);
    }


    return 0;
}
