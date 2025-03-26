#include <iostream>
using namespace std;
class Tienda {
private:
    string nombre;
    string direccion;
    string tipo;
    int stock;
public:
    Tienda(string _nombre, string _direccion, string _tipo) {
        nombre = _nombre;
        direccion = _direccion;
        tipo = _tipo;
        stock = 0;
    }
    void venderProducto() {
        if (stock > 0) {
            stock--;
            cout << "Se vendio un producto en " << nombre << ". Stock restante: " << stock << endl;
        } else {
            cout << "No hay stock disponible en " << nombre << "." << endl;
        }
    }

    void agregarProducto(int cantidad) {
        stock += cantidad;
        cout << "Se agregaron " << cantidad << " productos a " << nombre << ". Stock actual: " << stock << endl;
    }
};
int main() {
    Tienda tienda1("Fashion Store", "Av. Principal 123", "Ropa");
    Tienda tienda2("TechWorld", "Calle 45", "Electrónica");
    tienda1.agregarProducto(10);
    tienda1.venderProducto();
    tienda2.venderProducto();

    return 0;
}

