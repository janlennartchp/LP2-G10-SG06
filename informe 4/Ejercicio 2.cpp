#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Estudiante; 
class Curso {
private:
    string nombre;
    string codigo;
    string descripcion;
    string fechaInicio;
    string fechaFin;
    vector<Estudiante*> estudiantes; 
public:
    Curso(string nombre, string codigo, string descripcion, string fechaInicio, string fechaFin)
        : nombre(nombre), codigo(codigo), descripcion(descripcion), fechaInicio(fechaInicio), fechaFin(fechaFin) {}
    void agregarEstudiante(Estudiante* estudiante);
    void eliminarEstudiante(Estudiante* estudiante);
    void imprimirEstudiantes();
    string getNombre() {
        return nombre;
    }
};
class Estudiante {
private:
    string nombre;
    string apellido;
    string id;
    string correo;
    vector<Curso*> cursos; 
public:
    Estudiante(string nombre, string apellido, string id, string correo)
        : nombre(nombre), apellido(apellido), id(id), correo(correo) {}
    void agregarCurso(Curso* curso);
    void eliminarCurso(Curso* curso);
    void imprimirCursos();
    string getNombre() {
        return nombre;
    }
};
void Curso::agregarEstudiante(Estudiante* estudiante) {
    estudiantes.push_back(estudiante);
    estudiante->agregarCurso(this); 
}
void Curso::eliminarEstudiante(Estudiante* estudiante) {
    for (auto it = estudiantes.begin(); it != estudiantes.end(); ++it) {
        if (*it == estudiante) {
            estudiantes.erase(it);
            estudiante->eliminarCurso(this);
            break;
        }
    }
}
void Curso::imprimirEstudiantes() {
    cout << "Estudiantes en el curso " << nombre << " (" << codigo << "):" << endl;
    for (Estudiante* estudiante : estudiantes) {
        cout << "- " << estudiante->getNombre() << endl;
    }
}
void Estudiante::agregarCurso(Curso* curso) {
    cursos.push_back(curso);
}
void Estudiante::eliminarCurso(Curso* curso) {
    for (auto it = cursos.begin(); it != cursos.end(); ++it) {
        if (*it == curso) {
            cursos.erase(it);
            break;
        }
    }
}
void Estudiante::imprimirCursos() {
    cout << "Cursos de " << nombre << " " << apellido << " (ID: " << id << "):" << endl;
    for (Curso* curso : cursos) {
        cout << "- " << curso->getNombre() << endl;
    }
}
int main() {
    Curso* curso1 = new Curso("Matemáticas", "MAT101", "Curso introductorio a las matemáticas", "01/02/2025", "30/06/2025");
    Curso* curso2 = new Curso("Historia", "HIS201", "Curso sobre historia mundial", "01/02/2025", "30/06/2025");
    Estudiante* estudiante1 = new Estudiante("Carlos", "Gomez", "12345", "carlos@gmail.com");
    Estudiante* estudiante2 = new Estudiante("Ana", "Lopez", "67890", "ana@gmail.com");
    curso1->agregarEstudiante(estudiante1);
    curso1->agregarEstudiante(estudiante2);
    curso2->agregarEstudiante(estudiante1);
    estudiante1->agregarCurso(curso1);
    estudiante1->agregarCurso(curso2);
    estudiante2->agregarCurso(curso1);
    curso1->imprimirEstudiantes();
    curso2->imprimirEstudiantes();
    estudiante1->imprimirCursos();
    estudiante2->imprimirCursos();
    cout << "\nEliminando a Carlos de Matemáticas..." << endl;
    curso1->eliminarEstudiante(estudiante1);
    curso1->imprimirEstudiantes();
    estudiante1->imprimirCursos();
    delete curso1;
    delete curso2;
    delete estudiante1;
    delete estudiante2;
    return 0;
}
