
#include <stdio.h>
#include <stdlib.h>

int main(){
    int mes,dias;
    int i;
    int diaMax;
    float max=0;
    float cotiz;
    int primeraVuelta;
    int ene=31,
        feb=28,
        mar=31,
        abr=30,
        may=31,
        jun=30,
        jul=31,
        ago=31,
        sep=30,
        oct=31,
        nov=30,
        dic=31;

    printf("Ingrese el mes para el cual quiere hacer calculos: %s",&mes);

    if( mes == "ene"||
        mes == "feb"||
        mes == "mar"||
        mes == "abr"||
        mes == "may"||
        mes == "jun"||
        mes == "jul"||
        mes == "ago"||
        mes == "sep"||
        mes == "oct"||
        mes == "nov"||
        mes == "dic"){
        

        dias = mes;
        for(i=0; i<dias; i++){
             printf("Ingrese la cotizacion del dolar del dia: %d",cotiz);
             if(primeraVuelta==1){

                max = cotiz;
                primeraVuelta = 0;
                diaMax=1;
             }
             if(cotiz > max){
                max = cotiz;
                diaMax= i+1;
             }

        }
        printf("El dia de mayor cotizacion fue el: %d\nLa cotizacion de ese dia fue: %f",diaMax,max);

    }
    return 0;
   }
