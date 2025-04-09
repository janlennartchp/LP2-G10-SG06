#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Clase de los objetos agregados (Libro)
class Libro {
private:
    string titulo;
    int codigo;

public:
    Libro(string titulo, int codigo) {
        this->titulo = titulo;
        this->codigo = codigo;
    }

    string getTitulo() {
        return titulo;
    }

    int getCodigo() {
        return codigo;
    }

    void setTitulo(string nuevoTitulo) {
        titulo = nuevoTitulo;
    }
};

// Clase base (Biblioteca) - contiene la colección de libros
class Biblioteca {
private:
    string nombre;
    vector<Libro*> libros;

public:
    Biblioteca(string nombre) {
        this->nombre = nombre;
    }

    ~Biblioteca() {
        for (int i = 0; i < libros.size(); i++) {
            delete libros[i];
        }
        libros.clear();
    }

    void agregarLibro(Libro* libro) {
        libros.push_back(libro);
    }

    void eliminarLibroPorCodigo(int codigo) {
        for (int i = 0; i < libros.size(); i++) {
            if (libros[i]->getCodigo() == codigo) {
                delete libros[i];
                libros.erase(libros.begin() + i);
                break;
            }
        }
    }

    Libro* obtenerLibroPorCodigo(int codigo) {
        for (int i = 0; i < libros.size(); i++) {
            if (libros[i]->getCodigo() == codigo) {
                return libros[i];
            }
        }
    }

    void mostrarLibros() {
        cout << "Libros en la biblioteca \"" << nombre << "\":" << endl;
        for (int i = 0; i < libros.size(); i++) {
            cout << "- " << libros[i]->getTitulo() << " (Codigo: " << libros[i]->getCodigo() << ")" << endl;
        }
    }
};

int main() {
    // Crear libros
    Libro* libro1 = new Libro("Harry Potter", 1);
    Libro* libro2 = new Libro("Cien años de soledad", 2);
    Libro* libro3 = new Libro("El principito", 3);

    // Crear biblioteca
    Biblioteca biblioteca("Biblioteca Central");

    // Agregar libros
    biblioteca.agregarLibro(libro1);
    biblioteca.agregarLibro(libro2);
    biblioteca.agregarLibro(libro3);

    // Mostrar libros
    biblioteca.mostrarLibros();

    // Acceder a un libro y modificarlo
    Libro* buscado = biblioteca.obtenerLibroPorCodigo(2);
    if (buscado != 0) {
        buscado->setTitulo("Cien años de soledad (Edicion especial)");
    }

    // Eliminar un libro
    biblioteca.eliminarLibroPorCodigo(1);

    // Mostrar libros actualizados
    cout << "\nDespues de modificar y eliminar:" << endl;
    biblioteca.mostrarLibros();

    return 0;
}


