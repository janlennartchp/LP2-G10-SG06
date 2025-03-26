#include <iostream>
using namespace std;
class Persona {
private:
    string nombre;
    int edad;
public:
    Persona(string _nombre, int _edad) {
        nombre = _nombre;
        setEdad(_edad);
    }
    void setEdad(int _edad) {
        if (_edad > 0) edad = _edad;
        else cout << "Edad no válida." << endl;
    }

    int getEdad() { return edad; }
    string getNombre() { return nombre; }
};
int main() {
    Persona p1("Carlos", 25);
    Persona p2("Ana", 30);
    cout << p1.getNombre() << " tiene " << p1.getEdad() << " de edad" << endl;
    cout << p2.getNombre() << " tiene " << p2.getEdad() << " de edad" << endl;

    return 0;
}

