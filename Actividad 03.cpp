#include <iostream>
#include <vector>
using namespace std;

struct Producto {
    string nombre;
    float precio;
    int cantidad;
};

struct Pedido {
    Producto productos[10]; // Capacidad máxima de 10 productos por pedido
    int numProductos = 0;
    
    void agregarProducto(const Producto &p) {
        if (numProductos < 10) {
            productos[numProductos] = p;
            numProductos++;
        } else {
            cout << "No se pueden agregar más productos al pedido.\n";
        }
    }
};

class GestorDeInventario {
private:
    Producto inventario[100]; // Capacidad máxima de 100 productos en inventario
    int numProductos = 0;

public:
    void agregarProducto(const Producto &p) {
        if (numProductos < 100) {
            inventario[numProductos] = p;
            numProductos++;
        } else {
            cout << "Inventario lleno, no se pueden agregar más productos.\n";
        }
    }

    void actualizarInventario(const Pedido &pedido) {
        for (int i = 0; i < pedido.numProductos; i++) {
            for (int j = 0; j < numProductos; j++) {
                if (inventario[j].nombre == pedido.productos[i].nombre) {
                    if (inventario[j].cantidad >= pedido.productos[i].cantidad) {
                        inventario[j].cantidad -= pedido.productos[i].cantidad;
                    } else {
                        cout << "No hay suficiente stock de " << inventario[j].nombre << "\n";
                    }
                }
            }
        }
    }

    void mostrarInventario() {
        cout << "\nInventario Actual:\n";
        for (int i = 0; i < numProductos; i++) {
            cout << "Producto: " << inventario[i].nombre << " - Precio: " << inventario[i].precio << " - Cantidad: " << inventario[i].cantidad << "\n";
        }
    }
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
    Producto p;
    cout << "Producto solicitado: ";
    cin >> p.nombre;
    cout << "Cantidad solicitada: ";
    cin >> p.cantidad;
    ped.agregarProducto(p);
}

int main() {
    GestorDeInventario gestor;
    int opcion;

    do {
        cout << "\n1. Registrar producto\n2. Registrar pedido\n3. Mostrar inventario\n4. Salir\nOpcion: ";
        cin >> opcion;
        
        if (opcion == 1) {
            Producto p;
            registrarProducto(p);
            gestor.agregarProducto(p);
        } else if (opcion == 2) {
            Pedido ped;
            registrarPedido(ped);
            gestor.actualizarInventario(ped);
        } else if (opcion == 3) {
            gestor.mostrarInventario();
        }
    } while (opcion != 4);

    return 0;
}

