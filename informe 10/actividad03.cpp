#include <iostream>
#include <vector>
using namespace std;
class Ruta {
private:
    string id;
    double distancia;
public:
    Ruta(string idRuta, double dist) : id(idRuta), distancia(dist) {}
    void mostrar() const {
        cout << "Ruta ID: " << id << ", Distancia: " << distancia << " km" << endl;
    }
};
template <typename T>
class GestorEntregas {
private:
    vector<T> elementos;
public:
    void agregarElemento(const T& elem) {
        elementos.push_back(elem);
    }
    void mostrarElementos() const {
        cout << "=== Mostrando elementos del gestor ===" << endl;
        for (const auto& elem : elementos) {
            elem.mostrar();
        }
    }
    int cantidad() const {
        return elementos.size();
    }
};
int main() {
    GestorEntregas<Ruta> gestorRutas;
    gestorRutas.agregarElemento(Ruta("R-001", 15.5));
    gestorRutas.agregarElemento(Ruta("R-002", 22.3));
    gestorRutas.agregarElemento(Ruta("R-003", 10.0));
    gestorRutas.mostrarElementos();
    cout << "Total de rutas registradas: " << gestorRutas.cantidad() << endl;
    return 0;
}
