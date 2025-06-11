#include <iostream>
#include <vector>
#include <memory>
using namespace std;
class Personaje {
public:
    virtual void atacar() const = 0;
    virtual void defender() const = 0;
    virtual void habilidadEspecial() const = 0;
    virtual ~Personaje() {}
};
class Guerrero : public Personaje {
public:
    void atacar() const override {
        cout << "Guerrero ataca con espada " << endl;
    }
    void defender() const override {
        cout << "Guerrero bloquea con escudo ️" << endl;
    }
    void habilidadEspecial() const override {
        cout << "Guerrero usa 'Furia' " << endl;
    }
};
class Mago : public Personaje {
public:
    void atacar() const override {
        cout << "Mago lanza un hechizo " << endl;
    }
    void defender() const override {
        cout << "Mago crea un escudo magico " << endl;
    }
    void habilidadEspecial() const override {
        cout << "Mago usa 'Tormenta Arcana' " << endl;
    }
};
class Arquero : public Personaje {
public:
    void atacar() const override {
        cout << "Arquero dispara una flecha " << endl;
    }
    void defender() const override {
        cout << "Arquero esquiva el ataque " << endl;
    }
    void habilidadEspecial() const override {
        cout << "Arquero usa 'Lluvia de Flechas' ️" << endl;
    }
};
void mostrarMenu() {
    cout << "\n=== MENÚ RPG ===" << endl;
    cout << "1. Agregar Guerrero" << endl;
    cout << "2. Agregar Mago" << endl;
    cout << "3. Agregar Arquero" << endl;
    cout << "4. Ejecutar acciones" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opción: ";
}
int main() {
    vector<shared_ptr<Personaje>> personajes;
    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                personajes.push_back(make_shared<Guerrero>());
                cout << "Guerrero agregado." << endl;
                break;
            case 2:
                personajes.push_back(make_shared<Mago>());
                cout << "Mago agregado." << endl;
                break;
            case 3:
                personajes.push_back(make_shared<Arquero>());
                cout << "Arquero agregado." << endl;
                break;
            case 4:
                if (personajes.empty()) {
                    cout << "No hay personajes creados." << endl;
                } else {
                    cout << "\n--- ACCIONES DE LOS PERSONAJES ---\n";
                    for (size_t i = 0; i < personajes.size(); ++i) {
                        cout << "\nPersonaje #" << i + 1 << endl;
                        personajes[i]->atacar();
                        personajes[i]->defender();
                        personajes[i]->habilidadEspecial();
                    }
                }
                break;
            case 5:
                cout << "Saliendo del juego..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    } while (opcion != 5);
    return 0;
}
