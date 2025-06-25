#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void mostrarContenidoArchivo() {
    string nombreArchivo;
    cout << "Ingrese el nombre del archivo de texto (con extensión): ";
    getline(cin, nombreArchivo);
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cout << "Error: No se pudo abrir el archivo '" << nombreArchivo << "'." << endl;
        return;
    }
    cout << "\nContenido del archivo:\n\n";
    string linea;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }
    archivo.close();
}
int main() {
    int opcion;
    do {
        cout << "\n--- MENÚ ---" << endl;
        cout << "1. Leer archivo de texto" << endl;
        cout << "2. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();
        switch (opcion) {
            case 1:
                mostrarContenidoArchivo();
                break;
            case 2:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
        }
    } while (opcion != 2);
    return 0;
}
