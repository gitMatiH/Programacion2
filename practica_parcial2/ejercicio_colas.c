

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct cola {
	int ID;
	char Letra;
	struct cola * Siguiente_caracter;

}nodoCola;


nodoCola * crearNodo(int ID, char Letra);
void acolar(nodoCola** p, nodoCola** u, nodoCola* q);
nodoCola desacolar(nodoCola** p);
void mostrar(nodoCola);
//void mostrar2(nodoCola, int);

// generalmente hacemos
// mostrar(desacolar(&cola));

int main(void) {

	//crear cola "primera"
	nodoCola* p1 = NULL;
	nodoCola* u1 = NULL;

	//crear cola "segunda"
	nodoCola* p2 = NULL;
	nodoCola* u2 = NULL;





	return 0;
}


nodoCola* crearNodo(int ID, char Letra) {

	nodoCola* nuevoNodo = (nodoCola*)malloc(sizeof(nodoCola));
	nuevoNodo->ID = ID;
	nuevoNodo->Letra = Letra;
	nuevoNodo->Siguiente_caracter = NULL;

	return nuevoNodo;
}

void acolar(nodoCola** p, nodoCola** u, nodoCola* q) {

	printf("acolar_nodo\n");
	if (*p == NULL) {
		//crea o "desvacía" la cola. Ppio y final son el mismo.
		*p = *u = q;
	}
	else {
		//encadena a q a la cola
		(*u)->Siguiente_caracter = q;
		//setea a q como nuevo ultimo
		(*u) = q;
	}
}


nodoCola desacolar(nodoCola** p) {

	nodoCola* aux;
	nodoCola datos;

	datos = **p;
	aux = *p;

	//esto no se puede hacer sin doble puntero, porque se pierde
	//al cambiar al contexto del main
	*p = (*p)->Siguiente_caracter;
	
	free(aux);

	return datos;
}


void mostrar(nodoCola aux) {

	printf("%d", aux.ID);
	printf("%c", aux.Letra);
	/*
	codigo extra
	*/
}