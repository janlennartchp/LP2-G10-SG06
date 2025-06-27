#include <iostream>
#include <deque>
#include <cctype> // Para funciones como tolower()
using namespace std;

// Función para verificar si un carácter es vocal
bool esVocal(char c) {
    char min = tolower(c);
    return min == 'a' || min == 'e' || min == 'i' || min == 'o' || min == 'u';
}

int main() {
    deque<char> caracteres;
    string entrada;

    // Entrada de la cadena con validación
    cout << "Ingrese una cadena de texto: ";
    getline(cin, entrada);

    while (entrada.empty()) {
        cout << "La cadena no puede estar vacía. Ingrese nuevamente: ";
        getline(cin, entrada);
    }

    // Almacenar caracteres en el deque
    for (char c : entrada) {
        caracteres.push_back(c);
    }

    // a) Mostrar caracteres uno por uno usando iterador
    cout << "\nCaracteres uno por uno:\n";
    for (deque<char>::iterator it = caracteres.begin(); it != caracteres.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;

    // b) Reemplazar vocales por '*'
    for (deque<char>::iterator it = caracteres.begin(); it != caracteres.end(); ++it) {
        if (esVocal(*it)) {
            *it = '*';
        }
    }

    // Mostrar cadena modificada
    cout << "\nCadena con vocales reemplazadas:\n";
    for (char c : caracteres) {
        cout << c;
    }
    cout << endl;

    // c) Mostrar cadena en orden inverso con iterador inverso
    cout << "\nCadena en orden inverso:\n";
    for (deque<char>::reverse_iterator rit = caracteres.rbegin(); rit != caracteres.rend(); ++rit) {
        cout << *rit;
    }
    cout << endl;

    return 0;
}
