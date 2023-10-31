#include <stdio.h>
#include <stdlib.h>

typedef struct nodoLista{
    int dato;
    struct nodoLista * sig;
}nodo;

nodo* crearLista();
nodo* insertar1(nodo*, nodo*);
void insertar2(nodo* ,nodo *);

void mostrarLista(nodo* l);

nodo* crearNodo();
nodo* eliminar1(nodo*);

int main(void){
    nodo* l1 = NULL;
    nodo* l2 = NULL;
    int datos = 1;
    l1 = crearLista();
    
    l2 = (nodo*)malloc(sizeof(nodo));
    
    //inserta ppio
    
    printf("Hay datos? Si == 1: ");
    scanf("%d", &datos);
    
    while (datos == 1){

        l1 = insertar1(l1, crearNodo());
        printf("Hay mas datos? Si == 1: ");
        scanf("%d", &datos);
        
    }
    mostrarLista(l1);
    /*
    insertar2(l1,crearNodo());
    mostrarLista(l1);
    */
    l1 = eliminar1(l1);
    mostrarLista(l1);
    
    return 0;
}





nodo* crearLista(){
    
    nodo* l;
    l = (nodo*)malloc(sizeof(nodo));
    l->sig = NULL;
    return l;
}

nodo* crearNodo(){
    nodo* nuevoNodo;
    int dato;
    printf("\ningrese el dato del nodo: ");
    scanf("%d", &dato);
    nuevoNodo = (nodo*)malloc(sizeof(nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->sig = NULL;
    return nuevoNodo;
}


nodo* insertar1(nodo* l, nodo* nuevoNodo){
    nuevoNodo->sig = l;
    return nuevoNodo;
}


void mostrarLista(nodo* l){
    while (l->sig != NULL){
        
        printf("%d", l->dato);
        l = l->sig;
    }
    return;
}

void insertar2(nodo* l, nodo* nuevoNodo){
    nodo* aux;
    int pos=1;
    while(l->sig != NULL){
        if(pos == 2){
            aux = l->sig;
            l->sig=nuevoNodo;
            nuevoNodo->sig=aux;
        }
        pos++;
        l=l->sig;
    }
}

nodo* eliminar1(nodo *l){
    
    nodo *aux;
    l=aux;
    l=l->sig;
    free(aux);
    
    return l;
}




