
#include "../almacen.h"

void mostrarNodoProd(nodoProductos* pElemL) {
	if (pElemL != NULL) {
		printf("\nRegistro encontrado:\n");
		printf("\nid:\t%d", pElemL->id);
		printf("\nnombre:\t%s", pElemL->nombre);
		printf("\nprecio:\t%.2f", pElemL->precio);
		printf("\nstock:\t%d", pElemL->cantidad);
		printf("\n\nFin Registro encontrado\n");
	}
}

void mostrarListaProductos(nodoProductos* lP) {
	if (lP->sig != NULL) {	// si los hicieramos en conjunto en vez de secuencial, romperia la recursion
		printf("\n");
		printf("\nId:\t\t%d", lP->id);
		printf("\nProducto:\t%s", lP->nombre);
		printf("\nPrecio:\t\t%.2f", lP->precio);
		printf("\nCantidad:\t\t%d", lP->cantidad);
		printf("\n");
	}
	mostrarListaProductos(lP->sig);
	return;
}