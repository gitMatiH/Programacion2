

#include <stdio.h>
#include <stdlib.h>


typedef struct lista {
	int Num;
	struct lista* sig;
} nodo;

void crearListaR(nodo*);
void mostrarListaR(nodo*);
void generarListaR(nodo* l, nodo* l2);
int promedioLista(nodo*);

nodo* eliminarDeLista1(nodo* l, int promedio);
void eliminarDeLista2(nodo*, int);



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

	float promedio = promedioLista(l);
	printf("\npromedio lista: %.2f\n", promedio);
	l2 = eliminarDeLista1(l2, promedio);
	mostrarListaR(l2);
	eliminarDeLista2(l2, promedio);
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
	//else {
	//	printf("%d\n", l->Num);
	//	printf("%d\n", l->sig);
	//}

	return;
}


void generarListaR(nodo* l, nodo* l2) {

	l2->Num = l->Num;	// si estaba vacia va a ser -2
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


int promedioLista(nodo* l) {

	int cont = 0;
	int acum = 0;


	while (l->sig != NULL) {
		cont = cont + 1;
		acum = acum + l->Num;

		l = l->sig;
	}

	
	return (acum / cont);
	
}


nodo* eliminarDeLista1(nodo* l, int promedio) {

	nodo* aux;

	while (l->Num < promedio) {

		aux = l->sig;
		free(l);
		l = aux;

		printf("\nitero1\n");
	}
	return l;
}



void eliminarDeLista2(nodo* l, int promedio) {

	nodo* aux;

	while (l->sig != NULL && l->sig->sig != NULL)
	{
		if (l->sig->Num < promedio) {
			printf("\nborro %d\n", l->sig->Num);
			aux = l->sig->sig;
			free(l->sig);
			l->sig = aux;
		}else{
			printf("\nitero sobre %d\n", l->Num);
			l = l->sig;
		}


	}
	return;
}