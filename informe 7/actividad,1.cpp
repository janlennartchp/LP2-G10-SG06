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
public:
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
private:
    string infoEncriptada;
    string encriptar(const string& texto) const {
        string resultado = texto;
        for (char& c : resultado) {
            c += 1;
        }
        return resultado;
    }
public:
    ClienteSeguro(string _nombre, string _dni, double _saldo, string _email)
        : Cliente(_nombre, _dni, _saldo, _email) {
        infoEncriptada = encriptar(nombre + dni + email);
    }
    bool verificarAutenticidad(const string& n, const string& d, const string& e) const {
        string intento = encriptar(n + d + e);
        return intento == infoEncriptada;
    }
    void mostrarInfoEncriptada() const {
        cout << "Información encriptada: " << infoEncriptada << endl;
    }
};
// -------- Función principal --------
int main() {
    ClienteSeguro cliente1("Ana", "12345678", 15000.75, "ana@mail.com");
    cout << "\n=== DATOS DEL CLIENTE ===" << endl;
    cliente1.mostrarDatos();
    cout << "\n=== INFORMACIÓN ENCRIPTADA ===" << endl;
    cliente1.mostrarInfoEncriptada();
    cout << "\n=== VERIFICACIÓN DE AUTENTICIDAD ===" << endl;
    if (cliente1.verificarAutenticidad("Ana", "12345678", "ana@mail.com")) {
        cout << "Cliente verificado correctamente." << endl;
    } else {
        cout << "Datos incorrectos. Verificación fallida." << endl;
    }
    return 0;
}
