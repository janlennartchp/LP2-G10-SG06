#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// ------------------------------
// 1. Juego de Carreras
// ------------------------------
class Auto {
private:
    string nombre;
    int velocidad;

public:
    Auto(string nombre, int velocidad) : nombre(nombre), velocidad(velocidad) {}

    int getVelocidad() { return velocidad; }
    string getNombre() { return nombre; }
};

class Carrera {
private:
    int distanciaTotal;
    int dificultad;

public:
    Carrera(int distancia, int dificultad) : distanciaTotal(distancia), dificultad(dificultad) {}

    void competir(Auto jugador) {
        srand(time(0)); 
        int tiempoJugador = distanciaTotal / jugador.getVelocidad();
        int velocidadCPU = 10 + rand() % (dificultad * 10);
        int tiempoCPU = distanciaTotal / velocidadCPU;

        cout << "Tiempo del jugador: " << tiempoJugador << " segundos." << endl;
        cout << "Tiempo de la CPU: " << tiempoCPU << " segundos." << endl;

        if (tiempoJugador < tiempoCPU) {
            cout << jugador.getNombre() << " gana la carrera!" << endl;
        } else {
            cout << "La CPU gana la carrera!" << endl;
        }
    }
};

// ------------------------------
// 2. Sistema de Gestión de Pedidos
// ------------------------------
class Producto {
private:
    string nombre;
    int stock;

public:
    Producto(string nombre, int stock) : nombre(nombre), stock(stock) {}

    bool disponible(int cantidad) { return stock >= cantidad; }

    void reducirStock(int cantidad) {
        if (disponible(cantidad)) stock -= cantidad;
    }

    string getNombre() { return nombre; }
    int getStock() { return stock; }
};

class Inventario {
private:
    vector<Producto> disponibles;
    vector<Producto> agotados;

public:
    void agregarProducto(Producto producto) {
        if (producto.getStock() > 0) {
            disponibles.push_back(producto);
        } else {
            agotados.push_back(producto);
        }
    }

    void realizarPedido(string nombre, int cantidad) {
        for (auto& producto : disponibles) {
            if (producto.getNombre() == nombre && producto.disponible(cantidad)) {
                producto.reducirStock(cantidad);
                cout << "Pedido realizado para " << cantidad << " unidades de " << nombre << endl;
                if (producto.getStock() == 0) {
                    agotados.push_back(producto);
                }
                return;
            }
        }
        cout << "Producto agotado o insuficiente stock." << endl;
    }
};

// ------------------------------
// 3. Programa de Simulación de Vuelo
// ------------------------------
class Avion {
private:
    string modelo;
    double capacidadCombustible;
    double consumoPorHora;

public:
    Avion(string modelo, double capacidad, double consumo) 
        : modelo(modelo), capacidadCombustible(capacidad), consumoPorHora(consumo) {}

    bool tieneCombustibleSuficiente(double duracion) {
        return capacidadCombustible >= (consumoPorHora * duracion);
    }

    string getModelo() { return modelo; }
};

class Mision {
private:
    string destino;
    double duracion;
    int tripulacion;

public:
    Mision(string destino, double duracion, int tripulacion) 
        : destino(destino), duracion(duracion), tripulacion(tripulacion) {}

    void simularVuelo(Avion avion) {
        cout << "Simulando vuelo con destino a " << destino << "..." << endl;
        if (avion.tieneCombustibleSuficiente(duracion)) {
            cout << "Mision exitosa! El avion " << avion.getModelo() << " completo el vuelo." << endl;
        } else {
            cout << "Mision fallida! No hay suficiente combustible." << endl;
        }
    }
};

// ------------------------------
// Función principal
// ------------------------------
int main() {
    // Prueba del juego de carreras
    Carrera carrera(500, 3);
    Auto autoJugador("Coche Rojo", 50);
    carrera.competir(autoJugador);

    // Prueba del sistema de gestión de pedidos
    Inventario inventario;
    Producto prod1("Laptop", 10);
    Producto prod2("Teléfono", 0);
    inventario.agregarProducto(prod1);
    inventario.agregarProducto(prod2);
    inventario.realizarPedido("Laptop", 2);
    
    // Prueba del programa de simulación de vuelo
    Avion avion1("Boeing 747", 10000, 500);
    Mision mision1("Paris", 18, 5);
    mision1.simularVuelo(avion1);

    return 0;
}
