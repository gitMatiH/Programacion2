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
    int cantmult3;
    //punto2
    int cont2;
    int acum2;
    float promdiv4;
    //punto3
    int primero;
    int sumMultprimer;
    //punto4
    int max;
    int posmax;
    //punto5
    int min;
    int posmin;
    //punto6
    int numero;
    int contNum;
    //punto 4,5,6 usan el mismo contador.
    int contador;

}argumentos;

void mostrar(nodo a, argumentos*);
nodo* crearNodo(int);
void apilar(nodo**p , nodo* u);
nodo desapilar(nodo**);


int main()
{
    argumentos argumentos;

    int i,num;
    nodo* p=NULL;

    //Inicializar argumentos
    //punto1
    argumentos.cantmult3 = 0;
    //punto2
    argumentos.cont2 = 0;
    argumentos.acum2 = 0;
    //punto3
    argumentos.sumMultprimer = 0;
    //punto4
    //punto5
    //punto6
    argumentos.contNum = 0;



    //apilar
    printf("\nIngresamos datos a la pila.");

    for(i=0; i < CANT; i++){

        printf("\nIngrese numero: ");
        scanf("%d", &num);
        apilar(&p, crearNodo(num));

        if(i == 0){
        //Inicializar argumentos
        //punto3
        argumentos.primero = p->dato;
        //punto4
        argumentos.max = p->dato;
        argumentos.posmax = 1;
        //punto5
        argumentos.min = p->dato;
        argumentos.posmin = 1;
        }
        
    }

    

    //desapilar
    printf("\nVamos a desapilar todo.\n");
    argumentos.contador = 0;
    //Punto 6
    printf("Ingresa el numero del que desee contar las apariciones: ");
    scanf("%d", &argumentos.numero);

    while(p != NULL)
    {
        //actualizamos puntos 4,5,6
        argumentos.contador = argumentos.contador + 1;
        mostrar(desapilar(&p), &argumentos);

    }

    //calcular y mostrar resultados;
    //punto1
    printf("\nLa cantidad de numeros multiplos de 3 son: %d\n",argumentos.cantmult3);
   
    // punto2
    if(argumentos.cont2 != 0){
        argumentos.promdiv4 = ((float)argumentos.acum2/argumentos.cont2);
        printf("\nEL promedio de los divisores de 4 es: %.2f\n",argumentos.promdiv4);
    }else{
        printf("Error division por cero.");
    }

    // punto3
    printf("\nLa sumatoria de los multiplos del primer numero es: %d\n",argumentos.sumMultprimer);
    // punto4
    printf("\nEl numero maximo es: %d y su posicion es: %d\n",argumentos.max,argumentos.posmax);
    // punto5
    printf("\nEL numero minimo es: %d y su posicion es: %d\n",argumentos.min,argumentos.posmin);
    // punto6
    if (argumentos.contNum == 0) {
        printf("\nEl numero no se encontro en la pila\n");
        }
        else {
        printf("\nEl numero %d se encontro %d veces en la pila\n", argumentos.numero, argumentos.contNum);
        }
    

    printf("\n%d", argumentos.contador);

    return 0;

}


//DEFINICIONES
void mostrar(nodo a,argumentos* argumentos)
{
    //procesar el actual
    //punto1
    if(a.dato % 3 == 0){
        argumentos->cantmult3 = argumentos->cantmult3 + 1;
    }
    //punto2
    if(4 % a.dato == 0){
        argumentos->cont2 = argumentos->acum2 + 1;
        argumentos->acum2 = argumentos->acum2 + a.dato;
    }
    //punto3
    if(argumentos->primero % a.dato == 0){
        argumentos->sumMultprimer = argumentos->sumMultprimer + a.dato;
    }
    //punto4
    if(a.dato > argumentos->max){
        argumentos->max = a.dato;
        argumentos->posmax = argumentos->contador;
    }
    //punto5
    if(a.dato < argumentos->min){
        argumentos->min = a.dato;
        argumentos->posmin = argumentos->contador;
    }
    //punto6
    if(argumentos->numero == a.dato){
        argumentos->contNum = argumentos->contNum + 1;
    }

}

nodo* crearNodo(int num)
{
    nodo* u = (nodo *)malloc(sizeof(nodo));
    u->dato = num;

    u->siguiente = NULL;

    return u;
}

void apilar(nodo** p,nodo* u)
{
    u->siguiente = *p;
    *p = u;

    return;
}


nodo desapilar(nodo** p)
{
    
    nodo nodoKBZA = **p;
    nodo *aux = *p;
    
    *p = (*p)->siguiente;
    free(aux);

    return nodoKBZA;
    
}

