#include <iostream>
#include <string>
using namespace std;

class Dispositivo {
private:
    string marca;
    string modelo;
    int anioFabricacion;

public:
    // Constructor por defecto
    Dispositivo() : marca("Genérica"), modelo("Desconocido"), anioFabricacion(2000) {
        cout << "📦 Constructor por defecto de " << modelo << endl;
    }

    // Constructor parametrizado
    Dispositivo(string m, string mod, int anio)
        : marca(m), modelo(mod), anioFabricacion(anio) {
        cout << "📦 Constructor parametrizado de " << modelo << endl;
    }

    // Constructor de copia
    Dispositivo(const Dispositivo& otro)
        : marca(otro.marca), modelo(otro.modelo), anioFabricacion(otro.anioFabricacion) {
        cout << "📋 Constructor de copia de " << modelo << endl;
    }

    // Destructor
    ~Dispositivo() {
        cout << "🧹 Destructor de dispositivo modelo: " << modelo << endl;
    }

    void mostrar() const {
        cout << "🔧 " << marca << " - " << modelo << " (" << anioFabricacion << ")" << endl;
    }
};

int main() {
    // Arreglo de objetos Dispositivo
    Dispositivo dispositivos[3] = {
        Dispositivo("HP", "ProBook", 2020),
        Dispositivo("Lenovo", "ThinkPad", 2021),
        Dispositivo("Dell", "Inspiron", 2019)
    };

    cout << "\n📋 Mostrando dispositivos:\n";
    for (int i = 0; i < 3; ++i) {
        dispositivos[i].mostrar();
    }

    // Probar constructor de copia
    Dispositivo copia = dispositivos[1];
    copia.mostrar();

    return 0;
}
