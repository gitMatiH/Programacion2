
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cargarDatos(int nro_cuenta[50], char nombre_apellido[50][25], int tipo_cuenta[50], float saldo[50]);
int itemA(int nro_cuenta[50], char nombre_apellido[50][25], int tipo_cuenta[50], float saldo[50]);
int ordenarDatos(int nro_cuenta[50], char nombre_apellido[50][25], int tipo_cuenta[50], float saldo[50]);
int intercambiar_int(int* int1, int* int2);
int intercambiar_string(char* string1, char* string2);
int intercambiar_float(float* float1, float* float2);


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

	ordenarDatos(nro_cuenta, nombre_apellido, tipo_cuenta, saldo);

	int i = 0;

	while (i < 50) {
		printf("%d\n", nro_cuenta[i]);
		printf("%s\n", nombre_apellido[i]);
		printf("%d\n", tipo_cuenta[i]);
		printf("%f\n", saldo[i]);
		i++;
	}

	
	return 0;
}

int ordenarDatos(int nro_cuenta[50], char nombre_apellido[50][25], int tipo_cuenta[50], float saldo[50]) {
	int i = 0;
	int j = 50;
	//int aOrdenar;
	//aOrdenar = nro_cuenta[i];
	while (0 < j){
		while (i < j) {
			if (nro_cuenta[i] > nro_cuenta[i + 1]) {
				/*se podrían meter los cuatro intercambiar en un intercambiar gral que se fije por tipo. ¿cómo se hace esto correctamente?*/
				intercambiar_int(&nro_cuenta[i], &nro_cuenta[i + 1]);
				intercambiar_string(nombre_apellido[i], nombre_apellido[i+1]);
				intercambiar_int(&tipo_cuenta[i], &tipo_cuenta[i + 1]);
				intercambiar_float(&saldo[i], &saldo[i + 1]);
			}
			i++;
		}
		j--;
	}
	return 0;
}

int intercambiar_int(int* int1, int* int2) {
	
	int aux;
	aux = *int1;
	*int1 = *int2;
	*int2 = *int1;

	return 0;
}

int intercambiar_string(char* string1, char* string2) {
	//precondicion: los arreglos de caracteres deben tener el mismo tamaño maximo

	char* aux = (char*)malloc((strlen(string1) + 1) * sizeof(char));
	strcpy(aux, string1);
	strcpy(string1, string2);
	strcpy(string2, aux);
	free(aux);

	return 0;
}

int intercambiar_float(float* float1, float* float2) {

	float aux;
	aux = *float1;
	*float1 = *float2;
	*float2 = *float1;

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