#include <stdio.h>
//un acumulador es una funcion recursiva de si mismo

int sumatoria(int num)
{
  //caso base
  if (num == 1)
  {
    return 1;
  }
  return num+sumatoria(num-1); //caso recursivo/general
}

int main() {
  int num=5;
  printf("Ingrese un numero: ");
  scanf("%d",&num);
  num = sumatoria(num);
  printf("Su sumatoria es: %d\n", num);
  //printf("%d\n", sumatoria(num));   // se almacena en el return el llamado rec de la func
  return 0;
}