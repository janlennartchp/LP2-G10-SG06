#include <iostream>
using namespace std;

class Estudiante {
private:
    string nombre;
    int edad;
    string grado;
    float calificacion;

public:
    Estudiante(string _nombre, int _edad, string _grado) {
        nombre = _nombre;
        edad = _edad;
        grado = _grado;
        calificacion = 0;
    }

    void tomarExamen() {
        cout << nombre << " está tomando un examen." << endl;
    }

    void recibirCalificacion(float nota) {
        calificacion = nota;
        cout << nombre << " recibió una calificación de " << calificacion << "." << endl;
    }
};

int main() {
    Estudiante est1("Ana", 19, "Universidad");
    Estudiante est2("Luis", 17, "Secundaria");

    est1.tomarExamen();
    est2.recibirCalificacion(18.5);

    return 0;
}

