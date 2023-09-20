

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
	//int cantElem;	//para facilitar cosas, no es necesario
}listaDeFichas;

nodoListaDeFichas* insertarNodoPpio(listaDeFichas* pLF);
nodoListaDeFichas* insertarNodoFinal(listaDeFichas* pLF);

nodoListaDeFichas* eliminarNodoPpio(listaDeFichas* pLF);
nodoListaDeFichas* eliminarNodoFinal(listaDeFichas* pLF);


listaDeFichas* crearListaDeFichas(void);

int mostrarLista(listaDeFichas* pLF);
int mostrarListaR(nodoListaDeFichas* nLF);
int mostrarListaW(nodoListaDeFichas* nLF);
//int ordenarLista()
//int insertarEnPos(posx)
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
	//nodoListaDeFichas* aux;

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

		//printf("entre en null\n");
	}
	else
		// (pLF->cabecera != NULL) 
	{
		// significa que la lista tiene elementos
		nuevoNodo->siguiente = pLF->cabecera;
		pLF->cabecera = nuevoNodo;
		//printf("entre en !null\n");
	}

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

}



