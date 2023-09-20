

#include <stdio.h>
#include <stdlib.h>


typedef struct ficha {
	int codPersona;
	int edad;
}t_ficha;

typedef struct nodoListaDeFichas {
	t_ficha ficha;
	struct nodoListaDeFichas* siguiente;
}nodoListaDeFichas;

typedef struct listaDeFichas {
	struct nodoListaDeFichas* cabecera;	//se modifica solo si insertamos al ppio
	struct nodoListaDeFichas* actual;	//va mutando
	int cantElem;	//para facilitar cosas, no es necesario
}listaDeFichas;

//funciones de tipo insertar
nodoListaDeFichas* insertarNodoPpio(listaDeFichas* pLF);
nodoListaDeFichas* insertarNodoFinal(listaDeFichas* pLF);
int insertarEnPos(listaDeFichas* pLF, int posicion, nodoListaDeFichas* nodoNuevo);

//funciones de tipo eliminar
int eliminarNodoPpio(listaDeFichas* pLF);
int eliminarNodoFinal(listaDeFichas* pLF);

//funciones de tipo inicializar/crear
listaDeFichas* crearListaDeFichas(void);
nodoListaDeFichas* crearNodoListaDeFichas(void);

//funciones de tipo mostrar
int mostrarLista(listaDeFichas* pLF);
int mostrarListaR(nodoListaDeFichas* nLF);
int mostrarListaW(nodoListaDeFichas* nLF);


// Lista TODO de funciones: 
// 
//int ordenarLista()
// va a usar:
//int intercambiarElemLista()
// 
//int eliminarEnPos(posx)
//int eliminar( fcioncond)
//int existe(elemento)
//listaDeFichas->actual buscar(elemento)
// 
// precond: crear lista nueva y existe listaant
//int duplicarLista(listanueva, listaant)

int main(void) {

	//es una planilla
	listaDeFichas* planilla;			// es un puntero a lista de fichas
	planilla = crearListaDeFichas();

	//es otra planilla
	listaDeFichas* planilla2 = crearListaDeFichas();

	printf("%p\n", planilla->cabecera);
	printf("%p\n", planilla2->cabecera);


	insertarNodoPpio(planilla);
	insertarNodoPpio(planilla);
	insertarNodoFinal(planilla);
	printf("\nEstado actual de planilla:\n");
	mostrarLista(planilla);
	eliminarNodoFinal(planilla);
	printf("\nEstado actual de planilla:\n");
	mostrarLista(planilla);
	eliminarNodoPpio(planilla);
	printf("\nEstado actual de planilla:\n");
	mostrarLista(planilla);

	insertarNodoFinal(planilla2);
	mostrarLista(planilla2);



	printf("\nFIN PROGRAMA\n");
	return 0;
}


listaDeFichas* crearListaDeFichas(void) {
	listaDeFichas* lista;
	// claro, si no le devuelvo esa dir de memoria afuera no aparece. Funcionaba igual
	// porque le llegaba una lista con algo, pero nunca llegaba a null
	lista = (listaDeFichas*)malloc(sizeof(listaDeFichas));
	lista->cabecera = NULL;
	lista->actual = NULL;
	lista->cantElem = 0;
	return lista;
}



int mostrarLista(listaDeFichas* pLF) {

	pLF->actual = pLF->cabecera;

	//mostrarListaR(pLF->actual);
	mostrarListaW(pLF->actual);

}

int mostrarListaW(nodoListaDeFichas* nLF) {

	while (nLF != NULL) {
		//nuestro caso base
		//estariamos apuntando sobre el ultimo nodo
		printf("\n%d\n", nLF->ficha.codPersona);
		printf("\n%d\n", nLF->ficha.edad);
		printf("\n%p\n", nLF);

		nLF = nLF->siguiente;
	}
	//printf("llegue a null");
	return 0;

}

int mostrarListaR(nodoListaDeFichas* nLF) {

	if (nLF != NULL) {
		//nuestro caso base
		//estariamos apuntando sobre el ultimo nodo
		printf("\n%d\n", nLF->ficha.codPersona);
		printf("\n%d\n", nLF->ficha.edad);

		mostrarListaR(nLF->siguiente);
	}
	return 0;

}



nodoListaDeFichas* insertarNodoPpio(listaDeFichas* pLF) {

	int codigoPersona, edad;

	nodoListaDeFichas* nuevoNodo;
	nuevoNodo = (nodoListaDeFichas*)malloc(sizeof(nodoListaDeFichas));
	printf("ingrese codigo persona: ");
	scanf("%d", &codigoPersona);
	nuevoNodo->ficha.codPersona = codigoPersona;
	printf("ingrese edad persona: ");
	scanf("%d", &edad);
	nuevoNodo->ficha.edad = edad;

	nuevoNodo->siguiente = NULL;

	if (pLF->cabecera == NULL) {
		// significa que la lista vino vacia
		pLF->cabecera = nuevoNodo;
	}
	else
		// (pLF->cabecera != NULL) 
	{
		// significa que la lista tiene elementos
		nuevoNodo->siguiente = pLF->cabecera;
		pLF->cabecera = nuevoNodo;
	}
	
	pLF->cantElem = pLF->cantElem + 1;
	return 0;
}



nodoListaDeFichas* insertarNodoFinal(listaDeFichas* pLF) {

	int codigoPersona, edad;

	nodoListaDeFichas* nuevoNodo;
	nuevoNodo = (nodoListaDeFichas*)malloc(sizeof(nodoListaDeFichas));

	//ingreso datos al nodo / o lo inicializo, podemos poner algo por default tb
	printf("ingrese codigo persona: ");
	scanf("%d", &codigoPersona);
	nuevoNodo->ficha.codPersona = codigoPersona;

	printf("ingrese edad persona: ");
	scanf("%d", &edad);
	nuevoNodo->ficha.edad = edad;

	nuevoNodo->siguiente = NULL;



	if (pLF->cabecera == NULL) {
		// significa que la lista vino vacia, y que la cabecera sería principio y fin
		pLF->cabecera = nuevoNodo;
	}
	else // (pLF->cabecera != NULL), significa que la lista tiene elementos
	{
		// busca el nodo final, del cual el ->siguiente == NULL

		pLF->actual = pLF->cabecera;

		while (pLF->actual->siguiente != NULL) {
			pLF->actual = pLF->actual->siguiente;
		}

		pLF->actual->siguiente = nuevoNodo;
		pLF->actual = nuevoNodo;
	}


	pLF->cantElem = pLF->cantElem + 1;
	return 0;
}



int eliminarNodoFinal(listaDeFichas* pLF) {
	
	nodoListaDeFichas* anterior = NULL;		// tambien se podria hacer con menos recursos todavia, con ->siguiente->siguiente

	if (pLF->cabecera == NULL) {
		// significa que la lista vino vacia, y que la cabecera sería principio y fin
		printf("lista ya estaba vacia.");
	}
	else // necesitamos el actual y el anterior. O sea dos elementos. Por lo tanto, tenemos que ver primero si la lista tiene
		 // un solo elemento
	{
		pLF->actual = pLF->cabecera;

		if (pLF->actual->siguiente == NULL) {
			// tiene un solo elemento
			free(pLF->actual);
			pLF->cabecera = NULL;
			pLF->actual = pLF->cabecera;
		}
		else {
			while (pLF->actual->siguiente != NULL) {
				anterior = pLF->actual;
				pLF->actual = pLF->actual->siguiente;
			}

			free(pLF->actual);
			pLF->actual = anterior;
			pLF->actual->siguiente = NULL;

		}
		pLF->cantElem = pLF->cantElem - 1;
	}


	
	return 0;
}




int eliminarNodoPpio(listaDeFichas* pLF) {

	nodoListaDeFichas* pAuxiliar = NULL;

	if (pLF->cabecera == NULL) {
		// significa que la lista vino vacia, y que la cabecera sería principio y fin
		printf("lista ya estaba vacia.");
	}
	else // necesitamos el actual y el anterior. O sea dos elementos. Por lo tanto, tenemos que ver primero si la lista tiene
		 // un solo elemento
	{
		pLF->actual = pLF->cabecera;

		if (pLF->actual->siguiente == NULL) {
			// tiene un solo elemento
			free(pLF->actual);
			pLF->cabecera = NULL;
			pLF->actual = pLF->cabecera;
		}
		else {
			pAuxiliar = pLF->actual->siguiente;

			free(pLF->actual);
			pLF->actual = pAuxiliar;
			pLF->cabecera = pAuxiliar;

		}
		pLF->cantElem = pLF->cantElem - 1;
	}


	
	return 0;
}




int insertarEnPos(listaDeFichas* pLF, int posicion, nodoListaDeFichas* nodoNuevo) {
	
	int pos;

	if (pLF->cantElementos < posicion || posicion < 1) {
		// validar e imprimir medio que se estaria saliendo de las responsabilidades de insertarEnPos
		// -> oportunidad de refactoring
		printf("posicion invalida");
		return 0;
	}
	else {	//posicion valida
		//se posiciona
		pLF->actual = pLF->cabecera;
		pos = 1;
		while ( pos != (posicion-1) ) {//??
		
			pLF->actual = pLF->actual->siguiente;
			pos = pos + 1;
		}

	}



}

nodoListaDeFichas* crearNodoListaDeFichas(void) {

	int codigoPersona, edad;

	nodoListaDeFichas* nuevoNodo;
	nuevoNodo = (nodoListaDeFichas*)malloc(sizeof(nodoListaDeFichas));

	//ingreso datos al nodo / o lo inicializo, podemos poner algo por default tb
	printf("ingrese codigo persona: ");
	scanf("%d", &codigoPersona);
	nuevoNodo->ficha.codPersona = codigoPersona;

	printf("ingrese edad persona: ");
	scanf("%d", &edad);
	nuevoNodo->ficha.edad = edad;

	nuevoNodo->siguiente = NULL;


	return nuevoNodo;

}