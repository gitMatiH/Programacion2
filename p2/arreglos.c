#include <stdio.h>
#include <stdlib.h>

int cargar(int arreglo[]);
int mostrar(int arreglo[]);

int main(){

    int arr[5];
    cargar(arr);
    mostrar(arr);

    return 0;
}
int cargar(int arreglo[]){
    int num;
    for(i=0;i<5;i++){
        printf("Ingrese num\n");
        scanf("%d", &num);
        arreglo[i] = num;
    }
}
int mostrar(int arreglo[]){
    int i;
    for(i=0;i<5;i++){
        printf("En la pos %d = [%d]\n",i+1,arreglo[i]);
    }
}
