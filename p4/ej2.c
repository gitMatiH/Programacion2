//#include <stdlib.h> /*la nueva libreria*/
#include <stdio.h>

int main(){

    char c;  //o int c;
    int longitud_palabra = 0;
    char aux;
    printf("Ingrese una frase que termine con '.'\n");
    c = getchar();
    
    printf("\nLa frase con un solo espacio y sin palabras de una letra:\n");

    c = getchar();
    if (c==' '){
        putchar(c);
    }

    while(c!='.'){

        while(c==' '){
            c=getchar();
        }
        longitud_palabra = 1;
        
        aux=c;
        c=getchar();
        while(c!=' ' && c!='.'){
            longitud_palabra = longitud_palabra + 1;

            if(longitud_palabra == 2){
                putchar(aux);
            }
            putchar(c);
            c=getchar();
        }
        if (1<longitud_palabra){
            putchar(c);
        }

    }
    return 0;
}