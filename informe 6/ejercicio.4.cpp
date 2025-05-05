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
        alumnos.reserve(cantidad); // Reserva espacio para la cantidad de alumnos
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
    bool tieneEspacio() const {
        return alumnos.size() < cantidad;
    }
};
void mostrarMenu() {
    cout << "\nMenu de opciones:\n";
    cout << "1. Agregar un alumno\n";
    cout << "2. Mostrar grupo\n";
    cout << "3. Ordenar alumnos por promedio\n";
    cout << "4. Mostrar promedio general\n";
    cout << "5. Mostrar el mejor alumno\n";
    cout << "6. Salir\n";
    cout << "Seleccione una opción: ";
}
int main() {
    int cantidadAlumnos;
    cout << "Ingrese la cantidad de alumnos para el grupo: ";
    cin >> cantidadAlumnos;
    if (cantidadAlumnos <= 0) {
        cout << "Cantidad de alumnos no válida. El programa terminará.\n";
        return 0;
    }
    Grupo grupo(cantidadAlumnos);
    int opcion;
    string nombre;
    int edad;
    float promedio;
    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1: {
                if (!grupo.tieneEspacio()) {
                    cout << "No hay espacio para más alumnos en el grupo.\n";
                    break;
                }
                cout << "Ingrese el nombre del alumno: ";
                cin.ignore();  // Limpiar el buffer
                getline(cin, nombre);
                cout << "Ingrese la edad del alumno: ";
                cin >> edad;
                cout << "Ingrese el promedio del alumno: ";
                cin >> promedio;
                
                if (edad <= 0 || promedio < 0 || promedio > 20) {
                    cout << "Datos inválidos. Asegúrese de ingresar una edad positiva y un promedio entre 0 y 20.\n";
                } else {
                    grupo.agregarAlumno(nombre, edad, promedio);
                    cout << "Alumno agregado exitosamente.\n";
                }
                break;
            }
            case 2:
                cout << grupo.toString() << endl;
                break;
            case 3:
                grupo.ordenarPorPromedio();
                cout << "Alumnos ordenados por promedio.\n";
                break;
            case 4:
                cout << "Promedio general del grupo: " << grupo.promedioGeneral() << endl;
                break;
            case 5: {
                Alumno mejor = grupo.mejorAlumno();
                cout << "Mejor alumno: " << mejor.toString() << endl;
                break;
            }
            case 6:
                cout << "Saliendo del programa.\n";
                break;  
            default:
                cout << "Opción no válida. Intente nuevamente.\n";
        }
    } while (opcion != 6);
    return 0;
}