#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Clase FechaRegistro
class FechaRegistro {
private:
    int dia, mes, anio;
public:
    FechaRegistro(int d = 1, int m = 1, int a = 2000) : dia(d), mes(m), anio(a) {}

    void mostrarFecha() const {
        cout << dia << "/" << mes << "/" << anio;
    }
};
// Clase Direccion
class Direccion {
private:
    string calle;
    string ciudad;
    string pais;
public:
    Direccion(string c = "", string ciu = "", string p = "") : calle(c), ciudad(ciu), pais(p) {}

    void mostrarDireccion() const {
        cout << "Dirección: " << calle << ", " << ciudad << ", " << pais << endl;
    }
};
// Clase Cliente
class Cliente {
private:
    string nombre;
    FechaRegistro fecha;
    Direccion direccion;
public:
    Cliente(string nom = "", int d = 1, int m = 1, int a = 2000,
            string calle = "", string ciudad = "", string pais = "")
        : nombre(nom), fecha(d, m, a), direccion(calle, ciudad, pais) {}
    void mostrarCliente() const {
        cout << "Nombre: " << nombre << endl;
        direccion.mostrarDireccion();
        cout << "Fecha de Registro: ";
        fecha.mostrarFecha();
        cout << endl;
    }
    static Cliente crearDesdeInput() {
        string nom, calle, ciudad, pais;
        int d, m, a;
        cout << "Ingrese nombre del cliente: ";
        getline(cin, nom);
        cout << "Ingrese calle: ";
        getline(cin, calle);
        cout << "Ingrese ciudad: ";
        getline(cin, ciudad);
        cout << "Ingrese país: ";
        getline(cin, pais);
        cout << "Ingrese día de registro: ";
        cin >> d;
        cout << "Ingrese mes de registro: ";
        cin >> m;
        cout << "Ingrese año de registro: ";
        cin >> a;
        cin.ignore(); 
        return Cliente(nom, d, m, a, calle, ciudad, pais);
    }
};
// Función principal
int main() {
    vector<Cliente> clientes;
    int opcion;
    do {
        cout << "\n===== MENÚ CLIENTES =====" << endl;
        cout << "1. Ingresar clientes" << endl;
        cout << "2. Mostrar todos los clientes" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();
        switch (opcion) {
        case 1: {
            int n;
            cout << "¿Cuántos clientes desea ingresar?: ";
            cin >> n;
            cin.ignore();
            for (int i = 0; i < n; ++i) {
                cout << "\n--- Cliente #" << (i + 1) << " ---" << endl;
                clientes.push_back(Cliente::crearDesdeInput());
            }
            break;
        }
        case 2:
            if (clientes.empty()) {
                cout << "No hay clientes registrados." << endl;
            } else {
                cout << "\n=== LISTA DE CLIENTES ===" << endl;
                for (size_t i = 0; i < clientes.size(); ++i) {
                    cout << "\nCliente #" << (i + 1) << ":\n";
                    clientes[i].mostrarCliente();
                }
            }
            break;
        case 3:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opción inválida. Intente nuevamente." << endl;
        }

    } while (opcion != 3);
    return 0;
}
