/*
*	Matias Hillmann, legajo 0131473
*/

#include <stdio.h>


int main(void){

	printf("\nEjemplo de resta de aritmetica de punteros:\n");

	int i;
	int arr[10];
	for (i=0; i<10; i++){
		arr[i] = 10-i;
		printf("\n");
		printf("arr[%d] = 10-%d = %d", i, i, 10-i);
	}

	int * p1;
	int * p2;

	printf("\n\n");

	p1 = arr;
	p2 = &arr[7];
	printf("p1 = arr = &(arr[0])\n");
	printf("p2 = (arr+7) = &(arr[7])\n");


	printf("\n");

	printf("arr[0] = %d\t(= *p1)", *p1);

	printf("\n");

	printf("arr[7] = %d\t(= *p2)", *p2);

	printf("\n\n");

	printf("arr[4] = %d", arr[4]);

	printf("\nes equivalente a:\n");

	printf("*(p2-3) = %d", *(p2-3));

	printf("\n");
}