#include <stdio.h>
#include <stdlib.h>
int cargar(int vec[]);
void ordenar(int vec[], int pos);
void promedio(int vec[], int pos);

void mostrar(int vec[], int pos);



int main(){

    int vec[100], pos=0; 

    pos= cargar(vec);
    if(pos == 0){

        printf("No hay numeros impares\n");
    }else{
        mostrar(vec,pos);
        promedio(vec, pos);
        ordenar(vec,pos);
        mostrar(vec,pos);
    }


    return 0;
}

void ordenar(int vec[], int pos){

    int i, j, aux=0; 
    for(i=0;i<pos;i++){

        for(j=i+1;j<pos;j++){

            if(vec[i]<vec[j]){
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux; 
            }
        }


    }


}
void promedio(int vec[], int pos){
    
    int i,acum=0, cont=0;
    for(i=0;i<pos;i+=2){
        if(vec[i]%7==0){
            acum+=vec[i];
            cont++;
        }

    }
    if(cont!=0){
        printf("El promedio es %d\n", acum/cont);

    }else{
        printf("Error\n"); 
    }

}

void mostrar(int vec[], int pos){
    int i; 
    for(i=0;i<pos;i++){
        printf("[%d]", vec[i]); 
    }
}

int cargar(int vec[]){

    int num=0, i=0; 
    printf("Ingrese un numero entero\n");
    scanf("%d", &num);
    while(num!=0){

        if(num%2!=0){

            vec[i]=num; 
            i++; 

        }

        printf("Ingrese un numero entero\n");
        scanf("%d", &num);


    }
    return i; 
}