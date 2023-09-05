//Escribir un programa efectúe las siguientes operaciones:
//a) Declarar una matriz de 3x4 de tipo int. Cargar sus elementos y mostrarla
#include <stdio.h>

int cargarMatriz(int matriz[3][4]);
int mostrarMatriz(int matriz[3][4]);
int recorrerMatriz(int *punt);


int main()
{
    
    int *puntero;
    int matriz[3][4];
    //puntero = &matriz[0][0];
    puntero = &matriz;
    
    
    cargarMatriz(matriz);
    mostrarMatriz(matriz);
    
    recorrerMatriz(puntero);
    
    return 0;
}


int cargarMatriz(int matriz[3][4]){
    int i, j, a;
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            printf("ingrese el elemento [%d][%d]: ",i,j);
            scanf("%d", &a);
            matriz[i][j]=a;
        }
    }
}

int mostrarMatriz(int matriz[3][4]){
    int i, j;
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            printf("elemento[%d][%d] = %d\n", i, j, matriz[i][j]);
        }
    }
}

int recorrerMatriz(int *punt){
    int i;
    for(i=0;i<(3*4);i++){
        printf("elem %d = %d\n", i, *(punt+i) );
    }
}