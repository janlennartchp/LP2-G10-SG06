#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <functional>
using namespace std;
// Clase base abstracta
class Animal {
public:
    virtual void comer() const = 0;
    virtual void dormir() const = 0;
    virtual void moverse() const = 0;
    virtual void info() const = 0;
    virtual ~Animal() {}
};
// Fábrica dinámica para animales
class AnimalFactory {
public:
    using Creador = function<Animal*()>;
    static AnimalFactory& instancia() {
        static AnimalFactory instancia;
        return instancia;
    }
    void registrar(const string& tipo, Creador creador) {
        creadores[tipo] = creador;
    }
    Animal* crear(const string& tipo) const {
        auto it = creadores.find(tipo);
        if (it != creadores.end()) {
            return it->second();
        }
        return nullptr;
    }
    void listar() const {
        cout << "\nEspecies registradas:\n";
        for (const auto& par : creadores) {
            cout << " - " << par.first << "\n";
        }
    }
    bool existe(const string& tipo) const {
        return creadores.count(tipo) > 0;
    }
private:
    map<string, Creador> creadores;
};
// Implementación de Mamifero
class Mamifero : public Animal {
public:
    void comer() const override { cout << "El mamífero está comiendo hierba o carne.\n"; }
    void dormir() const override { cout << "El mamífero duerme tumbado.\n"; }
    void moverse() const override { cout << "El mamífero camina o corre.\n"; }
    void info() const override {
        cout << "\n[Mamífero]\n";
        comer(); dormir(); moverse();
    }
};
// Implementación de Ave
class Ave : public Animal {
public:
    void comer() const override { cout << "El ave picotea semillas.\n"; }
    void dormir() const override { cout << "El ave duerme en su nido.\n"; }
    void moverse() const override { cout << "El ave vuela.\n"; }
    void info() const override {
        cout << "\n[Ave]\n";
        comer(); dormir(); moverse();
    }
};
// Implementación de Reptil
class Reptil : public Animal {
public:
    void comer() const override { cout << "El reptil se alimenta de insectos.\n"; }
    void dormir() const override { cout << "El reptil duerme en zonas cálidas.\n"; }
    void moverse() const override { cout << "El reptil se arrastra.\n"; }
    void info() const override {
        cout << "\n[Reptil]\n";
        comer(); dormir(); moverse();
    }
};
// Registro estático de clases básicas
void registrarEspeciesBase() {
    AnimalFactory::instancia().registrar("Mamifero", []() { return new Mamifero(); });
    AnimalFactory::instancia().registrar("Ave", []() { return new Ave(); });
    AnimalFactory::instancia().registrar("Reptil", []() { return new Reptil(); });
}
// Clase personalizada generada dinámicamente
class EspeciePersonalizada : public Animal {
    string nombre, comida, sueno, movimiento;
public:
    EspeciePersonalizada(string n, string c, string d, string m)
        : nombre(n), comida(c), sueno(d), movimiento(m) {}
    void comer() const override { cout << comida << endl; }
    void dormir() const override { cout << sueno << endl; }
    void moverse() const override { cout << movimiento << endl; }
    void info() const override {
        cout << "\n[" << nombre << "]\n";
        comer(); dormir(); moverse();
    }
};
// Menú
void mostrarMenu() {
    cout << "\n--- SIMULADOR DE ANIMALES ---\n";
    cout << "1. Agregar animal\n";
    cout << "2. Mostrar todos los animales\n";
    cout << "3. Agregar nueva especie\n";
    cout << "4. Listar especies disponibles\n";
    cout << "5. Salir\n";
    cout << "Seleccione una opción: ";
}
int main() {
    registrarEspeciesBase();
    vector<unique_ptr<Animal>> animales;
    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            AnimalFactory::instancia().listar();
            cout << "Ingrese el nombre de la especie: ";
            string especie;
            getline(cin, especie);
            Animal* nuevo = AnimalFactory::instancia().crear(especie);
            if (nuevo) {
                animales.emplace_back(nuevo);
                cout << especie << " agregado correctamente.\n";
            } else {
                cout << "Especie no encontrada.\n";
            }
        }
        else if (opcion == 2) {
            if (animales.empty()) {
                cout << "No hay animales registrados.\n";
            } else {
                for (const auto& a : animales) {
                    a->info();
                }
            }
        }
        else if (opcion == 3) {
            string nombre, comida, dormir, moverse;
            cout << "Nombre de la nueva especie: ";
            getline(cin, nombre);

            if (AnimalFactory::instancia().existe(nombre)) {
                cout << "Esa especie ya existe.\n";
                continue;
            }
            cout << "¿Cómo come esta especie? ";
            getline(cin, comida);
            cout << "¿Cómo duerme esta especie? ";
            getline(cin, dormir);
            cout << "¿Cómo se mueve esta especie? ";
            getline(cin, moverse);
            AnimalFactory::instancia().registrar(nombre, [=]() {
                return new EspeciePersonalizada(nombre, comida, dormir, moverse);
            });
            cout << "Especie personalizada '" << nombre << "' agregada correctamente.\n";
        }
        else if (opcion == 4) {
            AnimalFactory::instancia().listar();
        }
        else if (opcion == 5) {
            cout << "Saliendo del simulador...\n";
        }
        else {
            cout << "Opción inválida.\n";
        }
    } while (opcion != 5);
    return 0;
}
