#include <stdio.h>
#include <stdlib.h>
/*def function(parametros):*/
/*PROTOTIPOS*/
int suma(int ,int );
int resta(int, int);

int multiplicacion(int numero1, int numero2){
    return numero1*numero2;
}

int main(){

    int numero1=5, numero2=2;
    int resul;
    resul = suma(numero1,numero2);
    printf("%d", resul);
    return 0;
}

/*funciones*/
int suma(int num1,int num2){/*variables locales*/

    return num1+num2;
}
int resta(int numero1,int numero2){
    return numero1-numero2;
}
