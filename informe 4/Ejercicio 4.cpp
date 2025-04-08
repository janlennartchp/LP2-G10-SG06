#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Trabajador {
private:
    string nombre;
    int id;
    vector<Trabajador*> compañeros;
public:
    Trabajador(string nombre, int id) : nombre(nombre), id(id) {}
    string getNombre() {
        return nombre;
    }
    int getId() {
        return id;
    }
    void agregarCompanero(Trabajador* compañero) {
        compañeros.push_back(compañero);
    }
    void imprimirCompaneros() {
        cout << "Compañeros de trabajo de " << nombre << " (ID: " << id << "):" << endl;
        for (Trabajador* compañero : compañeros) {
            cout << "- " << compañero->getNombre() << " (ID: " << compañero->getId() << ")" << endl;
        }
    }
};
class Gerente : public Trabajador {
private:
    vector<Trabajador*> trabajadoresACargo;  
public:
    Gerente(string nombre, int id) : Trabajador(nombre, id) {}
    void agregarTrabajadorACargo(Trabajador* trabajador) {
        trabajadoresACargo.push_back(trabajador);
    }
    void imprimirTrabajadoresACargo() {
        cout << "Trabajadores a cargo de " << getNombre() << " (ID: " << getId() << "):" << endl;
        for (Trabajador* trabajador : trabajadoresACargo) {
            cout << "- " << trabajador->getNombre() << " (ID: " << trabajador->getId() << ")" << endl;
            trabajador->imprimirCompaneros();
        }
    }
};
int main() {
    Trabajador* trabajador1 = new Trabajador("Carlos", 101);
    Trabajador* trabajador2 = new Trabajador("Ana", 102);
    Trabajador* trabajador3 = new Trabajador("Luis", 103);
    Trabajador* trabajador4 = new Trabajador("Pedro", 104);
    Gerente* gerente = new Gerente("Juan", 100);
    gerente->agregarTrabajadorACargo(trabajador1);
    gerente->agregarTrabajadorACargo(trabajador2);
    gerente->agregarTrabajadorACargo(trabajador3);
    gerente->agregarTrabajadorACargo(trabajador4);
    trabajador1->agregarCompanero(trabajador2);
    trabajador1->agregarCompanero(trabajador3);
    trabajador2->agregarCompanero(trabajador1);
    trabajador2->agregarCompanero(trabajador4);
    trabajador3->agregarCompanero(trabajador1);
    trabajador4->agregarCompanero(trabajador2);
    gerente->imprimirTrabajadoresACargo();
    delete trabajador1;
    delete trabajador2;
    delete trabajador3;
    delete trabajador4;
    delete gerente;
    return 0;
}
