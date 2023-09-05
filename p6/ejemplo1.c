#include <stdio.h>


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
   
    printf("direccion de a=%x\n", &a);

    return 0;
}