#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

struct Producto {
    string nombre;
    float precio;
    int cantidad;
};

struct Pedido {
    vector<Producto> productos;  // Usamos un vector para almacenar productos
    float totalPedido = 0.0;

    void agregarProducto(const Producto &producto) {
        productos.push_back(producto);
        totalPedido += producto.precio * producto.cantidad;
    }
};

class GestorDeInventario {
private:
    vector<Producto> inventario;

public:
    // Agregar un nuevo producto al inventario
    void agregarProducto(const Producto &producto) {
        inventario.push_back(producto);
    }

    // Buscar un producto por su nombre
    Producto* buscarProductoPorNombre(const string &nombre) {
        for (auto &producto : inventario) {
            if (producto.nombre == nombre) {
                return &producto;
            }
        }
        return nullptr;  // Producto no encontrado
    }

    // Mostrar el inventario completo
    void mostrarInventario() {
        cout << "\nInventario Actual:\n";
        for (const auto &producto : inventario) {
            cout << "Producto: " << producto.nombre << " - Precio: " << producto.precio << " - Cantidad: " << producto.cantidad << "\n";
        }
    }

    // Obtener todos los productos
    vector<Producto> obtenerInventario() {
        return inventario;
    }
};

class GeneradorDeReportes {
private:
    vector<Pedido> pedidosHistorial;
    GestorDeInventario* gestorDeInventario;

public:
    // Constructor que recibe el GestorDeInventario
    GeneradorDeReportes(GestorDeInventario* gestor) : gestorDeInventario(gestor) {}

    // Registrar un pedido
    void agregarPedido(const Pedido &pedido) {
        pedidosHistorial.push_back(pedido);
    }

    // Reporte de ventas totales
    void reporteVentas() {
        float ventasTotales = 0.0;
        int totalProductosVendidos = 0;

        for (const auto &pedido : pedidosHistorial) {
            ventasTotales += pedido.totalPedido;
            for (const auto &producto : pedido.productos) {
                totalProductosVendidos += producto.cantidad;
            }
        }

        cout << "\nReporte de Ventas Totales:\n";
        cout << "Ventas totales: $" << ventasTotales << "\n";
        cout << "Productos vendidos: " << totalProductosVendidos << "\n";
    }

    // Reporte de productos con inventario bajo
    void reporteInventarioBajo(int umbral) {
        cout << "\nReporte de Inventario Bajo (por debajo de " << umbral << " unidades):\n";

        for (const auto &producto : gestorDeInventario->obtenerInventario()) {
            if (producto.cantidad < umbral) {
                cout << "Producto: " << producto.nombre << " - Cantidad: " << producto.cantidad << "\n";
            }
        }
    }

    // Reporte general (ventas + inventario bajo)
    void reporteGeneral(int umbral) {
        reporteVentas();
        reporteInventarioBajo(umbral);
    }
};

class Descuentos {
public:
    static float aplicarDescuento(Producto &producto, int cantidadCompra, float porcentajeDescuento) {
        if (cantidadCompra > 5) {  // Si la cantidad comprada es mayor a 5, se aplica descuento
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

    Producto* prod = gestor.buscarProductoPorNombre(nombre);
    if (prod != nullptr && prod->cantidad >= cantidad) {
        p.nombre = prod->nombre;
        p.precio = prod->precio;
        p.cantidad = cantidad;
        Descuentos::aplicarDescuento(p, cantidad, 10);  // Descuento del 10% si la cantidad comprada es mayor a 5
        ped.agregarProducto(p);
        prod->cantidad -= cantidad;  // Actualizamos el inventario
    } else {
        cout << "Producto no disponible o no hay suficiente stock.\n";
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
            generador.reporteGeneral(10);  // Umbral de 10 unidades para inventario bajo
        } else if (opcion == 5) {
            cout << "¡Hasta luego!\n";
        } else {
            cout << "Opción no válida. Intenta de nuevo.\n";
        }
    } while (opcion != 5);

    return 0;
}
