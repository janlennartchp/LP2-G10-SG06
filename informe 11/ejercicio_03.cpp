#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Persona {
private:
    string nombre;
    int edad;
    string direccion;
public:
    Persona() = default;
    Persona(string n, int e, string d) : nombre(n), edad(e), direccion(d) {}
    void mostrar() const {
        cout << "Nombre: " << nombre << "\nEdad: " << edad
             << "\nDirección: " << direccion << endl;
    }
    void guardarEnArchivo(const string& archivo) const {
        ofstream out(archivo, ios::binary);
        size_t tam;
        tam = nombre.size();
        out.write(reinterpret_cast<const char*>(&tam), sizeof(tam));
        out.write(nombre.c_str(), tam);
        out.write(reinterpret_cast<const char*>(&edad), sizeof(edad));
        tam = direccion.size();
        out.write(reinterpret_cast<const char*>(&tam), sizeof(tam));
        out.write(direccion.c_str(), tam);
        out.close();
    }
    void cargarDeArchivo(const string& archivo) {
        ifstream in(archivo, ios::binary);
        size_t tam;
        char* buffer;
        in.read(reinterpret_cast<char*>(&tam), sizeof(tam));
        buffer = new char[tam + 1];
        in.read(buffer, tam);
        buffer[tam] = '\0';
        nombre = buffer;
        delete[] buffer;
        in.read(reinterpret_cast<char*>(&edad), sizeof(edad));
        in.read(reinterpret_cast<char*>(&tam), sizeof(tam));
        buffer = new char[tam + 1];
        in.read(buffer, tam);
        buffer[tam] = '\0';
        direccion = buffer;
        delete[] buffer;
        in.close();
    }
};
int main() {
    Persona p1("Ana Torres", 22, "Calle Los Olivos 321");
    p1.guardarEnArchivo("persona.bin");
    Persona p2;
    p2.cargarDeArchivo("persona.bin");
    cout << "\nDatos deserializados:\n";
    p2.mostrar();
    return 0;
}
