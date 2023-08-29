#include <stdio.h>

//invertirCadena(subcadena);
/*
int invertirEntero(int entero){
    //caso base
    if (entero/10 == 0){
        return printf("%d", entero);
    }else{
        return printf("%d", invertirEntero(entero%10));
    }
}
*/
/*
int inv(int num, int *base){
    //caso base
    int exp;
    exp = (*base) * (*base);
    if (num<10){
        return num*(exp);
    }
    printf("%d\n", *base);
    //printf("%d\n", (num%10)+inv(num/10, base)*(*base));
    //return (num%10)+inv(num/10, base)*(*base); // caso gral
    return (num%10)+inv(num/10, exp)*(*base);

}
*/
// falta pasarle la cantidad de digitos  del numero recursivamente
// contar digitos lo podemos hacer recursivo y usar en el ultimo return
// y tambien dividir sucesivamente la potencia de diez para usar la adecuada
/*
if not = 0 la division 
*/


int inv(int num, int *base){
    //caso base
    int exp;
    exp = (*base) * (*base);
    if (num<10){
        return num*(exp);
    }
    printf("%d\n", *base);
    //printf("%d\n", (num%10)+inv(num/10, base)*(*base));
    //return (num%10)+inv(num/10, base)*(*base); // caso gral
    return (num%10)+inv(num/10, exp)*(*base);
}

int main(){
    int entero = 123456;
    int i;
    /*
    int div;
    div = 15%10;
    printf("%d\n",div);
    div = 15/10;
    printf("%d\n",div);
    return 0;
    */
   //invertirEntero(entero);
   /*
   entero = invertirEntero(entero);
   printf("%d\n", entero);
    */
   int b = 1;
   i = inv(entero, &b);
   printf("%d", i);
}