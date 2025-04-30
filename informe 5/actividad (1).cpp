#include <iostream>
#include <string>
using namespace std;

class CuentaBancaria {
private:
    string numero;
    string titular;
    double saldo;

public:
    CuentaBancaria(string num, string tit, double sal = 0.0)
        : numero(num), titular(tit), saldo(sal) {}

    CuentaBancaria& depositar(double monto) {
        saldo += monto;
        return *this; // permite encadenar
    }

    CuentaBancaria& retirar(double monto) {
        if (monto <= saldo) {
            saldo -= monto;
        } else {
            cout << "Fondos insuficientes para retirar S/ " << monto << endl;
        }
        return *this; // permite encadenar
    }

    CuentaBancaria& mostrarSaldo() {
        cout << "Saldo actual de " << titular << ": S/ " << saldo << endl;
        return *this; // opcional para continuar cadena
    }
};

int main() {
    CuentaBancaria cuenta("001", "Junior Yucra", 0.0);
    cuenta.depositar(1000).retirar(200).mostrarSaldo();
    return 0;
}
