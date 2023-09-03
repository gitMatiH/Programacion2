#include <stdio.h>
#define VALOR 10


int sumarVectRec(int* vector, int i, int n) {

	if (i + 1 == n) {
		//printf("casobase\n");
		return vector[i];
	}
	//printf("recurro\n");
	return vector[i] + sumarVectRec(vector, ++i, n);
}




int main() {
	int i, num, res, max;
	//int n = VALOR;
	int vector[VALOR];

	//cargarVector
	for (i = 0; i < VALOR; i++) {
		printf("Ingrese un numero para la posicion %d del vector: ", i + 1);
		scanf("%d", &num);
		vector[i] = num;
	}

	//mostrarVector
	printf("\n");
	for (i = 0; i < VALOR; i++) {
		printf("posicion %d: %d\n", i + 1, vector[i]);
	}

	max = VALOR;
	res = sumarVectRec(vector, 0, max);
	printf("El resultado de la sumatoria de los elementos del vector es: %d", res);


	return 0;
}