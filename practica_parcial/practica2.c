/*

Se ingresan los siguientes datos de los empleados de una empresa: 
Nro de legajo, nombre y apellido, a�os de antiguedad en la empresa 
y sueldo. Generar una lista simplemente enlazada con estos datos. 
La carga termina con el nro de legajo igual a cero.

Mostrar la lista.
a) Generar una nueva lista con aquellos empleados que tienen mas de 10
a�os en la empresa e incrementar el sueldo en un 15%. Mostrar la lista.

b) Generar una nueva lista con los sueldos de cada empleado y al final
insertar el monto total que la empresa debe pagar en sueldos.

c) Eliminar de la lista original a aquellos empleados que tienen menos 
de 4 a�os de antig�edad generando con ellos una lista nueva

d) Insertar antes de cada nodo de aquellos empleados que tienen m�s de 
30 a�os de antiguedad en la lista  original un nodo incrementando el 30% 
de sueldo.

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct listaEmpleados {
	int legajo;
	char nombreYApellido[30];
	int antiguedad;
	float sueldo;
	struct listaEmpleados* sig;

}nodoListaEmpleados;

typedef struct listaMontos {
	float monto;
	struct listaMontos* sig;

}nodolistaMontos;


//declaraciones
void cargarLista(nodoListaEmpleados* l);

void aumentoAntiguedad(nodoListaEmpleados* l1, nodoListaEmpleados* lAumento);

void cargarListaMontos(nodoListaEmpleados* l1, nodolistaMontos* lMonto);

nodoListaEmpleados* eliminarYCrear1(nodoListaEmpleados* l1, nodoListaEmpleados* lNuevos);
void eliminarYCrear2(nodoListaEmpleados* l1, nodoListaEmpleados* lNuevos);

nodoListaEmpleados* insertar1(nodoListaEmpleados* l1);
void insertar2(nodoListaEmpleados* l1);

void mostrar(nodoListaEmpleados* l);

void mostrarMonto(nodolistaMontos* lMonto);

void mostrarMenu(void);



nodoListaEmpleados* concatenar(nodoListaEmpleados* aux, nodoListaEmpleados* lNuevos);



int main(void) {

	int opcion;
	float monto;
	nodoListaEmpleados* aux;

	nodoListaEmpleados* l1 = (nodoListaEmpleados*)malloc(sizeof(nodoListaEmpleados));
	l1->sig = NULL;

	nodoListaEmpleados* lAumento = (nodoListaEmpleados*)malloc(sizeof(nodoListaEmpleados));
	lAumento->sig = NULL;

	nodolistaMontos* lMonto = (nodolistaMontos*)malloc(sizeof(nodolistaMontos));
	lMonto->sig = NULL;

	nodoListaEmpleados* lNuevos = (nodoListaEmpleados*)malloc(sizeof(nodoListaEmpleados));
	lNuevos->sig = NULL;

	mostrarMenu();
	scanf("%d", &opcion);

	while (opcion != 0) {
	
		if (opcion == 1) {
			printf("\nCargamos la lista de empleados:\n");
			cargarLista(l1);
			printf("\nMostramos la lista de empleados\n");
			mostrar(l1);
		}
		if (opcion == 2) {
			aumentoAntiguedad(l1, lAumento);
			printf("\nMostramos la lista de empleados con aumento\n");
			mostrar(lAumento);
		}
		if (opcion == 3) {
			cargarListaMontos(l1, lMonto);
			mostrarMonto(lMonto);
		}
		if (opcion == 4) {
			eliminarYCrear2(l1, lNuevos);
			l1 = eliminarYCrear1(l1, lNuevos);
			/*
			l1 = eliminarYCrear1(l1, lNuevos);
			while (l1->sig != NULL && l1->antiguedad < 4) {
				l1 = eliminarYCrear1(l1, lNuevos);
			}
			eliminarYCrear2(l1, lNuevos);
			*/
		}
		if (opcion == 5) {
			insertar2(l1);
			l1 = insertar1(l1);
		}
		if (opcion == 6) {
			printf("\nMostramos la lista de empleados\n");
			mostrar(l1);
		}
		if (opcion == 7) {
			printf("\nMostramos la lista de empleados con aumento\n");
			mostrar(lAumento);
		}
		if (opcion == 8) {
			printf("\nMostramos la lista de empleados nuevos\n");
			mostrar(lNuevos);
		}
		if (opcion == 9) {
			printf("\nMostramos los montos parciales y totales a pagar:\n");
			mostrarMonto(lMonto);
		}

		mostrarMenu();
		scanf("%d", &opcion);
	}

	return 0;
}

void mostrarMenu(void) {
	printf("\nMenu");
	printf("\n1. Cargar lista de empleados");
	printf("\n2. Hacer un aumento por antiguedad");
	printf("\n3. Cargar lista montos y calcular Monto total al final de la lista");
	printf("\n4. Eliminar de lista los empleados mas nuevos e insertarlos en una nueva");
	printf("\n5. Poner delante de cada empleado de mas de 30 anios una copia de su registro con un aumento");
	printf("\n6. Mostrar lista de empleados");
	printf("\n7. Mostrar lista de empleados con aumento");
	printf("\n8. Mostrar lista de empleados nuevos");
	printf("\n9. Mostrar monto parcial y total");
	printf("\nIngrese opcion, 0 para salir: ");
}

void cargarLista(nodoListaEmpleados* l) {

	printf("\nIngrese el legajo del empleado: ");
	scanf("%d", &l->legajo);
	fflush(stdin);

	while (l->legajo != 0) {
	
		printf("\nIngrese el nombre y apellido del empleado: ");
		scanf(" %[^\n]", &l->nombreYApellido);
		fflush(stdin);

		printf("\nIngrese la antiguedad del empleado: ");
		scanf("%d", &l->antiguedad);
		fflush(stdin);

		printf("\nIngrese el sueldo del empleado: ");
		scanf("%f", &l->sueldo);
		fflush(stdin);

		nodoListaEmpleados* nuevoNodo = (nodoListaEmpleados*)malloc(sizeof(nodoListaEmpleados));
		nuevoNodo->sig = NULL;

		l->sig = nuevoNodo;

		l = l->sig;

		printf("\nIngrese el legajo del empleado: ");
		scanf("%d", &l->legajo);
		fflush(stdin);
	}

	return;
}



void mostrar(nodoListaEmpleados* l) {

	while (l->sig != NULL) {
	
		printf("\n");
		printf("\nEl legajo del empleado es: %d", l->legajo);
		printf("\nEl nombre del empleado es: %s", l->nombreYApellido);
		printf("\nLa antiguedad del empleado es: %d", l->antiguedad);
		printf("\nEl sueldo del empleado es: %.2f", l->sueldo);
		printf("\n");

		l = l->sig;
	}


	return;
}

void mostrarMonto(nodolistaMontos* lMonto){
	printf("\n");
	while (lMonto->sig != NULL) {

		//si llegamos al final
		if (lMonto->sig->sig == NULL) {
			printf("\nMonto Total: %f", lMonto->monto);
		}
		else {
			printf("\nSueldo: %f", lMonto->monto);
		}

		lMonto = lMonto->sig;
	}
	printf("\n");


	return;
}


void aumentoAntiguedad(nodoListaEmpleados* l1,nodoListaEmpleados* lAumento) {

	float sueldo, aumento;

	while (l1->sig != NULL) {

		if (l1->antiguedad > 10) {

			nodoListaEmpleados* nuevoNodo = (nodoListaEmpleados*)malloc(sizeof(nodoListaEmpleados));
			nuevoNodo->sig = NULL;

			lAumento->legajo = l1->legajo;
			strcpy(lAumento->nombreYApellido, l1->nombreYApellido);
			lAumento->antiguedad = l1->antiguedad;

			//incrementamos el sueldo en un 15%
			sueldo = l1->sueldo;
			aumento = sueldo * 15 / 100;
			sueldo = sueldo + aumento;
			lAumento->sueldo = sueldo;

			lAumento->sig = nuevoNodo;
			lAumento = lAumento->sig;
		}
		l1 = l1->sig;
	}

	return;
}


void cargarListaMontos(nodoListaEmpleados* l1, nodolistaMontos* lMonto) {

	float sumatoria = 0;

	while (l1->sig != NULL) {

		sumatoria = sumatoria + l1->sueldo;

		lMonto->monto = l1->sueldo;
		nodolistaMontos* nuevoNodo = (nodolistaMontos*)malloc(sizeof(nodolistaMontos));
		nuevoNodo->sig = NULL;
		lMonto->sig = nuevoNodo;
		lMonto = lMonto->sig;

		l1 = l1->sig;
	}

	//cargamos el nodo final con el total
	lMonto->monto = sumatoria;
	nodolistaMontos* nuevoNodo = (nodolistaMontos*)malloc(sizeof(nodolistaMontos));
	nuevoNodo->sig = NULL;
	lMonto->sig = nuevoNodo;

	return;
}


/*
nodoListaEmpleados* concatenar(nodoListaEmpleados* aux, nodoListaEmpleados* lNuevos) {

	//nodoListaEmpleados* vinculo;
	//vinculo = (nodoListaEmpleados*)malloc(sizeof(nodoListaEmpleados));

	nodoListaEmpleados* ppioLista = aux;

	while (aux->sig != NULL && aux->sig->sig != NULL) {
		aux = aux->sig;
	}
	aux->sig = lNuevos;

	return ppioLista;
}
*/

nodoListaEmpleados* eliminarYCrear1(nodoListaEmpleados* l1, nodoListaEmpleados* lNuevos) {

	nodoListaEmpleados* aux;

	if (l1->antiguedad < 4) {

		//se posiciona en el ultimo de la lista de lNuevos
		while (lNuevos->sig != NULL) {
			lNuevos = lNuevos->sig;
		}

		lNuevos->legajo = l1->legajo;
		strcpy(lNuevos->nombreYApellido, l1->nombreYApellido);
		lNuevos->antiguedad = l1->antiguedad;
		lNuevos->sueldo = l1->sueldo;
		nodoListaEmpleados* nuevoNodo = (nodoListaEmpleados*)malloc(sizeof(nodoListaEmpleados));
		nuevoNodo->sig = NULL;
		lNuevos->sig = nuevoNodo;


		aux = l1->sig;
		free(l1);
		l1 = aux;
	}
	return l1;
}


void eliminarYCrear2(nodoListaEmpleados* l1, nodoListaEmpleados* lNuevos) {

	/*
	while (lNuevos->sig != NULL) {
		lNuevos = lNuevos->sig;
	}
	*/

	nodoListaEmpleados* aux = NULL;

	// eliminar con condicion
	while (l1->sig != NULL && l1->sig->sig != NULL) {

		if (l1->sig->antiguedad < 4) {

			//poner en lista lNuevos
			lNuevos->legajo = l1->sig->legajo;
			strcpy(lNuevos->nombreYApellido, l1->sig->nombreYApellido);
			lNuevos->antiguedad = l1->sig->antiguedad;
			lNuevos->sueldo = l1->sig->sueldo;
			//crea el "nuevo ultimo"
			nodoListaEmpleados* nuevoNodo = (nodoListaEmpleados*)malloc(sizeof(nodoListaEmpleados));
			nuevoNodo->sig = NULL;
			lNuevos->sig = nuevoNodo;
			lNuevos = lNuevos->sig;

			//eliminar de l1
			aux = l1->sig->sig;
			free(l1->sig);
			l1->sig = aux;
		}
		else {
			l1 = l1->sig;
		}
	}
}


nodoListaEmpleados* insertar1(nodoListaEmpleados* l1) {

	float sueldo;

	nodoListaEmpleados* nuevoNodo = NULL;

	if (l1->antiguedad > 30) {
		nuevoNodo = (nodoListaEmpleados*)malloc(sizeof(nodoListaEmpleados));
		nuevoNodo->legajo = l1->legajo;
		strcpy(nuevoNodo->nombreYApellido, l1->nombreYApellido);
		nuevoNodo->antiguedad = l1->antiguedad;
		sueldo = l1->sueldo;
		//aumento
		sueldo = sueldo + sueldo * 0.30;
		nuevoNodo->sueldo = sueldo;
		nuevoNodo->sig = l1;
		l1 = nuevoNodo;
	}
	return l1;
}



void insertar2(nodoListaEmpleados* l1) {

	float sueldo;

	nodoListaEmpleados* nuevoNodo = NULL;

	while (l1->sig != NULL && l1->sig->sig != NULL) {
	
		if (l1->sig->antiguedad > 30) {
		
			nuevoNodo = (nodoListaEmpleados*)malloc(sizeof(nodoListaEmpleados));
			nuevoNodo->legajo = l1->sig->legajo;
			strcpy(nuevoNodo->nombreYApellido, l1->sig->nombreYApellido);
			nuevoNodo->antiguedad = l1->sig->antiguedad;
			sueldo = l1->sig->sueldo;
			//aumento
			sueldo = sueldo + sueldo * 0.30;
			nuevoNodo->sueldo = sueldo;
			nuevoNodo->sig = l1->sig;
			l1->sig = nuevoNodo;

			l1 = l1->sig->sig;
		}
		else {
			l1 = l1->sig;
		}
		

		
	}

	return;
}