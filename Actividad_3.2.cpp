#include <iostream>
using namespace std;
class Libro {
private:
    string titulo;
    string autor;

public:
    Libro(string _titulo, string _autor) {
        titulo = _titulo;
        autor = _autor;
    }

    void mostrarInfo() {
        cout << "Titulo: " << titulo << ", Autor: " << autor << endl;
    }
};

int main() {
    Libro biblioteca[3] = {
        Libro("1984", "George Orwell"),
        Libro("Cien aos de soledad", "Gabriel Garcia Marquez"),
        Libro("El principito", "Antoine de Saint-Exupéry")
    };

    for (int i = 0; i < 3; i++) {
        biblioteca[i].mostrarInfo();
    }

    return 0;
}

