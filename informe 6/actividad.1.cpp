#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Estudiante {
private:
    string nombre;
    int edad;
    float nota1, nota2, nota3;
public:
    Estudiante(string n, int e, float n1, float n2, float n3)
        : nombre(n), edad(e), nota1(n1), nota2(n2), nota3(n3) {}
    float promedio() const {
        return (nota1 + nota2 + nota3) / 3;
    }
    void mostrar() const {
        cout << "Nombre: " << nombre
             << ", Edad: " << edad
             << ", Promedio: " << promedio() << endl;
    }
    float getPromedio() const { return promedio(); }
};
void mostrarEstudiantesConPromedioMayor(const vector<Estudiante>& estudiantes, float umbral) {
    cout << "\nEstudiantes con promedio mayor a " << umbral << ":\n";
    for (const auto& est : estudiantes) {
        if (est.getPromedio() > umbral)
            est.mostrar();
    }
}
int main() {
    vector<Estudiante> estudiantes;
    estudiantes.emplace_back("Ana", 20, 15.5, 17.0, 16.2);
    estudiantes.emplace_back("Luis", 21, 12.3, 13.0, 14.5);
    estudiantes.emplace_back("Carla", 19, 18.0, 17.5, 19.0);
    estudiantes.emplace_back("Pedro", 22, 10.0, 11.5, 12.0);
    sort(estudiantes.begin(), estudiantes.end(),
         [](const Estudiante& a, const Estudiante& b) {
             return a.getPromedio() > b.getPromedio();
         });
    cout << "Estudiantes ordenados por promedio:\n";
    for (const auto& est : estudiantes)
        est.mostrar();
    mostrarEstudiantesConPromedioMayor(estudiantes, 15.0);
    return 0;
}
