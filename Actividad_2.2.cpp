#include <iostream>
using namespace std;
class CuentaBancaria {
private:
    string titular;
    double saldo;
public:
    CuentaBancaria(string _titular, double _saldo) {
        titular = _titular;
        saldo = (_saldo >= 0) ? _saldo : 0;
    }
    double getSaldo() { return saldo; }
    void depositar(double monto) {
        if (monto > 0) {
            saldo += monto;
            cout << "Deposito exitoso. Nuevo saldo: $" << saldo << endl;
        } else {
            cout << "Monto invalido." << endl;
        }
    }
    void retirar(double monto) {
        if (monto > saldo) {
            cout << "Fondos insuficientes." << endl;
        } else if (monto > 0) {
            saldo -= monto;
            cout << "Retiro exitoso. Nuevo saldo: $" << saldo << endl;
        } else {
            cout << "Monto invalido." << endl;
        }
    }
};
int main() {
    CuentaBancaria cuenta("Luis", 1000);

    cuenta.depositar(500);
    cuenta.retirar(200);
    cuenta.retirar(2000);  
    return 0;
}

