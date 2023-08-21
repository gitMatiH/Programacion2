#include <stdio.h>

int main(){
    int anio,autos;
    int primerAnio = 1;
    int maxAutos;
    int anioMax;
    int contAutos = 0;

    for(anio=1;anio<10;anio=anio+1){
        printf("Ingrese la cantidad de autos vendidos en el anio %d: ",anio);
        scanf("%d",&autos);

        if(primerAnio == 1){ // sin esto nos ahorramos el swicht 
        
            anioMax = primerAnio;
            maxAutos = autos;

            primerAnio = 0;
        }
 
        if(maxAutos < autos){ //autos es el valor actual, y max es el historico
            maxAutos = autos;
            anioMax = anio;

        }
        contAutos = contAutos+autos;

    }

    printf("El anio donde se vendio la mayor cantidad de autos fue el anio:  %d\nY la cantidad de autos vendidos fue: %d",anioMax,maxAutos);

    printf("\nLa cantidad total de autos vendidos en todos los anios fue de: %d", contAutos);
   }