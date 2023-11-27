#include<stdio.h>
#include<stdlib.h>


typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux, int ultimo, int *cantMult)
{
    printf("%d \n", aux.dato);

    if(aux.dato % ultimo == 0)
    {
        *cantMult = *cantMult + 1;
    }
}

nodo* crear_nodo(int dato )
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
  //printf("%02d p=%X u=%X\n", u->dato, *p, u);
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

int main()
{

   int i=0;
   int num;
   int ultimo;
   int cantMult = 0;
   nodo* p=NULL;

    printf("Ingrese un numero: ");
   	scanf("%d",&num);


    while(num != 999)
    {
   	    apilar(&p, crear_nodo(num));
        ultimo = num;
        i++;
        printf("Ingrese un numero: ");
   	    scanf("%d",&num);
    }
    

   printf("\nVamos a desapilar todo\n");
	while(p!=NULL)
   {
    	mostrar(desapilar(&p),ultimo,&cantMult);
   }

    if(cantMult == 0)
    {
        printf("\nNo hay ningun numero multiplo del ultimo.\n");

    }else{

        printf("La cantidad de elementos multiplos del ultimo es: %d\n",cantMult);
    }

   return 0;
}
