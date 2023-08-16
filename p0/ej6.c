#include <stdio.h>
#include <stdlib.h>

int main(){
    int num,numAnidado;
    int max;
    int i,j;
    int acum;
    float prom, salida;
    int contPares;

    printf("Ingrese un numero, ingrese un negativo para finalizar los datos: ");
    scanf("%d",&num);

    while(num>=0){ 
    
        
        //asignamos num a max
        max = num;
        j=0;
        acum=0;
        contPares=0;
        while(j < max){

            printf("Ingrese un numero: ");
            scanf("%d",&numAnidado);
            while(numAnidado < 0){
                printf("Error, ingrese un numero positivo");
                scanf("%d",&numAnidado);
            
            }

            if(numAnidado%2==0){
                contPares=contPares+1;
            }
            
            j=j+1;
            acum=acum+numAnidado;

            
        }
        
        if(num%2==0){
            contPares=contPares+1;
            }

        j=j*1.0;
        acum=acum*1.0;

        printf("El acumulador es: %d",acum);
        printf("La j es: %d",j);
        salida = acum / j;
        printf("\nEl promedio del lote es: %d", salida);

        printf("\nIngrese un numero, ingrese un negativo para finalizar los datos: ");
        scanf("%d",&num);
        

    

    }
    printf("La cantidad de numeros pares leidos es: %d", contPares);
 

}