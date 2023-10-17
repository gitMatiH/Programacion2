#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 10




typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux/*, *productoria*/)
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
  	printf("%02d p=%p u=%p\n", q->dato, *p, *u);
}

nodo desacolar(nodo** inicio)   // tb puedo trabajar aca
{
	nodo* aux;
   nodo datos;

	datos=**inicio;

	aux=*inicio;

	*inicio=(*inicio)->siguiente;
	free(aux);

    return datos;
}

int main()
{
    int productoria=1;
   int i,num;
   nodo* p=NULL;
   nodo* u=NULL;

   for(i=0; i<CANT; i++)
   {
       printf("Ingrese un numero");
       scanf("%d",&num);
        acolar(&p, &u, crear_nodo(num));

   }


   printf("\nVamos a desacolar todo\n");
	while(p!=NULL)
   {
    	//mostrar(desacolar(&p));
        nodo nodoCola = desacolar(&p);
        if (nodoCola.dato % 7 == 0){
            productoria = productoria * nodoCola.dato;
        }

   }
   printf("La productoria de los multiplos de 7 es %d\n", productoria);
   return 0;
}