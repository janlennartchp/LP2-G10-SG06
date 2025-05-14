#include <iostream>
#include <string>
using namespace std;
// -------- Clase Base: Persona --------
class Persona {
protected:
    string nombre;
    string dni;
public:
    Persona(string _nombre, string _dni) : nombre(_nombre), dni(_dni) {}
    void mostrarDatos() const {
        cout << "Nombre: " << nombre << endl;
        cout << "DNI: " << dni << endl;
    }
    void mostrarNombre() const {
        cout << "Nombre (desde método protegido): " << nombre << endl;
    }
};
// -------- Clase Derivada con Herencia Pública --------
class ClientePublico : public Persona {
public:
    ClientePublico(string _nombre, string _dni) : Persona(_nombre, _dni) {}
    void mostrarDatosCliente() {
        mostrarDatos();
    }
};
// -------- Clase Derivada con Herencia Protegida --------
class ClienteProtegido : protected Persona {
public:
    ClienteProtegido(string _nombre, string _dni) : Persona(_nombre, _dni) {}
    void mostrarDatosCliente() {
        mostrarDatos(); 
    }
    void mostrarNombreCliente() {
        mostrarNombre();
    }
};
// -------- Clase Derivada con Herencia Privada --------
class ClientePrivado : private Persona {
public:
    ClientePrivado(string _nombre, string _dni) : Persona(_nombre, _dni) {}
    void mostrarDatosCliente() {
        mostrarDatos();
    }
};
// -------- Función Principal --------
int main() {
    ClientePublico cliente1("Carlos", "12345678");
    cout << "--- CLIENTE PUBLICO ---" << endl;
    cliente1.mostrarDatosCliente();
    ClienteProtegido cliente2("Ana", "23456789");
    cout << "\n--- CLIENTE PROTEGIDO ---" << endl;
    cliente2.mostrarDatosCliente();
    cliente2.mostrarNombreCliente();
    ClientePrivado cliente3("Luis", "34567890");
    cout << "\n--- CLIENTE PRIVADO ---" << endl;
    cliente3.mostrarDatosCliente();
    return 0;
}
