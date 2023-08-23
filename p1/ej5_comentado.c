#include <stdio.h>

int main() {
    int edad;
    float sueldo;
    int total = 0;
    int cont = 0, sum = 0; // a)
    float prom = 0.0;
    int cont_e = 0; //b)
    float plus = 0.0;
    int sueldo_uno = 0, sueldo_dos = 0, sueldo_tres = 0; // c)
    float porMenor = 0.0, porEntre = 0.0, porMayor = 0.0;

    printf("Ingrese los siguientes datos (Ingrese ceros para salir):\n");

    while (1) {     //estas forzando un loop infinito!!
        printf("Ingrese su edad: ");
        scanf("%d", &edad);

        if (edad == 0) {    // habrás querido decir != 0 ? para validar?

            printf("Ingrese su sueldo: ");
            scanf("%f", &sueldo);

            if(sueldo == 0){
            break;  //pero así sale del while, y no sigue preguntando por datos validos
            }
        }

        printf("Ingrese su sueldo: ");
        scanf("%f", &sueldo);

        total++;    // no se entiende a qué cosa le acumula el total

        // A) PROMEDIO
        if (sueldo > 100000) {
            cont++;     // qué cuenta? algo relacionado a a?
            sum = sum + edad;
        }

        // B) SUELDO MAYORES DE 58 ANIOS
        if (edad > 58) {
            cont_e++;   // por qué contador_e? no estamos en el punto b?
            plus = sueldo + (sueldo * 0.05);
        }

        // C) PORCENTAJE DE EMPLEADOS
        if (sueldo < 15000) {   //me gustó como los nombraste acá
            sueldo_uno++;
        } else if (sueldo >= 15000 && sueldo <= 20000) {
            sueldo_dos++;
        } else if (sueldo > 20000) {
            sueldo_tres++;
        }
    }

    // te animás a modularizarlo con funciones?

    // A) Calcular el promedio solo si hay empleados con sueldo mayor a 100000
    if (cont > 0) {
        prom = (float)sum / cont;
        printf("El promedio de edades de empleados con sueldo mayor a 100000 es: %.2f\n", prom);
    }else{
        printf("No se registraron empleados que cumplan la consigna a)\n");
    }

    // B) Imprimir sueldo con el plus si hay empleados mayores de 58 anios
    if (cont_e > 0) {
        printf("El sueldo con el plus cobrado es: %.2f\n", plus);
    }else{
        printf("No se registraron empleados que cumplan la consigna b)\n");
    }

    // C) Calcular y mostrar los porcentajes
    porMenor = ((float)sueldo_uno / total) * 100;
    porEntre = ((float)sueldo_dos / total) * 100;
    porMayor = ((float)sueldo_tres / total) * 100;

    printf("El porcentaje de empleados con sueldo menor a 15000 es: %.2f%%\n", porMenor);
    printf("El porcentaje de empleados con sueldo entre 15000 y 20000 es: %.2f%%\n", porEntre);
    printf("El porcentaje de empleados con sueldo mayor a 20000 es: %.2f%%\n", porMayor);

    return 0;
}


