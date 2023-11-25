/*Crear una cola con la sig informacion:
    num: numero entero.
    *siguiente: puntero al proximo elemento de la cola.

Escribir una funcion para calcular el maximo elemento par de la cola y
en que posicion esta. Si no lo hubiese mostrar una leyenda indicativa. 
La carga finaliza con num = -1 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 10


typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;


void mostrar (nodo aux);
void mostrarPar (nodo aux, nodo** pColaPar, nodo** uColaPar);
nodo* crear_nodo(int dato);
void acolar(nodo** p,nodo** u, nodo *q);
nodo desacolar(nodo** inicio);



int main()
{

   int i,j,num;
   int cont = 0;
   int maxPar=0;
   int posMax;
   nodo* p=NULL;
   nodo* u=NULL;

   nodo* pColaPar = NULL;
   nodo* uColaPar = NULL;

   nodo* pColaPos = NULL;
   nodo* uColaPos = NULL;

   j=1;

    printf("Ingrese un numero: ");
    scanf("%d",&num);
   while(num != -1)
   {
        
        acolar(&p, &u, crear_nodo(num));

        if(num % 2 == 0)
        {
            acolar(&pColaPar ,&uColaPar ,crear_nodo(num));
            acolar(&pColaPos ,&uColaPos ,crear_nodo(j));

        }
        j++;
        printf("Ingrese un numero: ");
        scanf("%d",&num);
   }


   printf("\nVamos a desacolar todo:\n");
   
   if(pColaPar != NULL)
   {

   nodo aux = desacolar(&pColaPar);
   nodo aux2 = desacolar(&pColaPos);
   maxPar = aux.dato;
   posMax=aux2.dato;

   while(pColaPar!=NULL)
    {
        aux = desacolar(&pColaPar);
        aux2 = desacolar(&pColaPos);

        if(aux.dato > maxPar){
            posMax = aux2.dato;
            maxPar = aux.dato;
        }
    }

   }else{
        printf("No hubo numeros pares.");
   }

    if(maxPar != 0){
        printf("\nEl maximo es: %d y su posicion es: %d\n",maxPar,posMax);
    }



	
   return 0;
}

void mostrarPar (nodo aux, nodo** pColaPar, nodo** uColaPar)
{
    
    printf("%d \n", aux.dato);
}

void mostrar (nodo aux)
{
    
    printf("%d \n", aux.dato);
}

nodo* crear_nodo(int dato)
{
   nodo* u;
   u = (nodo *)malloc(sizeof(nodo));

   u->dato = dato;

   u->siguiente = NULL;

   return u;
}

void acolar(nodo** p,nodo** u, nodo *q)
{
   printf("acolar_nodo\n");
	if(*p==NULL)
    *p = *u = q; /*porque hay uno solo*/
   else
   {
    	(*u)->siguiente = q;
    	(*u) = q;
   }
  //	printf("%02d p=%X u=%X\n", q->dato, *p, *u);
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
