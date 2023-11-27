

#include<stdio.h>
#include<stdlib.h>





typedef struct tiponodo
{
    int num;

    struct tiponodo* siguiente;
}nodo;

void mostrar(nodo aux, int * pos, int * max, int * posmax)
{
    printf("%d\n", aux.num);
    
    if (*max<aux.num) {
        *max = aux.num;
        *posmax = *pos;
    }
    *pos = *pos + 1;
}

nodo* crear_nodo(int dato)
{
    nodo* u;
    u = (nodo*)malloc(sizeof(nodo));

    u->num = dato;

    u->siguiente = NULL;

    return u;
}

void acolar(nodo** p, nodo** u, nodo* q)
{
    printf("acolar_nodo\n");
    if (*p == NULL)
        *p = *u = q; /*porque hay uno solo*/
    else
    {
        (*u)->siguiente = q;
        (*u) = q;
    }
    printf("%d p=%p u=%p\n", q->num, *p, *u);
}

nodo desacolar(nodo** inicio)
{
    nodo* aux;
    nodo datos;

    datos = **inicio;

    aux = *inicio;

    *inicio = (*inicio)->siguiente;
    free(aux);

    return datos;
}

int main()
{
    int haydatos;

    int pos;
    int posmax;
    int max;

    int num;
    nodo* p = NULL;
    nodo* u = NULL;

    printf("\nHay datos? 1/0: ");
    scanf("%d", &haydatos);
    while (haydatos != 0 && haydatos != 1) {
        printf("\nOpcion invalida.");
        printf("\nHay datos? 1/0: ");
        scanf("%d", &haydatos);
    }
    printf("\nIngrese un numero: ");
    scanf("%d", &num);

    max = num;
    posmax = 1;

    while (haydatos) {

        
        acolar(&p, &u, crear_nodo(num));

        printf("\nHay datos? 1/0: ");
        scanf("%d", &haydatos);
        while (haydatos != 0 && haydatos != 1) {
            printf("\nOpcion invalida.");
            printf("\nHay datos? 1/0: ");
            scanf("%d", &haydatos);
        }
        printf("\nIngrese un numero: ");
        scanf("%d", &num);
    }

    pos = 1;
    printf("\nVamos a desacolar todo:\n");
    while (p != NULL)
    {
        mostrar(desacolar(&p), &pos, &max, &posmax);
    }

    printf("\nEl maximo elemento de la cola es: %d y esta en la posicion %d\n", max, posmax);


    return 0;
}
