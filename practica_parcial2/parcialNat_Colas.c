#include<stdio.h>
#include<stdlib.h>




typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux, int* max, int* pos, int *pos_max)
{
  	printf("%d \n", aux.dato);

    *pos = *pos + 1;
    if(aux.dato > *max)
    {
        *max = aux.dato;
        *pos_max = *pos;
    }
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

int main()
{

   int num;
   int max;
   int pos;
   int pos_max;

   nodo* p=NULL;
   nodo* u=NULL;

    printf("Ingrese un numero: ");
    scanf("%d",&num);
    max = num;
    while(num != 999)
    {
        acolar(&p, &u, crear_nodo(num));
    
        printf("Ingrese un numero: ");
        scanf("%d",&num);

    }


   printf("\nVamos a desacolar todo\n");
	while(p!=NULL)
    {
    	mostrar(desacolar(&p),&max,&pos,&pos_max);
    }

    printf("El elemento maximo de la cola es: %d en la posicion: %d\n",max,pos_max);
   
   return 0;
}
