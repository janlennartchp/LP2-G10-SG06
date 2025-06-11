#include <iostream>
using namespace std;
class Calculadora {
public:
    int sumar(int a, int b) {
        return a + b;
    }
    double sumar(double a, double b) {
        return a + b;
    }
    int sumar(int a, int b, int c) {
        return a + b + c;
    }
};
int main() {
    Calculadora calc;
    int resultado1 = calc.sumar(3, 4);   
    double resultado2 = calc.sumar(2.5, 4.7);     
    int resultado3 = calc.sumar(1, 2, 3); 
    cout << "Suma de 3 + 4 = " << resultado1 << endl;
    cout << "Suma de 2.5 + 4.7 = " << resultado2 << endl;
    cout << "Suma de 1 + 2 + 3 = " << resultado3 << endl;
    return 0;
}

/*
------------------------------------------------------------
Análisis: ¿Qué es el polimorfismo de sobrecarga?

- El polimorfismo de sobrecarga permite definir múltiples métodos con el mismo nombre,
  pero con diferentes tipos o cantidades de parámetros.
- El compilador elige automáticamente qué método usar según los argumentos enviados.

------------------------------------------------------------
Ventajas de la sobrecarga de métodos:

+ Mejora la legibilidad del código: el mismo nombre (por ejemplo, "sumar") se usa para distintas versiones de la misma operación.
+ Facilita el uso: los programadores no necesitan memorizar varios nombres para operaciones similares.
+ Reduce la redundancia: evita tener que crear métodos como sumarEnteros(), sumarDecimales(), etc.

------------------------------------------------------------
Conclusión:

La sobrecarga de métodos es una forma de polimorfismo que hace el código más limpio, intuitivo y fácil de mantener,
especialmente cuando se realizan operaciones similares con diferentes tipos de datos o cantidades de argumentos.
*/