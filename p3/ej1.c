#include <stdio.h>
#define n 3

int cargarMatriz(int matriz[n][n]);
int itemA(int matriz[n][n]);
/*
int itemB();
int itemC();
int itemD();
int itemE();
int itemF();
int itemG();
int itemH();
*/

int main(void)
{
	int matriz[n][n];
	int item_a;
	int sumatoria;

	cargarMatriz(matriz);

	item_a = itemA(matriz);
	printf("La sumatoria de los elementos de la segunda fila es: %d", item_a);

	/*
	itemB();
	itemC();
	itemD();
	itemE();
	itemF();
	itemG();
	itemH();
	*/
	return 0;
}

//deberia ir con el (los) tamaño(s) del arreglo que le pasamos
int cargarMatriz(int matriz[n][n])
{
	int i = 0, j = 0;
	int elem;
	while (i < n) {
		while (j < n){
			printf("ingrese el elemento [%d][%d]: ", i, j);
			scanf("%d", &elem);
			matriz[i][j] = elem;
			j = j + 1;
		}
		j = 0;
		i = i + 1;
	}
	return 0;
}

int itemA(int matriz[n][n])
{
	int sumatoria=0;
	int i = 1, j = 0;
	while (j < n) {
		sumatoria = sumatoria + matriz[i][j];
		j++;
	}
	return sumatoria;
}