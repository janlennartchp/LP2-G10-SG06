#include <iostream>
#include <string>
class CalculadoraDePrecio { // Interfaz para el cálculo de precios
public:
    virtual double calcularPrecio(double precioBase) = 0;
};
class ImpuestoLibro : public CalculadoraDePrecio { // Implementación de la interfaz para calcular precios de libros
public:
    double calcularPrecio(double precioBase) override {
        return precioBase * 1.1;  // Aplica un 10% de impuesto
    }
};
class ImpuestoRopa : public CalculadoraDePrecio { // Implementación de la interfaz para calcular precios de ropa
public:
    double calcularPrecio(double precioBase) override {
        return precioBase * 1.2;  // Aplica un 20% de impuesto
    }
};
class ImpuestoElectronico : public CalculadoraDePrecio { // Implementación de la interfaz para calcular precios de electrónicos
public:
    double calcularPrecio(double precioBase) override {
        return precioBase * 1.15;  // Aplica un 15% de impuesto
    }
};
class Producto { // Clase Producto que usa la calculadora de precio
private:
    double precioBase;
    CalculadoraDePrecio* calculadora;
public:
    Producto(double precio, CalculadoraDePrecio* calculadora)
        : precioBase(precio), calculadora(calculadora) {}

    double calcularPrecio() {
        return calculadora->calcularPrecio(precioBase);
    }
};
int main() {   // Se crea un objeto de tipo Producto con diferentes calculadoras de precio
    Producto* libro = new Producto(100, new ImpuestoLibro());
    Producto* ropa = new Producto(200, new ImpuestoRopa());
    Producto* electronico = new Producto(300, new ImpuestoElectronico());
    std::cout << "Precio libro: " << libro->calcularPrecio() << std::endl;
    std::cout << "Precio ropa: " << ropa->calcularPrecio() << std::endl;
    std::cout << "Precio electronico: " << electronico->calcularPrecio() << std::endl;
    delete libro;
    delete ropa;
    delete electronico;
    return 0;
}