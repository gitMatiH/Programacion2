/*

Crear una pila con la siguinte info:
    num: entero.
    *siguiente: puntero.

Escribir una funcion para mostrar la cantidad de numeros pares mayores al segundo
elemento de la pila. Si no hubiera algun numero mostrar una leyenda.
"No hay dos numeros en la pila."

Escribir una funcion que busque un numero solicitado previamente por teclado en la
pila e informar cuantas veces aparece el mismo y en que posicion.
La carga finaliza con el num = 999.


*/
#define MAX 10

#include<stdio.h>
#include<stdlib.h>

typedef struct tiponodo
{
int num;
struct tiponodo *siguiente;

}nodo;

void mostrar (nodo aux);
nodo* crear_nodo(int dato );
void apilar(nodo** p, nodo* u);
nodo desapilar(nodo** p);
void numPar (nodo aux, int* );
int busqueda (nodo** p, int numB, int* arreglo, int tamanioArr, int tamanioPila);
void carga(nodo** p, int* pos, int* segundo);
int cantidadPares(nodo** p, int* segundo);
void imprimir(int cantidad);
//void imprimir2();

int main()
{

    int i,num;
    int cantidad_pares;
    int pos=0;
    int segundo;
    int cantidad;
    int numB;
    int posB=1;
    int cont = 0;
    int tamanioPila;
    nodo* p=NULL;


    
    //funcion carga();
    printf("\nCargamos la pila 1:\n");
    carga(&p, &pos, &segundo);
    printf("\nTerminamos carga de la pila 1\n");
    

    //1)Mostrar la cantidad de numeros pares mayores al segundo elemento de la pila.
    //funcion imprimir()
    //imprimir(cantidadPares(&p, &segundo));
    cantidad_pares = cantidadPares(&p, &segundo);
    imprimir(cantidad_pares);
    
    
    //funcion carga();
    printf("\nCargamos la pila 2:\n");
    pos = 0;
    carga(&p, &pos, &segundo);
    tamanioPila = pos;
    printf("\nTerminamos carga de la pila 2\n");


    //2)Busque un numero solicitado previamente por teclado en la
    //pila e informar cuantas veces aparece el mismo y en que posicion.

    printf("\nIngrese el numero que desea buscar: ");
    scanf("%d", &numB);
    //funcion2()
    int arreglo[MAX];
    cont = busqueda(&p, numB, arreglo, MAX, tamanioPila);
    //imprimir2();
    printf("\ncont: ", cont);
    printf("\nEl numero: %d aparece %d veces,", numB, cont, posB);
    printf("\nen las posiciones:");
    for (int i = 0; i < cont; i++) {
        printf("\n%d", arreglo[i]);
    }
    printf("\n");



    return 0;
}


//2)Buscar un numero solicitado previamente por teclado en la
//pila e informar cuantas veces aparece el mismo y en que posicion.
int busqueda(nodo** p, int numB, int* arreglo, int tamanioArr, int tamanioPila)
{
    int contador = 0;
    int i = 0;
    int posB = tamanioPila;
    nodo aux;

    while (*p != NULL)
    {
        aux = desapilar(p);
        if ((aux.num == numB)) {
            contador = contador + 1;
            arreglo[i] = posB;
            i++;
        }
        posB--;

    }
    return contador;    //el contador corresponde con la cantidad de elementos en el arreglo
}

void imprimir2(int numB, int cont, int posB) {
    printf("El numero: %d, aparece: %d, en la posicion: %d", numB, cont, posB);
}


void mostrar(nodo aux)
{
    printf("%d \n", aux.num);
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

    printf("%d ", u->num);
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


int cantidadPares(nodo** p, int* segundo) {
    //int pos; // si la queremos, deberiamos pasarla x parametro referencia

    int cantidad = 0;
    while (*p != NULL)
    {
        nodo datos = desapilar(p);
        if (datos.num % 2 == 0 && datos.num > *segundo) {
            cantidad = cantidad + 1;
        }

        //pos = pos - 1;
    }
    return cantidad;
}

void imprimir(int cantidad) {

    if (cantidad == 0) {
        printf("\nNo hay numeros pares mayores al segundo elemento de la pila.\n");
    }
    else {
        printf("\nLa cantidad de numeros pares mayores al segundo elementod de la pila es: %d\n", cantidad);
    }

}

void carga(nodo** p, int* pos, int* segundo) {
    int num;


    printf("\nIngrese un numero: ");
    scanf("%d", &num);

    while (num != 999 && *pos < MAX)
    {
        *pos = *pos + 1;
        apilar(p, crear_nodo(num));

        if (*pos == 2)
        {
            *segundo = (*p)->num;
        }

        printf("\nIngrese un numero: ");
        scanf("%d", &num);
    }

}