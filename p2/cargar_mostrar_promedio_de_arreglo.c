#include <stdio.h>

void cargar(int a[],int d){
    int i;
    for(i=0;i<d;i++){
        printf("Ingrese el valor");
        scanf("%d",&a[i]);
    }
    return;
}    
 void mostrar(int a[],int d){
    int i;
    for(i=0;i<d;i++){
        printf("el valor es %d\n",a[i]);
    }
    return;   
}

int promedio(int vec[], int dim){
    int i=0, acum=0; 
    for(i=0;i<dim;i++){
        acum+=vec[i];
        
    }
    
    return acum/dim;
}


int main() {
    int vec[100],dim,p;
    printf("ingrese la cantidad de elementos");
    scanf("%d",&dim);
    cargar(vec,dim);
    mostrar(vec,dim);
    p=promedio(vec,dim);
    printf("el promedio es %d\n",p);
    return 0;
}#include <stdio.h>

void cargar(int a[],int d){
    int i;
    for(i=0;i<d;i++){
        printf("Ingrese el valor");
        scanf("%d",&a[i]);
    }
    return;
}    
 void mostrar(int a[],int d){
    int i;
    for(i=0;i<d;i++){
        printf("el valor es %d\n",a[i]);
    }
    return;   
}

int promedio(int vec[], int dim){
    int i=0, acum=0; 
    for(i=0;i<dim;i++){
        acum+=vec[i];
        
    }
    
    return acum/dim;
}


int main() {
    int vec[100],dim,p;
    printf("ingrese la cantidad de elementos");
    scanf("%d",&dim);
    cargar(vec,dim);
    mostrar(vec,dim);
    p=promedio(vec,dim);
    printf("el promedio es %d\n",p);
    return 0;
}