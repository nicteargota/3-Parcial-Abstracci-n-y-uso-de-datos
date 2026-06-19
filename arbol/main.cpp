#include <iostream>
#include <fstream>

using namespace std;

struct Nodo {
	int valor;
	Nodo* izq;
	Nodo* der;
};

Nodo* insertar(Nodo* raiz, int nuevoValor) {

	if (raiz == nullptr) {
		Nodo* nuevo = new Nodo;
		nuevo->valor = nuevoValor;
		nuevo->izq = nullptr;
		nuevo->der = nullptr;
		return nuevo;
	}

	if (nuevoValor < raiz->valor) {
		raiz->izq = insertar(raiz->izq, nuevoValor);
	}

	else if (nuevoValor > raiz->valor) {
		raiz->der = insertar(raiz->der, nuevoValor);
	}

	return raiz;
}

void mostrarInorden(Nodo* raiz) {
	if (raiz != nullptr) {
		mostrarInorden(raiz->izq);
		cout << raiz->valor << " ";
		mostrarInorden(raiz->der);
	}
}

int main() {
	Nodo* raiz = nullptr;

	ifstream archivoEntrada("arbol_datos.txt");
	if (archivoEntrada.is_open()) {
		int numero;

		while (archivoEntrada >> numero) {
			raiz = insertar(raiz, numero);
		}
		archivoEntrada.close();
		cout << "Numeros del arbol cargados correctamente." << endl;
	} else {
		cout << "No hay archivo arbol_datos.txt. Arbol vacio." << endl;
	}

	int opcion = 0;
	while (opcion != 3) {
		cout << "\n--- MENU ARBOL BINARIO DE BUSQUEDA ---" << endl;
		cout << "1. Insertar numero" << endl;
		cout << "2. Mostrar recorrido en orden" << endl;
		cout << "3. Salir" << endl;
		cout << "Que deseas hacer? ";
		cin >> opcion;

		switch (opcion) {
		case 1: {
			int num;
			cout << "Ingresa un numero entero: ";
			cin >> num;

			raiz = insertar(raiz, num);

			ofstream archivoSalida("arbol_datos.txt", ios::app);
			archivoSalida << num << endl;
			archivoSalida.close();

			cout << "Numero " << num << " insertado en el arbol y archivo." << endl;
			break;
		}
		case 2: {
			cout << "\nArbol Inorden (de menor a mayor):" << endl;
			if (raiz == nullptr) {
				cout << "El arbol esta vacio." << endl;
			} else {
				mostrarInorden(raiz);
				cout << endl;
			}
			break;
		}
		case 3:
			cout << "Terminando ejecucion..." << endl;
			break;
		default:
			cout << "Intenta otra vez." << endl;
		}
	}

	return 0;
}