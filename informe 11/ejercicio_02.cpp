#include <iostream>
#include <stdexcept>
using namespace std;
double divide(int a, int b) {
    if (b == 0) {
        throw runtime_error("Error: No se puede dividir por cero.");
    }
    return static_cast<double>(a) / b;
}
void realizarDivision() {
    int numerador, denominador;
    cout << "Ingrese el numerador: ";
    cin >> numerador;
    cout << "Ingrese el denominador: ";
    cin >> denominador;

    try {
        double resultado = divide(numerador, denominador);
        cout << "Resultado: " << resultado << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
}
int main() {
    int opcion;
    do {
        cout << "\n=== MENU DE DIVISION ===" << endl;
        cout << "1. Dividir dos numeros" << endl;
        cout << "2. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                realizarDivision();
                break;
            case 2:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 2);
    return 0;
}
