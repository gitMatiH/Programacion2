

#include <stdio.h>
#include <stdlib.h>


typedef struct lista {
	int Num;
	struct lista* sig;
} nodo;

void crearListaR(nodo*);
void mostrarListaR(nodo*);
void generarListaR(nodo* l, nodo* l2);



int main() {
	nodo* l;	//ojo nodo no inicializado
	nodo* l2;
	l = (nodo*)malloc(sizeof(nodo));
	l2 = (nodo*)malloc(sizeof(nodo));
	l2->sig = NULL;

	crearListaR(l);
	printf("\nlista:\n");
	mostrarListaR(l);

	generarListaR(l, l2);
	printf("\nlista impares:\n");
	//printf("\nl2 %p\n", l2);
	mostrarListaR(l2);


}


void crearListaR(nodo* l) {

	printf("\nIngrese un numero: ");
	scanf("%d", &l->Num);

	if (l->Num == -2) {	//caso base
		l->sig = NULL;
	}
	else {
		l->sig = (nodo*)malloc(sizeof(nodo));
		crearListaR(l->sig);
	}
	return;
}


void mostrarListaR(nodo* l) {
	
	if (l->sig != NULL) {	//usa una cajita para null
		printf("%d\n", l->Num);
		mostrarListaR(l->sig);
	}
	return;
}


void generarListaR(nodo* l, nodo* l2) {

	l2->Num = l->Num;
	l2->sig = NULL;

	if (l->sig != NULL) {

		//printf("\n%d\n", l->Num);

		if (l->Num % 2 != 0) {
			//printf("\nentre en cond a\n");
			nodo* nodoNuevo = (nodo*)malloc(sizeof(nodo));
			l2->sig = nodoNuevo;
			//printf("\nl2 %p\n", l2);
			generarListaR(l->sig, l2->sig);

		} else {
			//printf("\nentre en cond b\n");
			generarListaR(l->sig, l2);
		}
	}
	return;
}
