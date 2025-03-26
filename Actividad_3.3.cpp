#include <iostream>
using namespace std;
class Persona {
private:
    string nombre;
    int edad;
public:
    Persona() {} 
    Persona(string _nombre, int _edad) {
        nombre = _nombre;
        edad = _edad;
    }
    string getNombre() { return nombre; }
    int getEdad() { return edad; }
    void setEdad(int _edad) { edad = _edad; }
    void mostrarInfo() {
        cout << "Nombre: " << nombre << ", Edad: " << edad << " años" << endl;
    }
};
const int MAX_PERSONAS = 3;  
Persona lista[MAX_PERSONAS];  
int numPersonas = 0;          
void agregarPersona(string nombre, int edad) {
    if (numPersonas < MAX_PERSONAS) {
        lista[numPersonas] = Persona(nombre, edad);
        numPersonas++;
        cout << "Persona agregada: " << nombre << endl;
    } else {
        cout << "La lista está llena, no se pueden agregar más personas." << endl;
    }
}
void eliminarPersona(string nombre) {
    for (int i = 0; i < numPersonas; i++) {
        if (lista[i].getNombre() == nombre) {
            for (int j = i; j < numPersonas - 1; j++) {
                lista[j] = lista[j + 1];
            }
            numPersonas--;
            cout << "Persona eliminada: " << nombre << endl;
            return;
        }
    }
    cout << "Persona no encontrada." << endl;
}
void actualizarEdad(string nombre, int nuevaEdad) {
    for (int i = 0; i < numPersonas; i++) {
        if (lista[i].getNombre() == nombre) {
            lista[i].setEdad(nuevaEdad);
            cout << "Edad actualizada para " << nombre << " a " << nuevaEdad << " de edad." << endl;
            return;
        }
    }
    cout << "Persona no encontrada." << endl;
}
void mostrarLista() {
    if (numPersonas == 0) {
        cout << "La lista esta vacia." << endl;
        return;
    }
    for (int i = 0; i < numPersonas; i++) {
        lista[i].mostrarInfo();
    }
}
int main() {
    agregarPersona("Carlos", 25);
    agregarPersona("Ana", 30);
    agregarPersona("Luis", 28);
    cout << "\nLista inicial:" << endl;
    mostrarLista();
    eliminarPersona("Carlos");
    cout << "\nLista después de eliminar:" << endl;
    mostrarLista();
    actualizarEdad("Ana", 35);
    cout << "\nLista después de actualizar:" << endl;
    mostrarLista();
    return 0;
}



