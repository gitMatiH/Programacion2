/*
*	Matias Hillmann, legajo 0131473
*/

#include <stdio.h>

//declaraciones
int cargarArreglo(int arreglo[20], int tamanio);
void mostrarArreglo(int * arreglo, int tamanio);
int contarYAcumularC(int* arreglo, int tamanio, int * contador, int * acumulador);
void imprimirC(int contador_pares, int acumulador_impares);
void recorrerArreglo(int* arreglo, int tamanio);


// programa ppal
int main(void) {

	int arr[20];
	int tamanio_arr = 20;

	int contador_pares = 0;
	int acumulador_impares = 0;

	cargarArreglo(arr, tamanio_arr);
	mostrarArreglo(arr, tamanio_arr);
	contarYAcumularC(arr, tamanio_arr, &contador_pares, &acumulador_impares);
	imprimirC(contador_pares, acumulador_impares);
	recorrerArreglo(arr, tamanio_arr);


	return 0;
}


//funciones

int cargarArreglo(int arreglo[20], int tamanio_arr) {

	int i=0;

	while (i < tamanio_arr) {

		printf("Ingrese el elemento %d del array: ", i + 1);
		scanf("%d", &arreglo[i]);

		i = i + 1;
	}

	return 0;
}

void mostrarArreglo(int * arreglo, int tamanio_arr) {
	int i;
	
	printf("\n\nMostramos el arreglo cargado:\n");

	for (i = 0; i < tamanio_arr; i++) {
		printf("\nindice %d, posicion/elemento %d del arreglo:\narreglo[%d] = %d\n", i, i + 1, i, *(arreglo+i) );
	}
}

int contarYAcumularC(int* arreglo, int tamanio_arr, int* contador_pares, int* acumulador_impares) {
	
	int i;

	for (i = 0; i < tamanio_arr; i++) {
		if (*(arreglo + i) % 2 == 0) {
			*contador_pares = *contador_pares + 1;
		} else {
			*acumulador_impares = *acumulador_impares + *(arreglo + i);
		}
	}

	return 0;
}

void imprimirC(int contador_pares, int acumulador_impares) {
	printf("\n*********************************************************\n");
	printf("\nPunto C:\n");
	printf("\nLa cantidad de pares del arreglo fue un total de: %d\n", contador_pares);
	printf("\nLa sumatoria de los impares fue de: %d\n", acumulador_impares);
	printf("\n*********************************************************\n");
}

void recorrerArreglo(int* arreglo, int tamanio_arr) {
	
	int i;

	printf("\nRecorremos el arreglo:\n");
	for (i = 0; i < tamanio_arr; i++) {

		printf("\n");
		printf("Direccion de arreglo[%d] = 0x%p\n", i, arreglo+i);
		//printf("Direccion de arreglo[%d] en hexadecimal = %x\n", i, arreglo + i);
		printf("Contenido de arreglo[%d] = %d\n", i, *(arreglo + i) );

	}

}

/*
*	Matias Hillmann, legajo 0131473
*/