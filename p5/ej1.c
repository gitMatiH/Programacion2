#include <stdio.h>

int cocienteDivisionRec(int dividendo, int divisor) {

	//Caso base
	if (dividendo < divisor){
		return 0;
	}
	//Caso general
	dividendo = dividendo - divisor;

	return cocienteDivisionRec(dividendo, divisor)+1;	//le suma cada vez que PUEDE hacer
}

int cocienteDivisionRecCont(int dividendo, int divisor, int cont) {
	// pre: cont en cero al primer llamado
	//Caso base
	if (dividendo < divisor) {
		return cont;
	}
	//Caso general
	dividendo = dividendo - divisor;
	cont++;

	return cocienteDivisionRecCont(dividendo, divisor, cont);	//le suma cada vez que PUEDE hacer
}


int restoDivisionRec(int resto, int divisor) {

	//Caso base
	if (resto < divisor) {
		return resto;
	}
	//Caso general
	resto = resto - divisor;

	return restoDivisionRec(resto, divisor);
}


int main() {

	int dividendo;
	int divisor;
	int cociente;
	int resto;

	printf("Ingrese el dividendo: ");	//como uso el literal del string para hacerlo funcion (que reemplaze por el nombre de la variable)
	scanf("%d", &dividendo);
	printf("Ingrese el divisor: ");
	scanf("%d", &divisor);
	
	cociente = cocienteDivisionRec(dividendo, divisor);
	//cociente = cocienteDivisionRecCont(dividendo, divisor, 0);
	resto = restoDivisionRec(dividendo, divisor);

	printf("El cociente de dividir %d por %d = %d\n", dividendo, divisor, cociente);
	printf("El resto de dividir %d por %d = %d\n", dividendo, divisor, resto);

	return 0;
}