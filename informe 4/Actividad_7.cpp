#include <iostream>
#include <string>
using namespace std;
class Empleado {
public:
    string nombre;
    double salario;
    Empleado(string nombre, double salario) : nombre(nombre), salario(salario) {}
    virtual void mostrarInfo() const {
        cout << "Empleado: " << nombre << ", Salario: " << salario << endl;
    }
    virtual ~Empleado() {
        cout << "Destructor de Empleado" << endl;
    }
};
class Gerente : public Empleado {
public:
    string departamento;
    Gerente(string nombre, double salario, string departamento) : Empleado(nombre, salario), departamento(departamento) {}
    void mostrarInfo() const override {
        Empleado::mostrarInfo();
        cout << "Departamento: " << departamento << endl;
    }
    ~Gerente() {
        cout << "Destructor de Gerente" << endl;
    }
};
class Secretario : public Empleado {
public:
    string area;
    Secretario(string nombre, double salario, string area) : Empleado(nombre, salario), area(area) {}
    void mostrarInfo() const override {
        Empleado::mostrarInfo();
        cout << "Area: " << area << endl;
    }
    ~Secretario() {
        cout << "Destructor de Secretario" << endl;
    }
};
int main() {
    Gerente* gerente1 = new Gerente("Carlos Ruiz", 5000.0, "Ventas");
    Secretario* secretario1 = new Secretario("Ana Gomez", 2000.0, "Administracion");
    cout << "\nInformacion del Gerente:" << endl;
    gerente1->mostrarInfo();
    cout << "\nInformacion del Secretario:" << endl;
    secretario1->mostrarInfo();
    delete gerente1;
    delete secretario1;

    return 0;
}

