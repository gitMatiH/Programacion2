#include "../almacen.h"

nodoRanking* buscarMasVendido(nodoRanking* lR, nodoRanking* masVendido) {

	if (lR->sig != NULL) {
		if (masVendido == NULL) {
			masVendido = lR;
		}
		else {
			if (lR->ventas > masVendido->ventas) {
				masVendido = lR;
			}
		}
		buscarMasVendido(lR->sig, masVendido);
	}
	return masVendido;
}