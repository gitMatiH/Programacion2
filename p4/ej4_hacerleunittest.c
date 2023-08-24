#include <stdio.h>

int main(){

    char actual, anterior;  //o int c;

    printf("Ingrese una frase que termine con '.'\n");
    actual = getchar();

    while(actual!='.'){

        while(actual==' '){
            putchar(actual);
            anterior = actual;
            actual = getchar();
        }

        //putchar(c);
        anterior = actual;
        actual=getchar();
        while(actual!=' ' && actual!='.')
        {
            if (anterior == 'v' && actual == 'l'){
                anterior = 'b';
                putchar(anterior);
                //putchar(actual);
            }else{
                putchar(anterior);
                //putchar(actual);
            }
            anterior = actual;
            actual=getchar();
        }

        putchar(actual);

    }
    return 0;
}