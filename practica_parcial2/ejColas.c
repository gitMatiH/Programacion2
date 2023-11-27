/*

Ingresar números enteros a una cola hasta que el valor sea igual a cero.
Calcular y mostrar:
	a) La suma de los divisores del segundo número ingresado a la cola.
	b) El valor mínimo de la cola y su posición.
	Si esta repetido mostrar la cantidad de veces que se repite.
	c) Si la cola tiene una cantidad de números pares,
	mostrar la suma de los términos centrales, de lo contrario,
	mostrar el termino central.

	pares: n=10

	|5|4|9|8|7|1|2|3|6|4|

	primer elem = elemento (0+longCola/2)				|7|
	segundo elem = elemento (longCola-longCola/2)		|1|
							(0+longCola/2   +  1)

	impares: n = 5

	|5|4|9|8|7|				|5|4|9.0 , 9.4 , 9.5 , 9.6 , 9.9|8|7|

	n/2 = 2.5 => termino central es 2.5 redondeado para arriba
	impares: n//2 + 1

*/

#include <stdio.h>
#include <stdlib.h>




typedef struct cola {
	int num;
	struct cola* sig;
}nodo;

nodo* crearNodo(int num);
void acolar(nodo** p, nodo** u, nodo* q);
nodo desacolar(nodo** p);
void mostrar(nodo, int, int*, int min, int* min_cant, int* i, int long_cola, int* central, int* central1, int* central2);


// generalmente hacemos
// mostrar(desacolar(&cola));

int main(void) {

	//punto a
	int num;
	int segundo;
	int sumatoria_divisores = 0;
	// luego va a ser pos = long_cola
	int pos;
	int long_cola;

	//punto b
	int min;
	int pos_min = 0;
	int min_cant = 0;

	//punto c
	//caso impar:
	int central;
	//caso par:
	int central1;
	int central2;
	int i = 0;



	//crear cola
	nodo* p = NULL;
	nodo* u = NULL;


	//llenar la cola
	pos = 0;
	printf("Ingrese un numero, 0 para finalizar: ");
	scanf("%d", &num);
	fflush(stdin);

	if (num != 0) {
		min = num;
		pos_min = 1;
	}


	while (num != 0) {
		//punto a
		pos = pos + 1;
		if (pos == 2) {
			segundo = num;
		}

		//punto b
		if (num < min) {
			min = num;
			pos_min = pos;
		}

		acolar(&p, &u, crearNodo(num));

		printf("Ingrese un numero, 0 para finalizar: ");
		scanf("%d", &num);
		fflush(stdin);
	}
	long_cola = pos;

	printf("\nMostramos la cola: \n");
	while (p != NULL) {
		mostrar(desacolar(&p), segundo, &sumatoria_divisores, min, &min_cant, &i, long_cola, &central, &central1, &central2);
	}

	printf("\n");
	printf("\nLa sumatoria de los divisores del segundo elemento ingresado a la cola es: %d", sumatoria_divisores);

	printf("\nEl valor minimo de la cola es: %d\nSu posicion de primer aparicion es: %d", min, pos_min);
	printf("\nLa cantidad de veces que aparece %d es: %d\n", min, min_cant);

	if (long_cola % 2 == 0)
	{
		printf("\nLa cola fue par.");
		printf("\nEl elemento central de la izquierda fue: %d", central1);
		printf("\nEL elemento central de la derecha fue: %d\n", central2);
		printf("\nLa sumatoria es: %d\n", central1 + central2);


	}
	else {
		printf("\nLa cola fue impar.");
		printf("\nEl elemento central fue %d\n", central);

	}

	return 0;
}


nodo* crearNodo(int num) {

	nodo* nuevoNodo = (nodo*)malloc(sizeof(nodo));
	nuevoNodo->num = num;
	nuevoNodo->sig = NULL;

	return nuevoNodo;
}

void acolar(nodo** p, nodo** u, nodo* q) {

	printf("acolar_nodo\n");
	if (*p == NULL) {
		//crea o "desvacía" la cola. Ppio y final son el mismo.
		*p = *u = q;
	}
	else {
		//encadena a q a la cola
		(*u)->sig = q;
		//setea a q como nuevo ultimo
		(*u) = q;
	}
}


nodo desacolar(nodo** p) {

	nodo* aux;
	nodo datos;

	datos = **p;
	aux = *p;

	//esto no se puede hacer sin doble puntero, porque se pierde
	//al cambiar al contexto del main
	*p = (*p)->sig;

	free(aux);

	return datos;
}


void mostrar(nodo aux, int segundo, int* sumatoria_divisores, int min, int* min_cant, int* i, int long_cola, int* central, int* central1, int* central2) {

	//*i++;	//esto hace aritmetica de punteros
	*i = *i + 1;

	printf("\n%d", aux.num);


	if (segundo % aux.num == 0) {
		*sumatoria_divisores = *sumatoria_divisores + aux.num;
	}

	if (aux.num == min) {
		*min_cant = *min_cant + 1;
	}

	if (long_cola % 2 == 0) {
		//caso cant de elementos pares
		if (*i == long_cola / 2) {
			*central1 = aux.num;
		}
		if (*i == long_cola / 2 + 1) {
			*central2 = aux.num;
		}

	}
	else {
		if (*i == long_cola / 2 + 1) {
			*central = aux.num;
		}
	}
}