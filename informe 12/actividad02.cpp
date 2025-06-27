#include <iostream>
#include <list>
#include <algorithm> 
#include <string>
#include <cctype> 
using namespace std;
string aMayuscula(const string& palabra) {
    string resultado = palabra;
    transform(resultado.begin(), resultado.end(), resultado.begin(), ::toupper);
    return resultado;
}
int main() {
    list<string> palabras;
    string entrada;
    int cantidad;
    cout << "¿Cuántas palabras desea ingresar? ";
    cin >> cantidad;
    cin.ignore();
    for (int i = 0; i < cantidad; ++i) {
        cout << "Ingrese la palabra " << i + 1 << ": ";
        getline(cin, entrada);
        palabras.push_back(entrada);
    }
    palabras.sort();
    string palabraBuscada;
    cout << "\nIngrese la palabra que desea contar: ";
    getline(cin, palabraBuscada);
    int ocurrencias = count(palabras.begin(), palabras.end(), palabraBuscada);
    list<string> palabrasMayusculas;
    transform(palabras.begin(), palabras.end(), back_inserter(palabrasMayusculas), aMayuscula);
    cout << "\n--- Resultados ---" << endl;
    cout << "Número de veces que aparece '" << palabraBuscada << "': " << ocurrencias << endl;
    cout << "Lista de palabras en mayúsculas y ordenadas:\n";
    for (const string& palabra : palabrasMayusculas) {
        cout << palabra << endl;
    }
    return 0;
}
