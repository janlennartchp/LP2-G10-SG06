#include <iostream>
#include <map>
#include <string>

using namespace std;

// Definición de estructura Contacto
struct Contacto {
    string telefono;
    string correo;
};

// Mapa para almacenar los contactos ordenados por nombre
map<string, Contacto> agenda;

void agregarContacto() {
    string nombre, telefono, correo;
    cout << "Ingrese el nombre del contacto: ";
    getline(cin, nombre);
    cout << "Ingrese el número de teléfono: ";
    getline(cin, telefono);
    cout << "Ingrese el correo electrónico: ";
    getline(cin, correo);
    
    agenda[nombre] = {telefono, correo};
    cout << "Contacto agregado correctamente.\n";
}

void buscarContacto() {
    string nombre;
    cout << "Ingrese el nombre del contacto a buscar: ";
    getline(cin, nombre);

    auto it = agenda.find(nombre);
    if (it != agenda.end()) {
        cout << "\n--- Información del Contacto ---\n";
        cout << "Nombre: " << it->first << endl;
        cout << "Teléfono: " << it->second.telefono << endl;
        cout << "Correo: " << it->second.correo << endl;
    } else {
        cout << "Contacto no encontrado.\n";
    }
}

void actualizarContacto() {
    string nombre;
    cout << "Ingrese el nombre del contacto a actualizar: ";
    getline(cin, nombre);

    auto it = agenda.find(nombre);
    if (it != agenda.end()) {
        cout << "Nuevo número de teléfono: ";
        getline(cin, it->second.telefono);
        cout << "Nuevo correo electrónico: ";
        getline(cin, it->second.correo);
        cout << "Contacto actualizado correctamente.\n";
    } else {
        cout << "Contacto no encontrado.\n";
    }
}

void mostrarContactosOrdenados() {
    if (agenda.empty()) {
        cout << "La agenda está vacía.\n";
        return;
    }

    cout << "\n--- Lista de Contactos (orden alfabético) ---\n";
    for (const auto& par : agenda) {
        cout << "Nombre: " << par.first << endl;
        cout << "Teléfono: " << par.second.telefono << endl;
        cout << "Correo: " << par.second.correo << endl;
        cout << "---------------------------\n";
    }
}

void menuContactos() {
    int opcion;
    do {
        cout << "\n--- MENÚ DE CONTACTOS ---\n";
        cout << "1. Agregar contacto\n";
        cout << "2. Buscar contacto\n";
        cout << "3. Actualizar contacto\n";
        cout << "4. Mostrar todos los contactos\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer

        switch (opcion) {
            case 1: agregarContacto(); break;
            case 2: buscarContacto(); break;
            case 3: actualizarContacto(); break;
            case 4: mostrarContactosOrdenados(); break;
            case 0: cout << "Saliendo del programa...\n"; break;
            default: cout << "Opción no válida.\n";
        }

    } while (opcion != 0);
}

int main() {
    menuContactos();
    return 0;
}