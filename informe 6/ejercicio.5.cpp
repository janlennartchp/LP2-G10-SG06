#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
using namespace std;
class Alumno {
private:
    string nombre;
    int edad;
    float promedio;
public:
    Alumno(string _nombre, int _edad, float _promedio) {
        nombre = _nombre;
        edad = _edad;
        promedio = _promedio;
    }
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
    int capacidad;

public:
    Grupo(int _capacidad) {
        capacidad = _capacidad;
        alumnos.reserve(capacidad);
    }
    bool agregarAlumno(string nombre, int edad, float promedio) {
        if (alumnos.size() < capacidad) {
            alumnos.push_back(Alumno(nombre, edad, promedio));
            return true;
        }
        return false;
    }
    string toString() const {
        if (alumnos.empty()) return "El grupo aún no tiene alumnos.\n";
        string resultado = "📋 Lista de Alumnos:\n";
        for (const auto& a : alumnos) {
            resultado += " - " + a.toString() + "\n";
        }
        return resultado;
    }
    float promedioGeneral() const {
        float suma = 0;
        for (const auto& a : alumnos) {
            suma += a.getPromedio();
        }
        return alumnos.empty() ? 0 : suma / alumnos.size();
    }
    Alumno mejorAlumno() const {
        return *max_element(alumnos.begin(), alumnos.end(),
                            [](const Alumno& a, const Alumno& b) {
                                return a.getPromedio() < b.getPromedio();
                            });
    }

    bool estaLleno() const {
        return alumnos.size() >= capacidad;
    }
    bool estaVacio() const {
        return alumnos.empty();
    }
};
int leerEntero(string mensaje, int min, int max) {
    int valor;
    while (true) {
        cout << mensaje;
        cin >> valor;
        if (cin.fail() || valor < min || valor > max) {
            cout << "Entrada inválida. Intente nuevamente.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            return valor;
        }
    }
}

float leerFloat(string mensaje, float min, float max) {
    float valor;
    while (true) {
        cout << mensaje;
        cin >> valor;
        if (cin.fail() || valor < min || valor > max) {
            cout << "Entrada inválida. Intente nuevamente.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            return valor;
        }
    }
}
int main() {
    Grupo grupo(5);
    int opcion;

    do {
        cout << "\n===== MENÚ DEL GRUPO DE ALUMNOS =====\n";
        cout << "1. Agregar Alumno\n";
        cout << "2. Mostrar Alumnos\n";
        cout << "3. Mostrar Promedio General\n";
        cout << "4. Mostrar Mejor Alumno\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        cin.ignore(); 

        switch (opcion) {
            case 1: {
                if (grupo.estaLleno()) {
                    cout << " El grupo ya está lleno. No se pueden agregar más alumnos.\n";
                } else {
                    string nombre;
                    cout << "Ingrese nombre: ";
                    getline(cin, nombre);
                    int edad = leerEntero("Ingrese edad (12-100): ", 12, 100);
                    float promedio = leerFloat("Ingrese promedio (0.0 - 20.0): ", 0.0f, 20.0f);

                    if (grupo.agregarAlumno(nombre, edad, promedio)) {
                        cout << "Alumno agregado con éxito.\n";
                    }
                }
                break;
            }
            case 2:
                cout << grupo.toString();
                break;
            case 3:
                if (grupo.estaVacio()) {
                    cout << " No hay alumnos en el grupo.\n";
                } else {
                    cout << "Promedio general del grupo: " << grupo.promedioGeneral() << "\n";
                }
                break;
            case 4:
                if (grupo.estaVacio()) {
                    cout << " No hay alumnos para comparar.\n";
                } else {
                    cout << " Mejor alumno:\n" << grupo.mejorAlumno().toString() << "\n";
                }
                break;
            case 5:
                cout << " Saliendo del programa...\n";
                break;
            default:
                cout << "opción inválida.\n";
        }
    } while (opcion != 5);
    return 0;
}
