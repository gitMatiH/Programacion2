/*
Leer un texto carácter terminado en PUNTO. Contar cuantas palabras
empiezan y terminan con la misma letra.
*/

#include <stdio.h>
 int main(){
     int c,cont=0,aux,primera;
     printf("ingrese la frase \n");
     c=getchar();
     while(c!='.'){
         primera=c;
         while(c!=' ' && c!='.'){
             aux=c;
             c=getchar();
         }
         if (aux==primera)
             cont++;
         aux=' '; 
         primera=' ';
         if (c!='.')
             c=getchar();
         while(c==' ')
             c=getchar();
         
     }
     printf("\nla cantidad de palabras que empiezan y "
            "terminan con la misma letra es %d\n",cont);
 }