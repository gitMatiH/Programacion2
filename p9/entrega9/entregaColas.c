/*
Para las colas, averiguar:
1) La productoria de los numeros multiplos de 7.
2) El promedio de aquellos numeros divisores del ultimo numero ingresado
    a la cola
3) Sumatoria de aquellos numeros divisores del primer elemento ingresado
    a la cola.
4) El numero maximo y su posicion en la cola.
5) El numero minimo y su posicion en la cola.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 5


typedef struct tiponodo
{
	int num;

    struct tiponodo *siguiente;
}nodo;


void mostrar(nodo );
nodo *crear_nodo(int);
void acolar(nodo** p,nodo** u, nodo *q);
nodo desacolar(nodo** p);

int multiplosSiete(nodo** );
float promedioDivUltimo(nodo** ,nodo**);
int sumatoriaDivisoresPrimero(nodo** );
void posMax(nodo**, int*, int*);
void posMin(nodo**, int*, int*);

int main()
{
    int n, opcion;
    int i,num;
    int productoria; //(2)
    float promDiv; //(3)
    int sumatoriaDiv; //(4)
    int pos, max, min;//(5)(6)
    nodo* p=NULL;
    nodo* u=NULL;


   do
    {
        printf( "\n   1. Crear cola." );
        printf( "\n   2. Mostrar cola." );
        printf( "\n   3. Productoria de multiplos de 7.");
        printf( "\n   4. Promedio de los divisores del ultimo numero ingresado.");
        printf( "\n   5. Sumatoria de los divisores del primer numero ingresado." );
        printf( "\n   6. Numero maximo y posicion." );
        printf( "\n   7. Numero minimo y posicion." );
        printf( "\n   8. Salir." );

        printf( "\n\n   Introduzca opcion: ");
        scanf( "%d", &opcion );

        /* Inicio del anidamiento */

        switch ( opcion )
        {
            case 1: 
                    
                for(i=0; i<CANT; i++)
                {
       
                printf("Ingrese un numero: ");
                scanf("%d",&num);
                acolar(&p, &u, crear_nodo(num));

                }
                break;

            case 2: 

                printf("\nVamos a desacolar todo\n");
                while(p!=NULL)
                {
                    mostrar(desacolar(&p));
                }
                printf("\np: %p\nu: %p",p,u);
                break;

            case 3: 
            
                    productoria = multiplosSiete(&p);  
                    printf("\nLa productoria de los numeros multiplos de 7 es: %d\n", productoria);
                    break;

            case 4: 
                    promDiv = promedioDivUltimo(&p,&u);
                    printf("\nEL promedio de los numeros divisores del ultimo numero es: %.2f\n", promDiv);
                    break;

            case 5: 
                    sumatoriaDiv = sumatoriaDivisoresPrimero(&p);
                    printf( "\nLa sumatoria de los divisores del primer numero es: %d\n", sumatoriaDiv);
                    break;
            
            case 6: 
                    posMax(&p, &pos, &max);
                    printf( "\nEl numero maximo es: %d su posicion en la cola es: %d",max,pos);
                    break;
            
            case 7: 
                    posMin(&p, &pos, &min);
                    printf( "\nEl numero maximo es: %d su posicion en la cola es: %d",min,pos);
                    break;
        }

         /* Fin del anidamiento */

    } while ( opcion != 8 );

        return 0;
}

void mostrar (nodo aux)
{
  	printf("%d \n", aux.num);
}

nodo *crear_nodo(int num)
{
   nodo* u;
   u = (nodo *)malloc(sizeof(nodo));

   u->num = num;

   u->siguiente = NULL;

   return u;
}

void acolar(nodo** p,nodo** u, nodo *q)
{
   printf("Acolar_nodo\n");
	if(*p==NULL)
    *p = *u = q; /*porque hay uno solo*/
   else
   {
    	(*u)->siguiente = q;
    	(*u) = q;
   }
  //	printf("%02d p=%X u=%X\n", q->num, *p, *u);
}

nodo desacolar(nodo** inicio)
{
	nodo* aux;
    nodo datos;

	datos=**inicio;

	aux=*inicio;

	*inicio=(*inicio)->siguiente;
	free(aux);

    return datos;
}

//1) La productoria de los numeros multiplos de 7.

int multiplosSiete(nodo** p){

    int prod=1;

    while (*p != NULL) {
        nodo aux = desacolar(p);
        if (aux.num % 7 == 0) {
            prod = prod * aux.num;
        }
    }
    return prod;
}

//2) El promedio de aquellos numeros divisores del ultimo numero ingresad a la cola

float promedioDivUltimo(nodo** p, nodo** u){
    nodo aux;
    int cont = 0;
    int sum = 0;
    float prom;


    while(*p != *u){
        aux = desacolar(p);
        if((*u)->num % aux.num == 0){ //(*u).num es equivalente a u->num;
            cont++;
            sum = sum + aux.num;
            prom = sum/cont;
        }
    }
    aux = desacolar(p);

    return prom;

}


//3) Sumatoria de aquellos numeros divisores del primer elemento ingresada a la cola.

int sumatoriaDivisoresPrimero(nodo** p){

    nodo aux = desacolar(p);
    int sumaDiv = 0;
    int primero = aux.num;
    
    while (*p != NULL) {
        nodo aux = desacolar(p);

        if (primero % aux.num == 0) {
            sumaDiv = sumaDiv + aux.num;
        }
    }
    return sumaDiv;
}

//4) El numero maximo y su posicion en la cola.

void posMax(nodo** p, int *pos, int *max) {

    nodo aux = desacolar(p);
    int i = 1;
    *pos = 1;
    *max = aux.num;

    while (*p != NULL) {
        i++;
        aux = desacolar(p);
        if (aux.num > *max) {
            *max = aux.num;
            *pos = i;
        }
    }
    return;
}

//5) El numero minimo y su posicion en la cola.

void posMin(nodo** p, int* pos, int* min) {

    nodo aux = desacolar(p);
    int i = 1;
    *pos = 1;
    *min = aux.num;

    while (*p != NULL) {
        i++;
        aux = desacolar(p);
        if (aux.num < *min) {
            *min = aux.num;
            *pos = i;
        }
    }
    return;
}