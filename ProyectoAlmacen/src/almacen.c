/*

Escriba un programa que permita registrar las ventas y los productos que se 
venden en un pequeño supermercado de barrio.

De los productos se guarda la siguiente información:

ID producto
Nombre del producto
Precio
Contenido neto/ Cantidad
Crear un programa que calcule el valor que debe pagar el cliente, en base a 
los productos que desea llevar, así como el producto más vendido.

1) Al comenzar el día el dueño de la tienda, carga los nuevos productos que 
tiene para vender.
2) El dueño del local va a atender 10 clientes en el día o hasta que el número 
de cliente sea igual a 0 (cero).
3) Cada cliente puede llevar la cantidad de productos que desee siempre que sea 
mayor a cero y menor a 100.
4) Se debe calcular y mostrar el precio total (cantidad × precio) de cada producto elegido. 
Pueden hacerlo creando otra lista que guarde solo los precios totales según el producto.
5) Mostrar una lista de todos los productos disponibles. Para esto se puede usar la lista 
creada anteriormente o usando su imaginación.

IMPORTANTE: El programa debe contar con un menú que permita seleccionar que se desea hacer.

*/



#include "almacen.h"


int main(void) {

	int opcion;
	int contadorClientes = 0;
	int nroCliente = 1;
	nodoRanking* masVendido = NULL;

	nodoProductos* lP = (nodoProductos*)malloc(sizeof(nodoProductos));
	nodoTicket* lT = (nodoTicket*)malloc(sizeof(nodoTicket));
	nodoRanking* lR = (nodoRanking*)malloc(sizeof(nodoRanking));

	printf("\nCargue los productos:\n");
	cargarProductos(lP);	//una idea seria hacerlo por archivo csv, pero va copiando y pegando un txt
	inicializarRanking(lR, lP);		//no hace falta inicializar el ranking con listas, lo vas llenando directo

	printf("\n\nMenu");
	printf("\n1. Atender clientes");
	printf("\n2. Mostrar productos disponibles");
	printf("\n3. Mostrar producto mas vendido");
	printf("\n0. Salir");
	printf("\n\nIngrese opcion: ");
	scanf("%d", &opcion);
	system("cls");

	//loop principal
	while (opcion != 0) {

		switch (opcion) {

		case 0:
			break;

		case 1:

			atenderCliente(&contadorClientes, lP, lT, lR);

			break;

		case 2:
			printf("\nLista de disponibilidad:\n");
			mostrarDisponibles(lP);
			printf("\nFin de lista disponibilidad:\n");
			break;

		case 3:
			//ordenarLista(lR);
			nodoRanking * masVendido = (nodoRanking*)malloc(sizeof(nodoRanking));
			masVendido = NULL;
			masVendido = buscarMasVendido(lR, masVendido);
			if (masVendido == NULL) {
				printf("\nNo hubo ventas.\n");
			}
			else {
				printf("\nMas Vendido: \n");
				printf("\nid:\t%d", masVendido->id);
				printf("\nombre:\t%s", masVendido->nombre);
				printf("\nventas:\t%d", masVendido->ventas);
			}
			break;

		default:
			printf("Codigo invalido.");
			break;
		}

		printf("\n\nMenu");
		printf("\n1. Atender clientes");
		printf("\n2. Mostrar productos disponibles");
		printf("\n3. Mostrar producto mas vendido");
		printf("\n0. Salir");
		printf("\n\nIngrese opcion: ");
		scanf("%d", &opcion);
		system("cls");
	}


	return 0;
}

