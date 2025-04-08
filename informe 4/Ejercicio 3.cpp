#include <iostream>
#include <string>
using namespace std;
class Estudiante {
private:
    string nombre;
    int id;
public:
    Estudiante(string nombre, int id) : nombre(nombre), id(id) {}
    string getNombre() { return nombre; }
    int getId() { return id; }
    void imprimirInfo() {
        cout << "Estudiante: " << nombre << " (ID: " << id << ")" << endl;
    }
};
class Docente {
private:
    string nombre;
    int id;
public:
    Docente(string nombre, int id) : nombre(nombre), id(id) {}
    string getNombre() { return nombre; }
    int getId() { return id; }
    void imprimirInfo() {
        cout << "Docente: " << nombre << " (ID: " << id << ")" << endl;
    }
};
class Curso {
private:
    string nombre;
    string codigo;
public:
    Curso(string nombre, string codigo) : nombre(nombre), codigo(codigo) {}
    string getNombre() { return nombre; }
    string getCodigo() { return codigo; }
    void imprimirInfo() {
        cout << "Curso: " << nombre << " (Código: " << codigo << ")" << endl;
    }
};
class Asociacion {
private:
    Estudiante* estudiante; 
    Docente* docente;      
    Curso* curso;    
public:
    Asociacion(Estudiante* estudiante, Docente* docente, Curso* curso)
        : estudiante(estudiante), docente(docente), curso(curso) {}
    void imprimirRelacion() {
        cout << "Relación Ternaria: " << endl;
        estudiante->imprimirInfo();
        docente->imprimirInfo();
        curso->imprimirInfo();
        cout << "Este estudiante está inscrito en el curso " << curso->getNombre() 
             << ", impartido por el docente " << docente->getNombre() << "." << endl;
    }
};
int main() {
    Estudiante* estudiante1 = new Estudiante("Carlos Gomez", 101);
    Estudiante* estudiante2 = new Estudiante("Ana Lopez", 102);
    Docente* docente1 = new Docente("Dr. Juan Perez", 201);
    Docente* docente2 = new Docente("Lic. Maria Ruiz", 202);
    Curso* curso1 = new Curso("Matemáticas", "MAT101");
    Curso* curso2 = new Curso("Historia", "HIS202");
    Asociacion* asociacion1 = new Asociacion(estudiante1, docente1, curso1);
    Asociacion* asociacion2 = new Asociacion(estudiante2, docente2, curso2);
    asociacion1->imprimirRelacion();
    cout << endl;
    asociacion2->imprimirRelacion();
    delete estudiante1;
    delete estudiante2;
    delete docente1;
    delete docente2;
    delete curso1;
    delete curso2;
    delete asociacion1;
    delete asociacion2;
    return 0;
}
