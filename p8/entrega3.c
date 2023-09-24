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
nodoLista* insertarNodoFinal(lista* pL, nodoLista* nodoNuevo);
//int insertarEnPos(lista* pLF, int posicion, nodoLista* nodoNuevo);
//int insertarPosAnteriorACondicion(lista* pL, nodoLista* nodoNuevo);

//funciones de tipo eliminar
//int eliminarNodoPpio(lista* pL);
//int eliminarNodoFinal(lista* pL);
//int eliminarNodoActual(lista* pL);
//int eliminarEnPos(lista* pLF, int posicion);
//int eliminarActualCondicion(lista* pL);

//funciones de tipo mostrar
//int mostrarLista(lista* pL);
//int mostrarListaR(nodoLista* nL);
//int mostrarListaW(nodoLista* nL);


int cargarLista(lista* pL);


int sumaMayorAVeinte(lista*);
int sumaIgualAVeinte(lista*, lista*);

int main(void) {

	lista* lista1 = crearLista();
	lista* listaEliminados = crearLista();

	cargarLista(lista1);
	//mostrarLista(lista1);
	//solo para mi esto
	//por suerte las condiciones no se pisan, es decir es lo mismo ejecutar primero uno de los procedimientos que al reves
	//ojo, esto es solo cierto para mayores a cero (positivos)!!
	//sumaMayorAVeinte(lista1);
	//sumaIgualAVeinte(lista1, listaEliminados);
	//
	//mostrarLista(listaEliminados);
	//mostrarLista(lista1);

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
		//insertarNodoFinal(pL, nodoNuevo);
		pL->cantElem = pL->cantElem + 1;
		contNodos = contNodos + 1;

		printf("\nProcedemos a cargar el nodo %d\n", contNodos);
		printf("Ingrese el elemento \"num\": ");
		scanf("%d", &num);
	}


}