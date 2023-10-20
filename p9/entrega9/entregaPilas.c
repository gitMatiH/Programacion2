/*
De una pila, averiguar
1) La cantidad de numeros multiplos de 3
2) El promedio de aquellos numeros divisores de 4
3) La sumatoria de aquellos numeros multiplos del primer
    elemento ingresado a la pila
4) El numero maximo y su posicion en la pila
5) El numero minimo y su posicion en la pila
6) Ingresar un numero por teclado y calcular la cantidad de veces
    que esta en la pila. Si no esta, mostrar una leyenda.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CANT 4

//DECLARACIONES

typedef struct tiponodo
{
    int num;

    struct tiponodo *sig;

}nodo;


void mostrar(nodo aux);
nodo* crearNodo(int);
void apilar(nodo** p,nodo* u);
nodo desapilar(nodo** p);

void generarPila(nodo **);
void mostrarPilaDestr(nodo **);
void mostrarPila(nodo **);

int multiplosTres(nodo** );
float promedioDivCuatro(nodo**);
int sumatoriaMultiplosPrimero(nodo**);
void posMax(nodo**, int*, int*);
void posMin(nodo**, int*, int*);
void apariciones(nodo**, int, int*);

int main()
{
    int opcion;
    int cant;
    float promedio;
    int sumatoria;
    int pos, max, min;
    int numero, contador;

    nodo *p= NULL;  //"p" es nuestro
                    //handle, nustra 
                    //manija a la pila

    printf("\nMENU");
    printf("\n1. Generar pila.");
    printf("\n2. Mostrar pila destructivamente.");
    printf("\n3. Mostrar pila.");
    printf("\n4. Multiplos de 3.");
    printf("\n5. Promedio divisores 4.");
    printf("\n6. Sumatoria de elementos multiplos del primer elemento.");
    printf("\n7. Numero maximo y posicion.");
    printf("\n8. Numero minimo y su posicion.");
    printf("\n9. Cantidad de veces de un numero en pila.");
    printf("\n0. Salir.");
    printf("\nELija opcion: ");
    scanf("%d", &opcion);

    while (opcion != 0){
        switch (opcion)
        {
        case 1:
            printf("\nProcedemos a generar la pila para usar con las funciones\n");
            generarPila(&p);
            break;
        case 2:
            printf("\nMostramos la pila de manera destructiva\n");
            mostrarPilaDestr(&p);
            break;
        case 3:
            printf("\nMostramos la pila devolviendola intacta\n");
            mostrarPila(&p);
            break;
        case 4:
            if (p == NULL) {
                printf("\nPoblar primero la pila:\n");
                generarPila(&p);
            }
            cant = multiplosTres(&p);
            printf("\nla cantidad de multiplos de tres en la pila es de: %d\n", cant);
            break;
        case 5:
            if (p == NULL) {
                printf("\nPoblar primero la pila:\n");
                generarPila(&p);
            }
            promedio = promedioDivCuatro(&p);
            printf("\nEl promedio de los divisores de cuatro es de: %.2f\n", promedio);
            break;
        case 6:
            if (p == NULL) {
                printf("\nPoblar primero la pila:\n");
                generarPila(&p);
            }
            sumatoria = sumatoriaMultiplosPrimero(&p);
            printf("\nLa sumatoria de los multiplos del primer elemento de la lista es: %d\n", sumatoria);
            break;
        case 7:
            if (p == NULL) {
                printf("\nPila Vacia.\n");
            }
            else {
                posMax(&p, &pos, &max);
                printf("\nEl numero maximo de la pila es: %d\ny su posicion es: %d\n", max, pos);
            }
            break;
        case 8:
            if (p == NULL) {
                printf("\nPila Vacia.\n");
            }
            else {
                posMin(&p, &pos, &min);
                printf("\nEl numero minimo de la pila es: %d\ny su posicion es: %d\n", min, pos);
            }
            break;
        case 9:
            if (p == NULL) {
                printf("\nPila Vacia.\n");
            }
            else {
                contador = 0;
                printf("\nIngrese el numero a buscar en la pila: ");
                scanf("%d", &numero);
                apariciones(&p, numero, &contador);
                if (contador == 0) {
                    printf("\nEl numero no se encontro en la pila\n");
                }
                else {
                    printf("\nEl numero %d se encontro %d veces en la pila\n", numero, contador);
                }
            }
            break;
        default:
            printf("\nCodigo invalido.\n");
            break;
        }

        printf("\nMENU");
        printf("\n1. Generar pila.");
        printf("\n2. Mostrar pila destructivamente.");
        printf("\n3. Mostrar pila.");
        printf("\n4. Multiplos de 3.");
        printf("\n5. Promedio divisores 4.");
        printf("\n6. Sumatoria de elementos multiplos del primer elemento.");
        printf("\n7. Numero maximo y posicion.");
        printf("\n8. Numero minimo y su posicion.");
        printf("\n9. Cantidad de veces de un numero en pila.");
        printf("\n0. Salir.");
        printf("\nELija opcion: ");
        scanf("%d", &opcion);
    }

    return 0;
}


//DEFINICIONES
void mostrar(nodo aux)
{
    printf("\n%d\n", aux.num);
}

nodo* crearNodo(int num)
{
    nodo* u = (nodo *)malloc(sizeof(nodo));
    u->num = num;

    u->sig = NULL;

    return u;
}

void apilar(nodo** p,nodo* u)
{
    u->sig = *p;
    *p = u;

    return;
}


nodo desapilar(nodo** p)
{
    
    nodo nodoKBZA = **p;
    nodo *aux = *p;
    
    *p = (*p)->sig;
    free(aux);

    return nodoKBZA;
    
}


void generarPila(nodo ** p){

    int i;
    int num;

    for(i=0; i<CANT; i++){
        printf("\nIngrese numero: ");
        scanf("%d", &num);
        apilar(p, crearNodo(num));
    }
}


void mostrarPilaDestr(nodo **p)
{
    int pos = 1;
    while (*p!=NULL){

        printf("\npos:\n%d", pos);
        printf("\nelemento: ");
        mostrar(desapilar(p));
        pos++;

    }
}

// void mostrarPilaR(nodo **p, *pos)   //pos debe venir con el 1
// {
//     if (*p!=NULL){

//         printf("\npos: %d", pos);
//         mostrar(desapilar(&p));
//         mostrarPilaR(&p,&pos);

//     }
//     return;
// }


void mostrarPila(nodo **p){

    nodo * pAux = NULL;  // pila auxiliar
    
    int pos = 1;
    while (*p!=NULL){
        nodo nodoAux = desapilar(p);
        printf("\npos: %d", pos);
        printf("\nelemento: %d\n", nodoAux.num);
        apilar(&pAux, crearNodo(nodoAux.num));
        pos++;
    }

    while (pAux != NULL){
        nodo nodoAux = desapilar(&pAux);
        apilar(p, crearNodo(nodoAux.num));
    }
    //al desapilar se borran todos los elementos almacenados en memoria,
    //y al salir del scope de la funcion se elimina el puntero de la pila auxiliar

}


// precond: pila de la que queremos saber cuantos multiplos de tres hay
int multiplosTres(nodo** p) {
    int cant = 0;

    while (*p != NULL) {
        nodo nodoDesapilado = desapilar(p);
        if (nodoDesapilado.num % 3 == 0) {
            cant = cant + 1;
        }
    }
    return cant;
}


float promedioDivCuatro(nodo** p) {

    int acumulador = 0;
    int total = 0;
    float promedio;

    while (*p != NULL) {
        total = total + 1;
        nodo nodoDesapilado = desapilar(p);
        if (4 % nodoDesapilado.num == 0) {
            acumulador = acumulador + nodoDesapilado.num;
        }
    }
    if (total != 0) {
        promedio = (float)acumulador / total;
    }
    return promedio;
}



int sumatoriaMultiplosPrimero(nodo** p) {

    int primerNum;
    int sumatoria = 0;
    nodo nodoDesapilado;

    nodoDesapilado = desapilar(p);
    primerNum = nodoDesapilado.num;

    while (*p != NULL) {
        nodoDesapilado = desapilar(p);
        if (primerNum % nodoDesapilado.num == 0) {
            sumatoria = sumatoria + nodoDesapilado.num;
        }
    }


    return sumatoria;
}


void posMax(nodo** p, int *pos, int *max) {

    nodo nodoDesapilado;
    int i = 1;
    *pos = 1;
    nodoDesapilado = desapilar(p);
    *max = nodoDesapilado.num;

    while (*p != NULL) {
        i = i + 1;
        nodoDesapilado = desapilar(p);
        if (nodoDesapilado.num > *max) {
            *max = nodoDesapilado.num;
            *pos = i;
        }
    }
    return;
}



void posMin(nodo** p, int* pos, int* min) {

    nodo nodoDesapilado;
    int i = 1;
    *pos = 1;
    nodoDesapilado = desapilar(p);
    *min = nodoDesapilado.num;

    while (*p != NULL) {
        i = i + 1;
        nodoDesapilado = desapilar(p);
        if (nodoDesapilado.num < *min) {
            *min = nodoDesapilado.num;
            *pos = i;
        }
    }
    return;

}



void apariciones(nodo** p, int numero, int* contador) {

    nodo nodoDesapilado;

    while (*p != NULL) {
        nodoDesapilado = desapilar(p);
        if (nodoDesapilado.num = numero) {
            *contador = *contador +1;
        }
    }
    return;

}