

#include <stdio.h>
#include <stdlib.h>

/*
struct ficha {
	int codPersona;
	int edad;
};
*/



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
	//int cantElem;
}listaDeFichas;

nodoListaDeFichas* insertarNodoPpio(listaDeFichas* pLF);

int mostrarLista(listaDeFichas* pLF);
int mostrarListaR(nodoListaDeFichas* nLF);
int mostrarListaW(nodoListaDeFichas* nLF);
//int ordenarLista()
//int insertarFinal()
//int insertarEnPos(posx)
//int eliminarEnPos(posx)
//int eliminarPrim(posx)
//int eliminarUlt()
//int eliminar( fcioncond)
//int buscar(elemento)
//int duplicarLista(listanueva, listaant)

int main(void) {

	//crearLista()
	listaDeFichas* planilla;
	planilla = (listaDeFichas*)malloc(sizeof(listaDeFichas));
	planilla->cabecera = NULL;
	planilla->actual = NULL;

	printf("%p", planilla->cabecera);


	//planilla = (listaDeFichas*)malloc(sizeof(listaDeFichas));
	insertarNodoPpio(planilla);
	insertarNodoPpio(planilla);
	mostrarLista(planilla);

	/*
	//struct ficha f1;
	t_ficha f1;
	f1.codPersona = 123;
	f1.edad = 34;
	printf("codigo %d\n", f1.codPersona);
	printf("edad %d\n", f1.edad);
	*/
}

nodoListaDeFichas* insertarNodoPpio(listaDeFichas* pLF) {
	
	int codigoPersona, edad;
	//nodoListaDeFichas* aux;

	nodoListaDeFichas* nuevoNodo;
	nuevoNodo = (nodoListaDeFichas*)malloc(sizeof(nodoListaDeFichas));
	printf("ingrese codigo persona: ");
	scanf("%d",&codigoPersona);
	nuevoNodo->ficha.codPersona = codigoPersona;
	printf("ingrese edad persona: ");
	scanf("%d",&edad);
	nuevoNodo->ficha.edad = edad;

	nuevoNodo->siguiente = NULL;
	
	if (pLF->cabecera == NULL) {
		// significa que la lista vino vacia
		pLF->cabecera = nuevoNodo;

		printf("entre en null\n");
	}
	else
		// (pLF->cabecera != NULL) 
	{
		// significa que la lista tiene elementos
		nuevoNodo->siguiente = pLF->cabecera;
		pLF->cabecera = nuevoNodo;
		printf("entre en !null\n");
	}

}


int mostrarLista(listaDeFichas* pLF) {
	
	pLF->actual = pLF->cabecera;

	mostrarListaR(pLF->actual);
	//mostrarListaW(pLF->actual);

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