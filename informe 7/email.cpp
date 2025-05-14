#include <iostream>
#include <string>
using namespace std;
// -------- Clase base: Persona --------
class Persona {
protected:
    string email;
public:
    string nombre;
    int edad;
    double salario;
    Persona(string _nombre, int _edad, double _salario, string _email)
        : nombre(_nombre), edad(_edad), salario(_salario), email(_email) {}
    void mostrarDatosBasicos() const {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Salario: $" << salario << endl;
    }
};
// -------- Clase derivada: Empleado --------
class Empleado : public Persona {
public:
    Empleado(string _nombre, int _edad, double _salario, string _email)
        : Persona(_nombre, _edad, _salario, _email) {}
    void mostrarEmailEmpleado() const {
        cout << "Email del empleado: " << email << endl;
    }
};
// -------- Clase derivada: Cliente --------
class Cliente : public Persona {
public:
    Cliente(string _nombre, int _edad, double _salario, string _email)
        : Persona(_nombre, _edad, _salario, _email) {}

    void mostrarEmailCliente() const {
        cout << "Email del cliente: " << email << endl;
    }
};
// -------- Función principal --------
int main() {
    Empleado emp("Laura", 30, 3500.0, "laura@empresa.com");
    Cliente cli("Pedro", 25, 0.0, "pedro@hotmail.com");
    cout << "\n--- DATOS DEL EMPLEADO ---" << endl;
    emp.mostrarDatosBasicos();
    emp.mostrarEmailEmpleado();
    cout << "\n--- DATOS DEL CLIENTE ---" << endl;
    cli.mostrarDatosBasicos();
    cli.mostrarEmailCliente();
    return 0;
}

