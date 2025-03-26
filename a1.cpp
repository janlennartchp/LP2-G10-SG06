#include <iostream>
#include <vector>
using namespace std;

// Caso i: Biblioteca y Libro
class Libro {
private:
    string titulo;
    bool prestado;

public:
    Libro(string titulo) : titulo(titulo), prestado(false) {}

    void prestar() {
        if (!prestado) {
            prestado = true;
            cout << "El libro '" << titulo << "' ha sido prestado." << endl;
        } else {
            cout << "El libro '" << titulo << "' ya está prestado." << endl;
        }
    }

    void devolver() {
        if (prestado) {
            prestado = false;
            cout << "El libro '" << titulo << "' ha sido devuelto." << endl;
        } else {
            cout << "El libro '" << titulo << "' no estaba prestado." << endl;
        }
    }
};

class Biblioteca {
private:
    vector<Libro*> libros;

public:
    void agregarLibro(Libro* libro) {
        libros.push_back(libro);
    }

    void prestarLibro(Libro* libro) {
        libro->prestar();
    }
};

// Caso j: Factura y Producto
class Producto {
private:
    string nombre;
    double precio;
    int stock;

public:
    Producto(string nombre, double precio, int stock) 
        : nombre(nombre), precio(precio), stock(stock) {}

    bool disponible(int cantidad) {
        return stock >= cantidad;
    }

    bool reducirStock(int cantidad) {
        if (disponible(cantidad)) {
            stock -= cantidad;
            return true;
        }
        return false;
    }

    double getPrecio() { return precio; }
    string getNombre() { return nombre; }
};

class Factura {
private:
    vector<pair<Producto*, int>> productos;
    double total;

public:
    Factura() : total(0) {}

    void agregarProducto(Producto* producto, int cantidad) {
        if (producto->reducirStock(cantidad)) {
            productos.push_back(make_pair(producto, cantidad));
            total += producto->getPrecio() * cantidad;
            cout << "Producto '" << producto->getNombre() << "' agregado a la factura." << endl;
        } else {
            cout << "Stock insuficiente para '" << producto->getNombre() << "'." << endl;
        }
    }

    double getTotal() { return total; }
};

// Caso k: Carro y Rueda
class Rueda {
private:
    int tamano;

public:
    Rueda(int tamano) : tamano(tamano) {}
};

class Carro {
private:
    vector<Rueda*> ruedas;

public:
    Carro(int tamanoRueda) {
        for (int i = 0; i < 4; i++) {
            ruedas.push_back(new Rueda(tamanoRueda));
        }
    }

    void cambiarRueda(int posicion, Rueda* nuevaRueda) {
        if (posicion >= 0 && posicion < 4) {
            ruedas[posicion] = nuevaRueda;
            cout << "Rueda en posición " << posicion << " ha sido cambiada." << endl;
        }
    }
};

// Caso l: Tienda y Cliente
class Tienda {
private:
    vector<Producto*> productosDisponibles;

public:
    void agregarProducto(Producto* producto) {
        productosDisponibles.push_back(producto);
    }

    bool venderProducto(Producto* producto, int cantidad) {
        if (producto->reducirStock(cantidad)) {
            cout << "Producto '" << producto->getNombre() << "' vendido." << endl;
            return true;
        }
        cout << "Stock insuficiente para '" << producto->getNombre() << "'." << endl;
        return false;
    }
};

class Cliente {
private:
    vector<pair<Producto*, int>> carrito;

public:
    void agregarAlCarrito(Tienda* tienda, Producto* producto, int cantidad) {
        if (tienda->venderProducto(producto, cantidad)) {
            carrito.push_back(make_pair(producto, cantidad));
            cout << cantidad << " unidad(es) de '" << producto->getNombre() << "' agregada(s) al carrito." << endl;
        }
    }
};

int main() {
    // Pruebas de Biblioteca y Libro
    Biblioteca biblioteca;
    Libro libro1("El Principito");
    biblioteca.agregarLibro(&libro1);
    biblioteca.prestarLibro(&libro1);
    libro1.devolver();

    // Pruebas de Factura y Producto
    Producto prod1("Laptop", 1200.99, 5);
    Factura factura;
    factura.agregarProducto(&prod1, 2);

    // Pruebas de Carro y Rueda
    Carro carro(17);
    carro.cambiarRueda(2, new Rueda(18));

    // Pruebas de Tienda y Cliente
    Tienda tienda;
    tienda.agregarProducto(&prod1);
    Cliente cliente;
    cliente.agregarAlCarrito(&tienda, &prod1, 1);

    return 0;
}
