#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <memory>
using namespace std;
// Clase base
class Forma {
public:
    virtual double calcularArea() const = 0;
    virtual double calcularPerimetro() const = 0;
    virtual void mostrarInformacion() const = 0;
    virtual ~Forma() {}
};
// Registro de fábrica
using CreadorForma = Forma* (*)();
map<string, CreadorForma> registroFormas;
// --------------------- Formas conocidas -----------------------
class Circulo : public Forma {
    double radio;
public:
    Circulo() {
        cout << "Ingrese el radio: ";
        cin >> radio;
    }
    double calcularArea() const override {
        return M_PI * radio * radio;
    }
    double calcularPerimetro() const override {
        return 2 * M_PI * radio;
    }
    void mostrarInformacion() const override {
        cout << "Circulo - Radio: " << radio << "\n";
        cout << "Area: " << calcularArea() << ", Perimetro: " << calcularPerimetro() << "\n";
    }
};
Forma* crearCirculo() { return new Circulo(); }
class Rectangulo : public Forma {
    double base, altura;
public:
    Rectangulo() {
        cout << "Ingrese base y altura: ";
        cin >> base >> altura;
    }
    double calcularArea() const override {
        return base * altura;
    }
    double calcularPerimetro() const override {
        return 2 * (base + altura);
    }
    void mostrarInformacion() const override {
        cout << "Rectangulo - Base: " << base << ", Altura: " << altura << "\n";
        cout << "Area: " << calcularArea() << ", Perimetro: " << calcularPerimetro() << "\n";
    }
};
Forma* crearRectangulo() { return new Rectangulo(); }
class Triangulo : public Forma {
    double a, b, c;
public:
    Triangulo() {
        cout << "Ingrese los lados a, b y c: ";
        cin >> a >> b >> c;
        if (a + b <= c || a + c <= b || b + c <= a) {
            cout << "Triangulo invalido. Se usaran lados 1, 1, 1.\n";
            a = b = c = 1;
        }
    }
    double calcularArea() const override {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    double calcularPerimetro() const override {
        return a + b + c;
    }
    void mostrarInformacion() const override {
        cout << "Triangulo - Lados: " << a << ", " << b << ", " << c << "\n";
        cout << "Area: " << calcularArea() << ", Perimetro: " << calcularPerimetro() << "\n";
    }
};
Forma* crearTriangulo() { return new Triangulo(); }
// --------------------- Forma Personalizada -----------------------
class FormaPersonalizada : public Forma {
    string nombre;
    double area, perimetro;
public:
    FormaPersonalizada(string n, double a, double p) : nombre(n), area(a), perimetro(p) {}
    double calcularArea() const override { return area; }
    double calcularPerimetro() const override { return perimetro; }
    void mostrarInformacion() const override {
        cout << "Forma personalizada - " << nombre << "\n";
        cout << "Area: " << area << ", Perimetro: " << perimetro << "\n";
    }
};
// --------------------- Menú -----------------------
void inicializarRegistro() {
    registroFormas["Circulo"] = crearCirculo;
    registroFormas["Rectangulo"] = crearRectangulo;
    registroFormas["Triangulo"] = crearTriangulo;
}
void mostrarFormasDisponibles() {
    cout << "\nFormas disponibles:\n";
    for (const auto& entrada : registroFormas) {
        cout << "- " << entrada.first << "\n";
    }
}
void mostrarMenu() {
    cout << "\n--- MENU ---\n";
    cout << "1. Agregar forma existente\n";
    cout << "2. Agregar nueva forma personalizada\n";
    cout << "3. Mostrar todas las formas\n";
    cout << "4. Salir\n";
    cout << "Seleccione una opcion: ";
}
// --------------------- Main -----------------------
int main() {
    inicializarRegistro();
    vector<Forma*> formas;
    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
        case 1: {
            mostrarFormasDisponibles();
            cout << "Ingrese el nombre de la forma a agregar: ";
            string tipo;
            cin >> tipo;
            auto it = registroFormas.find(tipo);
            if (it != registroFormas.end()) {
                Forma* nueva = it->second();
                formas.push_back(nueva);
            } else {
                cout << "Tipo no registrado.\n";
            }
            break;
        }
        case 2: {
            string nombre;
            double area, perimetro;
            cout << "Ingrese nombre de la nueva forma: ";
            cin.ignore();
            getline(cin, nombre);
            cout << "Ingrese el área estimada: ";
            cin >> area;
            cout << "Ingrese el perímetro estimado: ";
            cin >> perimetro;
            formas.push_back(new FormaPersonalizada(nombre, area, perimetro));
            cout << "Forma personalizada agregada.\n";
            break;
        }
        case 3: {
            cout << "\n--- Formas registradas ---\n";
            for (Forma* f : formas) {
                f->mostrarInformacion();
                cout << "--------------------------\n";
            }
            break;
        }
        case 4:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opción inválida.\n";
        }
    } while (opcion != 4);
    for (Forma* f : formas) delete f;
    return 0;
}
