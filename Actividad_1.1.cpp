#include <iostream>
using namespace std;
class Animal {
private:
    string nombre;
    int edad;
    string tipo;

public:
    Animal(string _nombre, int _edad, string _tipo) {
        nombre = _nombre;
        edad = _edad;
        tipo = _tipo;
    }

    void alimentar() {
        cout << nombre << " esta comiendo." << endl;
    }

    void hacerSonido() {
        cout << nombre << " hace un sonido." << endl;
    }
};

int main() {
    Animal perro("Rex", 5, "Perro");
    Animal gato("Michi", 3, "Gato");

    perro.alimentar();
    gato.hacerSonido();

    return 0;
}

 

