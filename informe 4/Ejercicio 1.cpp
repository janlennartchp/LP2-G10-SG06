#include <iostream>
#include <string>
using namespace std;
class Hijo {
private:
    string nombre; 
public:
    Hijo(string nombre) {
        this->nombre = nombre;
    }
    string getNombre() {
        return nombre;
    }
    void setNombre(string nombre) {
        this->nombre = nombre;
    }
};
class Padre {
private:
    string nombre;  
    Hijo** hijos;  
    int numHijos; 
    int maxHijos;  
public:
    Padre(string nombre, int maxHijos) {
        this->nombre = nombre;
        this->maxHijos = maxHijos;
        this->numHijos = 0;
        hijos = new Hijo*[maxHijos];  
    }
    ~Padre() {
        delete[] hijos;
    }
    string getNombre() {
        return nombre;
    }
    void setNombre(string nombre) {
        this->nombre = nombre;
    }
    void agregarHijo(Hijo* hijo) {
        if (numHijos < maxHijos) {
            hijos[numHijos] = hijo;
            numHijos++;
        } else {
            cout << "No se pueden agregar más hijos." << endl;
        }
    }
    void imprimirInfo() {
        cout << "Padre: " << nombre << endl;
        cout << "Número de hijos: " << numHijos << endl;
    }
};
int main() {
    Padre padre("Juan", 3); 
    Hijo* hijo1 = new Hijo("Carlos");
    Hijo* hijo2 = new Hijo("Ana");
    Hijo* hijo3 = new Hijo("Luis");
    padre.agregarHijo(hijo1); 
    padre.agregarHijo(hijo2);
    padre.agregarHijo(hijo3);
    padre.imprimirInfo(); 
    delete hijo1; 
    delete hijo2;
    delete hijo3;
    return 0;
}