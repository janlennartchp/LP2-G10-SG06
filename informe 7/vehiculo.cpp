#include <iostream>
using namespace std;
class Vehiculo {
protected:
    string marca;
    string modelo;
    int anioFabricacion;
    double precio;
public:
    Vehiculo(string m, string mod, int anio, double p)
        : marca(m), modelo(mod), anioFabricacion(anio), precio(p) {}
    void mostrarDatosBase() const {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Año de fabricación: " << anioFabricacion << endl;
        cout << "Precio: $" << precio << endl;
    }
};
class Automovil : public Vehiculo {
private:
    int numPuertas;
    string tipoCombustible;
public:
    Automovil(string m, string mod, int anio, double p, int puertas, string combustible)
        : Vehiculo(m, mod, anio, p), numPuertas(puertas), tipoCombustible(combustible) {}
    void mostrarDatos() const {
        mostrarDatosBase();
        cout << "Número de puertas: " << numPuertas << endl;
        cout << "Tipo de combustible: " << tipoCombustible << endl;
    }
};
class Motocicleta : public Vehiculo {
private:
    int cilindrada;
public:
    Motocicleta(string m, string mod, int anio, double p, int cil)
        : Vehiculo(m, mod, anio, p), cilindrada(cil) {}
    void mostrarDatos() const {
        mostrarDatosBase();
        cout << "Cilindrada: " << cilindrada << " cc" << endl;
    }
};
int main() {
    Automovil auto1("Toyota", "Corolla", 2020, 20000, 4, "Gasolina");
    Motocicleta moto1("Yamaha", "R3", 2022, 7500, 321);
    cout << "=== Datos del Automóvil ===" << endl;
    auto1.mostrarDatos();
    cout << "\n=== Datos de la Motocicleta ===" << endl;
    moto1.mostrarDatos();
    return 0;
}
