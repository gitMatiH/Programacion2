/*Leer un texto carácter a carácter, 
terminado en PUNTO. Mostrar cuántas palabras
tienen más de 3 letras.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    //char c; // o int c;
    int c;
    int cont = 0;
    int conta = 0 ;
    printf("Ingrese una frase \n");
    //c = getchar();
    //putchar(c);
    int charAnterior=' ';
    int charActual;
    
    charActual = getchar();
    /*
    charAnterior = charActual;
    */
    int palabras = 0;

    while (charActual != '.'){
        if (charActual == ' ' && charAnterior == ' '){
            
        }
        if (charAnterior == ' ' && charActual != ' '){
            palabras = palabras +1;
        }
        if (charAnterior != ' ' && charActual == ' '){

        }
        charAnterior = charActual;
        charActual = getchar();
    }

    printf("palabras: %d", palabras);

    /*
    while (c != '.'){ // puedo hacer comparacion directa porque trata al caracter como enteros

        while (c == ' '){
            getchar();
        }


        if (64<c<123){
            conta=conta+1;
            getchar();
        }

        cont++;
        c= getchar();

    }
    printf("El cont= %d", cont);
*/

    /*
    while (c != '.'){ // puedo hacer comparacion directa porque trata al caracter como enteros

        c = getchar();  //sin getchar entra en loop infinito

    }
    putchar(c); // guarda el ultimo
    */

    /*
    //oracion =
    while (c != '.'){ // puedo hacer comparacion directa porque trata al caracter como enteros

        putchar(c);
        printf("\n");
        c = getchar();  //sin getchar entra en loop infinito

    }
    */

    /*
    //char *cadena = "hola esto es una prueba.";
    //printf("%s", cadena);

    char arreglo[10];
    char cadena[10];
    scanf("%s", arreglo);
    //scanf("%c", &arreglo[i]);
    scanf("%s", cadena);
    printf("%s\n", arreglo);
    printf("%s\n", cadena);
    if (strcmp(arreglo, cadena) == 0){
        printf("Las dos cadenas son iguales\n");
    }
    strcpy(arreglo, cadena);
    printf("%s\n", arreglo);
    printf("%s\n", cadena);
    */
    
    return 0;
}