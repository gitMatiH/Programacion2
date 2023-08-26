


#include <stdio.h>
#include <string.h>

int cargarDatos(int nro_cuenta[50], char nombre_apellido[50][25], int tipo_cuenta[50], float saldo[50]);
int itemA(int nro_cuenta[50], char nombre_apellido[50][25], int tipo_cuenta[50], float saldo[50]);

int main() {
	int nro_cuenta[50];
	char nombre_apellido[50][25];
	int tipo_cuenta[50];
	float saldo[50];

	cargarDatos(nro_cuenta, nombre_apellido, tipo_cuenta, saldo);
	
	itemA(nro_cuenta, nombre_apellido, tipo_cuenta, saldo);
	/*
	itemB();
	itemC();
	itemD();
	itemE();
	*/

}

int itemA(int nro_cuenta[50], char nombre_apellido[50][25], int tipo_cuenta[50], float saldo[50]) {

	int i = 0;

	while (i < 2) {
		printf("%d\n", nro_cuenta[i]);
		printf("%s\n", nombre_apellido[i]);
		printf("%d\n", tipo_cuenta[i]);
		printf("%f\n", saldo[i]);
		i++;
	}

	//ordenarDatos(int nro_cuenta[50], char nombre_apellido[50][25], int tipo_cuenta[50], double saldo[50]);
	return 0;
}


int cargarDatos(int nro_cuenta[50], char nombre_apellido[50][25], int tipo_cuenta[50], float saldo[50]) {
	int cuenta;
	char nombre[25];
	int tipo;
	float monto;

	int i=0;
	printf("Ingrese cuenta del cliente, 0 para terminar carga: ");
	scanf("%d", & cuenta);
	while (cuenta < 0) {
		printf("Error, dato invalido. ");
		printf("Ingrese cuenta del cliente, 0 para terminar carga: ");
		scanf("%d", & cuenta);
	}

	while (cuenta != 0) {
		nro_cuenta[i] = cuenta;

		fflush(stdin);	// sino se queda con el \n del paso anterior
		printf("Ingrese nombre y apellido del cliente: ");
		gets(nombre);
		while (25 < strlen(nombre) + 1) {	//+1 porque las cadenas terminan en \0
			printf("Error, cadena demasiado larga. ");
			printf("Ingrese nombre y apellido del cliente: ");
			gets(nombre);
		}
		strcpy(nombre_apellido[i], nombre);

		printf("Ingrese tipo de cuenta del cliente: ");
		scanf("%d", &tipo);
		while ( !(tipo == 1 || tipo == 2) ) {
			printf("Error, codigo invalido. ");
			printf("Ingrese tipo de cuenta del cliente: ");
			scanf("%d", &tipo);
		}
		tipo_cuenta[i] = tipo;

		printf("Ingrese saldo de la cuenta del cliente: ");
		scanf("%f", &monto);
		saldo[i] = monto;

	
		i = i + 1;
		printf("Ingrese cuenta del cliente, 0 para terminar carga: ");
		scanf("%d", &cuenta);
		while (cuenta < 0) {
			printf("Error, dato invalido.");
			printf("Ingrese cuenta del cliente, 0 para terminar carga: ");
			scanf("%d", &cuenta);
		}
	}
	return 0;
}