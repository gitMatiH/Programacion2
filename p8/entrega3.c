#include <stdio.h>
#include <stdlib.h>


typedef struct datos {
	int num;
	int num1;
	int num3;
}t_datos;

typedef struct nodoLista {
	t_datos datos;
	struct nodoLista* siguiente;
}nodoLista;

typedef struct lista {
	struct nodoLista* cabecera;
	struct nodoLista* actual;
	int cantElem;
}lista;

//funciones de tipo inicializar/crear
lista* crearLista(void);
nodoLista* crearNodoLista(int,int,int);

//funciones de tipo insertar
//nodoLista* insertarNodoPpio(lista* pL, nodoLista* nodoNuevo);
int insertarNodoFinal(lista* pLF, nodoLista* nuevoNodo);
//int insertarEnPos(lista* pLF, int posicion, nodoLista* nodoNuevo);
//int insertarPosAnteriorACondicion(lista* pL, nodoLista* nodoNuevo);

//funciones de tipo eliminar
//int eliminarNodoPpio(lista* pL);
//int eliminarNodoFinal(lista* pL);
//int eliminarNodoActual(lista* pL);
//int eliminarEnPos(lista* pLF, int posicion);
//int eliminarActualCondicion(lista* pL);

//funciones de tipo mostrar
int mostrarLista(lista* pL);
int mostrarListaR(nodoLista* nL, int i);
int mostrarListaW(nodoLista* nL, int i);


int cargarLista(lista* pL);


int sumaMayorAVeinte(lista*);
int sumaIgualAVeinte(lista*, lista*);

int main(void) {

	lista* lista1 = crearLista();
	lista* listaEliminados = crearLista();

	cargarLista(lista1);
	printf("\n\nprocedemos a mostrar la lista1:\n\n");
	mostrarLista(lista1);
	//solo para mi esto
	//por suerte las condiciones no se pisan, es decir es lo mismo ejecutar primero uno de los procedimientos que al reves
	//ojo, esto es solo cierto para mayores a cero (positivos)!!
	sumaMayorAVeinte(lista1);
	printf("\n\nprocedemos a mostrar la lista1:\n\n");
	mostrarLista(lista1);
	
	sumaIgualAVeinte(lista1, listaEliminados);
	printf("\n\nprocedemos a mostrar la lista1:\n\n");
	mostrarLista(lista1);
	//
	mostrarLista(listaEliminados);
	printf("\n\nprocedemos a mostrar la listaEliminados:\n\n");
	mostrarLista(listaEliminados);

	//elimina todos los nodos y luego la estructura central de lista tambien
	//eliminarLista(lista1);
	//eliminarLista(ListaEliminados);
	//mostrarLista(lista1);	// debe tener un fallback para lista vacia
	//mostrarLista(listaEliminados);

	return 0;
}

lista* crearLista(void) {
	lista* pL;
	pL = (lista*)malloc(sizeof(lista));
	pL->cabecera = NULL;
	pL->actual = NULL;
	pL->cantElem = 0;
	return pL;
}

nodoLista* crearNodoLista(int num, int num1, int num3) {

	nodoLista* nuevoNodo;
	nuevoNodo = (nodoLista*)malloc(sizeof(nodoLista));

	nuevoNodo->datos.num = num;
	nuevoNodo->datos.num1 = num1;
	nuevoNodo->datos.num3 = num3;
	nuevoNodo->siguiente = NULL;


	return nuevoNodo;

}


int cargarLista(lista* pL) {
	int contNodos = 0;
	int num, num1, num3;

	printf("\nProcedemos a cargar el nodo %d\n", contNodos+1);
	printf("Ingrese el elemento \"num\", 0 para terminar la carga: ");
	scanf("%d", &num);
	
	while (num != 0) {
		
		printf("Ingrese el elemento \"num1\": ");
		scanf("%d", &num1);

		printf("Ingrese el elemento \"num3\": ");
		scanf("%d", &num3);

	

		nodoLista* nodoNuevo = crearNodoLista(num, num1, num3);
		insertarNodoFinal(pL, nodoNuevo);
		pL->cantElem = pL->cantElem + 1;
		contNodos = contNodos + 1;

		printf("\nProcedemos a cargar el nodo %d\n", contNodos);
		printf("Ingrese el elemento \"num\", 0 para terminar la carga: ");
		scanf("%d", &num);
	}


}

int insertarNodoFinal(lista* pL, nodoLista* nuevoNodo) {


	if (pL->cabecera == NULL) {
		// significa que la lista vino vacia, y que la cabecera ser�a principio y fin
		pL->cabecera = nuevoNodo;
		pL->actual = pL->cabecera;
	}
	else // (pLF->cabecera != NULL), significa que la lista tiene elementos
	{
		// busca el nodo final, del cual el ->siguiente == NULL

		pL->actual = pL->cabecera;

		while (pL->actual->siguiente != NULL) {
			pL->actual = pL->actual->siguiente;
		}

		pL->actual->siguiente = nuevoNodo;
		pL->actual = nuevoNodo;
	}


	pL->cantElem = pL->cantElem + 1;
	return 0;
}


int mostrarLista(lista* pL) {

	int i = 1;

	pL->actual = pL->cabecera;

	mostrarListaR(pL->actual, i);
	//mostrarListaW(pL->actual);

}

int mostrarListaW(nodoLista* nL, int i) {

	while (nL != NULL) {
		printf("nodo numero: %d\n", i);
		printf("num: %d\n", nL->datos.num);
		printf("num1: %d\n", nL->datos.num1);
		printf("num3: %d\n", nL->datos.num3);
		//printf("\n%p\n", nL);

		nL = nL->siguiente;
	}
	//printf("llegue a null");
	return 0;

}

int mostrarListaR(nodoLista* nL, int i) {

	if (nL != NULL) {

		printf("nodo numero: %d\n", i);
		printf("num: %d\n", nL->datos.num);
		printf("num1: %d\n", nL->datos.num1);
		printf("num3: %d\n", nL->datos.num3);
		printf("\n");
		//printf("\n%p\n", nL);

		mostrarListaR(nL->siguiente, i+1);
	}
	return 0;

}


int sumaMayorAVeinte(lista* pL) {


	//nodoLista *previo, *siguiente;
	nodoLista* previo;

	previo = NULL;
	pL->actual = pL->cabecera;
	

	while (pL->actual != NULL) {
		//siguiente = pL->actual->siguiente;

		if ((pL->actual->datos.num +
			pL->actual->datos.num1 +
			pL->actual->datos.num3)
			 > 20)
		{
			printf("\nSuma mayor a veinte!\n");

			nodoLista* nuevoNodo = crearNodoLista(pL->actual->datos.num * 2,
				pL->actual->datos.num1 * 2,
				pL->actual->datos.num3 * 2);

			if (previo == NULL) { //es porque inserta en primera posicion

				nuevoNodo->siguiente = pL->actual;
				pL->cabecera = nuevoNodo;

			} else {

				nuevoNodo->siguiente = pL->actual;
				previo->siguiente = nuevoNodo;

			}

		}

		previo = pL->actual;
		pL->actual = pL->actual->siguiente;
	}


	return 0;
}



int sumaIgualAVeinte(lista* pL, lista* pLEliminados) {

	//printf("\nListaEliminados\n");
	//mostrarLista(pLEliminados);
	//nodoLista *previo, *siguiente;
	nodoLista* previo;

	previo = NULL;
	pL->actual = pL->cabecera;


	while (pL->actual != NULL) {
		//siguiente = pL->actual->siguiente;

		if ((pL->actual->datos.num +
			pL->actual->datos.num1 +
			pL->actual->datos.num3)
			 == 20)
		{
			printf("\nSuma igual a veinte!\n");


			if (previo == NULL) { //es porque elimina en primera posicion

				pL->cabecera = pL->actual->siguiente;

				pL->actual->siguiente = NULL;

				printf("num: %d\n", pL->actual->datos.num);
				printf("num1: %d\n", pL->actual->datos.num1);
				printf("num3: %d\n", pL->actual->datos.num3);
				printf("siguiente: %p\n", pL->actual->siguiente);
				printf("\n");
				
				nodoLista* nuevoNodo = crearNodoLista(	pL->actual->datos.num,
														pL->actual->datos.num1,
														pL->actual->datos.num3);
				insertarNodoFinal(pLEliminados, nuevoNodo);

				free(pL->actual);

				printf("\nListaEliminados\n");
				mostrarLista(pLEliminados);

				pL->actual = pL->cabecera;
				pL->cantElem = pL->cantElem - 1;
				//printf("\nListaEliminados\n");
				//mostrarLista(pLEliminados);

			}
			else {

				previo->siguiente = pL->actual->siguiente;


				printf("num: %d\n", pL->actual->datos.num);
				printf("num1: %d\n", pL->actual->datos.num1);
				printf("num3: %d\n", pL->actual->datos.num3);
				printf("siguiente: %p\n", pL->actual->siguiente);
				printf("\n");

				nodoLista* nuevoNodo = crearNodoLista(	pL->actual->datos.num,
														pL->actual->datos.num1,
														pL->actual->datos.num3);


				insertarNodoFinal(pLEliminados, nuevoNodo);
				free(pL->actual);

				pL->actual = previo->siguiente;

				pL->cantElem = pL->cantElem - 1;
				printf("\nListaEliminados\n");
				mostrarLista(pLEliminados);

			}

		} else {
			previo = pL->actual;
			pL->actual = pL->actual->siguiente;
		}
	}


	return 0;
}