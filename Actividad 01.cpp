#include <iostream>
using namespace std;

struct Producto {
    string nombre;
    float precio;
    int cantidad;
};

struct Pedido {
    string nombreProducto;
    int cantidad;
};

void registrarProducto(Producto &p) {
    cout << "Nombre del producto: ";
    cin >> p.nombre;
    cout << "Precio: ";
    cin >> p.precio;
    cout << "Cantidad en inventario: ";
    cin >> p.cantidad;
}

void registrarPedido(Pedido &ped) {
    cout << "Producto solicitado: ";
    cin >> ped.nombreProducto;
    cout << "Cantidad solicitada: ";
    cin >> ped.cantidad;
}

void mostrarProducto(Producto p) {
    cout << "\nProducto: " << p.nombre << " - Precio: " << p.precio << " - Cantidad: " << p.cantidad << "\n";
}

void mostrarPedido(Pedido ped) {
    cout << "\nPedido: " << ped.nombreProducto << " - Cantidad: " << ped.cantidad << "\n";
}

int main() {
    Producto p;
    Pedido ped;
    int opcion;

    do {
        cout << "\n1. Registrar producto\n2. Registrar pedido\n3. Mostrar producto\n4. Mostrar pedido\n5. Salir\nOpcion: ";
        cin >> opcion;
        
        if (opcion == 1) {
            registrarProducto(p);
        } else if (opcion == 2) {
            registrarPedido(ped);
        } else if (opcion == 3) {
            mostrarProducto(p);
        } else if (opcion == 4) {
            mostrarPedido(ped);
        }
    } while (opcion != 5);

    return 0;
}
