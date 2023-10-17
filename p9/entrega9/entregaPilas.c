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



int main()
{
    int opcion;
    
    nodo *p= NULL;  //"p" es nuestro
                    //handle, nustra 
                    //manija a la pila

    printf("\nMENU");
    printf("\n1. Generar pila.");
    printf("\n2. Mostrar pila destructivamente.");
    printf("\n3. Mostrar pila.");
    printf("\n4. Multiplos de 3.");
    printf("\n5. Promedio divisores 4.");
    printf("\n6. Sumatoria de elementos promedio del primer elemento.");
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
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        case 7:
            /* code */
            break;
        case 8:
            /* code */
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
        printf("\n6. Sumatoria de elementos promedio del primer elemento.");
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

}