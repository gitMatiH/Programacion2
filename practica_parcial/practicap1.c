/*

En la universidad hay dos nuevas carreras:
Inteligencia artificial
Ciberseguridad

Se desea generar un sistema de gestion con la siguiente estructura:
Legajo
Nombre	<- nombre de pila %s
Edad
Carrera (Seguridad/Inteligencia)
Año que esta cursando

Se pide:
1) Una funcion para cargar la informacion de los estudiantes
2) Crear una nueva lista en la que solo esten aquellos alumnos que están en inteligencia
y mas de dos años.
3) Generar una función que calcule y muestre el promedio de los estudiantes que eligen seguridad (por sobre otra?)
4) Generar una función que permita eliminar a los estudiantes que deseen dejar la carrera. La misma
recibirá por parámetro numero de legajo.
5) Generar un menú para poder gestionar las funciones de la lista.
6) Crear una funcion que permita insertar delante de un alumno determinado (la búsqueda debe realizarse
utilizando un número de legajo que se le solicitará al usuario) los siguientes datos:
Numero de legajo=9999
Nombre = "PEPE"
Edad = 99
Carrera = "Inteligencia"
Año que está cursando = 0

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Estructura de datos (lista)

typedef struct lista {
	int legajo;
	char nombre[30];
	int edad;
	char carrera[30];
	int anio;
	struct lista* siguiente;

}nodoLista;


void cargarLista(nodoLista* listaEstudiantes);

void crearLista(nodoLista* listaEstudiantes, nodoLista* listaInteligencia);

float promedioSeguridadI(nodoLista* listaEstudiantes);

nodoLista* eliminar1(int legajo, nodoLista* listaEstudiantes);
void eliminar2(int legajo, nodoLista* listaEstudiantes);

nodoLista * insertar1(int legajo, nodoLista* listaEstudiantes);
void insertar2(int legajo, nodoLista* listaEstudiantes);


void mostrar(nodoLista* listaEstudiantes);

int main(void) {

	int opcion;
	//para punto 3:
	float promedio;
	int contador;
	int acumulador;
	//punto 4
	int legajo;

	//creamos cosas y variables
	nodoLista* listaEstudiantes = (nodoLista*)malloc(sizeof(nodoLista));
	//caso base
	listaEstudiantes->siguiente = NULL;

	nodoLista* listaInteligencia = (nodoLista*)malloc(sizeof(nodoLista));
	//caso base
	listaInteligencia->siguiente = NULL;

	//pido dato
	printf("\nMenu");
	printf("\n1. Cargar lista de estudiantes");
	printf("\n2. Crear lista de estudiantes de Inteligencia de mas de dos anios");
	printf("\n3. Calcular el promedio de estudiantes que eligen Seguridad");
	printf("\n4. Eliminar estudiante de carrera");
	printf("\n5. Insertar registro delante de un legajo");
	printf("\n6. Mostrar lista de estudiantes");
	printf("\n7. Mostrar lista de estudiantes de seguridad de mas de dos anios");
	printf("\nIntroduzca una opcion, 0 para salir: ");
	scanf("%d", &opcion);
	fflush(stdin);

	while (opcion != 0) {
	
		if (opcion == 1) {
			cargarLista(listaEstudiantes);
		}
		if (opcion == 2) {
			crearLista(listaEstudiantes, listaInteligencia);
		}
		if (opcion == 3) {
			//algo = funcion() || funcion(&algo) (las funciones no imprimen)
			//recursivo
			//promedioSeguridadR(listaEstudiantes, &contador, &acumulador, &promedio);
			//iterativo
			promedio = promedioSeguridadI(listaEstudiantes);
			//imprimimos(algo)
			printf("\nEl promedio de estudiantes que eligen Seguridad es: %.2f", promedio);
		}
		if (opcion == 4) {
			//pedimos legajo
			printf("\nIngrese el legajo del estudiante del cual eliminar el registro: ");
			scanf("%d",&legajo);
			//vemos si esta en la cabecera, y si sí, eliminamos
			listaEstudiantes = eliminar1(legajo, listaEstudiantes);
			//vemos si está en algún otro lado, y si sí, eliminamos
			eliminar2(legajo, listaEstudiantes);
		}
		if (opcion == 5) {
			//pedimos legajo
			printf("\nIngrese el legajo del estudiante delante del cual insertar un registro: ");
			scanf("%d", &legajo);
			//vemos si se cumple la condicion en cabecera, y si sí, se modifica la cabecera
			listaEstudiantes = insertar1(legajo, listaEstudiantes);
			//vemos si se cumple la condicion en cualquier lugar de la lista (version clave)
			if (listaEstudiantes->legajo != 9999) {
				insertar2(legajo, listaEstudiantes);
			}
			else {
				insertar2(legajo, listaEstudiantes->siguiente);
			}
			//vemos si se cumple la condicion en cualquier lugar de la lista (version repetidos)

		}
		if (opcion == 6) {
			mostrar(listaEstudiantes);
		}
		if (opcion == 7) {
			mostrar(listaInteligencia);
		}

		//pido dato
		printf("\nMenu");
		printf("\n1. Cargar lista de estudiantes");
		printf("\n2. Crear lista de estudiantes de Inteligencia de mas de dos anios");
		printf("\n3. Calcular el promedio de estudiantes que eligen Seguridad");
		printf("\n4. Eliminar estudiante de carrera");
		printf("\n5. Insertar registro delante de un legajo");
		printf("\n6. Mostrar lista de estudiantes");
		printf("\n7. Mostrar lista de estudiantes de seguridad de mas de dos anios");
		printf("\nIntroduzca una opcion: ");
		scanf("%d", &opcion);
		fflush(stdin);
	}


	return 0;
}


//definiciones


void cargarLista(nodoLista* listaEstudiantes) {

	//pido datos (cond de corte)
	printf("\nIngrese el legajo: ");
	scanf("%d", &listaEstudiantes->legajo);
	fflush(stdin);

	while (listaEstudiantes->legajo != -1) {
		//pido resto de datos (si no se da cond de corte)
		
		//nombre
		//fflush(stdin);
		printf("\nIngrese el nombre: ");
		scanf("%s", &listaEstudiantes->nombre);
		fflush(stdin);
		
		//edad
		printf("\nIngrese la edad: ");
		scanf("%d", &listaEstudiantes->edad);
		fflush(stdin);
		//validacion
		while (listaEstudiantes->edad < 17) {
			printf("\nEdad invalida.");
			printf("\nIngrese la edad: ");
			scanf("%d", &listaEstudiantes->edad);
			fflush(stdin);
		};

		//carrera
		printf("\nIngrese la carrera (Seguridad/Inteligencia): ");
		//fflush(stdin);
		scanf("%s", &listaEstudiantes->carrera);
		fflush(stdin);
		//validar si es "Seguridad" o "Inteligencia"
		while ( strcmp(listaEstudiantes->carrera, "Seguridad") != 0 &&
				strcmp(listaEstudiantes->carrera, "Inteligencia") != 0)
		{
			printf("\nError.");
			printf("\nIngrese la carrera (Seguridad/Inteligencia): ");
			//fflush(stdin);
			scanf("%s", &listaEstudiantes->carrera);
			fflush(stdin);
		}

		//anio
		printf("\nIngrese el anio: ");
		scanf("%d", &listaEstudiantes->anio);
		fflush(stdin);
			

		//procesa
		//crear un nuevo nodo
		nodoLista* nuevoNodo = (nodoLista*)malloc(sizeof(nodoLista));
		//poner en null el siguiente del nuevo nodo
		nuevoNodo->siguiente = NULL;
		//poner listaEstudiantes->sig = nodoNuevo
		listaEstudiantes->siguiente = nuevoNodo;
		//avanzar en la lista listaEstudiantes = listaEstudiantes->sig
		listaEstudiantes = listaEstudiantes->siguiente;

		//pido datos (cond de corte)
		printf("\nIngrese el legajo: ");
		scanf("%d", &listaEstudiantes->legajo);
		fflush(stdin);
	}

}


void mostrar(nodoLista* listaEstudiantes) {

	while (listaEstudiantes->siguiente != NULL) {
		printf("\n");
		printf("\nLegajo: %d", listaEstudiantes->legajo);
		printf("\nNombre: %s", listaEstudiantes->nombre);
		printf("\nEdad: %d", listaEstudiantes->edad);
		printf("\nCarrera: %s", listaEstudiantes->carrera);
		printf("\nAnio: %d", listaEstudiantes->anio);
		printf("\n");

		// me muevo al siguiente elemento de la lista
		listaEstudiantes = listaEstudiantes->siguiente;
	}
}


void crearLista(nodoLista* listaEstudiantes, nodoLista* listaInteligencia) {


	while (listaEstudiantes->siguiente != NULL) {
		
		//si se dan las condiciones para agregar a la segunda lista
		if (strcmp(listaEstudiantes->carrera, "Inteligencia") == 0 &&
			listaEstudiantes->anio > 2)
		{
			//creamos nuevo nodo para listaInteligencia
			nodoLista* nuevoNodo = (nodoLista*)malloc(sizeof(nodoLista));
			nuevoNodo->siguiente = NULL;
			//cargamos en listaInteligencia
			listaInteligencia->legajo = listaEstudiantes->legajo;
			strcpy(listaInteligencia->nombre, listaEstudiantes->nombre);
			listaInteligencia->edad = listaEstudiantes->edad;
			strcpy(listaInteligencia->carrera, listaEstudiantes->carrera);
			listaInteligencia->anio = listaEstudiantes->anio;
			//ponemos como siguiente al actual de listaInteligencia al nuevo nodo
			listaInteligencia->siguiente = nuevoNodo;
			//avanzamos en listaInteligencia (para posicionarnos sobre la estructura vacia)
			listaInteligencia = listaInteligencia->siguiente;
		}
		// nos movemos en listaEstudiantes al siguiente elemento
		listaEstudiantes = listaEstudiantes->siguiente;
	}
	return;
}


float promedioSeguridadI(nodoLista* listaEstudiantes) {

	float promedio = 0;
	int contadorTot, contadorEst;
	contadorTot = 0;
	contadorEst = 0;

	while (listaEstudiantes->siguiente != NULL) {
		if (strcmp(listaEstudiantes->carrera, "Seguridad") == 0) {
			contadorEst = contadorEst + 1;
		}
		contadorTot = contadorTot + 1;
		listaEstudiantes = listaEstudiantes->siguiente;
	}

	if (contadorTot != 0) {
		promedio = (float)contadorEst / contadorTot;
	}

	return promedio;
}


nodoLista* eliminar1(int legajo, nodoLista* listaEstudiantes) {
	/* version mati
	if (listaEstudiantes->legajo == legajo) {
		//generamos un nodo auxiliar para guardar la direccion de la cabeza
		nodoLista* auxNodoCabeza;
		auxNodoCabeza = listaEstudiantes;
		listaEstudiantes = listaEstudiantes->siguiente;
		//free(nodoCabeza)
		free(auxNodoCabeza);
	}
	*/

	if (listaEstudiantes->legajo == legajo) {
		nodoLista* aux;
		aux = listaEstudiantes->siguiente;
		free(listaEstudiantes);
		listaEstudiantes = aux;
	}
	return listaEstudiantes;
}



void eliminar2(int legajo, nodoLista* listaEstudiantes) {
	//asumimos que el legajo es único, es una clave
	nodoLista* aux;

	/*
	//version sin repetidos (clave)
	while (listaEstudiantes->siguiente != NULL && listaEstudiantes->siguiente->siguiente != NULL) {
		if (listaEstudiantes->siguiente->legajo == legajo) {
			aux = listaEstudiantes->siguiente->siguiente;
			free(listaEstudiantes->siguiente);
			listaEstudiantes->siguiente = aux;
		}
		listaEstudiantes = listaEstudiantes->siguiente;
	}
	*/

	
	//version con repetidos
	while (listaEstudiantes->siguiente != NULL && listaEstudiantes->siguiente->siguiente != NULL) {
		if (listaEstudiantes->siguiente->legajo == legajo) {
			aux = listaEstudiantes->siguiente->siguiente;
			free(listaEstudiantes->siguiente);
			listaEstudiantes->siguiente = aux;
		}
		else {
			listaEstudiantes = listaEstudiantes->siguiente;
		}	
	}
	
	return;
}




nodoLista* insertar1(int legajo, nodoLista* listaEstudiantes) {

	if (listaEstudiantes->legajo == legajo) {
		nodoLista* nuevoNodo = (nodoLista*)malloc(sizeof(nodoLista));
		nuevoNodo->legajo = 9999;
		strcpy(nuevoNodo->nombre, "PEPE");
		nuevoNodo->edad = 99;
		strcpy(nuevoNodo->carrera, "Inteligencia");
		nuevoNodo->anio = 0;
		nuevoNodo->siguiente = listaEstudiantes;
		listaEstudiantes = nuevoNodo;
	}

	return listaEstudiantes;
}



/*
Numero de legajo=9999
Nombre = "PEPE"
Edad = 99
Carrera = "Inteligencia"
Año que está cursando = 0
*/

void insertar2(int legajo, nodoLista* listaEstudiantes) {
	
	while (listaEstudiantes->siguiente != NULL && listaEstudiantes->siguiente->siguiente != NULL) {
		if (listaEstudiantes->siguiente->legajo == legajo) {
			nodoLista* nuevoNodo = (nodoLista*)malloc(sizeof(nodoLista));
			nuevoNodo->legajo = 9999;
			strcpy(nuevoNodo->nombre, "PEPE");
			nuevoNodo->edad = 99;
			strcpy(nuevoNodo->carrera, "Inteligencia");
			nuevoNodo->anio = 0;
			nuevoNodo->siguiente = NULL;

			nuevoNodo->siguiente = listaEstudiantes->siguiente;
			listaEstudiantes->siguiente = nuevoNodo;
		}
		listaEstudiantes = listaEstudiantes->siguiente->siguiente;
	}

	return;
}