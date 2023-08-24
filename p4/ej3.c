#include <stdio.h>

int main(){

    char c;  //o int c;
    int longitud_palabra = 0;
    char ultima_letra;
    int contador_palabras_ej3;
    printf("Ingrese una frase que termine con '.'\n");
    c = getchar();

    while(c!='.'){

        while(c==' '){
            c = getchar();
        }
        if (c!='.'){
            longitud_palabra = 1;
        }

        c=getchar();
        while(c!=' ' && c!='.'){
            longitud_palabra = longitud_palabra +1;
            ultima_letra = c;
            c=getchar();
        }

        if ( (2<longitud_palabra) && ultima_letra == 'n'){
            contador_palabras_ej3 = contador_palabras_ej3 +1;
        }
        longitud_palabra = 0;

    }

    printf("La cantidad de palabras con mas de dos"
            " letras que terminan en n es: %d\n", contador_palabras_ej3);
    return 0;
}