#include <iostream>
class Figura { // Interfaz para definir un contrato común
public:
    virtual double calcularArea() const = 0;
    virtual ~Figura() {}
};
class Rectangulo : public Figura { // Implementación de Rectángulo
protected:
    double ancho, alto;
public:
    Rectangulo(double a, double h) : ancho(a), alto(h) {}
    void setAncho(double a) { ancho = a; }
    void setAlto(double h) { alto = h; }
    double getAncho() const { return ancho; }
    double getAlto() const { return alto; }
    double calcularArea() const override {
        return ancho * alto;
    }
};
class Cuadrado : public Figura { // Implementación de Cuadrado como una figura independiente
private:
    double lado;
public:
    Cuadrado(double l) : lado(l) {}
    void setLado(double l) { lado = l; }
    double getLado() const { return lado; }
    double calcularArea() const override {
        return lado * lado;
    }
};
void testFigura(Figura& figura) {
    std::cout << "Área calculada: " << figura.calcularArea() << std::endl;
}
int main() {
    Rectangulo rect(5, 10);
    Cuadrado cuad(4);
    std::cout << "Prueba con Rectangulo:" << std::endl;
    testFigura(rect);
    std::cout << "\nPrueba con Cuadrado:" << std::endl;
    testFigura(cuad);
    return 0;
}