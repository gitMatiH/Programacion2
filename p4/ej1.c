
#include <stdio.h>

int main(){

    char c;  //o int c;
    int cont_palabras=0;
    int cont_letras=0;
    printf("Ingrese una frase que termine con '.'\n");
    c = getchar();
    while(c!='.'){

        //procesa blancos
        while(c==' '){
            c=getchar();
        }

        //procesa palabras (dinamicamente)
        while(c!=' ' && c!='.'){
            cont_letras = cont_letras +1;
            c=getchar();

            //si fue mas larga que tres caracteres, agrega al contador
            if( (c==' ' || c=='.') && 3 < cont_letras){
                cont_palabras++;
                //printf("conte.");
            }
        }
        cont_letras = 0;
    }
    printf("\nLa cantidad de palabras con mas de tres letras = %d \n %c", cont_palabras,c);
    return 0;
}

