#include <iostream>
#include <string>
using namespace std;
class Ruta {
private:
    string idRuta;
    double distancia;
public:
    Ruta(string id, double dist) : idRuta(id), distancia(dist) {}
    template <typename T>
    void planificarHorario(T factor) {
        cout << "Planificando ruta " << idRuta 
             << " con factor de planificación: " << factor << endl;
    }
    void mostrar() const {
        cout << "Ruta ID: " << idRuta << " | Distancia: " << distancia << " km\n";
    }
};
class Entrega {
private:
    string idEntrega;
    string destinatario;
public:
    Entrega(string id, string dest) : idEntrega(id), destinatario(dest) {}
    template <typename Vehiculo>
    void asignarVehiculo(Vehiculo veh) {
        cout << "Entrega " << idEntrega 
             << " asignada al vehículo: " << veh << endl;
    }
    void mostrar() const {
        cout << "Entrega ID: " << idEntrega << " | Destinatario: " << destinatario << endl;
    }
};
int main() {
    Ruta r1("R-101", 15.7);
    r1.mostrar();
    r1.planificarHorario(8);
    r1.planificarHorario("08:30 AM");
    Entrega e1("E-550", "Juan Pérez");
    e1.mostrar();
    e1.asignarVehiculo("Camión A1"); 
    e1.asignarVehiculo(102);
    return 0;
}
