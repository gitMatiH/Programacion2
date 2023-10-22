#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CANT 5

typedef struct tiponodo
{
    int dato;

    struct tiponodo* siguiente;
}nodo;

typedef struct tiporegistro {
    //punto1
    int prodmult7;
    //punto2
    int ultimo;
    int cont2;
    int acum2;
    float promdivult;
    //punto3
    int primero;
    int sumdivprimer;
    //punto4
    int max;
    int posmax;
    //punto5
    int min;
    int posmin;
    //4y5 comparten
    int contador;

}argumentos;


// DECLARACIONES

void mostrar(nodo aux, argumentos*);
nodo* crear_nodo(int q);
void acolar(nodo** p, nodo** u, nodo* q);
nodo desacolar(nodo** p);



int main(void) {

    argumentos argumentos;

    int i, num;
    nodo* p = NULL;
    nodo* u = NULL;

    //incializar argumentos
    //punto1
    argumentos.prodmult7 = 1;
    //punto2
    argumentos.cont2 = 0;
    argumentos.acum2 = 0;
    argumentos.promdivult = 0;
    //punto3
    argumentos.sumdivprimer = 0;

    //acolar
    printf("\nVamos ingresar datos a la cola\n");

    for (i = 0; i < CANT; i++) {
        printf("Ingrese un numero: ");
        scanf("%d", &num);

        acolar(&p, &u, crear_nodo(num));
        
        if (i == 0) {
            //inicializar argumentos
            //punto2
            argumentos.ultimo = u->dato;
            //punto3
            argumentos.primero = p->dato;
            //punto4
            argumentos.min = p->dato;
            argumentos.posmin = 1;
            //punto5
            argumentos.max = p->dato;
            argumentos.posmax = 1;
        }
    }


    //desacolar
    printf("\nVamos a desacolar todo\n");
    argumentos.contador = 0;
    while (p != NULL)
    {
        //actualizar puntos 4 y 5
        argumentos.contador = argumentos.contador + 1;
        mostrar(desacolar(&p), &argumentos);
        
    }

    //calcular y mostrar resultados
    //punto1
    printf("\nLa productoria de los numeros multiplos de 7 es: %d\n", argumentos.prodmult7);
    //punto2
    argumentos.promdivult = ( (float)argumentos.acum2 / argumentos.cont2 );
    printf("\nEl promedio de los divisores del ultimo numero es: %.2f\n", argumentos.promdivult);
    //punto3
    printf("\nLa sumatoria de los divisores del primer numero es: %d\n", argumentos.sumdivprimer);
    //punto4
    printf("\nEl mayor elemento fue: %d\ny su posicion fue: %d\n", argumentos.max, argumentos.posmax);
    //punto5
    printf("\nEl menor elemento fue: %d\ny su posicion fue: %d\n", argumentos.min, argumentos.posmin);

    return 0;
}



// DEFINICIONES

void mostrar(nodo aux, argumentos* argumentos) {

    //procesar el actual
    //punto1
    if (aux.dato % 7 == 0) {
        argumentos->prodmult7 = argumentos->prodmult7 * aux.dato;
    }
    //punto2
    if (argumentos->ultimo % aux.dato == 0) {
        argumentos->cont2 = argumentos->cont2 +1;
        argumentos->acum2 = argumentos->acum2 + aux.dato;
    }
    //punto3
    if (argumentos->primero % aux.dato == 0) {
        argumentos->sumdivprimer = argumentos->sumdivprimer + aux.dato;
    }
    //punto4
    if (aux.dato < argumentos->min) {
        argumentos->min = aux.dato;
        argumentos->posmin = argumentos->contador;
    }
    //punto5
    if (aux.dato > argumentos->max) {
        argumentos->max = aux.dato;
        argumentos->posmax = argumentos->contador;
    }

    //print dato actual
    printf("%d \n", aux.dato);

}

nodo* crear_nodo(int q) {
    nodo* u;
    u = (nodo*)malloc(sizeof(nodo));

    u->dato = q;
    u->siguiente = NULL;

    return u;
}


void acolar(nodo** p, nodo** u, nodo* q) {
    if (*p == NULL) *p = *u = q;
    else 
    {
        (*u)->siguiente = q;
        (*u) = q;
    }
    return;
}

nodo desacolar(nodo** p) {
    nodo* aux;
    nodo d;

    d = **p;

    aux = *p;

    *p = (*p)->siguiente;
    free(aux);

    return d;
}