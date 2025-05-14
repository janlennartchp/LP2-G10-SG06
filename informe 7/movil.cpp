#include <iostream>
#include <string>
using namespace std;
// -------- Clase Base: Móvil --------
class Movil {
protected:
    string marca;
    string modelo;
    string sistemaOperativo;
public:
    Movil(string _marca, string _modelo, string _sistemaOperativo)
        : marca(_marca), modelo(_modelo), sistemaOperativo(_sistemaOperativo) {
        cout << "Constructor de Móvil: " << marca << " " << modelo << " creado." << endl;
    }
    virtual ~Movil() {
        cout << "Destructor de Móvil: " << marca << " " << modelo << " destruido." << endl;
    }
    void mostrarDatos() const {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Sistema Operativo: " << sistemaOperativo << endl;
    }
};
// -------- Clase Derivada: Teléfono --------
class Telefono : public Movil {
private:
    string tipoRed;
public:
    Telefono(string _marca, string _modelo, string _sistemaOperativo, string _tipoRed)
        : Movil(_marca, _modelo, _sistemaOperativo), tipoRed(_tipoRed) {
        cout << "Constructor de Teléfono: " << marca << " " << modelo << " creado." << endl;
    }
    ~Telefono() {
        cout << "Destructor de Teléfono: " << marca << " " << modelo << " destruido." << endl;
    }
    void mostrarDatosTelefono() const {
        mostrarDatos(); 
        cout << "Tipo de Red: " << tipoRed << endl;
    }
};
// -------- Clase Derivada: Tablet --------
class Tablet : public Movil {
private:
    bool tienePencil;
public:
    Tablet(string _marca, string _modelo, string _sistemaOperativo, bool _tienePencil)
        : Movil(_marca, _modelo, _sistemaOperativo), tienePencil(_tienePencil) {
        cout << "Constructor de Tablet: " << marca << " " << modelo << " creado." << endl;
    }
    ~Tablet() {
        cout << "Destructor de Tablet: " << marca << " " << modelo << " destruido." << endl;
    }
    void mostrarDatosTablet() const {
        mostrarDatos();
        cout << "Tiene Pencil: " << (tienePencil ? "Sí" : "No") << endl;
    }
};
// -------- Función Principal --------
int main() {
    Telefono telefono1("Samsung", "Galaxy S21", "Android", "5G");
    cout << "\n--- DATOS DEL TELÉFONO ---" << endl;
    telefono1.mostrarDatosTelefono();
    Tablet tablet1("Apple", "iPad Pro", "iOS", true);
    cout << "\n--- DATOS DE LA TABLET ---" << endl;
    tablet1.mostrarDatosTablet();
    return 0;
}
