#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <stdexcept>
using namespace std;
class Producto {
private:
    string nombre;
    float precio;
    int cantidad;
public:
    Producto() {}
    Producto(string n, float p, int c) : nombre(n), precio(p), cantidad(c) {}
    string getNombre() const { return nombre; }
    float getPrecio() const { return precio; }
    int getCantidad() const { return cantidad; }
    void setPrecio(float p) { precio = p; }
    void setCantidad(int c) { cantidad = c; }
    string serializar() const {
        return nombre + "," + to_string(precio) + "," + to_string(cantidad);
    }
    static Producto deserializar(const string& linea) {
        stringstream ss(linea);
        string nombre, temp;
        float precio;
        int cantidad;
        getline(ss, nombre, ',');
        getline(ss, temp, ','); precio = stof(temp);
        getline(ss, temp, ','); cantidad = stoi(temp);
        return Producto(nombre, precio, cantidad);
    }
};
const string ARCHIVO = "inventario.csv";
void agregarProducto() {
    string nombre;
    float precio;
    int cantidad;
    try {
        cout << "Nombre del producto: ";
        cin >> nombre;
        cout << "Precio: ";
        cin >> precio;
        if (cin.fail() || precio < 0) throw invalid_argument("Precio invalido.");
        cout << "Cantidad: ";
        cin >> cantidad;
        if (cin.fail() || cantidad < 0) throw invalid_argument("Cantidad invalida.");
        ofstream archivo(ARCHIVO, ios::app);
        if (!archivo.is_open()) throw runtime_error("No se pudo abrir el archivo.");
        Producto p(nombre, precio, cantidad);
        archivo << p.serializar() << endl;
        archivo.close();
        cout << "Producto agregado exitosamente.\n";
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        cin.clear(); cin.ignore(1000, '\n');
    }
}
void mostrarInventario() {
    ifstream archivo(ARCHIVO);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
        return;
    }
    string linea;
    cout << "\nINVENTARIO:\n";
    while (getline(archivo, linea)) {
        Producto p = Producto::deserializar(linea);
        cout << "Producto: " << p.getNombre() << " | Precio: " << p.getPrecio() << " | Cantidad: " << p.getCantidad() << endl;
    }
    archivo.close();
}
vector<Producto> cargarProductos() {
    vector<Producto> productos;
    ifstream archivo(ARCHIVO);
    string linea;
    while (getline(archivo, linea)) {
        productos.push_back(Producto::deserializar(linea));
    }
    archivo.close();
    return productos;
}
void guardarProductos(const vector<Producto>& productos) {
    ofstream archivo(ARCHIVO);
    for (const auto& p : productos) {
        archivo << p.serializar() << endl;
    }
    archivo.close();
}
void actualizarProducto() {
    string nombre;
    cout << "Nombre del producto a actualizar: ";
    cin >> nombre;
    vector<Producto> productos = cargarProductos();
    bool encontrado = false;
    for (auto& p : productos) {
        if (p.getNombre() == nombre) {
            float nuevoPrecio;
            int nuevaCantidad;
            cout << "Nuevo precio: ";
            cin >> nuevoPrecio;
            cout << "Nueva cantidad: ";
            cin >> nuevaCantidad;
            p.setPrecio(nuevoPrecio);
            p.setCantidad(nuevaCantidad);
            encontrado = true;
            break;
        }
    }
    if (encontrado) {
        guardarProductos(productos);
        cout << "Producto actualizado correctamente.\n";
    } else {
        cerr << "Producto no encontrado.\n";
    }
}
void realizarVenta() {
    string nombre;
    int cantidadVenta;
    cout << "Nombre del producto a vender: ";
    cin >> nombre;
    cout << "Cantidad a vender: ";
    cin >> cantidadVenta;
    try {
        if (cantidadVenta <= 0) throw invalid_argument("Cantidad de venta invalida.");
        vector<Producto> productos = cargarProductos();
        bool vendido = false;
        for (auto& p : productos) {
            if (p.getNombre() == nombre) {
                if (p.getCantidad() < cantidadVenta) {
                    throw runtime_error("No hay suficiente stock.");
                }
                p.setCantidad(p.getCantidad() - cantidadVenta);
                vendido = true;
                break;
            }
        }
        if (vendido) {
            guardarProductos(productos);
            cout << "Venta realizada exitosamente.\n";
        } else {
            throw runtime_error("Producto no encontrado.");
        }
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}
int main() {
    int opcion;
    do {
        cout << "\nGESTION DE INVENTARIO - TIENDA DE PRODUCTOS ELECTRONICOS\n";
        cout << "1. Registrar nuevo producto\n";
        cout << "2. Actualizar producto\n";
        cout << "3. Realizar venta\n";
        cout << "4. Mostrar inventario\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1: agregarProducto(); break;
            case 2: actualizarProducto(); break;
            case 3: realizarVenta(); break;
            case 4: mostrarInventario(); break;
            case 0: cout << "Saliendo del programa.\n"; break;
            default: cout << "Opcion invalida.\n"; break;
        }
    } while (opcion != 0);
    return 0;
}