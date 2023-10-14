#include "../almacen.h"
#include "atenderCliente.h"



void atenderCliente(int* contadorClientes,
	nodoProductos* lP,
	nodoTicket* lT,
	nodoRanking* lR)
{
	float monto = 0.0;
	int nro_cliente; // podria estar vinculado a una BBDD
	if (*contadorClientes < 10) {
		printf("\n\nIngrese el numero de cliente: ");
		scanf("%d", &nro_cliente);

		if (nro_cliente != 0) {

			*contadorClientes = *contadorClientes + 1;

			printf("\nAgregando al ticket:\n");
			lT->sig = NULL;
			generarTicket(lP, lT, lR);
			printf("\n*********************************************\n");
			printf("\nNro. cliente: %d\n\nTicket:\n", nro_cliente);
			mostrarTicket(lT);
			monto = calcularTotal(lT, &monto);
			//aplicar descuentos y beneficios al nro de cliente (fidelizacion)
			printf("\nMonto total: %.2f\n", monto);
			printf("\nFin ticket\n");
			printf("\n*********************************************\n");
			//almacenar ticket en BBDD
			lT = borrarTicket(lT); // hacer el borrado mas eficiente
			mostrarTicket(lT); //ticket vacio, opcional

			atenderCliente(contadorClientes, lP, lT, lR);
		}

	}
	else {
		printf("\nmaximo de clientes diarios alcanzado.\n");
	}
	return;
}

void mostrarTicket(nodoTicket* lT) {
	if (lT->sig != NULL) {	// si los hicieramos en conjunto en vez de secuencial, romperia la recursion
		printf("\nId:\t\t%d", lT->id);
		printf("\nProducto:\t%s", lT->nombre);
		printf("\nPrecio:\t\t%.2f", lT->precio);
		printf("\nCantidad:\t%d", lT->cantidad);
		printf("\nTotal:\t\t%f", lT->total);
		printf("\n");
		mostrarTicket(lT->sig);
	}

	return;
}

float calcularTotal(nodoTicket* lT, float* monto) {
	//// precond: monto cero para el primer llamado
	if (lT->sig != NULL) {
		*monto = *monto + lT->total;
		calcularTotal(lT->sig, monto);
	}
	return *monto;
}

nodoTicket* borrarTicket(nodoTicket* lT) {
	nodoTicket* aux = NULL;
	if (lT->sig != NULL) {
		aux = lT->sig;
		free(lT);
		lT = aux;
		borrarTicket(lT);
	}
	else {
		return lT;
	}
}



void generarTicket(nodoProductos* lP,
	nodoTicket* lT,
	nodoRanking* lR)
{
	printf("\nEntro a generar\n");
	nodoProductos* pElemL = NULL;
	int existe;
	int id;
	int cant;


	printf("\nIngrese ID del producto, 0 para terminar: ");
	scanf("%d", &id);
	if (id != 0) {
		pElemL = buscar(lP, id, pElemL);
		mostrarNodoProd(pElemL);

		if (pElemL != NULL && (pElemL->cantidad) > 0) {	//tiene q ser en este orden pq sino falla si es null
			printf("\nIngrese cantidad a llevar: ");
			scanf("%d", &cant);
			while (cant > pElemL->cantidad) {
				printf("\nNo hay stock para esa cantidad.\nLleve hasta %d.", pElemL->cantidad);
				printf("\nIngrese cantidad a llevar: ");
				scanf("%d", &cant);
			}

			agregar(lT, id, cant, pElemL);
			descontar(pElemL, cant);
			actualizarRanking(lR, id, cant);
			generarTicket(lP, lT, lR);
		}
		else
		{
			printf("producto no disponible");
			generarTicket(lP, lT, lR);
		}
	}
	return;
}




nodoProductos* buscar(nodoProductos* lP, int id, nodoProductos* pElemL) {
	if (lP->sig != NULL) {
		if (id == lP->id) {
			pElemL = lP;	//apuntan a lo mismo, NO es una copia
		}
		else {
			pElemL = buscar(lP->sig, id, pElemL);	//esto era clave
		}
	}
	return pElemL;
}

void agregar(nodoTicket* lT, int id, int cant, nodoProductos* pElemL) {

	if (lT->sig != NULL) {
		if (lT->id == id) {
			lT->precio = pElemL->precio;
			lT->cantidad = lT->cantidad + cant;
			lT->total = lT->precio * lT->cantidad;
		}
		else {
			agregar(lT->sig, id, cant, pElemL);
		}
	}
	else { //estaba vacia y creamos nuevo registro
		lT->id = pElemL->id;
		strcpy(lT->nombre, pElemL->nombre);
		lT->precio = pElemL->precio;
		lT->cantidad = cant;
		lT->total = lT->precio * lT->cantidad;
		nodoTicket* nuevoNodo = (nodoTicket*)malloc(sizeof(nodoTicket));
		nuevoNodo->sig = NULL;
		lT->sig = nuevoNodo;
	}
	return;
}




void descontar(nodoProductos* pElemL, int cant) {
	// pElemL ya es un puntero al lugar de la lista que queremos
	if ((pElemL->cantidad - cant) >= 0) {
		pElemL->cantidad = pElemL->cantidad - cant;
	}
	else {
		printf("\nError.\n");
		pElemL->cantidad = 0;
	}
	return;
}

void actualizarRanking(nodoRanking* lR, int id, int cant) {
	// aqui si hay que buscar el nodo
	if (lR->sig != NULL) {
		if (lR->id == id) {
			lR->ventas = lR->ventas + cant;
			return;
		}
		actualizarRanking(lR->sig, id, cant);
		return;
	}
}


void mostrarDisponibles(nodoProductos* lP) {

	if (lP->sig != NULL) {	// si los hicieramos en conjunto en vez de secuencial, romperia la recursion
		if (lP->cantidad > 0) {
			printf("\n");
			printf("\nId:\t\t%d", lP->id);
			printf("\nProducto:\t%s", lP->nombre);
			printf("\nPrecio:\t\t%.2f", lP->precio);
			printf("\nStock:\t\t%d", lP->cantidad);
			printf("\n");
		}
		mostrarDisponibles(lP->sig);
	}
	return;
}
