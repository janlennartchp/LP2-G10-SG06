#include <iostream>
#include <vector>
#include <algorithm> 
#include <numeric> 
using namespace std;
bool esPar(int n) {
    return n % 2 == 0;
}
int main() {
    vector<int> numeros;
    int cantidad, valor;
    cout << "¿Cuántos números desea ingresar? ";
    cin >> cantidad;
    for (int i = 0; i < cantidad; ++i) {
        cout << "Ingrese el número " << i + 1 << ": ";
        cin >> valor;
        numeros.push_back(valor);
    }
    int suma = accumulate(numeros.begin(), numeros.end(), 0);
    int maximo = *max_element(numeros.begin(), numeros.end());
    int minimo = *min_element(numeros.begin(), numeros.end());
    sort(numeros.begin(), numeros.end());
    numeros.erase(remove_if(numeros.begin(), numeros.end(), esPar), numeros.end());
    cout << "\n--- Resultados ---" << endl;
    cout << "Suma total: " << suma << endl;
    cout << "Número máximo: " << maximo << endl;
    cout << "Número mínimo: " << minimo << endl;
    cout << "Contenido final del vector (sin pares, ordenado): ";
    for (int n : numeros) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
