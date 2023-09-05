#include <stdio.h>
int duplicarElmentos(int arr[5]);
int imprimirElementos(int arr[5]);

int main()
{
    int arr[5];
    int a;
    a=2;
    int i;
    for(i=0;i<5;i++){
        arr[i]=i*2;
        printf("%d\n", arr[i]);
    }
    printf("\n");
    for(i=0;i<5;i++){
        printf("%d\n", *(arr+i));
    }
   
    printf("\n");
   
    printf("a=%d\n", a);
   
    printf("direccion de a=%p\n", &a);
   
    printf("Antes:\n");
    imprimirElementos(arr);
    printf("\n");
    duplicarElmentos(arr);
    printf("Despues:\n");
    imprimirElementos(arr);
   

    return 0;
}

int duplicarElmentos(int arr[5]){
    int i;
    for(i=0;i<5;i++){
        arr[i]=arr[i]*2;
    }
}

int imprimirElementos(int arr[5]){
    int i;
    for(i=0;i<5;i++){
        printf("%d\n", *(arr+i));
    }
}