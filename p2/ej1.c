#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cargarDatos(int dia_vuelo[3], char nom_ciudad[3][25], int capacidad_avion[3], int cant_pas_vend[3]);

int itemA(int dia_vuelo[3], char nom_ciudad[3][25], int capacidad_avion[3], int cant_pas_vend[3]);
int buscarLineal(int cant_pas_vend[3]);

int itemB(int dia_vuelo[3], char nom_ciudad[3][25], int capacidad_avion[3], int cant_pas_vend[3]);
int ordenarDatos(int dia_vuelo[3], char nom_ciudad[3][25], int capacidad_avion[3], int cant_pas_vend[3]);
int intercambiar_int(int* int1, int* int2);
int intercambiar_string(char* string1, char* string2);

float itemC(int dia_vuelo[3], char nom_ciudad[3][25], int capacidad_avion[3], int cant_pas_vend[3]);
float porcentaje(int cant_pas_vend[3]);


int main() {
	//int dia_vuelo = 3;
	int dia_vuelo[3];
	char nom_ciudad[3][25];
	int capacidad_avion[3];
	int cant_pas_vend[3];

	cargarDatos(dia_vuelo, nom_ciudad, capacidad_avion, cant_pas_vend);

	itemA(dia_vuelo, nom_ciudad, capacidad_avion, cant_pas_vend);
	itemB(dia_vuelo, nom_ciudad, capacidad_avion, cant_pas_vend);
    itemC(dia_vuelo, nom_ciudad, capacidad_avion, cant_pas_vend);

	/*
	itemD();
	itemE();
	*/

}

int itemA(int dia_vuelo[3], char nom_ciudad[3][25], int capacidad_avion[3], int cant_pas_vend[3]) {

	int indice;
	char ciudad_nombre[25];
    int dia_Dvuelo;

	indice = buscarLineal(cant_pas_vend);
	strcpy(ciudad_nombre, &nom_ciudad[indice][0]);	// sin & tira warning que pasa un char a tipo puntero a char implicitamente
    dia_Dvuelo = dia_vuelo[indice];


	printf("La ciudad con la mayor cantidad de pasajes vendidos es: %s\t el dia: %d\n",ciudad_nombre,dia_Dvuelo);

	return 0;
}
// La ciudad y el día con la mayor cantidad de pasajes vendidos
int buscarLineal(int cant_pas_vend[3]) {
	// busqueda lineal (otra seria busqueda binaria(si estuviese ordenado por saldo), podriamos poner una opcion como parametro, 1,2 etc y documentar eso)
	int i = 0;
	int indice = i;
	int mayorCant = cant_pas_vend[0];

	while (i < 3) {

	
		if (cant_pas_vend[i] > mayorCant) {
			indice = i;
			printf("Nuevo Mayor %d\n", cant_pas_vend[i]);
			mayorCant = cant_pas_vend[i];
		}
		i = i + 1;
	}

	return indice;
}

int itemB(int dia_vuelo[3], char nom_ciudad[3][25], int capacidad_avion[3], int cant_pas_vend[3]) {


	ordenarDatos(dia_vuelo, nom_ciudad, capacidad_avion, cant_pas_vend);

	int i = 0;

	while (i < 3) {
		printf("\n");
		printf("Dia de vuelo:\t\t\t%d\n", dia_vuelo[i]);
		printf("Nombre de la ciudad:\t\t%s\n", nom_ciudad[i]);
		printf("Capacidad del avion:\t\t%d\n", capacidad_avion[i]);
		printf("Cantidad de pasajes vendidos:\t%d\n", cant_pas_vend[i]);
		printf("\n");
		i++;
	}


	return 0;
}

int ordenarDatos(int dia_vuelo[3], char nom_ciudad[3][25], int capacidad_avion[3], int cant_pas_vend[3]) {
	int i = 0;

	while (i < 3) {
		int j = 0;
		while (j < 3 - ( 1 + i)) {
			if (cant_pas_vend[j] > cant_pas_vend[j + 1]) {
				/*se podr�an meter los cuatro intercambiar en un intercambiar gral que se fije por tipo. �c�mo se hace esto correctamente?*/
				intercambiar_int(&dia_vuelo[j], &dia_vuelo[j + 1]);
				intercambiar_string(nom_ciudad[j], nom_ciudad[j + 1]);
				intercambiar_int(&capacidad_avion[j], &capacidad_avion[j + 1]);
				intercambiar_int(&cant_pas_vend[j], &cant_pas_vend[j + 1]);
			}
			j++;
		}
		i++;
	}
	return 0;
}

int intercambiar_int(int* int1, int* int2) {

	int aux;
	aux = *int1;
	*int1 = *int2;
	*int2 = aux;

	return 0;
}

int intercambiar_string(char* string1, char* string2) {
	//precondicion: los arreglos de caracteres deben tener el mismo tama�o maximo

	char* aux = (char*)malloc((strlen(string1) + 1) * sizeof(char));
	strcpy(aux, string1);
	strcpy(string1, string2);
	strcpy(string2, aux);
	free(aux);

	return 0;
}


int cargarDatos(int dia_vuelo[3], char nom_ciudad[3][25], int capacidad_avion[3], int cant_pas_vend[3]) {
	int dia_v;
	char ciudad[25];
	int cap_avion;
	int pas_vend;

	int i = 0;
	printf("Ingrese dia de vuelo, 0 para terminar carga: ");
	scanf("%d", &dia_v);
	while (dia_v < 0) {
		printf("Error, dato invalido. ");
		printf("Ingrese dia de vuelo, 0 para terminar carga: ");
		scanf("%d", &dia_v);
	}

	while (dia_v != 0) {
		dia_vuelo[i] = dia_v;

		fflush(stdin);	// sino se queda con el \n del paso anterior (sirve para ingreso manual porque lee del stdin). Tendr�amos que hacer de stdin a donde sea q apunte scanf
							//seria algo del tipo if ingresoManual fflush(stdin) else scanf
		//scanf(" ");			// para cuando lee de un archivo as� se "come" el \n que queda trabado en el archivo. debe haber una mejor manera de hacer esto..
		printf("Ingrese nombre de la ciudad: ");
		gets(ciudad);
		while (25 < strlen(ciudad) + 1) {	//+1 porque las cadenas terminan en \0
			printf("Error, cadena demasiado larga. ");
			printf("Ingrese nombre y apellido del cliente: ");
			gets(ciudad);
		}
		strcpy(nom_ciudad[i], ciudad);

		printf("Ingrese la capacidad del avion: ");
		scanf("%d", &cap_avion);
		while (cap_avion < 0) {
			printf("Error, ingrese un numero mayor a 0. ");
			printf("Ingrese la capacidad del avion: ");
			scanf("%d", &cap_avion);
		}
		capacidad_avion[i] = cap_avion;

		printf("Ingrese la cantidad de pasajes vendidos: ");
		scanf("%d", &pas_vend);
		cant_pas_vend[i] = pas_vend;


		i = i + 1;
		printf("Ingrese dia de vuelo, 0 para terminar carga: ");
		scanf("%d", &dia_v);
		while (dia_v < 0) {
			printf("Error, dato invalido.");
			printf("Ingrese dia de vuelo, 0 para terminar carga: ");
			scanf("%d", &dia_v);
		}
		printf("\n");
	}
	return 0;
}

/*float itemC(int dia_vuelo[3], char nom_ciudad[3][25], int capacidad_avion[3], int cant_pas_vend[3]){

    int i=0;
	char ciudad_por[25];

    float por;

    while (i < 3) {

	por = (int)porcentaje(cant_pas_vend);
	strcpy(ciudad_por, &nom_ciudad[i][0]);	// sin & tira warning que pasa un char a tipo puntero a char implicitamente

    }

    printf("El porcentaje de cada ciudad es: ");
    printf("Ciudad: %s \t Porcentaje: %f\n",ciudad_por,por);

    
//comparar las cadenas, una de ciudades y otro de procentajes; 
/*paris => porcentaje
barcelona =>porcentaje
cordoba =>procentaje

*/

	return 0;
}


float porcentaje(int cant_pas_vend[3]){
    int i;
    float cont=0,acum=0;
    float porcent;
    float cpv;

    while (i < 3) {
        
        if (cant_pas_vend[i] > 0) {

			cpv = (float)cant_pas_vend[i];
            acum = acum + cpv;
        }
		cont++;
	}
    porcent = (acum/cont)*100;

    return porcent;

}*/