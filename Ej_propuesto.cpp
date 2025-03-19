#include <iostream>
#include <vector>

using namespace std;

class Producto {
public:
    string nombre;
    double precio;
    int stock;

    Producto(string n, double p, int s) {
        nombre = n;
        precio = p;
        stock = s;
    }
};

class Tienda {
private:
    vector<Producto> inventario;
    vector<string> pedidos;
    double totalVentas;

public:
    Tienda() {
        totalVentas = 0.0;
    }

    void registrarProducto(string nombre, double precio, int stock) {
        inventario.push_back(Producto(nombre, precio, stock));
        cout << "Producto '" << nombre << "' registrado con éxito.\n";
    }

    void venderProducto(string nombre, int cantidad) {
        for (size_t i = 0; i < inventario.size(); i++) {
            if (inventario[i].nombre == nombre) {
                if (inventario[i].stock >= cantidad) {
                    inventario[i].stock -= cantidad;
                    totalVentas += cantidad * inventario[i].precio;
                    cout << "Venta realizada: " << cantidad << " de " << nombre << endl;
                    return;
                } else {
                    cout << "Stock insuficiente para " << nombre << endl;
                    return;
                }
            }
        }
        cout << "Producto no encontrado.\n";
    }

    void registrarPedido(string nombre) {
        for (size_t i = 0; i < inventario.size(); i++) {
            if (inventario[i].nombre == nombre) {
                pedidos.push_back(nombre);
                cout << "Pedido registrado: " << nombre << endl;
                return;
            }
        }
        cout << "El producto no existe.\n";
    }

    void notificarPedidos() {
        if (pedidos.empty()) {
            cout << "\nNo hay pedidos pendientes.\n";
            return;
        }
        cout << "\nPedidos listos:\n";
        for (size_t i = 0; i < pedidos.size(); i++) {
            cout << "- " << pedidos[i] << endl;
        }
        pedidos.clear();
    }

    void mostrarInventario() {
        cout << "\nInventario:\n";
        if (inventario.empty()) {
            cout << "No hay productos en el inventario.\n";
            return;
        }
        for (size_t i = 0; i < inventario.size(); i++) {
            cout << inventario[i].nombre << " | Precio: S/ " << inventario[i].precio << " | Stock: " << inventario[i].stock << endl;
        }
    }

    void mostrarVentas() {
        cout << "\nTotal ventas: S/ " << totalVentas << endl;
    }
};

int main() {
    Tienda tienda;

    int opcion;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Registrar Producto\n";
        cout << "2. Vender Producto\n";
        cout << "3. Registrar Pedido\n";
        cout << "4. Notificar Pedidos\n";
        cout << "5. Mostrar Inventario\n";
        cout << "6. Mostrar Ventas\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            string nombre;
            double precio;
            int stock;
            cout << "Ingrese nombre del producto: ";
            cin >> nombre;
            cout << "Ingrese precio del producto: ";
            cin >> precio;
            cout << "Ingrese stock del producto: ";
            cin >> stock;
            tienda.registrarProducto(nombre, precio, stock);
        } else if (opcion == 2) {
            string nombre;
            int cantidad;
            cout << "Ingrese nombre del producto a vender: ";
            cin >> nombre;
            cout << "Ingrese cantidad a vender: ";
            cin >> cantidad;
            tienda.venderProducto(nombre, cantidad);
        } else if (opcion == 3) {
            string nombre;
            cout << "Ingrese nombre del producto a pedir: ";
            cin >> nombre;
            tienda.registrarPedido(nombre);
        } else if (opcion == 4) {
            tienda.notificarPedidos();
        } else if (opcion == 5) {
            tienda.mostrarInventario();
        } else if (opcion == 6) {
            tienda.mostrarVentas();
        } else if (opcion == 7) {
            cout << "Saliendo del programa...\n";
        } else {
            cout << "Opción inválida. Intente nuevamente.\n";
        }

    } while (opcion != 7);

    return 0;
}



