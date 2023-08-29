#include <stdio.h>


int fac(int num)
{
  //caso base
  if (num == 1)
  {
    return 1;
  }
  return num*fac(num-1); //caso recursivo/general
}

int main() {
  int num=5;
  printf("Ingrese un numero: ");
  scanf("%d",&num);
  num = fac(num);
  printf("Su factorial es: %d\n", num);
  //printf("%d\n", fac(num));   // se almacena en el return el llamado rec de la func
  return 0;
}