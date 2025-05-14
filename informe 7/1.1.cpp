#include <iostream>

class Rectangulo;
class AmigoRectangulo {
public:
    // Función amiga que accede a los atributos privados de Rectangulo
    static const Rectangulo& compararArea(const Rectangulo& r1, const Rectangulo& r2);
};
class Rectangulo {
private:
    double base;
    double altura;
public:
    // Constructor
    Rectangulo(double b, double a) : base(b), altura(a) {}
    // Declarar la clase AmigoRectangulo como amiga
    friend class AmigoRectangulo;
    // Método para mostrar datos (opcional)
    void mostrar() const {
        std::cout << "Rectángulo [Base: " << base << ", Altura: " << altura << "]\n";
    }
};
// Definición de la función amiga
const Rectangulo& AmigoRectangulo::compararArea(const Rectangulo& r1, const Rectangulo& r2) {
    double area1 = r1.base * r1.altura;
    double area2 = r2.base * r2.altura;
    return (area1 >= area2) ? r1 : r2;
}
// Ejemplo de uso
int main() {
    Rectangulo rect1(5.0, 3.0);
    Rectangulo rect2(4.0, 4.0);
    const Rectangulo& mayor = AmigoRectangulo::compararArea(rect1, rect2);
    std::cout << "El rectángulo con mayor área es:\n";
    mayor.mostrar();
    return 0;
}
