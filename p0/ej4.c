#include <stdio.h>

int main(){

    int num;
    int menor;
    int cont_a=0;
    int cont_b=0;
    int acum_b=0;
    float prom;
    int cont_c=0;

    printf("Ingresar numeros y un numero negativo para finalizar: ");
    scanf("%d",&num);

    menor = num;

    while(num>0){

        //PARTE A
        if(num > 4 && num < 25){
            cont_a=cont_a+1;

        }

        //PARTE B
        if(num%6==0){ 
            printf("Entro el numero %d\n",num);
            cont_b=cont_b+1;
            acum_b=acum_b+num;
        }
        
        //PARTE C
        if(num < menor){
            menor = num;
        }

        //PEDIDA DE DATOS
        printf("Ingresar numeros y un numero negativo para finalizar: ");
        scanf("%d",&num);

    }
    //PARTE A
    printf("La cantidad de numeros mayores a 4 y menores a 25 es: %d",cont_a);
    
    //PARTE B
   //converted to float
    cont_b=cont_b*1.0;
    acum_b=acum_b*1.0;
    prom =  acum_b/cont_b;

    printf("\nEl promedio de los numeros  multiplos de 6 es: %f",prom);

    //PARTE C

    printf("\nEl menor numero leido es: %d",menor);


}