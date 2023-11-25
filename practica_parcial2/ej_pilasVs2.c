/*Crear una pila con la siguinte info:
    num: entero.
    *siguiente: puntero.

Escribir una funcion para mostrar la cantidad de numeros pares mayores al segundo
elemento de la pila. Si no hubiera algun numero mostrar una leyenda.
"No hay dos numeros en la pila."

Escribir una funcion que busque un numero solicitado previamente por teclado en la
pila e informar cuantas veces aparece el mismo y en que posicion.
La carga finaliza con el num = 999.
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>





typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux, int *cont,int segundo, nodo **pPos, int buscado, int *cont1, int *posicion);
nodo* crear_nodo(int dato);
void apilar(nodo** p, nodo* u);
nodo desapilar(nodo** p);


int main()
{
   int i,num;
   int cont=0, cont1=0;
   int segundo;
   int buscado;
   int posicion=0;
   nodo* p=NULL;
   nodo* pPos=NULL;

   i=0;

//resuelto por Naty 
    printf("Ingrese un numero: ");
   	scanf("%d",&num);
    while(num != 999)
   {
    apilar(&p, crear_nodo(num));
    i++;
    posicion=posicion+1;
    if (i==1)  segundo=num;
   	printf("Ingrese un numero: ");
   	scanf("%d",&num);   	    
    
   }
   printf("\nIngrese el numero a buscar: ");
   scanf("%d",&buscado);

   printf("\nVamos a desapilar todo\n");
	while(p!=NULL)
   {
    	mostrar(desapilar(&p),&cont,segundo,&pPos,buscado,&cont1,&posicion);
   }

   if(i <= 1)
   {
    printf("\nNo hay dos numeros en la pila.\n");
   }else{
   printf("\nLa cantidad de numeros mayores al segundo es: %d\n",cont);
   }

   printf("\nLa cantidad de veces que %d aparece es: %d\nEn las posiciones: \n",buscado,cont1);

   while(pPos != NULL)
   {
    printf("\n%d aparecio en la posicion %d",buscado,desapilar(&pPos).dato);
   }
   printf("\n");



   return 0;
}

void mostrar (nodo aux, int *cont,int segundo, nodo **pPos, int buscado, int *cont1, int *posicion)
{   
     	printf("%d \n", aux.dato);
     	   
     	if ((aux.dato %2 == 0)  &&
            (aux.dato > segundo) && 
            (aux.dato!=segundo))
            {
     	    *cont=*cont+1;
            }
        if(aux.dato == buscado)
        {
            *cont1=*cont1+1;
            apilar(pPos, crear_nodo(*posicion));
        }
        *posicion = *posicion - 1;
}

nodo* crear_nodo(int dato)
{
   nodo* u;
   u = (nodo *)malloc(sizeof(nodo));
   u->dato = dato;

   u->siguiente = NULL;

   return u;
}

void apilar(nodo** p, nodo* u)
{
    printf("apilar_nodo\n");


  	u->siguiente = *p;
  //	printf("%d p=%p u=%p\n", u->dato, *p, u);
	*p = u;
}

nodo desapilar(nodo** p)
{
	nodo* aux;
    nodo datos;

	datos=**p;

	aux=*p;

	*p=(*p)->siguiente;
	free(aux);

    return datos;

}
//autores: Naty y Maty,
