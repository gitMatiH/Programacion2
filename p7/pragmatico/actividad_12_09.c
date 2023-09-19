/*
**
**	Código del menú
**	diariamente carga antes de entrar al loop
**
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//declaraciones
typedef struct infoProducto {
	int id;
	char nombre[30];
	float precio;
	//float contenido;
	int cantidad;
} infoProducto;

typedef struct infoTicket {
	int id;
	char nombre[30];
	float precio;
	int cantidad;
	float total;
} infoTicket;


typedef struct rankingProducto {
	int id;
	int ventas;
} rankingProducto;

typedef struct nodoListaProductos {
	infoProducto datos;
	struct nodoListaProductos* siguiente;
} nodoListaProductos;

typedef struct nodoListaTicket {
	infoTicket datos;
	struct nodoListaTicket* siguiente;
} nodoListaTicket;

/*
typedef struct listaProductos {
	struct nodoListaProductos* primerElemento;
} listaProductos;
*/

//funciones ppales
int cargarProductos(infoProducto infoProductos[1000], int* cantProductos);
int atenderCliente(int* nroCliente, int* contadorClientes, infoProducto infoProductos[1000], int* cantProductos, rankingProducto rankingProductos[1000]);
int mostrarDisponibles(infoProducto infoProductos[1000], int cantProductos);
int masVendido(rankingProducto rankingProductos[1000], int cantProductos);

//funciones secundarias
int inicializarRanking();
int actualizarRanking();
int ordenarRanking(rankingProducto rankingProductos[1000], int cantProductos);
int intercambiar_struct(rankingProducto* rankingProductosA, rankingProducto* rankingProductosB);


int crearListaTicket(nodoListaProductos* listaCarrito, nodoListaTicket* listaTicket);


int buscarProducto(infoProducto infoProductos[1000], int cantProductos, int codProducto);
int existeProducto(infoProducto infoProductos[1000], int cantProductos, int codProducto);
int hayStock(infoProducto infoProductos[1000], int cantProductos, int codProducto);
int agregarCarrito(infoProducto infoProductos[1000], int indice, nodoListaProductos* listaCarrito, int cant);
int sacarDeStock(infoProducto infoProductos[1000], int indice, int cant);



int main(void) {

	int opcion;
	int contadorClientes = 0;
	int nroCliente = 1;

	infoProducto infoProductos[1000];	//equivale a struct infoProducto infoProductos[1000];
	int cantProductos;
	rankingProducto rankingProductos[1000];

	printf("\nCargue los productos:\n");
	cargarProductos(infoProductos, &cantProductos);	//una idea seria hacerlo por archivo csv
	inicializarRanking();
	printf("\n\n");
	printf("Menu\n");
	printf("1. Atender cliente\n");
	printf("2. Mostrar productos disponibles\n");
	printf("3. Mostrar producto mas vendido\n");
	printf("0. Salir\n");
	printf("\n");
	printf("Ingrese opcion: ");
	scanf("%d", &opcion);


	//loop principal
	while (opcion != 0 && contadorClientes <= 10 && nroCliente != 0) {

		switch (opcion) {
			case 1:
				atenderCliente(&nroCliente, &contadorClientes, infoProductos, &cantProductos, rankingProductos);
				break;
			case 2:
				mostrarDisponibles(infoProductos, cantProductos);
				break;
			case 3:
				masVendido(rankingProductos, cantProductos);
				break;
			default:
				printf("Codigo invalido.");
				break;
		}

		if (nroCliente != 0) {
			printf("\n\n");
			printf("Menu\n");
			printf("1. Atender cliente\n");
			printf("2. Mostrar productos disponibles\n");
			printf("3. Mostrar producto mas vendido\n");
			printf("0. Salir\n");
			printf("\n");
			printf("Ingrese opcion: ");
			scanf("%d", &opcion);
		}
	}


	// loop para poder ver cosas una vez cerrado
	printf("\n\n");
	printf("Dia cerrado.\n");
	printf("Menu\n");
	printf("1. Mostrar productos disponibles\n");
	printf("2. Mostrar producto mas vendido\n");
	printf("0. Salir\n");
	printf("\n");
	printf("Ingrese opcion: ");
	scanf("%d", &opcion);

	while (opcion != 0) {
		printf("\n\n");
		printf("Dia cerrado.\n");
		printf("Menu\n");
		printf("1. Mostrar productos disponibles\n");
		printf("2. Mostrar producto mas vendido\n");
		printf("0. Salir\n");
		printf("\n");
		printf("Ingrese opcion: ");
		scanf("%d", &opcion);
	}
};


int cargarProductos(infoProducto infoProductos[1000], int * cantProductos) {


	*cantProductos = 0;

	int id;
	char nombre[30];
	float precio;
	//float contenido;
	int cantidad;

	printf("\nIngrese ID del producto %d, 0 para terminar de cargar: ", *cantProductos+1);
	scanf("%d", &id);
	infoProductos[*cantProductos].id = id;

	while (id != 0 && *cantProductos < 1000) {
	
		printf("Ingrese el nombre del producto: ");
		fflush(stdin);
		fgets(nombre, 30, stdin);
		strcpy(infoProductos[*cantProductos].nombre, nombre);

		printf("Ingrese el precio del producto: ");
		fflush(stdin);
		scanf("%.2f", &precio);
		infoProductos[*cantProductos].precio = precio;
		
		/*
		printf("Ingrese el contenido del producto: ");
		fflush(stdin);
		scanf("%.2fd", &contenido);
		infoProductos[*cantProductos].contenido = contenido;
		*/

		printf("Ingrese la cantidad del producto: ");
		fflush(stdin);
		scanf("%d", &cantidad);
		infoProductos[*cantProductos].cantidad = cantidad;


		*cantProductos = *cantProductos + 1;

		printf("\nIngrese ID del producto %d, 0 para terminar de cargar: ", *cantProductos+1);
		scanf("%d", &id);
		infoProductos[*cantProductos].id = id;
	}
}


int atenderCliente(int* nroCliente, int* contadorClientes, infoProducto infoProductos[1000], int* cantProductos, rankingProducto rankingProductos[1000]) {
	
	int codProducto;
	int cant_productos_carrito = 0;
	nodoListaProductos* listaCarrito = NULL;
	nodoListaTicket* listaTicket = NULL;
	int indice, cant, stock;

	//arma el carrito del cliente con una lista y saca los correspondientes al array
	printf("ingrese codigo del producto, 0 para terminar: ");
	scanf("%d", &codProducto);
	while (codProducto == 0 && !existeProducto(infoProductos, *cantProductos, codProducto) && !hayStock(infoProductos, *cantProductos, codProducto) ) {
		if (codProducto == 0) {
			printf("debe llevar al menos un producto.\n");
			printf("ingrese codigo del producto, 0 para terminar: ");
			scanf("%d", &codProducto);
		}
		else {
			printf("producto no disponible.\n");
			printf("ingrese codigo del producto, 0 para terminar: ");
			scanf("%d", &codProducto);
		}
	}
	
	while (codProducto != 0 && cant_productos_carrito < 100) {

		indice = buscarProducto(infoProductos, *cantProductos, codProducto);
		//printf("\n indice %d\n", indice);
		stock = infoProductos[indice].cantidad;
		//printf("\n stock %d\n", stock);

		printf("ingrese la cantidad a llevar: ");
		fflush(stdin);
		scanf("%d", &cant);
		while (cant < 1 || cant > stock) {
			printf("cantidad no valida.");
			printf("ingrese la cantidad a llevar: ");
			scanf("%d", &cant);
		}

		agregarCarrito(infoProductos, indice, listaCarrito, cant);
		
		
		sacarDeStock(infoProductos, indice, cant);


		cant_productos_carrito = cant_productos_carrito + 1;

		printf("ingrese codigo del producto, 0 para terminar: ");
		scanf("%d", codProducto);
		while (!existeProducto(infoProductos, *cantProductos, codProducto) && !hayStock(infoProductos, *cantProductos, codProducto)) {
			printf("producto no disponible.\n");
			printf("ingrese codigo del producto, 0 para terminar: ");
		}
	}
	

	//prepara una lista de cant x precio (listaticket)
	//si no existe en la lista, crea nodo y agrega, sino, agrega a existente (modifica elemento)
	crearListaTicket(listaCarrito, listaTicket);


	//imprime esa lista, actualiza el ranking y la borra
	//imprimirTicket(listaTicket);
	actualizarRanking(infoProductos, listaTicket);
	
}

int existeProducto(infoProducto infoProductos[1000],int cantProductos,int codProducto) {
	int i;
	int existe = 0;
	for (i = 0; i < cantProductos; i++) {
		if (infoProductos[i].id == codProducto) {
			existe = 1;
			//printf("existe!");
		}
	}
	return existe;
}
int hayStock(infoProducto infoProductos[1000], int cantProductos, int codProducto) {
	int i;
	int haystock = 0;
	for (i = 0; i < cantProductos; i++) {
		if (infoProductos[i].id == codProducto && infoProductos[i].cantidad > 0) {
			haystock = 1;
			//printf("hay stock!");
		}
	}
	return haystock;
}

int buscarProducto(infoProducto infoProductos[1000], int cantProductos, int codProducto) {
	int i = 0;
	while (i < cantProductos && codProducto != infoProductos[i].id) {
	
		i = i + 1;
	}
	return i;
}

int agregarCarrito(infoProducto infoProductos[1000], int indice, nodoListaProductos* listaCarrito, int cant) {

	nodoListaProductos* elementoNuevo;
	printf("holii");
	if (listaCarrito == NULL)
	{
		elementoNuevo = (nodoListaProductos*)malloc(sizeof(nodoListaProductos));
		//insertarPrincipio(listaDisponibles, elementoNuevo)
		elementoNuevo->datos.id = infoProductos[indice].id;
		//puts
		//elementoNuevo->nombre = infoProductos[i].nombre;
		elementoNuevo->datos.precio = infoProductos[indice].precio;
		elementoNuevo->datos.cantidad = infoProductos[indice].cantidad;
		elementoNuevo->siguiente = NULL;

		listaCarrito = elementoNuevo;
		printf("soy un elemento nuevo");
	}
	else {
		
		elementoNuevo = (nodoListaProductos*)malloc(sizeof(nodoListaProductos));
		//insertarPrincipio(listaDisponibles, elementoNuevo)
		elementoNuevo->datos.id = infoProductos[indice].id;
		//puts
		//elementoNuevo->nombre = infoProductos[i].nombre;
		elementoNuevo->datos.precio = infoProductos[indice].precio;
		elementoNuevo->datos.cantidad = infoProductos[indice].cantidad;
		elementoNuevo->siguiente = NULL;

		//inserta ppio
		elementoNuevo->siguiente = listaCarrito;
		listaCarrito = elementoNuevo;
		printf("soy otro elemento nuevo");
	}
}

int crearListaTicket(nodoListaProductos* listaCarrito, nodoListaTicket* listaTicket) {
	
	int esta;

	int id;
	char nombre[30];
	float precio;
	int cantidad;
	float total;

	nodoListaProductos* pActualListaCarrito = NULL;
	nodoListaTicket* pActualListaTicket = NULL;
	nodoListaTicket* nodoNuevo = NULL;


	if (listaCarrito != NULL) {
		//crear nuevo nodo para listaTicket y engancharlo
		pActualListaCarrito = listaCarrito;

		while (listaCarrito->siguiente != NULL) {



			//buscar si esta en listaTicket
			esta = 0;
			pActualListaTicket = listaTicket;
			if (pActualListaTicket->datos.id == pActualListaCarrito->datos.id) {
				esta = 1;
			}
			while (listaTicket->siguiente != NULL && !esta) {
				if (pActualListaTicket->datos.id == pActualListaCarrito->datos.id) {
					esta = 1;
				}
			}
			// si NO, 
			//crear nuevo nodo para listaTicket y engancharlo
			if (!esta) {
				nodoNuevo = (nodoListaTicket*)malloc(sizeof(nodoListaTicket));
				nodoNuevo->datos.id = pActualListaCarrito->datos.id;
				//nodoNuevo->datos.nombre = pActualListaCarrito->datos.nombre;
				//usar puts
				nodoNuevo->datos.precio = pActualListaCarrito->datos.precio;
				nodoNuevo->datos.cantidad = pActualListaCarrito->datos.cantidad;
				nodoNuevo->datos.total = precio*cantidad;
				nodoNuevo->siguiente = NULL;
				if (listaTicket == NULL) {
					listaTicket = nodoNuevo;
				}
				else {
					nodoNuevo->siguiente = listaTicket;
					listaTicket = nodoNuevo;
				}
			}

			// si SI,
			//sumarle la cantidad y hacer sumar al total el precio*cant
			if (esta) {
				pActualListaTicket->datos.cantidad = pActualListaTicket->datos.cantidad + cantidad;
				pActualListaTicket->datos.total = pActualListaTicket->datos.total + precio * cantidad;
			}



			pActualListaCarrito = pActualListaCarrito->siguiente;
		}


	}
	else {
		printf("Error, carrito vacio.");
	}

}


int sacarDeStock(infoProducto infoProductos[1000], int indice, int cant) {

	infoProductos[indice].cantidad = infoProductos[indice].cantidad - cant;

}


int actualizarRanking(infoProducto rankingProductos[1000], nodoListaTicket* listaTicket) {

}


int mostrarDisponibles(infoProducto infoProductos[1000], int cantProductos) {
	//recorrer el array y cargar en una lista los que tienen cantidad > 0
	int i;
	nodoListaProductos* prin = NULL;
	nodoListaProductos* elementoNuevo;
	nodoListaProductos* punteroActual;

	//listaProductos* listaDisponibles;
	//prin = (nodoListaProductos*)malloc(sizeof(nodoListaProductos));
	//nodoListaProductos* prin = NULL;



	for (i = 0; i < cantProductos; i++) {
		if (infoProductos[i].cantidad >= 1) {
			if (prin == NULL)
			{
				elementoNuevo = (nodoListaProductos*)malloc(sizeof(nodoListaProductos));
				//insertarPrincipio(listaDisponibles, elementoNuevo)
				elementoNuevo->datos.id = infoProductos[i].id;
				//puts
				//elementoNuevo->nombre = infoProductos[i].nombre;
				elementoNuevo->datos.precio = infoProductos[i].precio;
				elementoNuevo->datos.cantidad = infoProductos[i].cantidad;
				elementoNuevo->siguiente = NULL;

				prin = elementoNuevo;
			}
			else {
				elementoNuevo = (nodoListaProductos*)malloc(sizeof(nodoListaProductos));
				//insertarPrincipio(listaDisponibles, elementoNuevo)
				elementoNuevo->datos.id = infoProductos[i].id;
				//puts
				//elementoNuevo->nombre = infoProductos[i].nombre;
				elementoNuevo->datos.precio = infoProductos[i].precio;
				elementoNuevo->datos.cantidad = infoProductos[i].cantidad;
				elementoNuevo->siguiente = NULL;

				//inserta ppio
				elementoNuevo->siguiente = prin;
				prin = elementoNuevo;
			}
		}
	}

	//imprime esa lista
	printf("\n\nLista de los productos disponibles:\n");
	if (prin != NULL){
		punteroActual = prin;

		printf("id: %d\n", punteroActual->datos.id);
		printf("nombre: %s\n", punteroActual->datos.nombre);
		printf("precio: %.2f\n", punteroActual->datos.precio);
		printf("stock: %d\n", punteroActual->datos.cantidad);



		while (punteroActual->siguiente != NULL) {

			punteroActual = punteroActual->siguiente;
			printf("\n\n");

			printf("id: %d\n", punteroActual->datos.id);
			printf("nombre: %s\n", punteroActual->datos.nombre);
			printf("precio: %.2f\n", punteroActual->datos.precio);
			printf("stock: %d\n", punteroActual->datos.cantidad);
		}


	} else {
		printf("lista vacía");
	}
}




int inicializarRanking() {

}

int masVendido(rankingProducto rankingProductos[1000],int cantProductos) {
	
	//ordena el ranking (masvendido a menosvendido)
	ordenarRanking(rankingProductos, cantProductos);
	//imprimir el primero del array de ranking
	printf("El producto mas vendido es: %d", rankingProductos[0].id);
	printf("Que vendio un total de: %d", rankingProductos[0].ventas);
	
}

int ordenarRanking(rankingProducto rankingProductos[1000], int cantProductos) {
	int i = 0;

	while (i < cantProductos) {
		int j = 0;
		while (j < cantProductos - (1 + i)) {
			if (rankingProductos[j].ventas < rankingProductos[j + 1].ventas) {
				intercambiar_struct(&rankingProductos[j], &rankingProductos[j + 1]);
			}
			j++;
		}
		i++;
	}
	return 0;
}

int intercambiar_struct(rankingProducto* elemRankingProductosA, rankingProducto* elemRankingProductosB) {

	int aux;
	aux = elemRankingProductosA->id;
	elemRankingProductosA->id = elemRankingProductosB->id;
	elemRankingProductosB->id = aux;

	aux = elemRankingProductosA->ventas;
	elemRankingProductosA->ventas = elemRankingProductosB->ventas;
	elemRankingProductosB->ventas = aux;

}