#include <stdio.h>
#include <stdlib.h>

/*
Desarrollar un programa que permita eliminar el nodo 
que contenga la información Z de la pila.
*/

#define CANT 10
#define BUSCADO 7

typedef struct tiponodo {

    int A;

    struct tiponodo* SIG;

}nodo;

//declaraciones

void mostrar(nodo);
nodo* crearNodo(int);
void apilar(nodo** p, nodo* u);
nodo desapilar(nodo** p);


int main(void) {

    int i, I, pos;
    int num;
    nodo* p1;
    nodo* p2;
    nodo nodoActual;

    int Z = BUSCADO;

    //acolar
    printf("\nVamos ingresar %d datos a la pila (FIFO, por eso muestra en el ingreso la pos de mayor a menor)\n", CANT);

    for (i = 0; i < CANT; i++) {
        printf("Ingrese numero pos %d: ", CANT-i);
        scanf("%d", &num);

        apilar(&p1, crearNodo(num));

    }

    while (p1 != NULL)
    {
        //apila en p2 los que desapila en p1
        nodoActual = desapilar(&p1);
        if (nodoActual.A != Z) {
            apilar(&p2, crearNodo(nodoActual.A));
        }

    }

    while (p2 != NULL) {
        //reapila en p1 los que apilo en p2
        nodoActual = desapilar(&p2);
        apilar(&p1, crearNodo(nodoActual.A));
    }


    printf("\nMostramos pila, habiendo respetado el orden original y eliminado la informacion Z = %d\n", BUSCADO);
    pos = 1;
    while (p1 != NULL) {
        printf("\nposicion: %d", pos);
        printf("\nelemento: ");
        mostrar(desapilar(&p1));
        printf("\n");
        pos++;
    }
}



//definiciones

void mostrar(nodo n)
{
    printf("%d", n.A);
}

nodo* crearNodo(int num)
{
    nodo* u = (nodo*)malloc(sizeof(nodo));
    u->A = num;

    u->SIG = NULL;

    return u;
}

void apilar(nodo** p, nodo* u)
{
    u->SIG = *p;
    *p = u;

    return;
}


nodo desapilar(nodo** p)
{

    nodo nodoCab = **p;
    nodo* aux = *p;

    *p = (*p)->SIG;
    free(aux);

    return nodoCab;

}