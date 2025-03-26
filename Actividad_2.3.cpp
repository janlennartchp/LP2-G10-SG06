#include <iostream>
using namespace std;

class Libro {
private:
    string titulo;
    string autor;
    string genero;
public:
    Libro(string _titulo, string _autor, string _genero) {
        titulo = _titulo;
        autor = _autor;
        genero = _genero;
    }
    string getTitulo() { return titulo; }
    string getAutor() { return autor; }
    string getGenero() { return genero; }

    void mostrarInfoLibro() {
        cout << "Titulo: " << titulo << ", Autor: " << autor << ", Genero: " << genero << endl;
    }
};

int main() {
    Libro libro1("1984", "George Orwell", "Distopia");
    Libro libro2("El principito", "Antoine de Saint-Exupéry", "Ficcion");
    libro1.mostrarInfoLibro();
    libro2.mostrarInfoLibro();

    return 0;
}

