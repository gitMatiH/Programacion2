#include <stdio.h>
#include <stdlib.h>

void swap(int* i, int* j) {
    int aux;
    aux = *i;
    *i = *j;
    *j = aux;
    return;
}

void mostrar(int array[10], int i) {

    if (i < 10) {
        printf("%d, ", array[i]);
        mostrar(array, ++i);
    }

    return;
}


int main(void) {

    int i;
    int j;
    int n = 10;
    int array[10] = { 5,6,0,2,3,1,4,7,9,8 };

    printf("\narray desordenado:\n");
    mostrar(array, 0);

    i = 0;
    while (i < n) {
        j = 0;
        while (j < n) {
            //if (array[i] > array[j]) {    //asi ordena desc
            if (array[i] < array[j]) {      //asi ordena asc
                swap(&array[i], &array[j]);
            }

            j++;
        }
        i++;
    }
    printf("\narray ordenado:\n");
    mostrar(array, 0);
}

/*


void ordenar(nodo* actual)
{
     nodo *siguiente;
     nodo *aux=(nodo*)malloc(sizeof(nodo));

     while(actual->sig != NULL)
     {
          siguiente = actual->sig;

          while(siguiente->sig !=NULL)
          {
               if(actual->num > siguiente->num)
               {
                    //swap
                    aux->num        =   siguiente->num;
                    siguiente->num  =   actual->num;
                    actual->num     =   aux->num;
               }
               siguiente = siguiente->sig;
          }
          actual = actual->sig;

     }
};


*/