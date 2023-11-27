#include<stdio.h>
#include<stdlib.h>




typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux, int* acum, int* cont)
{
  	printf("%d \n", aux.dato);

    *cont = *cont + 1;
    if(*cont <= 3)
    {
        *acum = *acum + aux.dato;
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
   int acum = 0;
   int cont = 0;
   float prom;
   nodo* p=NULL;
   nodo* u=NULL;

    printf("Ingrese un numero: ");
    scanf("%d",&num);
    while(num != 999)
    {
        acolar(&p, &u, crear_nodo(num));
    
        printf("Ingrese un numero: ");
        scanf("%d",&num);

    }


   printf("\nVamos a desacolar todo\n");
	while(p!=NULL)
   {
    	mostrar(desacolar(&p),&acum,&cont);
   }

   if(cont >= 3)
   {
        prom = (float)acum/3;
        printf("El promedio de los primeros 3 numeros es: %.2f\n",prom);
    
   }else{
        printf("No hay mas de tres elementos en la pila.");
   }
   return 0;
}
