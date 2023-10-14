
#include "../almacen.h"



void cargarProductos(nodoProductos* lP) {
	int codigo;
	char nombre[30];

	printf("\nIngrese el codigo de un producto, 0 para terminar: ");

	// validar_codigo() que no se repita el id
	scanf("%d", &codigo);
	while (codigo < 0) {
		printf("\nCodigo Invalido.\n");
		printf("\nIngrese el codigo de un producto, 0 para terminar: ");
		scanf("%d", &codigo);
	}	// si lo hiciese todo recursivo, en vez de una estructura while
		// para validar tendria que hacer una funcion recursiva nueva
	// validar_codigo()
	// adentro de la validación debería ir la no-duplicacion de la clave

	if (codigo != 0) {
		lP->id = codigo;

		printf("\nIngrese el nombre del producto: ");
		fflush(stdin);
		scanf("%[^\n]", nombre);

		while (strlen(nombre) > 29) {
			printf("El nombre debe ser mas corto.");
			printf("\nIngrese el nombre del producto: ");
			fflush(stdin);
			scanf("%[^\n]", nombre);
		}
		strcpy((lP->nombre), nombre);
		fflush(stdin);

		printf("\nIngrese el precio del producto: ");
		scanf("%f", &lP->precio);

		printf("\nIngrese la cantidad en stock del producto: ");
		scanf("%d", &lP->cantidad);

		nodoProductos* nuevoNodo = (nodoProductos*)malloc(sizeof(nodoProductos));
		lP->sig = nuevoNodo;
		cargarProductos(lP->sig);
	}
	else {
		//crea el "nodo final"
		lP->sig = NULL;
	}

	return;

}
