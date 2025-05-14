#include <iostream>
#include <string>
using namespace std;
// -------- Clase Base: Cliente --------
class Cliente {
protected:
    string nombre;
    string dni;
    double saldo;
    string email;
    string infoEncriptada;
    string encriptar(const string& texto) const {
        string resultado = texto;
        for (char& c : resultado) {
            c += 1;
        }
        return resultado;
    }
public:
    // Constructor
    Cliente(string _nombre, string _dni, double _saldo, string _email)
        : nombre(_nombre), dni(_dni), saldo(_saldo), email(_email) {}
    void mostrarDatos() const {
        cout << "Nombre: " << nombre << endl;
        cout << "DNI: " << dni << endl;
        cout << "Saldo: $" << saldo << endl;
        cout << "Email: " << email << endl;
    }
};
// -------- Clase Derivada: ClienteSeguro --------
class ClienteSeguro : public Cliente {
public:
    ClienteSeguro(string _nombre, string _dni, double _saldo, string _email)
        : Cliente(_nombre, _dni, _saldo, _email) {
        // Usando el método protegido para encriptar y guardar
        infoEncriptada = encriptar(nombre + dni + email);
    }
    void mostrarInfoEncriptada() const {
        cout << "Información encriptada: " << infoEncriptada << endl;
    }
    bool verificarAutenticidad(const string& n, const string& d, const string& e) const {
        return encriptar(n + d + e) == infoEncriptada;
    }
};
// -------- Función principal --------
int main() {
    ClienteSeguro cliente1("Luis", "98765432", 20000.0, "luis@mail.com");
    cout << "\n=== DATOS DEL CLIENTE ===" << endl;
    cliente1.mostrarDatos();
    cout << "\n=== INFORMACIÓN ENCRIPTADA ===" << endl;
    cliente1.mostrarInfoEncriptada();
    cout << "\n=== VERIFICACIÓN ===" << endl;
    if (cliente1.verificarAutenticidad("Luis", "98765432", "luis@mail.com")) {
        cout << "Verificación correcta." << endl;
    } else {
        cout << "Verificación fallida." << endl;
    }
    return 0;
}
