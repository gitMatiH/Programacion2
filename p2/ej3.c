
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMORIA_CUENTAS 50

int cargarDatos(int nro_cuenta[50], char nombre_apellido[50][25], int tipo_cuenta[50], float saldo[50]);

int itemA(int nro_cuenta[50], char nombre_apellido[50][25], int tipo_cuenta[50], float saldo[50]);
int ordenarDatos(int nro_cuenta[50], char nombre_apellido[50][25], int tipo_cuenta[50], float saldo[50]);
int intercambiar_int(int* int1, int* int2);
int intercambiar_string(char* string1, char* string2);
int intercambiar_float(float* float1, float* float2);

int itemB(int nro_cuenta[50], char nombre_apellido[50][25], int tipo_cuenta[50], float saldo[50]);
int buscarLineal(float saldo[50]);

int itemD(int nro_cuenta[50], char nombre_apellido[50][25], int tipo_cuenta[50], float saldo[50]);



int main() {
	//int cantidad_cuentas = 50;
	int nro_cuenta[50];
	char nombre_apellido[50][25];
	int tipo_cuenta[50];
	float saldo[50];

	//inicializarBD(nro_cuenta, nombre_apellido, tipo_cuenta, saldo)

	cargarDatos(nro_cuenta, nombre_apellido, tipo_cuenta, saldo);

	itemA(nro_cuenta, nombre_apellido, tipo_cuenta, saldo);
	itemB(nro_cuenta, nombre_apellido, tipo_cuenta, saldo);
	//itemC();
	itemD(nro_cuenta, nombre_apellido, tipo_cuenta, saldo);
	//itemE();

}

int itemD(int nro_cuenta[50], char nombre_apellido[50][25], int tipo_cuenta[50], float saldo[50]) {
	float porcentaje;
	porcentaje = calcularPorcentajeArray();
	printf("El porcentaje de clientes que tienen un saldo mayor a 100 000: %f", porcentaje)
	return 0;
}

float calcularPorcentajeArray() {
	int acumulador_parte=0;
	int acumulador_total=0;
	while !(finArray) {
		if cond_parte{
			acumulador_parte = acumulador_parte + 1;
		}
		acumulador_total = acumulador_total + 1;
		arr.siguiente();

	}
	float calcularPorcentaje((float)parte, (float)total);
}

float calcularPorcentaje(float parte, float total) {
	float porcentaje;
	porcentaje = parte * 100 / total;
	return porcentaje;
}

int itemB(int nro_cuenta[50], char nombre_apellido[50][25], int tipo_cuenta[50], float saldo[50]) {

	int indice;
	char nombreyapellido[25];

	indice = buscarLineal(saldo);
	strcpy(nombreyapellido, &nombre_apellido[indice][0]);	// sin & tira warning que pasa un char a tipo puntero a char implicitamente

	printf("El nombre y apellido de la cuenta con menor saldo es: %s\n", nombreyapellido);

	return 0;
}

int buscarLineal(float saldo[50]) {
	// busqueda lineal (otra seria busqueda binaria(si estuviese ordenado por saldo), podriamos poner una opcion como parametro, 1,2 etc y documentar eso)
	int i = 0;

	int indice = i;
	float menorsaldo = saldo[0];

	while (i < 50) {

		//printf("saldo: %.2f\n", saldo[i]);

		if (saldo[i] < menorsaldo) {
			indice = i;
			printf("nuevo menor! %.2f\n", saldo[i]);
			menorsaldo = saldo[i];
		}
		i = i + 1;
	}

	return indice;
}

int itemA(int nro_cuenta[50], char nombre_apellido[50][25], int tipo_cuenta[50], float saldo[50]) {


	ordenarDatos(nro_cuenta, nombre_apellido, tipo_cuenta, saldo);

	int i = 0;

	while (i < 50) {
		printf("\n");
		printf("numero de cuenta:\t%d\n", nro_cuenta[i]);
		printf("nombre y apellido:\t%s\n", nombre_apellido[i]);
		printf("tipo de cuenta:\t\t%d\n", tipo_cuenta[i]);
		printf("saldo:\t\t\t%f\n", saldo[i]);
		printf("\n");
		i++;
	}


	return 0;
}

int ordenarDatos(int nro_cuenta[50], char nombre_apellido[50][25], int tipo_cuenta[50], float saldo[50]) {
	int i = 0;

	while (i < 50) {
		int j = 0;
		while (j < 50 - ( 1 + i)) {
			if (nro_cuenta[j] > nro_cuenta[j + 1]) {
				/*se podrían meter los cuatro intercambiar en un intercambiar gral que se fije por tipo. ¿cómo se hace esto correctamente?*/
				intercambiar_int(&nro_cuenta[j], &nro_cuenta[j + 1]);
				intercambiar_string(nombre_apellido[j], nombre_apellido[j + 1]);
				intercambiar_int(&tipo_cuenta[j], &tipo_cuenta[j + 1]);
				intercambiar_float(&saldo[j], &saldo[j + 1]);
			}
			j++;
		}
		i++;
	}
	return 0;
}

int intercambiar_int(int* int1, int* int2) {

	int aux;
	aux = *int1;
	*int1 = *int2;
	*int2 = aux;

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
	*float2 = aux;

	return 0;
}


int cargarDatos(int nro_cuenta[50], char nombre_apellido[50][25], int tipo_cuenta[50], float saldo[50]) {
	int cuenta;
	char nombre[25];
	int tipo;
	float monto;

	int i = 0;
	printf("Ingrese cuenta del cliente, 0 para terminar carga: ");
	scanf("%d", &cuenta);
	while (cuenta < 0) {
		printf("Error, dato invalido. ");
		printf("Ingrese cuenta del cliente, 0 para terminar carga: ");
		scanf("%d", &cuenta);
	}

	while (cuenta != 0) {
		nro_cuenta[i] = cuenta;

		//fflush(stdin);	// sino se queda con el \n del paso anterior (sirve para ingreso manual porque lee del stdin). Tendríamos que hacer de stdin a donde sea q apunte scanf
							//seria algo del tipo if ingresoManual fflush(stdin) else scanf
		scanf(" ");			// para cuando lee de un archivo así se "come" el \n que queda trabado en el archivo. debe haber una mejor manera de hacer esto..
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
		while (!(tipo == 1 || tipo == 2)) {
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
		printf("\n");
	}
	return 0;
}