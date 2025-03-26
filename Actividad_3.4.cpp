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

    bool esIgualA(Libro otro) {
        return (titulo == otro.titulo) && (autor == otro.autor);
    }
};
int main() {
    Libro libro1("1984", "George Orwell");
    Libro libro2("1984", "George Orwell");
    Libro libro3("Cien años de soledad", "Gabriel García Márquez");
    if (libro1.esIgualA(libro2)) cout << "Los libros son iguales." << endl;
    else cout << "Los libros son diferentes." << endl;
    if (libro1.esIgualA(libro3)) cout << "Los libros son iguales." << endl;
    else cout << "Los libros son diferentes." << endl;
    return 0;
}

