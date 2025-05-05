#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Alumno {
private:
    string nombre;
    int edad;
    float promedio;

public:
    Alumno(string _nombre, int _edad, float _promedio)
        : nombre(_nombre), edad(_edad), promedio(_promedio) {}

    float getPromedio() const {
        return promedio;
    }

    string toString() const {
        return "Nombre: " + nombre + ", Edad: " + to_string(edad) + ", Promedio: " + to_string(promedio);
    }

    bool operator<(const Alumno& otro) const {
        return promedio < otro.promedio;
    }
};

class Grupo {
private:
    vector<Alumno> alumnos;
    int cantidad;

public:
    Grupo(int _cantidad) : cantidad(_cantidad) {
        alumnos.reserve(cantidad); // No crea los objetos aún, solo reserva espacio
    }
    string toString() const {
        string resultado = "Grupo de alumnos:\n";
        for (const auto& a : alumnos) {
            resultado += " - " + a.toString() + "\n";
        }
        return resultado;
    }
    void agregarAlumno(string nombre, int edad, float promedio) {
        if (alumnos.size() < cantidad) {
            alumnos.push_back(Alumno(nombre, edad, promedio));
        } else {
            cout << "Ya se alcanzó la cantidad máxima de alumnos.\n";
        }
    }
    void ordenarPorPromedio() {
        sort(alumnos.begin(), alumnos.end());
    }
    float promedioGeneral() const {
        if (alumnos.empty()) return 0;
        float suma = 0;
        for (const auto& a : alumnos) {
            suma += a.getPromedio();
        }
        return suma / alumnos.size();
    }
    Alumno mejorAlumno() const {
        Alumno mejor = alumnos[0];
        for (const auto& a : alumnos) {
            if (a.getPromedio() > mejor.getPromedio()) {
                mejor = a;
            }
        }
        return mejor;
    }
};
int main() {
    Grupo grupo(5);
    grupo.agregarAlumno("Ana", 20, 18.5);
    grupo.agregarAlumno("Luis", 21, 15.2);
    grupo.agregarAlumno("Carla", 19, 17.4);
    grupo.agregarAlumno("Miguel", 22, 16.8);
    grupo.agregarAlumno("Sofia", 20, 19.1);

    cout << grupo.toString() << endl;

    grupo.ordenarPorPromedio();
    cout << "Alumnos ordenados por promedio:\n" << grupo.toString() << endl;

    cout << "Promedio general del grupo: " << grupo.promedioGeneral() << endl;

    Alumno mejor = grupo.mejorAlumno();
    cout << "Mejor alumno: " << mejor.toString() << endl;

    return 0;
}
