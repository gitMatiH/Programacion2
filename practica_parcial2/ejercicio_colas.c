

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

	int num;
	char car;
	nodoCola datos;
	int sumatoria = 0;

	//crear cola de entrada
	nodoCola* p = NULL;
	nodoCola* u = NULL;

	//crear cola "primera"
	nodoCola* p1 = NULL;
	nodoCola* u1 = NULL;

	//crear cola "segunda"
	nodoCola* p2 = NULL;
	nodoCola* u2 = NULL;

	//llenar la cola de entrada
	printf("Ingrese un numero, -1 para finalizar: ");
	scanf("%d", &num);

	while (num != -1) {
		fflush(stdin);
		printf("Ingrese el caracter asociado: ");
		scanf("%c", &car);

		acolar(&p, &u, crearNodo(num, car));

		printf("Ingrese un numero, -1 para finalizar: ");
		scanf("%d", &num);
	}

	//punto a

	//llenar las dos colas
	//desacolar funciona con la cola vacia? Tira o no tira errror?

	while (p != NULL) {

		datos = desacolar(&p);

		if (datos.ID > 55) {
			acolar(&p1, &u1, crearNodo(datos.ID, datos.Letra));
		}
		if (datos.ID > 56 && datos.ID < 100) {
			acolar(&p2, &u2, crearNodo(datos.ID, datos.Letra));
		}
		if (datos.ID <= 55 || datos.ID >= 100){
			sumatoria = sumatoria + datos.ID;
		}
	}


	//punto b
	printf("La sumatoria de todos los ID de los elementos desacolados que no se guardaron en ninguna cola es: %d", sumatoria);

	//punto c
	printf("\nMostramos la cola primera: \n");
	while (p1 != NULL) {
		mostrar(desacolar(&p1));
	}

	printf("\nMostramos la cola segunda: \n");
	while (p2 != NULL) {
		mostrar(desacolar(&p2));
	}

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

	printf("\n");
	printf("\n%d", aux.ID);
	printf("\n%c", aux.Letra);
	printf("\n");
	/*
	codigo extra
	*/
}