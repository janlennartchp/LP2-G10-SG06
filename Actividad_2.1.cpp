#include <iostream>
using namespace std;
class Persona {
private:
    string nombre;
    int edad;
    string genero;
    string dni;
public:
    Persona(string _nombre, int _edad, string _genero, string _dni) {
        nombre = _nombre;
        setEdad(_edad);
        setGenero(_genero);
        setDNI(_dni);
    }
    string getNombre() { return nombre; }
    int getEdad() { return edad; }
    string getGenero() { return genero; }
    string getDNI() { return dni; }
    void setEdad(int _edad) {
        if (_edad >= 0) edad = _edad;
        else cout << "Edad no valida." << endl;
    }
    void setGenero(string _genero) {
        if (_genero == "Masculino" || _genero == "Femenino" || _genero == "Otro")
            genero = _genero;
        else
            cout << "Genero no valido." << endl;
    }
    void setDNI(string _dni) {
        if (_dni.length() == 8) dni = _dni;
        else cout << "DNI inválido." << endl;
    }
};
int main() {
    Persona p1("Carlos", 25, "Masculino", "12345678");
    Persona p2("Ana", -5, "Si", "87654321"); 
    cout << p1.getNombre() << " es "<< p1.getGenero()<< " tiene "<< p1.getEdad() << " de edad y su DNI es " << p1.getDNI() << endl;
    return 0;
}

