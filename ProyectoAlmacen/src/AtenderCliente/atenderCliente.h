


// Declaraciones de las que depende atenderCliente


void mostrarNodoProd(nodoProductos* pElemL);

void mostrarTicket(nodoTicket* lT);

nodoTicket* borrarTicket(nodoTicket* lT);

void generarTicket(nodoProductos* lP,
	nodoTicket* lT,
	nodoRanking* lR);

nodoProductos* buscar(nodoProductos* lP, int id, nodoProductos* pElemL);

void agregar(nodoTicket* lT, int id, int cant, nodoProductos* pElemL);

void descontar(nodoProductos* pElemL, int cant);

void actualizarRanking(nodoRanking* lR, int id, int cant);

float calcularTotal(nodoTicket* lT, float* monto);