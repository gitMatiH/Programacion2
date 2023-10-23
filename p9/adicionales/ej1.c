#include <stdio.h>
#include <stdlib.h>

/*
Desarrollar un programa que permita dado un entero N, 
asignar el valor I al elemento N-ésimo desde la parte superior de la pila, 
volviendo a dejar los N-1 elementos inferiores donde se encontraban.
*/

#define CANT 10

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

    //acolar
    printf("\nVamos ingresar datos a la pila\n");

    for (i = 0; i < CANT; i++) {
        printf("Ingrese numero: ");
        scanf("%d", &num);

        apilar(&p1, crearNodo(num));

    }

    printf("\nIngrese cual es la posicion desde el elemento quiere reemplazar en la pila: \n");
    scanf("%d", &pos);
    while (pos > CANT) {
        printf("Error. Elija un numero menor o igual a %d", CANT);
        printf("\nIngrese cual es la posicion desde el elemento quiere reemplazar en la pila: \n");
        scanf("%d", &pos);
    }
    printf("\nIngrese por que numero lo quiere reemplazar: \n");
    scanf("%d", &I);


    i = 1;
    while (i<pos)
    {   
        //apila en p2 los que desapila en p1
        nodoActual = desapilar(&p1);
        apilar(&p2, crearNodo(nodoActual.A));
        i++;
    }

    nodoActual = desapilar(&p1);
    apilar(&p2, crearNodo(I));

    while (p2 != NULL) {
        //reapila en p1 los que apilo en p2
        nodoActual = desapilar(&p2);
        apilar(&p1, crearNodo(nodoActual.A));
    }


    printf("\nMostramos pila\n");
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