#include <iostream>
using namespace std;
class AnimalTemprano {
public:
    void hacerSonido() {
        cout << "AnimalTemprano: El animal hace un sonido generico." << endl;
    }
};
class PerroTemprano : public AnimalTemprano {
public:
    void hacerSonido() {
        cout << "PerroTemprano: El perro ladra: ¡Guau!" << endl;
    }
};
class AnimalTardio {
public:
    virtual void hacerSonido() {
        cout << "AnimalTardio: El animal hace un sonido generico." << endl;
    }
    virtual ~AnimalTardio() {}
};
class PerroTardio : public AnimalTardio {
public:
    void hacerSonido() override {
        cout << "PerroTardio: El perro ladra: ¡Guau!" << endl;
    }
};
int main() {
    cout << "=== Enlace Temprano ===" << endl;
    AnimalTemprano* animal1 = new PerroTemprano();
    animal1->hacerSonido();
    delete animal1;
    cout << "\n=== Enlace Tardio ===" << endl;
    AnimalTardio* animal2 = new PerroTardio();
    animal2->hacerSonido();
    delete animal2;
    return 0;
}
/*
------------------------------------------------------------
¿Por qué el resultado es diferente?

- En el caso del enlace temprano, el método no es virtual. Por lo tanto, C++ decide en tiempo de compilación 
  que debe ejecutar el método de la clase base, usando el tipo del puntero.
- En el enlace tardío, al usar la palabra clave 'virtual', C++ espera hasta el tiempo de ejecución para determinar
  qué método usar, basándose en el tipo real del objeto.

------------------------------------------------------------
Ventajas y Desventajas:

Enlace Temprano (Static Binding):
+ Más rápido en ejecución (no usa tablas virtuales).
+ Menor consumo de memoria.
- No soporta polimorfismo verdadero.
- Menos flexible ante cambios o extensiones.

Enlace Tardío (Dynamic Binding):
+ Soporta polimorfismo (permite cambiar comportamiento en tiempo de ejecución).
+ Muy flexible y extensible (útil en OOP).
- Ligeramente más lento por la sobrecarga de resolución dinámica.
- Usa más memoria (tablas virtuales o VTables).

------------------------------------------------------------
Conclusión:
Usa enlace temprano cuando el comportamiento no necesita cambiar dinámicamente.
Usa enlace tardío para diseños polimórficos y escalables en sistemas orientados a objetos.
*/