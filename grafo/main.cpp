#include <iostream>
#include <fstream>

using namespace std;

const int MAX_TAMANO = 20;

int main() {

	int matriz[MAX_TAMANO][MAX_TAMANO] = {0};
	int nodosExistentes = 0;

	ifstream archivoEntrada("grafo_datos.txt");
	if (archivoEntrada.is_open()) {
		int origen, destino;
		char coma;

		while (archivoEntrada >> origen) {
			archivoEntrada >> coma;
			archivoEntrada >> destino;

			if (origen >= 0 && origen < MAX_TAMANO && destino >= 0 && destino < MAX_TAMANO) {
				matriz[origen][destino] = 1;
				matriz[destino][origen] = 1; 

				if (origen >= nodosExistentes) nodosExistentes = origen + 1;
				if (destino >= nodosExistentes) nodosExistentes = destino + 1;
			}
		}
		archivoEntrada.close();
		cout << "Datos cargados correctamente. Nodos detectados: " << nodosExistentes << endl;
	} else {
		cout << "No se encontro grafo_datos.txt, se iniciara vacio (0 nodos)." << endl;
	}

	int opcion = 0;
	while (opcion != 3) {
		cout << "\n--- MENU GRAFO (Actual: " << nodosExistentes << " nodos) ---" << endl;
		cout << "1. Agregar conexion" << endl;
		cout << "2. Mostrar matriz y conexiones" << endl;
		cout << "3. Salir" << endl;
		cout << "Elige una opcion: ";
		cin >> opcion;

		switch (opcion) {
		case 1: {
			int o, d;
			cout << "Ingresa el nodo origen (0 a " << MAX_TAMANO - 1 << "): ";
			cin >> o;
			cout << "Ingresa el nodo destino (0 a " << MAX_TAMANO - 1 << "): ";
			cin >> d;

			if (o >= 0 && o < MAX_TAMANO && d >= 0 && d < MAX_TAMANO) {
				matriz[o][d] = 1;
				matriz[d][o] = 1;

				if (o >= nodosExistentes) nodosExistentes = o + 1;
				if (d >= nodosExistentes) nodosExistentes = d + 1;

				ofstream archivoSalida("grafo_datos.txt", ios::app);
				archivoSalida << o << "," << d << endl;
				archivoSalida.close();

				cout << "Conexion agregada y guardada con exito." << endl;
			} else {
				cout << "Error: Nodos fuera de limite de seguridad." << endl;
			}
			break;
		}
		case 2: {
			if (nodosExistentes == 0) {
				cout << "\n(El grafo esta vacio, no hay datos que mostrar)" << endl;
			} else {

				cout << "\n--- MATRIZ DE ADYACENCIA ---" << endl;
				for (int i = 0; i < nodosExistentes; i++) {
					for (int j = 0; j < nodosExistentes; j++) {
						cout << matriz[i][j] << " ";
					}
					cout << endl;
				}

				cout << "\n--- LISTA DE CONEXIONES DETECTADAS ---" << endl;
				for (int i = 0; i < nodosExistentes; i++) {
					cout << "Nodo [" << i << "] esta conectado con: ";
					bool tieneConexiones = false;

					for (int j = 0; j < nodosExistentes; j++) {
						if (matriz[i][j] == 1) {
							cout << "-> " << j << " ";
							tieneConexiones = true;
						}
					}

					if (!tieneConexiones) {
						cout << "ninguno";
					}
					cout << endl;
				}
				cout << "--------------------------------------" << endl;
			}
			break;
		}
		case 3:
			cout << "Saliendo del programa..." << endl;
			break;
		default:
			cout << "Opcion invalida. Intenta de nuevo." << endl;
		}
	}

	return 0;
}