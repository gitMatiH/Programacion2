#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 4



typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux)

{
     	printf("%d \n", aux.dato);
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
  	printf("%02d p=%p u=%p\n", u->dato, *p, u);
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
    int j = 0;
    int max, pos;
    int * posMax;

   int i,num;
   nodo* p=NULL;


   for(i=0; i<CANT; i++)
   {
   	printf("Ingrese un numero \n");
   	scanf("%d",&num);
   	apilar(&p, crear_nodo(num));
   }


   printf("\nVamos a desapilar todo\n");
   nodo nodoPila = desapilar(&p);
   j++;
   max = nodoPila.dato;
   pos = j;
   posMax = &(nodoPila.dato);

	while(p!=NULL)
   {
    	//mostrar(desapilar(&p));

        nodo nodoPila = desapilar(&p);
        j++;

        if (max < nodoPila.dato){
            max = nodoPila.dato;
            posMax = &(nodoPila.dato);
            pos = j;
        }
        
   }
    printf("El maximo vale %d, y su posicion en la pila es %d", max, pos);

   getchar();
   return 0;
}