#include <iostream>
#include <string>
using namespace std;
class Motor {
private:
    string tipo;
    int caballosDeFuerza;
public:
    Motor(string tipo, int caballos) : tipo(tipo), caballosDeFuerza(caballos) {}
    void mostrarInfo() {
        cout << "Tipo de motor: " << tipo << ", Caballos de fuerza: " << caballosDeFuerza << endl;
    }
    void setTipo(string nuevoTipo) {
        tipo = nuevoTipo;
    }
    void setCaballos(int nuevosCaballos) {
        caballosDeFuerza = nuevosCaballos;
    }
};
class Auto {
private:
    string marca;
    Motor* motor; 
public:
    Auto(string marca, string tipoMotor, int caballos) : marca(marca) {
        motor = new Motor(tipoMotor, caballos); 
    }
    ~Auto() {
        delete motor;
    }
    Motor& getMotor() {
        return *motor;
    }
    void mostrarAuto() {
        cout << "Auto marca: " << marca << endl;
        motor->mostrarInfo();
    }
};
int main() {
    Auto miAuto("Toyota", "Gasolina", 120);
    cout << "InformaciOn inicial del auto:" << endl;
    miAuto.mostrarAuto();
    miAuto.getMotor().setTipo("HIbrido");
    miAuto.getMotor().setCaballos(150);
    cout << "\nDespuEs de modificar el motor:" << endl;
    miAuto.mostrarAuto();

    return 0;
}




