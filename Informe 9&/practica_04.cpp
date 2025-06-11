#include <iostream>
using namespace std;

class Animal {
public:
    virtual void hacerSonido() const {
        cout << "Sonido genérico de animal." << endl;
    }
    virtual ~Animal() {}
};

class Perro : public Animal {
public:
    void hacerSonido() const override {
        cout << "El perro dice: ¡Guau!" << endl;
    }
};

class Gato : public Animal {
public:
    void hacerSonido() const override {
        cout << "El gato dice: ¡Miau!" << endl;
    }
};

class Vaca : public Animal {
public:
    void hacerSonido() const override {
        cout << "La vaca dice: ¡Muuu!" << endl;
    }
};

int main() {
    const int N = 3;
    Animal* animales[N];
    animales[0] = new Perro();
    animales[1] = new Gato();
    animales[2] = new Vaca();

    cout << "=== SONIDOS DE ANIMALES ===" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Animal " << i + 1 << ": ";
        animales[i]->hacerSonido();
        delete animales[i];
    }

    return 0;
}

/*
------------------------------------------------------------
Análisis: ¿Qué es el polimorfismo de subtipo?

- Permite usar un puntero a la clase base (Animal) para manejar objetos de clases derivadas (Perro, Gato, Vaca).
- Al declarar el método como virtual, C++ ejecuta automáticamente la versión adecuada según el tipo real del objeto.

------------------------------------------------------------
Ventajas del polimorfismo de subtipo:

+ Permite que las funciones trabajen con diferentes tipos de objetos sin cambiar su código.
+ Facilita la reutilización y el mantenimiento del software.
+ Hace posible cambiar el comportamiento en clases derivadas sin afectar la clase base.

------------------------------------------------------------
Conclusión:

El uso de funciones virtuales permite redefinir métodos en clases hijas y garantiza que se ejecute el comportamiento 
correcto en tiempo de ejecución, habilitando el polimorfismo dinámico de manera eficaz.
*/