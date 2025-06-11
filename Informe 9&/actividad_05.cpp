#include <iostream>
#include <vector>
#include <memory>
#include <limits>

using namespace std;

// Clase base
class Producto {
protected:
    string nombre;
    double precio;
public:
    Producto(string n, double p) : nombre(n), precio(p) {}
    virtual ~Producto() {}
    virtual double calcularValor() const = 0;
    virtual void mostrarInfo() const = 0;
};

// Producto: Electrónico
class Electronico : public Producto {
public:
    Electronico(string n, double p) : Producto(n, p) {}
    double calcularValor() const override {
        return precio * 1.18; // 18% IGV
    }
    void mostrarInfo() const override {
        cout << "Electrónico - " << nombre << ", Precio: S/ " << precio << ", Total con IGV: S/ " << calcularValor() << endl;
    }
};

// Producto: Ropa
class Ropa : public Producto {
public:
    Ropa(string n, double p) : Producto(n, p) {}
    double calcularValor() const override {
        return precio * 0.90; // 10% de descuento
    }
    void mostrarInfo() const override {
        cout << "Ropa - " << nombre << ", Precio: S/ " << precio << ", Total con descuento: S/ " << calcularValor() << endl;
    }
};

// Producto: Alimento
class Alimento : public Producto {
public:
    Alimento(string n, double p) : Producto(n, p) {}
    double calcularValor() const override {
        return precio; // Sin cambios
    }
    void mostrarInfo() const override {
        cout << "Alimento - " << nombre << ", Precio: S/ " << precio << endl;
    }
};

// Función para validar entrada numérica
double leerDoublePositivo(string mensaje) {
    double valor;
    while (true) {
        cout << mensaje;
        cin >> valor;
        if (!cin.fail() && valor > 0) {
            break;
        } else {
            cout << "Entrada inválida. Intente nuevamente.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return valor;
}

int main() {
    vector<unique_ptr<Producto>> inventario;
    int opcion;

    do {
        cout << "\n=== MENU DE INVENTARIO ===\n";
        cout << "1. Agregar producto electrónico\n";
        cout << "2. Agregar producto de ropa\n";
        cout << "3. Agregar producto alimenticio\n";
        cout << "4. Mostrar inventario\n";
        cout << "5. Calcular valor total del inventario\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (cin.fail()) {
            cout << "Entrada no válida.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        string nombre;
        double precio;

        switch (opcion) {
            case 1:
                cout << "Nombre del producto: ";
                cin.ignore();
                getline(cin, nombre);
                precio = leerDoublePositivo("Precio del producto: S/ ");
                inventario.push_back(unique_ptr<Producto>(new Electronico(nombre, precio)));
                break;
            case 2:
                cout << "Nombre del producto: ";
                cin.ignore();
                getline(cin, nombre);
                precio = leerDoublePositivo("Precio del producto: S/ ");
                inventario.push_back(unique_ptr<Producto>(new Ropa(nombre, precio)));
                break;
            case 3:
                cout << "Nombre del producto: ";
                cin.ignore();
                getline(cin, nombre);
                precio = leerDoublePositivo("Precio del producto: S/ ");
                inventario.push_back(unique_ptr<Producto>(new Alimento(nombre, precio)));
                break;
            case 4:
                cout << "\n=== LISTA DE PRODUCTOS ===\n";
                for (size_t i = 0; i < inventario.size(); ++i) {
                    cout << i + 1 << ". ";
                    inventario[i]->mostrarInfo();
                }
                break;
            case 5: {
                double total = 0;
                for (size_t i = 0; i < inventario.size(); ++i) {
                    total += inventario[i]->calcularValor();
                }
                cout << "\nValor total del inventario: S/ " << total << endl;
                break;
            }
            case 0:
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while (opcion != 0);

    return 0;
}
