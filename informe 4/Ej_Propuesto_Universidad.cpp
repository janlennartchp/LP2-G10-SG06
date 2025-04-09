#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Asociación bidireccional y de Agregación 
class Profesor {
private:
    string nombre;
    string direccion;
    string telefono;

public:
    Profesor(string n, string d, string t) : nombre(n), direccion(d), telefono(t) {}

    string getNombre() { return nombre; }

    void mostrar() {
        cout << "Profesor: " << nombre << ", Dirección: " << direccion << ", Teléfono: " << telefono << endl;
    }
};
class Asignatura;
class Estudiante {
private:
    string nombre;
    string direccion;
    string matricula;
    vector<Asignatura*> asignaturas; // Asociación bidireccional con Asignatura
public:
    Estudiante(string n, string d, string m) : nombre(n), direccion(d), matricula(m) {}
    string getNombre() { return nombre; }
    void agregarAsignatura(Asignatura* asignatura) {
        asignaturas.push_back(asignatura); // se completa la relación bidireccional
    }
    void mostrar() {
        cout << "Estudiante: " << nombre << ", Dirección: " << direccion << ", Matrícula: " << matricula << endl;
    }

    void mostrarAsignaturas();
};
class Asignatura {
private:
    string codigo;
    string nombre;
    string descripcion;
    Profesor* profesor; // Agregación: Asignatura tiene un profesor, pero no lo crea
    vector<Estudiante*> estudiantes; // Asociación bidireccional con Estudiante
    vector<int> notas;
    vector<int> asistencias;
public:
    Asignatura(string c, string n, string d, Profesor* p)
        : codigo(c), nombre(n), descripcion(d), profesor(p) {}
    string getNombre() { return nombre; }
    void inscribirEstudiante(Estudiante* estudiante, int nota, int asistencia) {
        estudiantes.push_back(estudiante);
        notas.push_back(nota);
        asistencias.push_back(asistencia);
        estudiante->agregarAsignatura(this); // relación bidireccional
    }
    void mostrar() {
        cout << "Asignatura: " << nombre << ", Código: " << codigo << ", Descripción: " << descripcion << endl;
        if (profesor != nullptr) {
            profesor->mostrar();
        }
        cout << "Estudiantes inscritos: " << estudiantes.size() << endl;
        for (int i = 0; i < estudiantes.size(); i++) {
            cout << " - ";
            estudiantes[i]->mostrar();
            cout << "   Nota: " << notas[i] << ", Asistencias: " << asistencias[i] << endl;
        }
    }
};
void Estudiante::mostrarAsignaturas() {
    cout << "Asignaturas matriculadas: " << endl;
    for (auto a : asignaturas) {
        cout << " - " << a->getNombre() << endl;
    }
}
void mostrarMenu() {
    cout << "\n--- MENÚ UNIVERSIDAD ---\n";
    cout << "1. Registrar profesor\n";
    cout << "2. Registrar estudiante\n";
    cout << "3. Registrar asignatura\n";
    cout << "4. Matricular estudiante en asignatura\n";
    cout << "5. Ver datos de asignatura\n";
    cout << "6. Ver datos de estudiante\n";
    cout << "7. Salir\n";
    cout << "Ingrese opción: ";
}
int main() {
    vector<Profesor*> profesores;
    vector<Estudiante*> estudiantes;
    vector<Asignatura*> asignaturas;
    int opcion;
    while (true) {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            string nombre, direccion, telefono;
            cout << "Nombre del profesor: ";
            getline(cin, nombre);
            cout << "Dirección: ";
            getline(cin, direccion);
            cout << "Teléfono: ";
            getline(cin, telefono);
            profesores.push_back(new Profesor(nombre, direccion, telefono));
            cout << "Profesor registrado con éxito.\n";
        } else if (opcion == 2) {
            string nombre, direccion, matricula;
            cout << "Nombre del estudiante: ";
            getline(cin, nombre);
            cout << "Dirección: ";
            getline(cin, direccion);
            cout << "Matrícula: ";
            getline(cin, matricula);
            estudiantes.push_back(new Estudiante(nombre, direccion, matricula));
            cout << "Estudiante registrado con éxito.\n";
        } else if (opcion == 3) {
            if (profesores.empty()) {
                cout << "Primero debe registrar al menos un profesor.\n";
                continue;
            }
            string codigo, nombre, descripcion;
            cout << "Código de la asignatura: ";
            getline(cin, codigo);
            cout << "Nombre: ";
            getline(cin, nombre);
            cout << "Descripción: ";
            getline(cin, descripcion);
            cout << "Profesores disponibles:\n";
            for (int i = 0; i < profesores.size(); i++) {
                cout << i + 1 << ". " << profesores[i]->getNombre() << endl;
            }
            int index;
            cout << "Seleccione profesor (número): ";
            cin >> index;
            cin.ignore();
            if (index < 1 || index > profesores.size()) {
                cout << "Opción inválida.\n";
            } else {
                asignaturas.push_back(new Asignatura(codigo, nombre, descripcion, profesores[index - 1]));
                cout << "Asignatura registrada con éxito.\n";
            }
        } else if (opcion == 4) {
            if (asignaturas.empty() || estudiantes.empty()) {
                cout << "Debe haber al menos un estudiante y una asignatura.\n";
                continue;
            }
            cout << "Estudiantes:\n";
            for (int i = 0; i < estudiantes.size(); i++) {
                cout << i + 1 << ". " << estudiantes[i]->getNombre() << endl;
            }
            int e;
            cout << "Seleccione estudiante: ";
            cin >> e;
            cin.ignore();
            cout << "Asignaturas:\n";
            for (int i = 0; i < asignaturas.size(); i++) {
                cout << i + 1 << ". " << asignaturas[i]->getNombre() << endl;
            }
            int a;
            cout << "Seleccione asignatura: ";
            cin >> a;
            cin.ignore();
            int nota, faltas;
            cout << "Nota obtenida: ";
            cin >> nota;
            cout << "Número de faltas: ";
            cin >> faltas;
            cin.ignore();
            if (e >= 1 && e <= estudiantes.size() && a >= 1 && a <= asignaturas.size()) {
                asignaturas[a - 1]->inscribirEstudiante(estudiantes[e - 1], nota, faltas);
                cout << "Estudiante matriculado con éxito.\n";
            } else {
                cout << "Datos inválidos.\n";
            }
        } else if (opcion == 5) {
            for (int i = 0; i < asignaturas.size(); i++) {
                cout << i + 1 << ". " << asignaturas[i]->getNombre() << endl;
            }
            int i;
            cout << "Seleccione asignatura: ";
            cin >> i;
            cin.ignore();
            if (i >= 1 && i <= asignaturas.size()) {
                asignaturas[i - 1]->mostrar();
            } else {
                cout << "Opción inválida.\n";
            }
        } else if (opcion == 6) {
            for (int i = 0; i < estudiantes.size(); i++) {
                cout << i + 1 << ". " << estudiantes[i]->getNombre() << endl;
            }
            int i;
            cout << "Seleccione estudiante: ";
            cin >> i;
            cin.ignore();
            if (i >= 1 && i <= estudiantes.size()) {
                estudiantes[i - 1]->mostrar();
                estudiantes[i - 1]->mostrarAsignaturas();
            } else {
                cout << "Opción inválida.\n";
            }
        } else if (opcion == 7) {
            cout << "¡Gracias por usar el sistema!\n";
            break;
        } else {
            cout << "Opción inválida.\n";
        }
    }
    for (auto p : profesores) delete p;
    for (auto e : estudiantes) delete e;
    for (auto a : asignaturas) delete a;

    return 0;
}
