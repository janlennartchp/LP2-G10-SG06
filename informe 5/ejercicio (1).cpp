#include <iostream>
#include <string>
using namespace std;
class Producto {
private:
    string nombre;
    float precio;
    float descuento;
public:
    Producto() : nombre(""), precio(0.0), descuento(0.0) {}
    Producto& setNombre(const string& n) {
        nombre = n;
        return *this;
    }
    Producto& setPrecio(float p) {
        precio = p;
        return *this;
    }
    Producto& setDescuento(float d) {
        descuento = d;
        return *this;
    }
    float calcularPrecioFinal() const {
        return precio * (1 - descuento / 100.0);
    }
    void mostrar() const {
        cout << "Producto: " << nombre
             << " | Precio: $" << precio
             << " | Descuento: " << descuento << "%"
             << " | Precio Final: $" << calcularPrecioFinal() << endl;
    }
};
int main() {
    const int MAX = 100;
    Producto productos[MAX];
    int cantidad = 0;
    int opcion;
    do {
        cout << "\n===== MENÚ DE PRODUCTOS =====" << endl;
        cout << "1. Agregar producto" << endl;
        cout << "2. Mostrar productos y total" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();
        if (opcion == 1) {
            if (cantidad >= MAX) {
                cout << "Límite de productos alcanzado." << endl;
                continue;
            }
            string nombre;
            float precio, descuento;
            cout << "Ingrese nombre del producto: ";
            getline(cin, nombre);
            cout << "Ingrese precio del producto: ";
            cin >> precio;
            cout << "Ingrese descuento (%): ";
            cin >> descuento;
            cin.ignore();
            productos[cantidad].setNombre(nombre).setPrecio(precio).setDescuento(descuento);
            cantidad++;
            cout << "Producto agregado correctamente." << endl;
        }
        else if (opcion == 2) {
            float total = 0;

            if (cantidad == 0) {
                cout << "No hay productos registrados." << endl;
            } else {
                cout << "\n=== LISTA DE PRODUCTOS ===" << endl;
                for (int i = 0; i < cantidad; ++i) {
                    productos[i].mostrar();
                    total += productos[i].calcularPrecioFinal();
                }
                cout << "\nTotal acumulado con descuentos: $" << total << endl;
            }
        }
        else if (opcion != 3) {
            cout << "Opción no válida. Intente nuevamente." << endl;
        }
    } while (opcion != 3);
    cout << "Programa finalizado." << endl;
    return 0;
}
