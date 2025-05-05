#include <iostream>
#include <cmath>
using namespace std;
class Circulo {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}
    void mostrarDatos() const {
        cout << "Radio: " << radio << ", Diámetro: " << 2 * radio << endl;
    }
    friend double calcularArea(const Circulo& c);
};
double calcularArea(const Circulo& c) {
    return M_PI * c.radio * c.radio;
}
int main() {
    int cantidad;
    cout << "¿Cuántos círculos deseas ingresar? ";
    cin >> cantidad;
    for (int i = 0; i < cantidad; ++i) {
        double radio;
        cout << "\nIngresa el radio del círculo #" << i + 1 << ": ";
        cin >> radio;
        Circulo c(radio);
        c.mostrarDatos();
        cout << "Área: " << calcularArea(c) << endl;
    }
    return 0;
}
