#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_NODOS = 20;

int main() {
	string nombresVertices[MAX_NODOS];
	int matriz[MAX_NODOS][MAX_NODOS] = {0};
	int totalVertices = 0;

	string nodoInicialGeneral = "N/A";
	string nodoFinalGeneral = "N/A";
	bool primerNodoRegistrado = false;

	ifstream archivoEntrada("digrafo_datos.txt");
	if (archivoEntrada.is_open()) {
		string linea;
		while (getline(archivoEntrada, linea)) {
			if (linea.empty()) continue;

			size_t posComa = linea.find(',');
			if (posComa == string::npos) continue;

			string origen = linea.substr(0, posComa);
			string destino = linea.substr(posComa + 1);

			if (origen.empty() || destino.empty()) continue;

			if (!primerNodoRegistrado) {
				nodoInicialGeneral = origen;
				primerNodoRegistrado = true;
			}
			nodoFinalGeneral = destino;

			int indiceOrigen = -1;
			for (int i = 0; i < totalVertices; i++) {
				if (nombresVertices[i] == origen) indiceOrigen = i;
			}
			if (indiceOrigen == -1 && totalVertices < MAX_NODOS) {
				indiceOrigen = totalVertices;
				nombresVertices[totalVertices] = origen;
				totalVertices++;
			}

			int indiceDestino = -1;
			for (int i = 0; i < totalVertices; i++) {
				if (nombresVertices[i] == destino) indiceDestino = i;
			}
			if (indiceDestino == -1 && totalVertices < MAX_NODOS) {
				indiceDestino = totalVertices;
				nombresVertices[totalVertices] = destino;
				totalVertices++;
			}

			if (indiceOrigen != -1 && indiceDestino != -1) {
				matriz[indiceOrigen][indiceDestino] = 1;
			}
		}
		archivoEntrada.close();
	} else {
		cout << "Error: No se pudo abrir el archivo 'digrafo_datos.txt'." << endl;
		return 1;
	}

	if (totalVertices == 0) {
		cout << "El digrafo esta vacio." << endl;
		return 0;
	}

	cout << "============================================" << endl;
	cout << "      PROPIEDADES GENERALES DEL DIGRAFO     " << endl;
	cout << "============================================" << endl;
	cout << "NODO INICIAL GENERAL : " << nodoInicialGeneral << endl;
	cout << "NODO FINAL GENERAL   : " << nodoFinalGeneral << endl;
	cout << "--------------------------------------------" << endl;

	cout << "VERTICES (NODOS) -> V = { ";
	for (int i = 0; i < totalVertices; i++) {
		cout << nombresVertices[i] << (i == totalVertices - 1 ? "" : ", ");
	}
	cout << " }" << endl;
	cout << "--------------------------------------------" << endl;

	cout << "\n=== CALCULO DE LA RUTA MAS RAPIDA ===" << endl;
	string inicioBuscar, finBuscar;
	cout << "Escribe el Nodo de SALIDA: ";
	cin >> inicioBuscar;
	cout << "Escribe el Nodo de LLEGADA: ";
	cin >> finBuscar;

	int idxInicio = -1, idxFin = -1;
	for (int i = 0; i < totalVertices; i++) {
		if (nombresVertices[i] == inicioBuscar) idxInicio = i;
		if (nombresVertices[i] == finBuscar) idxFin = i;
	}

	if (idxInicio == -1 || idxFin == -1) {
		cout << "\nError: Uno o ambos nodos no existen en el digrafo." << endl;
	} else if (idxInicio == idxFin) {
		cout << "\nYa estas en el destino. Ruta: " << inicioBuscar << endl;
	} else {
		int cola[MAX_NODOS];
		int frente = 0, finalCola = 0;
		int visitado[MAX_NODOS] = {0};
		int padre[MAX_NODOS];
		for(int i = 0; i < totalVertices; i++) padre[i] = -1;

		cola[finalCola++] = idxInicio;
		visitado[idxInicio] = 1;
		bool encontrado = false;

		while (frente < finalCola) {
			int actual = cola[frente++];
			if (actual == idxFin) {
				encontrado = true;
				break;
			}
			for (int j = 0; j < totalVertices; j++) {
				if (matriz[actual][j] == 1 && !visitado[j]) {
					visitado[j] = 1;
					padre[j] = actual;
					cola[finalCola++] = j;
				}
			}
		}

		if (encontrado) {
			cout << "\n¡Ruta mas rapida encontrada con exito!" << endl;
			int caminoRuta[MAX_NODOS];
			int pasos = 0;
			int pasoActual = idxFin;

			while (pasoActual != -1) {
				caminoRuta[pasos++] = pasoActual;
				pasoActual = padre[pasoActual];
			}

			cout << "Trayectoria mas corta: ";
			for (int i = pasos - 1; i >= 0; i--) {
				cout << nombresVertices[caminoRuta[i]];
				if (i > 0) cout << " -> ";
			}
			cout << endl;
		} else {
			cout << "\nNo existe ninguna ruta para llegar desde '" << inicioBuscar << "' hasta '" << finBuscar << "'." << endl;
		}
	}
	cout << "============================================" << endl;

	return 0;
}