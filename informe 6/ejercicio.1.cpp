#include <iostream>
#include <string>
using namespace std;
class Alumno {
private:
    string nombre;
    int edad;
    float promedio;
public:
    // Constructor
    Alumno(string n, int e, float p) : nombre(n), edad(e), promedio(p) {}
    void mostrarDatos() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Promedio: " << promedio << endl;
    }
};
int main() {
    string nombre;
    int edad;
    float promedio;
    cout << "Ingrese el nombre del alumno: ";
    getline(cin, nombre);
    cout << "Ingrese la edad del alumno: ";
    cin >> edad;
    cout << "Ingrese el promedio del alumno: ";
    cin >> promedio;
    Alumno alumno1(nombre, edad, promedio);
    cout << "\nDatos del alumno:\n";
    alumno1.mostrarDatos();
    return 0;
}
