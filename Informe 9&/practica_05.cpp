#include <iostream>
#include <cmath>
using namespace std;

class FiguraGeometrica {
public:
    virtual double calcularArea() const = 0;
    virtual double calcularPerimetro() const = 0;
    virtual ~FiguraGeometrica() {}
};

class Circulo : public FiguraGeometrica {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}
    double calcularArea() const override {
        return M_PI * radio * radio;
    }
    double calcularPerimetro() const override {
        return 2 * M_PI * radio;
    }
};

class Rectangulo : public FiguraGeometrica {
private:
    double largo, ancho;
public:
    Rectangulo(double l, double a) : largo(l), ancho(a) {}
    double calcularArea() const override {
        return largo * ancho;
    }
    double calcularPerimetro() const override {
        return 2 * (largo + ancho);
    }
};

class Triangulo : public FiguraGeometrica {
private:
    double lado1, lado2, lado3;
public:
    Triangulo(double a, double b, double c) : lado1(a), lado2(b), lado3(c) {}
    double calcularArea() const override {
        double s = (lado1 + lado2 + lado3) / 2;
        return sqrt(s * (s - lado1) * (s - lado2) * (s - lado3));
    }
    double calcularPerimetro() const override {
        return lado1 + lado2 + lado3;
    }
};

int main() {
    const int N = 3;
    FiguraGeometrica* figuras[N];
    figuras[0] = new Circulo(5.0);
    figuras[1] = new Rectangulo(4.0, 6.0);
    figuras[2] = new Triangulo(3.0, 4.0, 5.0);

    cout << "=== FIGURAS GEOMÉTRICAS ===" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Figura " << i + 1 << ": Área = " << figuras[i]->calcularArea()
             << ", Perímetro = " << figuras[i]->calcularPerimetro() << endl;
        delete figuras[i];
    }

    return 0;
}

/*
------------------------------------------------------------
Análisis: ¿Qué es el polimorfismo de subtipo?

- Permite usar punteros a la clase abstracta FiguraGeometrica para trabajar con objetos de diferentes figuras.
- Gracias a los métodos virtuales puros, se obliga a las clases hijas a implementar sus propias versiones.

------------------------------------------------------------
Ventajas del polimorfismo de subtipo:

+ Define un contrato común para diferentes figuras.
+ Permite agregar nuevas figuras sin cambiar el código que las utiliza.
+ Mejora la cohesión y escalabilidad del diseño orientado a objetos.

------------------------------------------------------------
Conclusión:

El uso de clases abstractas e interfaces con métodos virtuales puros permite una implementación clara de 
comportamientos comunes, garantizando que cada clase derivada implemente su lógica específica.
*/