/*
**
**	Código del menú
**	diariamente carga antes de entrar al loop
**
*/

#include <stdio.h>
#include <string.h>

//declaraciones

int cargarProductos();


int main(void) {

	int opcion;
	int contadorClientes = 0;
	int nroCliente;
	estructura ArrayClientes[10];

	cargarProductos();
	printf("Abre el super y se empiezan a atender clientes.");
	
	/*
	Menu (switch)
	0. cargarProductos (nuevos)
	1. atenderCliente	(usa uno de ArregloClientes o crea uno nuevo, si hay menos de diez)
	2. facturarCliente
	3. mostrarProductosDisponibles
	4. mostrarProductoMasVendido
	
	*/
	while (opcion != 0) {
	
		printf("\n\n");
		printf("Menu\n");
		printf("1. Cargar productos\n")
		printf("2. Atender cliente\n");
		printf("3. Facturar cliente\n");
		printf("4. Mostrar productos disponibles\n");
		printf("5. Mostrar producto mas vendido\n");
		printf("0. Salir\n");
		printf("\n");
		printf("Ingrese opcion: ");
		scanf("%d", &opcion);

		if (codigoCliente == 0) {
			break;
		}

	}




};



//loop atendercliente
printf("Ingrese nro de cliente, 0 para cerrar: ");
scanf("%d", &nroCliente)
while (nroCliente != 0 && contadorClientes < 10) {







	printf("Ingrese nro de cliente, 0 para cerrar: ");
	scanf("%d", &nroCliente)
}