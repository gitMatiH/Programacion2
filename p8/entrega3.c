#include <stdio.h>
#include <stdlib.h>


typedef struct datos {
	int num;
	int num1;
	int num2;
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
nodoLista* crearNodoLista(void);

//funciones de tipo insertar
nodoLista* insertarNodoPpio(lista* pLF, nodoLista* nodoNuevo);
nodoLista* insertarNodoFinal(lista* pLF, nodoLista* nodoNuevo);
int insertarEnPos(lista* pLF, int posicion, nodoLista* nodoNuevo);
int insertarPosAnteriorACondicion(lista* pLF, nodoLista* nodoNuevo);

//funciones de tipo eliminar
int eliminarNodoPpio(lista* pLF);
int eliminarNodoFinal(lista* pLF);
int eliminarNodoActual(lista* pLF);
int eliminarEnPos(lista* pLF, int posicion);
int eliminarActualCondicion(lista* pLF);

//funciones de tipo mostrar
int mostrarLista(lista* pLF);
int mostrarListaR(nodoLista* nLF);
int mostrarListaW(nodoLista* nLF);


int cargarLista(lista);


int main() {

	lista* lista1 = crearLista();
	lista* listaEliminados = crearLista();

	cargarLista(lista1);
	mostrarLista(lista1);
	//solo para mi esto
	//por suerte las condiciones no se pisan, es decir es lo mismo ejecutar primero uno de los procedimientos que al reves
	//ojo, esto es solo cierto para mayores a cero (positivos)!!
	sumaMayorAVeinte(lista1);
	sumaIgualAVeinte(lista1, listaEliminados);
	//
	mostrarLista(listaEliminados);
	mostrarLista(lista1);

	//elimina todos los nodos y luego la estructura central de lista tambien
	//eliminarLista(lista1);
	//eliminarLista(ListaEliminados);
	//mostrarLista(lista1);	// debe tener un fallback para lista vacia
	//mostrarLista(listaEliminados);

	return 0;
}



int cargarLista(lista* pL) {
	int contNodos = 0;


	printf("\nProcedemos a cargar el nodo %d\n", contNodos);
	printf("Ingrese el elemento \"num\", 0 para terminar la carga: ");
	scanf("%d", &num);
	
	while (num != 0) {
		
		printf("Ingrese el elemento \"num1\": ");
		scanf("%d", &num1);

		printf("Ingrese el elemento \"num3\": ");
		scanf("%d", &num3);

	

		nodoLista* nodoNuevo = crearNodo();
		insertarNodoFinal(pL);
		pL->cantElem = pL->cantElem + 1;
		contNodos = contNodos + 1;

		printf("\nProcedemos a cargar el nodo %d\n", contNodos);
		printf("Ingrese el elemento \"num\": ");
		scanf("%d", &num);
	}

	


}