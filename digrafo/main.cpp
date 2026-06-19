#include <iostream>
#include <fstream>

using namespace std;

const int MAX_TAMANO = 20;

int main() {

	int matriz[MAX_TAMANO][MAX_TAMANO] = {0};
	int nodosExistentes = 0;

	ifstream archivoEntrada("digrafo_datos.txt");
	if (archivoEntrada.is_open()) {
		int origen, destino;
		char coma;

		while (archivoEntrada >> origen) {
			archivoEntrada >> coma;
			archivoEntrada >> destino;

			if (origen >= 0 && origen < MAX_TAMANO && destino >= 0 && destino < MAX_TAMANO) {
				matriz[origen][destino] = 1;

				if (origen >= nodosExistentes) nodosExistentes = origen + 1;
				if (destino >= nodosExistentes) nodosExistentes = destino + 1;
			}
		}
		archivoEntrada.close();
		cout << "Datos cargados desde digrafo_datos.txt correctamente. Nodos detectados: " << nodosExistentes << endl;
	} else {
		cout << "No se encontro digrafo_datos.txt, el grafo esta vacio (0 nodos)." << endl;
	}

	int opcion = 0;
	while (opcion != 3) {
		cout << "\n--- MENU DIGRAFO (Actual: " << nodosExistentes << " nodos) ---" << endl;
		cout << "1. Agregar ruta dirigida" << endl;
		cout << "2. Mostrar matriz y rutas dirigidas" << endl;
		cout << "3. Salir" << endl;
		cout << "Opcion: ";
		cin >> opcion;

		switch (opcion) {
		case 1: {
			int origen, destino;
			cout << "Nodo origen (0 a " << MAX_TAMANO - 1 << "): ";
			cin >> origen;
			cout << "Nodo destino (0 a " << MAX_TAMANO - 1 << "): ";
			cin >> destino;

			if (origen >= 0 && origen < MAX_TAMANO && destino >= 0 && destino < MAX_TAMANO) {
				matriz[origen][destino] = 1;

				if (origen >= nodosExistentes) nodosExistentes = origen + 1;
				if (destino >= nodosExistentes) nodosExistentes = destino + 1;

				ofstream archivoSalida("digrafo_datos.txt", ios::app);
				archivoSalida << origen << "," << destino << endl;
				archivoSalida.close();

				cout << "Ruta agregada exitosamente." << endl;
			} else {
				cout << "Error: Nodos fuera de limite de seguridad." << endl;
			}
			break;
		}
		case 2: {
			if (nodosExistentes == 0) {
				cout << "\n(El digrafo esta vacio, no hay datos que mostrar)" << endl;
			} else {

				cout << "\n--- MATRIZ DIRIGIDA ---" << endl;
				for (int i = 0; i < nodosExistentes; i++) {
					for (int j = 0; j < nodosExistentes; j++) {
						cout << matriz[i][j] << " ";
					}
					cout << endl;
				}

				cout << "\n--- LISTA DE RUTAS DIRIGIDAS ---" << endl;
				for (int i = 0; i < nodosExistentes; i++) {
					cout << "Nodo [" << i << "] apunta hacia: ";
					bool tieneSalidas = false;

					for (int j = 0; j < nodosExistentes; j++) {
						if (matriz[i][j] == 1) {
							cout << "-> " << j << " ";
							tieneSalidas = true;
						}
					}

					if (!tieneSalidas) {
						cout << "ninguno (es un destino final)";
					}
					cout << endl;
				}
				cout << "--------------------------------" << endl;
			}
			break;
		}
		case 3:
			cout << "Adios!" << endl;
			break;
		default:
			cout << "Opcion incorrecta." << endl;
		}
	}

	return 0;
}