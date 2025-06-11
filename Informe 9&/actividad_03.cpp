#include <iostream>
#include <vector>
#include <memory>
#include <limits>
using namespace std;
class Empleado {
public:
    virtual double calcularSalario() const = 0;
    virtual string tipoEmpleado() const = 0;
    virtual ~Empleado() {}
};
class Asalariado : public Empleado {
private:
    double salarioMensual;
public:
    Asalariado(double salario) : salarioMensual(salario) {}
    double calcularSalario() const override {
        return salarioMensual;
    }
    string tipoEmpleado() const override {
        return "Asalariado";
    }
};
class PorHora : public Empleado {
private:
    double horasTrabajadas;
    double tarifaPorHora;
public:
    PorHora(double horas, double tarifa) : horasTrabajadas(horas), tarifaPorHora(tarifa) {}
    double calcularSalario() const override {
        return horasTrabajadas * tarifaPorHora;
    }
    string tipoEmpleado() const override {
        return "Por Hora";
    }
};
class Comisionista : public Empleado {
private:
    double ventasRealizadas;
    double porcentajeComision;
public:
    Comisionista(double ventas, double porcentaje) : ventasRealizadas(ventas), porcentajeComision(porcentaje) {}
    double calcularSalario() const override {
        return ventasRealizadas * porcentajeComision / 100.0;
    }
    string tipoEmpleado() const override {
        return "Comisionista";
    }
};
void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
int main() {
    vector<shared_ptr<Empleado>> empleados;
    int opcion;
    do {
        cout << "\n=== MENU SISTEMA DE NOMINA ===\n";
        cout << "1. Agregar Asalariado\n";
        cout << "2. Agregar Empleado por Hora\n";
        cout << "3. Agregar Comisionista\n";
        cout << "4. Mostrar Salarios\n";
        cout << "0. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        if (cin.fail()) {
            cout << "\n[Error] Ingrese un número válido.\n";
            limpiarBuffer();
            continue;
        }

        switch (opcion) {
        case 1: {
            double salario;
            cout << "Ingrese salario mensual: ";
            cin >> salario;
            if (cin.fail() || salario < 0) {
                cout << "[Error] Ingrese un salario válido.\n";
                limpiarBuffer();
                break;
            }
            empleados.push_back(make_shared<Asalariado>(salario));
            break;
        }
        case 2: {
            double horas, tarifa;
            cout << "Ingrese horas trabajadas: ";
            cin >> horas;
            cout << "Ingrese tarifa por hora: ";
            cin >> tarifa;
            if (cin.fail() || horas < 0 || tarifa < 0) {
                cout << "[Error] Ingrese datos válidos.\n";
                limpiarBuffer();
                break;
            }
            empleados.push_back(make_shared<PorHora>(horas, tarifa));
            break;
        }
        case 3: {
            double ventas, porcentaje;
            cout << "Ingrese ventas realizadas: ";
            cin >> ventas;
            cout << "Ingrese porcentaje de comisión: ";
            cin >> porcentaje;
            if (cin.fail() || ventas < 0 || porcentaje < 0) {
                cout << "[Error] Ingrese datos válidos.\n";
                limpiarBuffer();
                break;
            }
            empleados.push_back(make_shared<Comisionista>(ventas, porcentaje));
            break;
        }
        case 4: {
            if (empleados.empty()) {
                cout << "No hay empleados registrados.\n";
                break;
            }
            cout << "\n=== SALARIOS ===\n";
            for (size_t i = 0; i < empleados.size(); ++i) {
                cout << i + 1 << ". Tipo: " << empleados[i]->tipoEmpleado()
                     << ", Salario: S/ " << empleados[i]->calcularSalario() << endl;
            }
            break;
        }
        case 0:
            cout << "Saliendo del sistema...\n";
            break;
        default:
            cout << "[Error] Opción no válida.\n";
        }
    } while (opcion != 0);
    return 0;
}
