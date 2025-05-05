#include <iostream>
using namespace std;
class Banco {
private:
    static float tasaInteres;   

public:
    static void cambiarTasa(float nuevaTasa) {
        tasaInteres = nuevaTasa;
    }
    static float obtenerTasa() {
        return tasaInteres;
    }
};

float Banco::tasaInteres = 0.05;  

class CuentaBancaria {
private:
    float saldo;

public:
    CuentaBancaria(float saldoInicial) {
        saldo = saldoInicial;
    }

    void depositar(float monto) {
        saldo += monto;
    }

    void retirar(float monto) {
        if (monto <= saldo)
            saldo -= monto;
        else
            cout << "Fondos insuficientes\n";
    }

    void mostrarSaldo() {
        cout << "Saldo actual: $" << saldo << endl;
    }

    void calcularInteresGanado() {
        float interes = saldo * Banco::obtenerTasa();
        cout << "Interés ganado: $" << interes << endl;
    }
};

int main() {
    Banco::cambiarTasa(0.07);  

    CuentaBancaria cuenta1(1000.0);
    cuenta1.depositar(500);
    cuenta1.retirar(200);
    cuenta1.mostrarSaldo();
    cuenta1.calcularInteresGanado();

    return 0;
}
