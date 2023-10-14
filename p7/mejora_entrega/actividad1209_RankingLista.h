

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct listaProductos {
	int id;
	char nombre[30];
	float precio;
	//float contenido;
	int cantidad;
	struct listaProductos* sig;
} nodoProductos;

typedef struct listaTicket {
	int id;
	char nombre[30];
	float precio;
	//float contenido;
	int cantidad;
	float total;
	struct listaTicket* sig;
} nodoTicket;

typedef struct rankingProducto {
	int id;
	char nombre[30];
	int ventas;
	struct rankingProducto* sig;
} nodoRanking;


//declaraciones

// es void porque los inserta en orden, o sea que estan enganchados
// a la lista que esta en el programa ppal
void cargarProductos(nodoProductos* lP);

void inicializarRanking(nodoRanking* lR, nodoProductos* lP);

void atenderCliente(int* contadorClientes, 
							nodoProductos* lP, 
							nodoTicket* lT, 
							nodoRanking* lR);

void mostrarDisponibles(nodoProductos* lP);

nodoRanking* buscarMasVendido(nodoRanking* lR, nodoRanking* masVendido);

//void ordenarLista(nodoRanking* lR);




