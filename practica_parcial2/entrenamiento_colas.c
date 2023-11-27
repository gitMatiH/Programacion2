

#include<stdio.h>
#include<stdlib.h>
#include<string.h>






typedef struct tiponodo
{
    int dato;

    struct tiponodo* siguiente;
}nodo;

void mostrar(nodo aux, int * cant_elem, int * sumatoria_elem)
{
    printf("%d \n", aux.dato);

    *cant_elem = *cant_elem + 1;
    if (*cant_elem <= 3) {
        *sumatoria_elem = *sumatoria_elem + aux.dato;
    }

}

nodo* crear_nodo(int dato)
{
    nodo* u;
    u = (nodo*)malloc(sizeof(nodo));

    u->dato = dato;

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
    printf("%d p=%p u=%p\n", q->dato, *p, *u);
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
    int cant_elem = 0;
    int sumatoria_elem = 0;

    float promedio;

    int haydatos;

    int num;
    nodo* p = NULL;
    nodo* u = NULL;


    printf("\nHay datos? 1/0: ");
    scanf("%d", &haydatos);
    while (haydatos != 1 && haydatos != 0) {
        printf("\nopcion invalida\n");
        printf("\nHay datos? 1/0: ");
        scanf("%d", &haydatos);
    }



    while (haydatos) {

        printf("Ingrese un numero: ");
        scanf("%d", &num);

        acolar(&p, &u, crear_nodo(num));

        printf("\nHay datos? 1/0: ");
        scanf("%d", &haydatos);
        while (haydatos != 1 && haydatos != 0) {
            printf("\nopcion invalida\n");
            printf("\nHay datos? 1/0: ");
            scanf("%d", &haydatos);
        }
    }


    printf("\nVamos a desacolar todo\n");
    while (p != NULL)
    {
        mostrar(desacolar(&p), &cant_elem, &sumatoria_elem);
    }

    if (cant_elem < 3) {
        printf("\nNo hubo tres numeros\n");
    }
    else {
        if (cant_elem > 0) {
            promedio = (float)sumatoria_elem / 3;
            printf("\nEl promedio de los tres primeros numeros ingresados es: %.2f\n", promedio);
        }
        else {
            printf("\nError, no hubo elementos en la cola\n");
        }
    }


    return 0;
}
