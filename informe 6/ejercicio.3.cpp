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
    // Constructor
    Alumno(string n, int e, float p) : nombre(n), edad(e), promedio(p) {}
    // Método que retorna una cadena de texto representando al alumno
    string toString() const {
        return "Nombre: " + nombre + ", Edad: " + to_string(edad) + ", Promedio: " + to_string(promedio);
    }
    // Método para comparar promedio
    bool tienePromedioMenorQue(const Alumno& otro) const {
        return this->promedio < otro.promedio;
    }
    // Método para mostrar los datos
    void mostrarDatos() const {
        cout << toString() << endl;
    }
    // Getter para promedio (opcional)
    float getPromedio() const {
        return promedio;
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
    void mostrarDestacados(float limite) const {
        cout << "\nAlumnos con promedio mayor a " << limite << ":\n";
        for (const auto& alumno : alumnos) {
            if (alumno.getPromedio() > limite)
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
    float limite;
    cout << "\nMostrar alumnos con promedio mayor a: ";
    cin >> limite;
    grupo.mostrarDestacados(limite);
    return 0;
}
