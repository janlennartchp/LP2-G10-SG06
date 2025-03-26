#include <iostream>
using namespace std;

class Carro {
private:
    string modelo;
    int fecha;
    int velocidad;

public:
    Carro(string _modelo, int _fecha) {
        modelo = _modelo;
        fecha = _fecha;
        velocidad = 0;
    }

    void acelerar() {
        velocidad += 10;
        cout << modelo << " acelero a " << velocidad << " km/h." << endl;
    }

    void frenar() {
        velocidad = max(0, velocidad - 10);
        cout << modelo << " freno a " << velocidad << " km/h." << endl;
    }
};

int main() {
    Carro carro1("Toyota", 2020);
    Carro carro2("Honda", 2018);

    carro1.acelerar();
    carro2.acelerar();
    carro1.frenar();

    return 0;
}

