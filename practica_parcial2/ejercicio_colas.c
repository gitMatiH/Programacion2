

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
void mostrar2(nodoCola, int);

// generalmente hacemos
// mostrar(desacolar(&cola));

int main(void) {





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



}


nodoCola desacolar(nodoCola** p) {



}