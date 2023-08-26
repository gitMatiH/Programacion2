


#include <stdio.h>
#include <string.h>


int main() {
	int i = 10;

	char nombre_apellido[50][15];
	char nombre[15];
	printf("Ingrese nombre y apellido del cliente: ");
	//scanf("%s", &nombre);
	gets(nombre);
	while (15 < strlen(nombre)+1) {
		//fflush(stdin);
		printf("Error, cadena demasiado larga.\n");
		printf("Ingrese nombre y apellido del cliente: ");
		gets(nombre);
	}
	strcpy(nombre_apellido[i], nombre);
	printf("%s\n", nombre);
	printf("%s\n", nombre_apellido[i]);
	//*nombre_apellido[1] = "hola q tal";	esto no funca
	strcpy(nombre_apellido[1], "hola q tal");
	printf("%s\n", nombre_apellido[1]);
}