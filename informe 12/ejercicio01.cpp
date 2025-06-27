#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
struct Producto {
    string descripcion;
    int cantidad;
};
map<string, Producto> inventario;
void agregarProducto() {
    string codigo, descripcion;
    int cantidad;
    cout << "Ingrese el código del producto: ";
    cin >> codigo;
    if (inventario.find(codigo) != inventario.end()) {
        cout << "Ya existe un producto con ese código.\n";
        return;
    }
    cin.ignore();
    cout << "Ingrese la descripción del producto: ";
    getline(cin, descripcion);
    cout << "Ingrese la cantidad en stock: ";
    cin >> cantidad;

    inventario[codigo] = {descripcion, cantidad};
    cout << "Producto agregado correctamente.\n";
}
void actualizarCantidad() {
    string codigo;
    int cantidad;
    cout << "Ingrese el código del producto a actualizar: ";
    cin >> codigo;
    auto it = inventario.find(codigo);
    if (it != inventario.end()) {
        cout << "Cantidad actual: " << it->second.cantidad << "\n";
        cout << "Ingrese la nueva cantidad: ";
        cin >> cantidad;
        it->second.cantidad = cantidad;
        cout << "Cantidad actualizada.\n";
    } else {
        cout << "Producto no encontrado.\n";
    }
}
void buscarProducto() {
    string codigo;
    cout << "Ingrese el código del producto a buscar: ";
    cin >> codigo;
    auto it = inventario.find(codigo);
    if (it != inventario.end()) {
        cout << "Código: " << it->first << "\n";
        cout << "Descripción: " << it->second.descripcion << "\n";
        cout << "Cantidad: " << it->second.cantidad << "\n";
    } else {
        cout << "Producto no encontrado.\n";
    }
}
void mostrarProductosOrdenados() {
    vector<pair<string, Producto>> productos(inventario.begin(), inventario.end());
    sort(productos.begin(), productos.end(), [](const auto& a, const auto& b) {
        return a.second.descripcion < b.second.descripcion;
    });
    cout << "\n--- Lista de productos ordenados por descripción ---\n";
    for (const auto& p : productos) {
        cout << "Código: " << p.first
             << ", Descripción: " << p.second.descripcion
             << ", Cantidad: " << p.second.cantidad << "\n";
    }
}
int main() {
    int opcion;
    do {
        cout << "\n--- Menú de Gestión de Inventario ---\n";
        cout << "1. Agregar producto\n";
        cout << "2. Actualizar cantidad\n";
        cout << "3. Buscar producto por código\n";
        cout << "4. Mostrar productos ordenados\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        switch (opcion) {
            case 1: agregarProducto(); break;
            case 2: actualizarCantidad(); break;
            case 3: buscarProducto(); break;
            case 4: mostrarProductosOrdenados(); break;
            case 5: cout << "Saliendo del programa...\n"; break;
            default: cout << "Opción no válida.\n";
        }
    } while (opcion != 5);
    return 0;
}
