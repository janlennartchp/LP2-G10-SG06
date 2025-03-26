#include <iostream>
using namespace std;

class Factura {
private:
    int numero;
    string fecha;
    double monto;
public:
    Factura(int _numero, string _fecha, double _monto) {
        numero = _numero;
        fecha = _fecha;
        monto = (_monto >= 0) ? _monto : 0;
    }
    int getNumero() { return numero; }
    string getFecha() { return fecha; }
    double getMonto() { return monto; }
    void mostrarFactura() {
        cout << "Factura #" << numero << " - Fecha: " << fecha << " - Monto: $" << monto << endl;
    }
};

int main() {
    Factura f1(1001, "2024-03-25", 250.75);
    Factura f2(1002, "2024-03-26", -50);  
    f1.mostrarFactura();
    f2.mostrarFactura();

    return 0;
}

