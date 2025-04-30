#include <iostream>
#include <string>
using namespace std;

class Habitacion {
private:
    int numero;
    string tipo;
    double precioPorNoche;

public:
    Habitacion(int num = 0, string t = "", double precio = 0.0)
        : numero(num), tipo(t), precioPorNoche(precio) {}

    double getPrecioPorNoche() const {
        return precioPorNoche;
    }

    void mostrar() const {
        cout << "Habitación " << numero << " | Tipo: " << tipo
             << " | Precio por noche: S/ " << precioPorNoche << endl;
    }
};

class ReservaHotel {
private:
    Habitacion* habitaciones;
    int cantidad;

public:
    ReservaHotel(int cant) : cantidad(cant) {
        habitaciones = new Habitacion[cantidad];
        for (int i = 0; i < cantidad; ++i) {
            int opcionTipo;
            string tipo;
            double precio;

            cout << "\nSeleccione tipo de habitación " << (i + 1) << ":\n";
            cout << "1. Simple (S/ 100)\n";
            cout << "2. Doble (S/ 150)\n";
            cout << "3. Suite  (S/ 250)\n";
            
            do {
                cout << "Ingrese opción (1-3): ";
                cin >> opcionTipo;
                if (opcionTipo < 1 || opcionTipo > 3)
                    cout << "opción inválida. Intente nuevamente.\n";
            } while (opcionTipo < 1 || opcionTipo > 3);

            switch (opcionTipo) {
                case 1: tipo = "Simple"; precio = 100; break;
                case 2: tipo = "Doble";  precio = 150; break;
                case 3: tipo = "Suite";  precio = 250; break;
            }

            habitaciones[i] = Habitacion(i + 1, tipo, precio);
        }
    }

    ~ReservaHotel() {
        delete[] habitaciones;
        cout << "\nMemoria liberada (ReservaHotel).\n";
    }

    void mostrarHabitaciones() const {
        cout << "\nLista de habitaciones:\n";
        for (int i = 0; i < cantidad; ++i)
            habitaciones[i].mostrar();
    }

    double calcularTotalPorNoche() const {
        double total = 0;
        for (int i = 0; i < cantidad; ++i)
            total += habitaciones[i].getPrecioPorNoche();
        return total;
    }
};

int main() {
    int opcion;
    ReservaHotel* reserva = nullptr;

    do {
        cout << "\n=== MENÚ RESERVA HOTEL ===\n";
        cout << "1. Crear nueva reserva\n";
        cout << "2. Mostrar habitaciones\n";
        cout << "3. Calcular total por noche\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                if (reserva) delete reserva;
                int cant;
                cout << "¿Cuántas habitaciones desea registrar?: ";
                cin >> cant;
                reserva = new ReservaHotel(cant);
                break;
            }
            case 2:
                if (reserva)
                    reserva->mostrarHabitaciones();
                else
                    cout << "Primero debe crear una reserva.\n";
                break;
            case 3:
                if (reserva)
                    cout << "\nTotal por noche: S/ " << reserva->calcularTotalPorNoche() << endl;
                else
                    cout << "Primero debe crear una reserva.\n";
                break;
            case 0:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "opción inválida.\n";
        }
    } while (opcion != 0);

    delete reserva;
    return 0;
}
