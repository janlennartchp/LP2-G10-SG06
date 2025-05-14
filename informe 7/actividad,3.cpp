#include <iostream>
#include <string>
using namespace std;
// -------- Clase Base: Persona --------
class Persona {
protected:
    string nombre;
    string dni;
    double saldo;
public:
    Persona(string _nombre, string _dni, double _saldo)
        : nombre(_nombre), dni(_dni), saldo(_saldo) {
        cout << "Constructor de Persona: " << nombre << " creado." << endl;
    }
    virtual ~Persona() {
        cout << "Destructor de Persona: " << nombre << " destruido." << endl;
    }
    void mostrarDatos() const {
        cout << "Nombre: " << nombre << endl;
        cout << "DNI: " << dni << endl;
        cout << "Saldo: $" << saldo << endl;
    }
};
// -------- Clase Derivada: Cliente --------
class Cliente : public Persona {
private:
    string email;
public:
    Cliente(string _nombre, string _dni, double _saldo, string _email)
        : Persona(_nombre, _dni, _saldo), email(_email) {
        cout << "Constructor de Cliente: " << nombre << " creado." << endl;
    }
    ~Cliente() {
        cout << "Destructor de Cliente: " << nombre << " destruido." << endl;
    }
    void mostrarEmail() const {
        cout << "Email: " << email << endl;
    }
    void mostrarDatosCompletos() const {
        mostrarDatos();
        mostrarEmail();
    }
};
// -------- Función Principal --------
int main() {
    Cliente cliente1("Juan", "98765432", 2500.0, "juan@mail.com");
    cout << "\n--- DATOS DEL CLIENTE ---" << endl;
    cliente1.mostrarDatosCompletos();
    return 0;
}
