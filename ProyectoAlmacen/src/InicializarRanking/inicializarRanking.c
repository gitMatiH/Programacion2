#include "../almacen.h"


void inicializarRanking(nodoRanking* lR, nodoProductos* lP) {

	lR->sig = NULL;


	if (lP->sig != NULL) {	// si los hicieramos en conjunto en vez de secuencial, romperia la recursion

		lR->id = lP->id;
		strcpy(lR->nombre, lP->nombre);
		lR->ventas = 0;

		nodoRanking* nuevoNodo = (nodoRanking*)malloc(sizeof(nodoRanking));
		lR->sig = nuevoNodo;
		inicializarRanking(lR->sig, lP->sig);
	}
	return;
}