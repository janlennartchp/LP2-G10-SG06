#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

class Evento {
public:
    string nombre;
    string fecha;
    vector<string> asistentes;

    Evento() : nombre(""), fecha("") {}
    Evento(string n, string f) : nombre(n), fecha(f) {}

    void agregarAsistente(const string& nombreAsistente) {
        if (nombreAsistente.empty()) {
            cout << "El nombre del asistente no puede estar vacío.\n";
            return;
        }
        asistentes.push_back(nombreAsistente);
    }

    void mostrarAsistentesOrdenados() {
        if (asistentes.empty()) {
            cout << "No hay asistentes registrados para este evento.\n";
            return;
        }

        sort(asistentes.begin(), asistentes.end());
        cout << "\nAsistentes al evento '" << nombre << "' (" << fecha << "):\n";
        for (const string& a : asistentes)
            cout << "- " << a << endl;
    }
};

map<string, Evento> listaEventos;

string leerEntradaNoVacia(const string& mensaje) {
    string entrada;
    do {
        cout << mensaje;
        getline(cin, entrada);
        if (entrada.empty())
            cout << "La entrada no puede estar vacía. Intente nuevamente.\n";
    } while (entrada.empty());
    return entrada;
}

bool validarFecha(const string& fecha) {
    if (fecha.length() != 10) return false;
    if (fecha[4] != '-' || fecha[7] != '-') return false;

    string anio = fecha.substr(0, 4);
    string mes = fecha.substr(5, 2);
    string dia = fecha.substr(8, 2);

    if (!all_of(anio.begin(), anio.end(), ::isdigit)) return false;
    if (!all_of(mes.begin(), mes.end(), ::isdigit)) return false;
    if (!all_of(dia.begin(), dia.end(), ::isdigit)) return false;

    int anio_i = stoi(anio);
    int mes_i = stoi(mes);
    int dia_i = stoi(dia);

    if (anio_i < 1900 || anio_i > 2100) return false;
    if (mes_i < 1 || mes_i > 12) return false;
    if (dia_i < 1 || dia_i > 31) return false;

    // Validación más estricta según mes
    if ((mes_i == 4 || mes_i == 6 || mes_i == 9 || mes_i == 11) && dia_i > 30) return false;
    if (mes_i == 2 && dia_i > 29) return false;

    return true;
}

string leerFechaValida() {
    string fecha;
    do {
        cout << "Fecha del evento (YYYY-MM-DD): ";
        getline(cin, fecha);
        if (!validarFecha(fecha)) {
            cout << "Formato inválido. Ejemplo válido: 2025-06-27\n";
        }
    } while (!validarFecha(fecha));
    return fecha;
}

void agregarEvento() {
    string nombre = leerEntradaNoVacia("Nombre del evento: ");
    
    if (listaEventos.count(nombre)) {
        cout << "Ya existe un evento con ese nombre.\n";
        return;
    }

    string fecha = leerFechaValida();
    listaEventos.emplace(nombre, Evento(nombre, fecha));
    cout << "Evento agregado exitosamente.\n";
}

void agregarAsistente() {
    if (listaEventos.empty()) {
        cout << "No hay eventos registrados aún.\n";
        return;
    }

    string nombreEvento = leerEntradaNoVacia("Nombre del evento: ");
    auto it = listaEventos.find(nombreEvento);

    if (it != listaEventos.end()) {
        string nombreAsistente = leerEntradaNoVacia("Nombre del asistente: ");
        it->second.agregarAsistente(nombreAsistente);
        cout << "Asistente agregado.\n";
    } else {
        cout << "Evento no encontrado.\n";
    }
}

void mostrarAsistentesOrdenados() {
    if (listaEventos.empty()) {
        cout << "No hay eventos registrados.\n";
        return;
    }

    string nombreEvento = leerEntradaNoVacia("Nombre del evento: ");
    auto it = listaEventos.find(nombreEvento);

    if (it != listaEventos.end()) {
        it->second.mostrarAsistentesOrdenados();
    } else {
        cout << "Evento no encontrado.\n";
    }
}

void buscarEventosPorFecha() {
    if (listaEventos.empty()) {
        cout << "No hay eventos registrados.\n";
        return;
    }

    string fecha = leerFechaValida();
    bool encontrado = false;

    for (const auto& par : listaEventos) {
        if (par.second.fecha == fecha) {
            if (!encontrado) {
                cout << "\nEventos en la fecha " << fecha << ":\n";
            }
            cout << "- " << par.second.nombre << endl;
            encontrado = true;
        }
    }

    if (!encontrado)
        cout << "No se encontraron eventos en esa fecha.\n";
}

void menuEventos() {
    int opcion;
    do {
        cout << "\n--- MENÚ ORGANIZACIÓN DE EVENTOS ---\n";
        cout << "1. Agregar evento\n";
        cout << "2. Agregar asistente a un evento\n";
        cout << "3. Mostrar asistentes ordenados\n";
        cout << "4. Buscar eventos por fecha\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: agregarEvento(); break;
            case 2: agregarAsistente(); break;
            case 3: mostrarAsistentesOrdenados(); break;
            case 4: buscarEventosPorFecha(); break;
            case 0: cout << "Saliendo del programa...\n"; break;
            default: cout << "Opción inválida. Intente nuevamente.\n";
        }

    } while (opcion != 0);
}

int main() {
    menuEventos();
    return 0;
}