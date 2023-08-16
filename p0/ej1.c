#include <stdio.h>

int main(){
    float peso,estatura;
    float cuadradoEstatura;
    float bmi;

    printf("Ingrese el peso: ");
    scanf("%f",&peso);

    printf("Ingrese su estatura: ");
    scanf("%f",&estatura);

    if(estatura == 0){
        printf("Error division por 0");
        return 0;
    }

    cuadradoEstatura = estatura * estatura;

    bmi = peso/cuadradoEstatura;

    printf("El indice de masa corporal es: %f",bmi);

    return 0;
   }