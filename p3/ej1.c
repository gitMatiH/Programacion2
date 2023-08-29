#include <stdio.h>
#define n 3

int cargarMatriz(int matriz[n][n]);
int itemA(int matriz[n][n]);
int itemB(int matriz[n][n], int mayorElemento);
float itemC(int matriz[n][n]);
int itemD(int matriz[n][n]);
void itemE(int matriz[n][n],int *,int *,int *);
int itemF(int matriz[n][n]);

int itemH(int matriz[n][n]);

/*
int itemG();

*/

int main(void)
{
	int matriz[n][n];
	int item_a;
	int sumatoria;

	int item_b;
	int mayorElemento;

	float item_c;

	int item_d;

	int item_e;
	int minF1,minF2,minF3;

	int item_f;

	int item_h;

	cargarMatriz(matriz);

	item_a = itemA(matriz);
	printf("\n\n");
	printf("La sumatoria de los elementos de la segunda fila es: %d", item_a);
	printf("\n\n");

	item_b = itemB(matriz,mayorElemento);
	printf("\n\n");
	printf("El mayor elemento de la segunda columna es: %d", item_b);
	printf("\n\n");

	item_c = itemC(matriz);
	printf("\n\n");
	printf("El promedio de todos los multiplos de 5 en la matriz es: %f", item_c);
	printf("\n\n");

	item_d = itemD(matriz);
	printf("\n\n");
	printf("La sumatoria de la diagonal principal es: %d", item_d);
	printf("\n\n");

	itemE(matriz,&minF1,&minF2,&minF3);
	printf("\n\n");
	printf("EL elemento min de la fila 1 es: %d\n",minF1);
	printf("EL elemento min de la fila 2 es: %d\n",minF2);
	printf("EL elemento min de la fila 3 es: %d\n",minF3);
	printf("\n\n");

	item_f = itemF(matriz);
	printf("\n\n");
	printf("La sumatoria de la diagonal secundaria es: %d", item_f);
	printf("\n\n");


	item_h = itemH(matriz);
	printf("\n\n");
	if(item_h == 1){
		printf("La matriz es simetrica");
	}else if (item_h == 0){
		printf("La matriz no es simetrica");
	}else{
		printf("Error");
	}
	printf("\n\n");


	/*
	itemG();
	itemH();
	*/
	return 0;
}

//deberia ir con el (los) tama�o(s) del arreglo que le pasamos
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

int itemB(int matriz[n][n], int mayorElemento){

	int i;
	mayorElemento=matriz[0][1];
	for(i=0;i<n;i++){
		if(mayorElemento < matriz[i][1]){
			mayorElemento = matriz[i][1];
		}
	}

	return mayorElemento;
}

float itemC(int matriz[n][n]){
	int i,j;
	int cont_prom=0;
	int acum_prom=0;
	float promedio;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(matriz[i][j]%5==0){
				cont_prom=cont_prom+1;
				acum_prom=acum_prom+matriz[i][j];
			}
		}
	}
	promedio = (float) acum_prom/(float)cont_prom;
	
	return promedio;
}

int itemD(int matriz[n][n]){
	int sumaDia=0;
	int i;
	for(i=0;i<n;i++){
		if(matriz[i][i]==matriz[i][i]){
			sumaDia = sumaDia + matriz[i][i];
		}
	}
	return sumaDia;
}

void itemE(int matriz[n][n],int* minF1,int* minF2,int* minF3){

	int minF;
	int i,j;
	for(i=0;i<n;i++){
		minF = matriz[i][0];
		for(j=0;j<n;j++){
			if(matriz[i][j] < minF){
				minF = matriz[i][j];
			}
		}
		if(i==0){
			*minF1 = minF;
		}
		if(i==1){
			*minF2 = minF;
		}
		if(i==2){
			*minF3 = minF;
		}
	}
}

int itemF(int matriz[n][n]){
	int sumaDiaS=0;
	int i=0,j=2;
	while(i < n){
		sumaDiaS = sumaDiaS + matriz[i][j];
		//J decrementa enganchado al incremento de i (estan relacionados)
		j--;
		i++;
	}
	return sumaDiaS;
}

int itemH(int matriz[n][n]){ 
	//Necesita una manera de recorrer la matriz y la regla
	//para actuaizar la i y la j (como se relaciona)
	int booleano=1;
	int i=0,j=0;
	while (booleano == 1 && i < n) {
		while(booleano == 1 && j < n-i){
			/*
			printf("Elemento i,j: %d\t",matriz[i][j]);
			printf("Elemento j,i %d\n",matriz[j][i]);
			*/
			if(matriz[i][j] != matriz[j][i]){
				booleano = 0;
			}
			j++;
		}
		i++;
	}
	return booleano;
}