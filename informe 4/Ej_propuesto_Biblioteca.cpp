#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Asociación unidireccional
class Autor {
private:
    string nombre;
    string nacionalidad;

public:
    Autor(string nombre, string nacionalidad) : nombre(nombre), nacionalidad(nacionalidad) {}

    void mostrarInfo() {
        cout << "Autor: " << nombre << ", Nacionalidad: " << nacionalidad << endl;
    }

    string getNombre() const {
        return nombre;
    }
};
class Libro {
private:
    string ISBN;
    string titulo;
    Autor* autor;  // Asociación unidireccional: Libro sabe quién es su autor

public:
    Libro(string ISBN, string titulo, Autor* autor) : ISBN(ISBN), titulo(titulo), autor(autor) {}
    void mostrarInfo() {
        cout << "ISBN: " << ISBN << ", Título: " << titulo << endl;
        autor->mostrarInfo();
    }

    string getTitulo() const {
        return titulo;
    }

    string getISBN() const {
        return ISBN;
    }

    Autor* getAutor() const {
        return autor;
    }
};
class Usuario {
private:
    string nombre;
    string telefono;
    vector<Libro*> librosPrestados;
public:
    Usuario(string nombre, string telefono) : nombre(nombre), telefono(telefono) {}

    void prestarLibro(Libro* libro) {
        librosPrestados.push_back(libro);
        cout << "Libro prestado a " << nombre << ": " << libro->getTitulo() << endl;
    }
    void mostrarInfo() const {
        cout << "Usuario: " << nombre << ", Teléfono: " << telefono << endl;
        cout << "Libros prestados: " << endl;
        if (librosPrestados.empty()) {
            cout << "No hay libros prestados." << endl;
        }
        for (auto libro : librosPrestados) {
            libro->mostrarInfo();  
        }
    }
    string getNombre() const {
        return nombre;
    }
};
void mostrarMenu() {
    cout << "\n----- Sistema de Gestion de Biblioteca -----" << endl;
    cout << "1. Registrar autor" << endl;
    cout << "2. Registrar libro" << endl;
    cout << "3. Registrar usuario" << endl;
    cout << "4. Prestar libro a usuario" << endl;
    cout << "5. Mostrar información de usuario" << endl;
    cout << "6. Salir" << endl;
    cout << "Ingrese una opción: ";
}
int main() {
    vector<Autor*> autores;
    vector<Libro*> libros;
    vector<Usuario*> usuarios;
    int opcion;
    while (true) {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();  // Para ignorar el salto de línea
        if (opcion == 1) {
            string nombreAutor, nacionalidad;
            cout << "Ingrese el nombre del autor: ";
            getline(cin, nombreAutor);
            cout << "Ingrese la nacionalidad del autor: ";
            getline(cin, nacionalidad);
            Autor* autor = new Autor(nombreAutor, nacionalidad);
            autores.push_back(autor);
            cout << "Autor registrado con éxito!" << endl;
        } else if (opcion == 2) {
            string ISBN, titulo;
            cout << "Ingrese el ISBN del libro: ";
            getline(cin, ISBN);
            cout << "Ingrese el título del libro: ";
            getline(cin, titulo);
            cout << "\nAutores registrados:\n";
            for (int i = 0; i < autores.size(); ++i) {
                cout << i + 1 << ". " << autores[i]->getNombre() << endl;
            }
            int opcionAutor;
            cout << "Seleccione el autor del libro (1-" << autores.size() << "): ";
            cin >> opcionAutor;
            cin.ignore();
            if (opcionAutor >= 1 && opcionAutor <= autores.size()) {
                Autor* autorSeleccionado = autores[opcionAutor - 1];
                Libro* libro = new Libro(ISBN, titulo, autorSeleccionado);
                libros.push_back(libro);
                cout << "Libro registrado con éxito!" << endl;
            } else {
                cout << "Opción inválida. El libro no ha sido registrado." << endl;
            }
        } else if (opcion == 3) {
            string nombreUsuario, telefono;
            cout << "Ingrese el nombre del usuario: ";
            getline(cin, nombreUsuario);
            cout << "Ingrese el teléfono del usuario: ";
            getline(cin, telefono);
            Usuario* usuario = new Usuario(nombreUsuario, telefono);
            usuarios.push_back(usuario);
            cout << "Usuario registrado con éxito!" << endl;
        } else if (opcion == 4) {
            string nombreUsuario;
            cout << "Ingrese el nombre del usuario: ";
            getline(cin, nombreUsuario);
            Usuario* usuarioEncontrado = nullptr;
            for (auto usuario : usuarios) {
                if (usuario->getNombre() == nombreUsuario) {
                    usuarioEncontrado = usuario;
                    break;
                }
            }
            if (usuarioEncontrado != nullptr) {
                cout << "Libros registrados:\n";
                for (int i = 0; i < libros.size(); ++i) {
                    cout << i + 1 << ". " << libros[i]->getTitulo() << endl;
                }
                int opcionLibro;
                cout << "Seleccione el libro a prestar (1-" << libros.size() << "): ";
                cin >> opcionLibro;
                cin.ignore();
                if (opcionLibro >= 1 && opcionLibro <= libros.size()) {
                    usuarioEncontrado->prestarLibro(libros[opcionLibro - 1]);
                } else {
                    cout << "Opción inválida. El libro no ha sido prestado." << endl;
                }
            } else {
                cout << "Usuario no encontrado." << endl;
            }
        } else if (opcion == 5) {
            string nombreUsuario;
            cout << "Ingrese el nombre del usuario para ver su información: ";
            getline(cin, nombreUsuario);
            Usuario* usuarioEncontrado = nullptr;
            for (auto usuario : usuarios) {
                if (usuario->getNombre() == nombreUsuario) {
                    usuarioEncontrado = usuario;
                    break;
                }
            }
            if (usuarioEncontrado != nullptr) {
                usuarioEncontrado->mostrarInfo();
            } else {
                cout << "Usuario no encontrado." << endl;
            }
        } else if (opcion == 6) {
            cout << "¡Gracias por usar el sistema!" << endl;
            break;
        } else {
            cout << "Opción inválida. Intente nuevamente." << endl;
        }
    }
    for (auto autor : autores) {
        delete autor;
    }
    for (auto libro : libros) {
        delete libro;
    }
    for (auto usuario : usuarios) {
        delete usuario;
    }

    return 0;
}
