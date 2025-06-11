#include <iostream>
#include <cmath>
using namespace std;
class Figura {
public:
    virtual double calcularArea() const = 0;
    virtual ~Figura() {}
};
class Circulo : public Figura {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}
    double calcularArea() const override {
        return M_PI * radio * radio;
    }
};
class Rectangulo : public Figura {
private:
    double base, altura;
public:
    Rectangulo(double b, double h) : base(b), altura(h) {}
    double calcularArea() const override {
        return base * altura;
    }
};
class Triangulo : public Figura {
private:
    double base, altura;
public:
    Triangulo(double b, double h) : base(b), altura(h) {}
    double calcularArea() const override {
        return (base * altura) / 2.0;
    }
};
int main() {
    const int N = 3;
    Figura* figuras[N];
    figuras[0] = new Circulo(5.0);  
    figuras[1] = new Rectangulo(4.0, 6.0); 
    figuras[2] = new Triangulo(3.0, 8.0); 
    cout << "=== ÁREAS DE FIGURAS ===" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Figura " << i + 1 << ": Área = " << figuras[i]->calcularArea() << endl;
        delete figuras[i];
    }
    return 0;
}
/*
------------------------------------------------------------
Análisis: ¿Qué es el polimorfismo de subtipo?

- Permite usar un puntero o referencia a la clase base (Figura) para manejar objetos de clases derivadas (Circulo, Rectangulo, Triangulo).
- Al declarar el método como virtual, C++ ejecuta automáticamente el método correspondiente según el tipo real del objeto en tiempo de ejecución.

------------------------------------------------------------
Ventajas del polimorfismo de subtipo:

+ Permite escribir código más genérico y reutilizable.
+ Hace que sea fácil agregar nuevas clases derivadas sin modificar el código que usa la clase base.
+ Mejora la extensibilidad del software y facilita la implementación de patrones de diseño como el patrón de fábrica.

------------------------------------------------------------
Conclusión:

El polimorfismo de subtipo es clave en la programación orientada a objetos porque permite trabajar de forma uniforme con distintos tipos de objetos relacionados jerárquicamente, 
favoreciendo el diseño limpio, flexible y escalable.
*/
