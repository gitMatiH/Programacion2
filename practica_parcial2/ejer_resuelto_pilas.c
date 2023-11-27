//Hallar la cantidad de multiplos del ultimo valor ingresado a la pila.
//Hallar el valor minimo de la pila y la posicion en la que se encuentra. 

#include<stdlib.h>
#include<stdio.h>   

#define CANT 4



typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux,int *g, int *min, int *pos, int *cont, int ultimo, int *cont_elementos)

{
     	*g=*g-1; // g es la cantidad de elementos de la pila.
                //y va descontando a medida que desapila.
        *cont_elementos = *cont_elementos - 1;  //en carga se incrementa y en mostrar se decrementa

        printf("%d \n", aux.dato);
     	//*acum=*acum+aux.dato;
     	if (aux.dato < *min){
            *min=aux.dato;
        //    *pos=*g; //se lo pasa a pos, para saber su posicion
            *pos=*cont_elementos;
            }

        if (aux.dato % ultimo == 0 && aux.dato!=ultimo)
                *cont=*cont+1;

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
  	printf("%d p=%p u=%p\n", u->dato, *p, u);
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


   int i,num,acum=0,min,segundo,cont=0,ultimo,pos;
   int cont_elementos = 0;
   nodo* p=NULL;
    int g=CANT; //es la cantidad de elementos de la pila
                //puede ser reemplazada por un contador en caso de usar un while();
                //  int g=CANT  === int cont_elementos;

    printf("Ingrese un numero: ");
   	scanf("%d",&num);
    if(num != -1) cont_elementos = 1; //distinguir entre posicion e indice
                                    // el indice empieza en cero, es como el cero de un mapa
                                    // y la posicion se corresponde con el orden de los elementos.
                                    // pos ocupa el espacio y el indice indica donde comienza.
    
    while(num != -1)
    {

        apilar(&p, crear_nodo(num));
        cont_elementos = cont_elementos + 1;

         if (i==1) segundo=num;
        ultimo = num; //va a dejar de actualizar cuando sea el ultimo
   	    printf("Ingrese un numero: ");
   	    scanf("%d",&num);


    }

   min=ultimo;  //num es el tope de la pila, por eso empezamos desde ahi.
            // cuando num sale del if, obtenemos el primer elemento para comparar.
  
            //el primero que entra, es el ultimo que sale.

   printf("\nVamos a desapilar todo\n");
	while(p!=NULL)
   {
    	mostrar(desapilar(&p),&g, &min, &pos, &cont,ultimo,&cont_elementos);
   }
   //printf("%d\n",acum/CANT);
   //printf("%d \n",max);
    printf("La cantidad de multiplos del ultimo valor es: %d\n",cont);
    printf("El valor minimo y su posicion es; %d %d\n",min,pos);


   
   return 0;

}
