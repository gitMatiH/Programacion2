/*
Una encuestadora necesita ingresar los datos de sus encuestados mediante un programa.
Por lo tanto se pide que el programa deje ingresar:
    El número de documento de la persona
    La edad de la persona
    El salario de la persona

La carga termina con número de documento sea igual a 0.

Finalmente el programa debe mostrar por pantalla:

a) El número de documento de la persona con menor salario
b) El promedio de edad de aquellas personas cuyo salario es superior a $35000
c) El porcentaje de personas que ganan menos de $30000.

Utilizar funciones para la carga de datos y hacer con funciones el promedio y 
porcentaje luego de haber terminado con el pedido de datos.
*/

#include <stdio.h>
#define SALARIO_MIN 20000

//prototipos
float calcular_promedio(int, int);
float calcular_porcentaje(int, int);

int main(){
    //estructura persona
    int documento, edad;
    float salario;
    //variables para calculos
    int i;
    int primera_entrada = 1;

    int documento_salario_min;

    int sumatoria_edad_b;
    int contador_edad_b;
    float promedio_b;

    int contador_personas_c;
    int contador_personas_total;
    float porcentaje_c;

    //inicializacion variables
    sumatoria_edad_b = 0;
    contador_edad_b = 0;
    contador_personas_c = 0;
    contador_personas_total = 0;

    //carga datos
    printf("Ingrese el documento de la persona a cargar datos, 0 para finalizar la carga.\n");
    scanf("%d", &documento);

    while (documento != 0){
        
        //pide resto datos
        
        printf("Ingrese la edad de la persona: ");
        scanf("%d", &edad);
        while (edad < 18){
            printf("Edad invalida.");
            printf("Ingrese la edad de la persona: ");
            scanf("%d", &edad);
        }

        printf("Ingrese el salario de la persona: ");
        scanf("%f", &salario);
        while (salario < SALARIO_MIN){
            printf("Salario invalido.");
            printf("Ingrese el salario de la persona: ");
            scanf("%f", &salario);
        }

        //procesa
        
        //a
        if (primera_entrada == 1){
            documento_salario_min = documento;
            primera_entrada = 0;
        }
        if (documento_salario_min < documento){
            documento_salario_min = documento;
        }

        //b
        if (35000 < salario){
            sumatoria_edad_b = sumatoria_edad_b + edad;
            contador_edad_b = contador_edad_b +1;
        }


        //c
        if (salario < 30000){
            contador_personas_c = contador_personas_c+1;
        }

        //general
        contador_personas_total = contador_personas_total +1;

        //vuelve a preguntar para condicion de carga
        printf("Ingrese el documento de la persona a cargar datos, 0 para finalizar la carga.\n");
        scanf("%d", &documento);
    }

    //item_a
    printf("El documento de la persona con el menor salario es: %d\n", documento_salario_min);


    //item_b
    if (contador_edad_b!=0){
        promedio_b = calcular_promedio(sumatoria_edad_b, contador_edad_b);
        printf("El promedio de edad de personas cuyo sueldo es mayor a 35000 es de: %f\n", promedio_b);
    } else {
        printf("No hubo personas con sueldo mayor a 35000.\n");
    }
    
    //item_c
    if (contador_personas_total!=0){
        porcentaje_c = calcular_porcentaje(contador_personas_c, contador_personas_total);
        printf("El porcentaje de personas cuyo sueldo es menor a 30000 es: %f\n", porcentaje_c);
    } else {
        printf("No se contaron personas para el punto c.\n");
    }

}

float calcular_promedio(int sumatoria, int elementos){
    float promedio;
    //automatic typecast?
    //float(sumatoria);
    //float(elementos);
    promedio = (float) sumatoria/elementos;
    return promedio;
}

float calcular_porcentaje(int cantidad, int total_cantidad){
    float porcentaje;
    //float cantidad;
    //float total_cantidad;
    porcentaje =  (float)cantidad*100/total_cantidad;
    return porcentaje;
}