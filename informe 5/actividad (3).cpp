#include <iostream>
#include <string>
using namespace std;
// Clase Fecha
class Fecha {
private:
    int dia;
    int mes;
    int anio;

public:
    Fecha(int d, int m, int a) : dia(d), mes(m), anio(a) {}

    void mostrar() const {
        cout << dia << "/" << mes << "/" << anio << endl;
    }
};
// Clase Contrato
class Contrato {
private:
    string codigo;
    string descripcion;
    Fecha fechaInicio;
public:
    Contrato(string cod, string desc, Fecha fecha)
        : codigo(cod), descripcion(desc), fechaInicio(fecha) {}

    void mostrar() const {
        cout << "Código: " << codigo << endl;
        cout << "Descripción: " << descripcion << endl;
        cout << "Fecha de inicio: ";
        fechaInicio.mostrar();
    }
};
// Clase Empleado
class Empleado {
private:
    string nombre;
    Contrato contrato;
public:
    Empleado(string nom, Contrato cont)
        : nombre(nom), contrato(cont) {}

    void mostrar() const {
        cout << "Empleado: " << nombre << endl;
        contrato.mostrar();
    }
};
int main() {
    string nombreEmpleado, codigoContrato, descripcionContrato;
    int dia, mes, anio;
    cout << "Ingrese el nombre del empleado: ";
    getline(cin, nombreEmpleado);
    cout << "Ingrese el código del contrato: ";
    getline(cin, codigoContrato);
    cout << "Ingrese la descripción del contrato: ";
    getline(cin, descripcionContrato);
    cout << "Ingrese la fecha de inicio del contrato (día mes año): ";
    cin >> dia >> mes >> anio;
    Fecha fechaInicio(dia, mes, anio);
    Contrato contrato(codigoContrato, descripcionContrato, fechaInicio);
    Empleado empleado(nombreEmpleado, contrato);
    cout << "\n--- INFORMACIÓN DEL EMPLEADO ---\n";
    empleado.mostrar();
    return 0;
}
