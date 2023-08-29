/***
 * 
 * Ingresar un número y calcular a partir de ese cuántos
 * números pares hay e imprimirlos en pantalla. Por ejemplo,
 * si se ingresa un 8, contar desde 8 hasta 0.
 * Resolverlo recursivamente
 * 
 * Imprime: 6, 4, 2. En total hay 3 números pares
 * 
***/

#include <stdio.h>

int funcionRecursiva(int num, int* pares, int *cont){
    // precond: primer pasaje es el numero y contador en cero

    if (num%2 == 0){
        *cont = *cont +1;
        pares[*cont] = num;        
    }
    return funcionRecursiva(num-1, pares, cont);
}

int main () {

    int num;
    int cont=0;
    int i = 0;
    int pares[num/2+1];
    printf("Ingrese un numero: ");
    scanf("%d", &num);
    funcionRecursiva(num, pares, &cont);
    while (i < cont){
        printf("%d", pares[i]);
    }


    return 0;
}