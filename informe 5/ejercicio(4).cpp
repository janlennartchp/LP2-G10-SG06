#include <iostream>
using namespace std;

class Gerente {
public:
    Gerente() {
        cout << "Constructor de Gerente\n";
    }
    ~Gerente() {
        cout <<  "Destructor de Gerente\n";
    }
};

class Direccion {
public:
    Direccion() {
        cout << "Constructor de Direccion\n";
    }
    ~Direccion() {
        cout << "Destructor de Direccion\n";
    }
};

class Empresa {
private:
    Gerente gerente;
    Direccion direccion;

public:
    // Lista de inicialización
    Empresa() : gerente(), direccion() {
        cout << "Constructor de Empresa\n";
    }

    ~Empresa() {
        cout << " Destructor de Empresa\n";
    }
};

int main() {
    Empresa* empresa = nullptr;
    int opcion;

    do {
        cout << "\n=== MENÚ DE EMPRESA ===\n";
        cout << "1. Crear Empresa\n";
        cout << "2. Eliminar Empresa\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                if (empresa) {
                    cout << "Ya existe una empresa. Elimínela antes de crear otra.\n";
                } else {
                    empresa = new Empresa();
                }
                break;

            case 2:
                if (empresa) {
                    delete empresa;
                    empresa = nullptr;
                    cout << "Empresa eliminada.\n";
                } else {
                    cout << "No hay empresa que eliminar.\n";
                }
                break;

            case 3:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "opción inválida. Intente nuevamente.\n";
        }

    } while (opcion != 3);

    // Eliminación segura al salir si no se hizo antes
    if (empresa) {
        delete empresa;
        cout << "Empresa eliminada automáticamente al salir.\n";
    }

    return 0;
}
