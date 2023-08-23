#include <stdio.h>
#include <stdlib.h>

int main(){
    int vec[10];
    int i,num;
    int pos=0;

    while(pos<5){
        printf("Ingrese num\n");
        scanf("%d", &num);
        if(num%2==0){
            vec[pos] = num;
            pos++;
        }
    }
    for(i=0;i<5;i++){
        printf("En la pos %d = [%d]\n",i+1,vec[i]);
    }
  /*  for(i=0;i<10;i++){
        printf("Ingrese num\n");
        scanf("%d", &num);

        if(num%2==0){//usar validacion con while en vez de if
            vec[i] = num;
        }

    }*/


    return 0;
}
