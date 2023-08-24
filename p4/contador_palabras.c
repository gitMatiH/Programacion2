//#include <stdlib.h> /*la nueva libreria*/
#include <stdio.h>
//#include <string.h>

int main(){

    char c,primera, ultima;  //o int c;
    int cont=0;
    printf("Ingrese una frase que termine con '.'\n");
    c = getchar();
    // buenas tardes  .  palabras=2 espacios=4
    while(c!='.'){ //no es mejor con los 2 while?

        while(c==' '){
            c=getchar();
        }

        while(c!=' ' && c!='.'){//hola
            c=getchar();
            if(c==' ' || c=='.'){
                cont++;
            }

        }
        putchar(c);

    }
    printf("\nEl cont= %d \n %c", cont,c);



    return 0;
}

