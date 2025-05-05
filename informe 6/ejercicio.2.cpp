#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Alumno {
private:
    string nombre;
    int edad;
    float promedio;
public:
    Alumno(string n, int e, float p) : nombre(n), edad(e), promedio(p) {}

    void mostrarDatos() const {
        cout << "Nombre: " << nombre << ", Edad: " << edad << ", Promedio: " << promedio << endl;
    }
};
class Grupo {
private:
    vector<Alumno> alumnos;
    int cantidad;
public:
    Grupo() : cantidad(0) {}
    void agregarAlumno(const Alumno& a) {
        alumnos.push_back(a);
        cantidad++;
    }
    void mostrarGrupo() const {
        cout << "\nGrupo de " << cantidad << " alumno(s):\n";
        for (const auto& alumno : alumnos) {
            alumno.mostrarDatos();
        }
    }
};
int main() {
    Grupo grupo;
    int total;
    cout << "¿Cuántos alumnos desea ingresar?: ";
    cin >> total;
    cin.ignore();
    for (int i = 0; i < total; ++i) {
        string nombre;
        int edad;
        float promedio;
        cout << "\nAlumno #" << (i + 1) << ":\n";
        cout << "Nombre: ";
        getline(cin, nombre);
        cout << "Edad: ";
        cin >> edad;
        cout << "Promedio: ";
        cin >> promedio;
        cin.ignore();
        Alumno nuevo(nombre, edad, promedio);
        grupo.agregarAlumno(nuevo);
    }
    grupo.mostrarGrupo();
    return 0;
}
