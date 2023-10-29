/*

Desarrollar un programa en C que permita ingresar números 
en un árbol binario de búsqueda. Mostrarlo en preorden, en orden 
y en postorden. Calcular y mostrar (en una función 
y no en el programa principal):

El valor máximo múltiplo de la raíz.
La cantidad de nodos hojas divisores de la raíz.
La sumatoria de aquellos nodos pares con un hijo.

*/



#include <stdio.h>
#include <stdlib.h>



typedef struct arbol {
	int dato;
	struct arbol* izq;
	struct arbol* der;
}nodoArbol;

//declaraciones

void crear(nodoArbol**);
nodoArbol* crearNodo(int);
void insertar(nodoArbol**, int);
void mostrarInorder(nodoArbol*);
void mostrarPreorder(nodoArbol*);
void mostrarPosorder(nodoArbol*);
void proceso(nodoArbol*, int*, int*, int*, int raiz);


int main(void) {

	int raiz;
	int maxMult, cont = 0, sum = 0, c = 0;
	float prom = 0;

	nodoArbol* arbol = NULL;
	nodoArbol* arbol2 = NULL;

	printf("\nCreamos arbol:\n");
	crear(&arbol);
	printf("\nArbol 1 creado\n");

	printf("\nPasamos a mostrar secuencia de recorrido inorder del arbol\n");
	mostrarInorder(arbol);

	printf("\nPasamos a mostrar secuencia de recorrido preorder del arbol\n");
	mostrarPreorder(arbol);

	printf("\nPasamos a mostrar secuencia de recorrido posorder del arbol\n");
	mostrarPosorder(arbol);

	printf("\nResolvemos los puntos del ejercicio: \n");

	raiz = arbol->dato;
	maxMult = arbol->dato;
	proceso(arbol, &maxMult, &cont, &sum, raiz);

	printf("El elemento multiplo de la raiz y maximo del arbol es: %d\n", maxMult);
	printf("La cantidad de nodos hojas divisores de la raiz: %d\n", cont);
	printf("La sumatoria de nodos pares con un solo hijo es: %d\n", sum);

	return 0;
}


//definiciones

void crear(nodoArbol** arbol) {

	int num;

	printf("Ingrese dato (entero) a insertar en el arbol binario (de busqueda), -1 para terminar: ");
	scanf("%d", &num);
	while (num != -1) {

		insertar(arbol, num);

		printf("Ingrese dato (entero) a insertar en el arbol binario (de busqueda), -1 para terminar: ");
		scanf("%d", &num);
	}

	return;
}

nodoArbol* crearNodo(int num) {
	nodoArbol* nuevoNodo;
	nuevoNodo = (nodoArbol*)malloc(sizeof(nodoArbol));
	nuevoNodo->dato = num;
	nuevoNodo->izq = NULL;
	nuevoNodo->der = NULL;
	return nuevoNodo;
}

void insertar(nodoArbol** arbol, int num) {
	nodoArbol* nuevoNodo;

	if (*arbol == NULL) {
		nuevoNodo = crearNodo(num);
		*arbol = nuevoNodo;
	}
	else {
		if ((*arbol)->dato > num) {
			insertar(&(*arbol)->izq, num);
		}
		else if ((*arbol)->dato < num) {
			insertar(&(*arbol)->der, num);
		}
	}
	// si es igual simplemente lo ignora y va a return (no hace nada) 
	return;
}

void mostrarInorder(nodoArbol* arbol) {

	if (arbol != NULL) {
		mostrarInorder(arbol->izq);
		printf("%d\n", arbol->dato);
		mostrarInorder(arbol->der);
	}
	return;
}

void mostrarPreorder(nodoArbol* arbol) {

	if (arbol != NULL) {
		printf("%d\n", arbol->dato);
		mostrarPreorder(arbol->izq);
		mostrarPreorder(arbol->der);
	}
	return;
}

void mostrarPosorder(nodoArbol* arbol) {

	if (arbol != NULL) {
		mostrarPosorder(arbol->izq);
		mostrarPosorder(arbol->der);
		printf("%d\n", arbol->dato);
	}
	return;
}

void proceso(nodoArbol* arbol, int* maxMult, int* cont, int* sum, int raiz) {
	//usamos la variante inorder

	if (arbol != NULL) {

		proceso(arbol->izq, maxMult, cont, sum, raiz);

		//Evalúa valor máximo múltiplo de la raíz;
		if ( (arbol->dato > *maxMult) && (arbol->dato % raiz == 0) ) {
			*maxMult = arbol->dato;
		}
		//Actualiza la cantidad de nodos hojas divisores de la raíz;
		if (arbol->izq == NULL &&
			arbol->der == NULL &&
			(raiz % arbol->dato == 0))
		{
			*cont = *cont + 1;
		}
		//Actualiza la sumatoria de aquellos nodos pares con un hijo;
		if (((arbol->izq != NULL && arbol->der == NULL) ||
			(arbol->izq == NULL && arbol->der != NULL)) &&
			(arbol->dato % 2 == 0))
		{
			*sum = *sum + arbol->dato;
		}

		proceso(arbol->der, maxMult, cont, sum, raiz);
	}
}