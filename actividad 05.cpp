#include <iostream>
#include <vector>
#include <iomanip>
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

    Producto* obtenerInventario() {
        return inventario;
    }

    int obtenerNumProductos() {
        return numProductos;
    }

    Producto* buscarProductoPorNombre(const string &nombre) {
        for (int i = 0; i < numProductos; i++) {
            if (inventario[i].nombre == nombre) {
                return &inventario[i];
            }
        }
        return nullptr; // Si no se encuentra el producto
    }
};

class GeneradorDeReportes {
private:
    vector<Pedido> pedidosHistorial;
    GestorDeInventario* gestorDeInventario;

public:
    GeneradorDeReportes(GestorDeInventario* gestor) : gestorDeInventario(gestor) {}

    // Registrar un pedido
    void agregarPedido(const Pedido &pedido) {
        pedidosHistorial.push_back(pedido);
        gestorDeInventario->actualizarInventario(pedido);
    }

    // Generar reporte de ventas
    void reporteVentas() {
        float ventasTotales = 0;
        for (const auto &pedido : pedidosHistorial) {
            for (int i = 0; i < pedido.numProductos; i++) {
                ventasTotales += pedido.productos[i].precio * pedido.productos[i].cantidad;
            }
        }
        cout << "Ventas Totales: " << ventasTotales << "\n";
    }

    // Generar reporte de inventario bajo
    void reporteInventarioBajo(int umbral) {
        cout << "Productos con inventario bajo (menor a " << umbral << " unidades):\n";
        Producto* inventario = gestorDeInventario->obtenerInventario();
        int numProductos = gestorDeInventario->obtenerNumProductos();

        for (int i = 0; i < numProductos; i++) {
            if (inventario[i].cantidad < umbral) {
                cout << "Producto: " << inventario[i].nombre << " - Cantidad: " << inventario[i].cantidad << "\n";
            }
        }
    }

    // Generar reporte general
    void reporteGeneral() {
        cout << "\nReporte General:\n";
        reporteVentas();
        reporteInventarioBajo(10);  // Umbral de 10 unidades
    }
};

class Descuentos {
public:
    static float aplicarDescuento(Producto &producto, int cantidadCompra, float porcentajeDescuento) {
        if (cantidadCompra > 5) { // Si la cantidad comprada es mayor a 5, se aplica descuento
            producto.precio -= producto.precio * (porcentajeDescuento / 100);
            cout << "Descuento aplicado: " << porcentajeDescuento << "%\n";
        }
        return producto.precio;
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

void registrarPedido(Pedido &ped, GestorDeInventario &gestor) {
    Producto p;
    string nombre;
    int cantidad;

    cout << "Producto solicitado: ";
    cin >> nombre;
    cout << "Cantidad solicitada: ";
    cin >> cantidad;

    p.nombre = nombre;
    p.cantidad = cantidad;
    Producto* prod = gestor.buscarProductoPorNombre(nombre);

    if (prod != nullptr) {
        p.precio = prod->precio;
        Descuentos::aplicarDescuento(p, cantidad, 10);  // Descuento del 10% si la cantidad comprada es mayor a 5
        ped.agregarProducto(p);
    } else {
        cout << "Producto no encontrado.\n";
    }
}

void mostrarMenu() {
    cout << "\n1. Registrar producto\n2. Registrar pedido\n3. Mostrar inventario\n4. Generar reportes\n5. Salir\nOpción: ";
}

int main() {
    GestorDeInventario gestor;
    GeneradorDeReportes generador(&gestor);

    // Productos iniciales
    Producto p1 = {"ProductoA", 100.0, 50};
    Producto p2 = {"ProductoB", 150.0, 30};
    Producto p3 = {"ProductoC", 200.0, 10};
    
    // Agregar productos al inventario
    gestor.agregarProducto(p1);
    gestor.agregarProducto(p2);
    gestor.agregarProducto(p3);

    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        
        if (opcion == 1) {
            Producto p;
            registrarProducto(p);
            gestor.agregarProducto(p);
        } else if (opcion == 2) {
            Pedido ped;
            registrarPedido(ped, gestor);
            generador.agregarPedido(ped);
        } else if (opcion == 3) {
            gestor.mostrarInventario();
        } else if (opcion == 4) {
            generador.reporteGeneral();
        } else if (opcion == 5) {
            cout << "¡Hasta luego!\n";
        } else {
            cout << "Opción no válida. Intenta de nuevo.\n";
        }
    } while (opcion != 5);

    return 0;
}
