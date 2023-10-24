#include <stdio.h>
#include <stdlib.h>


//declaraciones

typedef struct lista {
    int Num;
    struct lista * sig;
}nodo;

void crearListaR(nodo*);
void crearListaI(nodo*);
void mostrarListaR(nodo* l, int i);
void mostrarListaI(nodo*);
nodo* crearNodo(int num);

void generarListaR(nodo* lmult3, nodo* l1);
void generarListaI(nodo* lmult3, nodo* l1);

int main (void)
{
    int i;
    nodo* l1 = NULL;
    nodo* lmult3 = NULL;

    l1 = (nodo*)malloc(sizeof(nodo));
    l1->sig = NULL;
    
    lmult3 = (nodo*)malloc(sizeof(nodo));
    lmult3->sig = NULL;

    int opcion;


    printf("\nMenu:\n");
    printf("1.Crear y mostrar Lista. (R)\n");
    printf("2.Crear y mostrar Lista. (I)\n");
    printf("3.Generar otra lista con multiplos de 3. (R)\n");
    printf("4.Generar otra lista con multiplos de 3. (I)\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    
    while(opcion != 0) {
        
        switch (opcion)
        {
        case 1:
            printf("\nProcedemos a crear lista\n");
            printf("\n***********************************\n");
            crearListaR(l1);
            printf("\n***********************************\n");
            i = 0;
            printf("\nProcedemos a mostrar lista\n");
            printf("\n***********************************\n");
            mostrarListaR(l1, i+1);
            printf("\n***********************************\n");
            break;

        case 2:
            printf("\nProcedemos a crear lista\n");
            printf("\n***********************************\n");
            crearListaI(l1);
            printf("\nProcedemos a mostrar lista\n");
            printf("\n***********************************\n");
            mostrarListaI(l1);
            printf("\n***********************************\n");
            break;
        
        case 3:
            printf("Procedemos a generar la lista de multiplos de 3.");
            printf("\n***********************************\n");
            generarListaR(lmult3, l1);
            printf("\n***********************************\n");
            printf("\nProcedemos a mostrar lista\n");
            printf("\n***********************************\n");
            i = 0;
            mostrarListaR(lmult3, i+1);
            printf("\n***********************************\n");
            break;

        case 4:
            printf("Procedemos a generar la lista de multiplos de 3.");
            printf("\n***********************************\n");
            generarListaI(lmult3, l1);
            printf("\n***********************************\n");
            printf("\nProcedemos a mostrar lista\n");
            printf("\n***********************************\n");
            mostrarListaI(lmult3);
            printf("\n***********************************\n");
            break;

        default:
            printf("\ncodigo invalido\n");
            break;
        }

        printf("\nMenu:\n");
        printf("1.Crear y mostrar Lista. (R)\n");
        printf("2.Crear y mostrar Lista. (I)\n");
        printf("3.Generar otra lista con multiplos de 3. (R)\n");
        printf("4.Generar otra lista con multiplos de 3. (I)\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);
    }
    return 0;
}


//definiciones

void crearListaR(nodo* l){
    nodo* nuevoNodo;

    printf("\nIngrese un numero para el nuevo nodo, 1000 para terminar: ");
    scanf("%d", &l->Num);

    if(l->Num != 1000){
        l->sig = crearNodo(l->Num);
        crearListaR(l->sig);
    }else{
        l->sig = NULL;
    }

    return;
}

void crearListaI(nodo* l){

    nodo* nodoNuevo;

    printf("\nIngrese un numero para el nuevo nodo, 1000 para terminar: ");
    scanf("%d", &l->Num);
    while(l->Num != 1000){
        nodoNuevo = (nodo*)malloc(sizeof(nodo));
        l->sig = nodoNuevo;
        l = l->sig;
        printf("\nIngrese un numero para el nuevo nodo, 1000 para terminar: ");
        scanf("%d", &l->Num);
    }
    l->sig = NULL;

    return;
}

void mostrarListaR(nodo* l, int i){

    if (l->sig != NULL){
        printf("\npos: %d", i);
        printf("\nelem: %d\n", l->Num);
        mostrarListaR(l->sig, i+1);
    }
    return;
}

void mostrarListaI(nodo* l){
    int pos = 1;
    while (l->sig != NULL){
        printf("\npos: %d\n", pos);
        printf("elem: %d\n", l->Num);
        pos++;
        l = l->sig;
    }

    return;
}

nodo* crearNodo(int num){
    nodo* nuevoNodo;
    nuevoNodo = (nodo*)malloc(sizeof(nodo));
    nuevoNodo->Num = num;
    nuevoNodo->sig = NULL;
    return nuevoNodo;
}

void generarListaR(nodo* lmult3, nodo* l1){


}


void generarListaI(nodo* lmult3, nodo* l1){

    nodo* nodoNuevo;
    lmult3->Num = l1->Num;
    while(l1->sig != NULL){
        if (l1->Num % 3 == 0){
            nodoNuevo = (nodo*)malloc(sizeof(nodo));
            lmult3->sig = nodoNuevo;
        }
        lmult3 = lmult3->sig;
        l1 = l1->sig;
        lmult3->Num = l1->Num;
    }
    lmult3->sig = NULL;

}
