#include <iostream>
using namespace std;
// ==== Parte 1: ComponenteA, ComponenteB y Sistema ====
class ComponenteA {
public:
    ComponenteA() {
        cout << "Constructor de ComponenteA" << endl;
    }
    ~ComponenteA() {
        cout << "Destructor de ComponenteA" << endl;
    }
};
class ComponenteB {
public:
    ComponenteB() {
        cout << "Constructor de ComponenteB" << endl;
    }
    ~ComponenteB() {
        cout << "Destructor de ComponenteB" << endl;
    }
};
class Sistema {
private:
    ComponenteA a;
    ComponenteB b;
public:
    Sistema() {
        cout << "Constructor de Sistema" << endl;
    }
    ~Sistema() {
        cout << "Destructor de Sistema" << endl;
    }
};
// ==== Parte 2: Clase A y Clase B (B contiene un A) ====
class A {
public:
    A() {
        cout << "Constructor de A" << endl;
    }
    ~A() {
        cout << "Destructor de A" << endl;
    }
};
class B {
private:
    A a;
public:
    B() {
        cout << "Constructor de B" << endl;
    }
    ~B() {
        cout << "Destructor de B" << endl;
    }
};
int main() {
    cout << "==== CREACIÓN DEL OBJETO SISTEMA ====" << endl;
    {
        Sistema sistema;
        cout << ">> Dentro del bloque de Sistema." << endl;
    }
    cout << ">> Fuera del bloque de Sistema." << endl;

    cout << "\n==== CREACIÓN DEL OBJETO B ====" << endl;
    {
        B objB;
        cout << ">> Dentro del bloque de B." << endl;
    }
    cout << ">> Fuera del bloque de B." << endl;
    return 0;
}
