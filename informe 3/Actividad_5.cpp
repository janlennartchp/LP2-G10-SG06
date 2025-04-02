#include <iostream>
using namespace std;
class IProcesadorDePedido {
 public:
    virtual void procesarPedido(double monto) = 0;
    virtual ~IProcesadorDePedido() {}
};
class ProcesadorDePedidoReal : public IProcesadorDePedido {
 public:
    void procesarPedido(double monto) override {
        cout << "Pedido procesado por un monto de $" << monto << endl;
    }
};
class SistemaDeVentas {
 private:
    IProcesadorDePedido* procesadorDePedido;

 public:
    SistemaDeVentas(IProcesadorDePedido* procesador) {
        this->procesadorDePedido = procesador;
    }

    void realizarPedido(double monto) {
        procesadorDePedido->procesarPedido(monto);
        cout << "Pedido realizado exitosamente" << endl;
    }
};
int main() {
    ProcesadorDePedidoReal procesador;
    SistemaDeVentas sistema(&procesador);
    sistema.realizarPedido(150.0);

    return 0;
}


