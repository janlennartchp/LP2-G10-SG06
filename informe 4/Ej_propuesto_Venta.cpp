#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Relaciones unidireccionales y bidireccionales
class Proveedor {
private:
    string nombre;

public:
    Proveedor(string nombre) : nombre(nombre) {}

    string getNombre() const {
        return nombre;
    }
};
class Producto {
private:
    string codigo;
    string descripcion;
    double precio;
    Proveedor* proveedor;  // Relación unidireccional con Proveedor
public:
    Producto(string codigo, string descripcion, double precio, Proveedor* proveedor)
        : codigo(codigo), descripcion(descripcion), precio(precio), proveedor(proveedor) {}
    void mostrarInfo() const {
        cout << "Código: " << codigo << ", Descripción: " << descripcion << ", Precio: " << precio << endl;
        cout << "Proveedor: " << proveedor->getNombre() << endl;
    }
    double getPrecio() const {
        return precio;
    }
    string getCodigo() const {
        return codigo;
    }
};
class Cliente {
private:
    string nombre;
    string direccion;
    string telefono;
    vector<class Venta*> ventasRealizadas;  // Relación bidireccional con Ventas
public:
    Cliente(string nombre, string direccion, string telefono)
        : nombre(nombre), direccion(direccion), telefono(telefono) {}

    void realizarVenta(class Venta* venta);  // Función para completar la relación bidireccional
    void mostrarInfo() const {
        cout << "Cliente: " << nombre << ", Dirección: " << direccion << ", Teléfono: " << telefono << endl;
    }

    string getNombre() const {
        return nombre;
    }

    vector<class Venta*> getVentas() const {
        return ventasRealizadas;
    }
};
class Venta {
private:
    int numeroFactura;
    string fecha;
    Cliente* cliente;  // Relación bidireccional con Cliente
    vector<Producto*> productosVendidos;  // Productos vendidos

public:
    Venta(int numeroFactura, string fecha, Cliente* cliente)
        : numeroFactura(numeroFactura), fecha(fecha), cliente(cliente) {
        cliente->realizarVenta(this);  // Relación bidireccional con Cliente
    }

    void agregarProducto(Producto* producto) {
        productosVendidos.push_back(producto);
    }
    void mostrarInfo() const {
        cout << "Factura No: " << numeroFactura << ", Fecha: " << fecha << endl;
        cout << "Cliente: " << cliente->getNombre() << endl;
        cout << "Productos vendidos: " << endl;
        double total = 0;
        for (int i = 0; i < productosVendidos.size(); ++i) {
            productosVendidos[i]->mostrarInfo();
            total += productosVendidos[i]->getPrecio();
        }
        cout << "Total de la venta: " << total << endl;
    }
    Cliente* getCliente() const {
        return cliente;
    }
};

// Implementación de la relación bidireccional entre Cliente y Venta
void Cliente::realizarVenta(Venta* venta) {
    ventasRealizadas.push_back(venta);
}
void mostrarMenu() {
    cout << "\n----- Sistema de Gestión de Tienda de Ropa -----" << endl;
    cout << "1. Registrar proveedor" << endl;
    cout << "2. Registrar producto" << endl;
    cout << "3. Registrar cliente" << endl;
    cout << "4. Realizar venta" << endl;
    cout << "5. Mostrar información de cliente" << endl;
    cout << "6. Mostrar ventas de cliente" << endl;
    cout << "7. Salir" << endl;
    cout << "Ingrese una opción: ";
}
int main() {
    vector<Proveedor*> proveedores;
    vector<Producto*> productos;
    vector<Cliente*> clientes;
    vector<Venta*> ventas;
    int opcion;
    while (true) {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();  
        if (opcion == 1) {
            string nombreProveedor;
            cout << "Ingrese el nombre del proveedor: ";
            getline(cin, nombreProveedor);
            Proveedor* proveedor = new Proveedor(nombreProveedor);
            proveedores.push_back(proveedor);
            cout << "Proveedor registrado con éxito!" << endl;
        } else if (opcion == 2) {
            string codigo, descripcion;
            double precio;
            cout << "Ingrese el código del producto: ";
            getline(cin, codigo);
            cout << "Ingrese la descripción del producto: ";
            getline(cin, descripcion);
            cout << "Ingrese el precio del producto: ";
            cin >> precio;
            cin.ignore();
            cout << "\nProveedores registrados:\n";
            for (int i = 0; i < proveedores.size(); ++i) {
                cout << i + 1 << ". " << proveedores[i]->getNombre() << endl;
            }
            int opcionProveedor;
            cout << "Seleccione el proveedor del producto (1-" << proveedores.size() << "): ";
            cin >> opcionProveedor;
            cin.ignore();
            if (opcionProveedor >= 1 && opcionProveedor <= proveedores.size()) {
                Proveedor* proveedorSeleccionado = proveedores[opcionProveedor - 1];
                Producto* producto = new Producto(codigo, descripcion, precio, proveedorSeleccionado);
                productos.push_back(producto);
                cout << "Producto registrado con éxito!" << endl;
            } else {
                cout << "Opción inválida. El producto no ha sido registrado." << endl;
            }
        } else if (opcion == 3) {
            string nombreCliente, direccion, telefono;
            cout << "Ingrese el nombre del cliente: ";
            getline(cin, nombreCliente);
            cout << "Ingrese la dirección del cliente: ";
            getline(cin, direccion);
            cout << "Ingrese el teléfono del cliente: ";
            getline(cin, telefono);
            Cliente* cliente = new Cliente(nombreCliente, direccion, telefono);
            clientes.push_back(cliente);
            cout << "Cliente registrado con éxito!" << endl;
        } else if (opcion == 4) {
            string nombreCliente;
            cout << "Ingrese el nombre del cliente para realizar la venta: ";
            getline(cin, nombreCliente);
            Cliente* clienteEncontrado = nullptr;
            for (int i = 0; i < clientes.size(); ++i) {
                if (clientes[i]->getNombre() == nombreCliente) {
                    clienteEncontrado = clientes[i];
                    break;
                }
            }
            if (clienteEncontrado != nullptr) {
                int numeroFactura;
                string fecha;
                cout << "Ingrese el número de factura: ";
                cin >> numeroFactura;
                cin.ignore();
                cout << "Ingrese la fecha de la venta: ";
                getline(cin, fecha);
                Venta* venta = new Venta(numeroFactura, fecha, clienteEncontrado);
                cout << "\nProductos disponibles:\n";
                for (int i = 0; i < productos.size(); ++i) {
                    cout << i + 1 << ". " << productos[i]->getCodigo() << ": " << productos[i]->getPrecio() << endl;
                }
                int opcionProducto;
                while (true) {
                    cout << "Seleccione el producto a vender (0 para terminar): ";
                    cin >> opcionProducto;
                    if (opcionProducto == 0) break;
                    if (opcionProducto >= 1 && opcionProducto <= productos.size()) {
                        venta->agregarProducto(productos[opcionProducto - 1]);
                    } else {
                        cout << "Opción inválida. El producto no ha sido agregado." << endl;
                    }
                }
                ventas.push_back(venta);
                cout << "Venta registrada con éxito!" << endl;
            } else {
                cout << "Cliente no encontrado." << endl;
            }
        } else if (opcion == 5) {
            string nombreCliente;
            cout << "Ingrese el nombre del cliente para ver su información: ";
            getline(cin, nombreCliente);
            Cliente* clienteEncontrado = nullptr;
            for (int i = 0; i < clientes.size(); ++i) {
                if (clientes[i]->getNombre() == nombreCliente) {
                    clienteEncontrado = clientes[i];
                    break;
                }
            }
            if (clienteEncontrado != nullptr) {
                clienteEncontrado->mostrarInfo();
            } else {
                cout << "Cliente no encontrado." << endl;
            }
        } else if (opcion == 6) {
            string nombreCliente;
            cout << "Ingrese el nombre del cliente para ver sus ventas: ";
            getline(cin, nombreCliente);
            Cliente* clienteEncontrado = nullptr;
            for (int i = 0; i < clientes.size(); ++i) {
                if (clientes[i]->getNombre() == nombreCliente) {
                    clienteEncontrado = clientes[i];
                    break;
                }
            }
            if (clienteEncontrado != nullptr) {
                vector<Venta*> ventasCliente = clienteEncontrado->getVentas();
                if (ventasCliente.empty()) {
                    cout << "Este cliente no tiene ventas registradas." << endl;
                } else {
                    for (int i = 0; i < ventasCliente.size(); ++i) {
                        ventasCliente[i]->mostrarInfo();
                    }
                }
            } else {
                cout << "Cliente no encontrado." << endl;
            }
        } else if (opcion == 7) {
            cout << "¡Gracias por usar el sistema!" << endl;
            break;
        } else {
            cout << "Opción no válida. Intente de nuevo." << endl;
        }
    }
    for (auto proveedor : proveedores) delete proveedor;
    for (auto producto : productos) delete producto;
    for (auto cliente : clientes) delete cliente;
    for (auto venta : ventas) delete venta;
    return 0;
}
