#include <iostream>
#include <cmath>
#include <string>
using namespace std;
template <typename T>
double calcularDistancia(T x1, T y1, T x2, T y2) {
    return sqrt(pow((double)(x2 - x1), 2) + pow((double)(y2 - y1), 2));
}
template <typename Distancia, typename Velocidad>
double tiempoEstimado(Distancia d, Velocidad v) {
    if (v == 0) {
        cerr << "Error: la velocidad no puede ser cero." << endl;
        return -1;
    }
    return static_cast<double>(d) / v;
}
template <typename T>
void generarInforme(const string& idRuta, T distancia, T tiempo) {
    cout << "----------------------------------\n";
    cout << "ID de Ruta: " << idRuta << endl;
    cout << "Distancia estimada: " << distancia << " km" << endl;
    cout << "Tiempo estimado: " << tiempo << " horas" << endl;
    cout << "----------------------------------\n";
}
int main() {
    int x1 = 10, y1 = 20, x2 = 30, y2 = 35;
    double distancia = calcularDistancia(x1, y1, x2, y2);
    double tiempo = tiempoEstimado(distancia, 60.0);
    generarInforme("Ruta-A1", distancia, tiempo);
    float a1 = 5.5f, b1 = 2.0f, a2 = 8.2f, b2 = 6.7f;
    double distancia2 = calcularDistancia(a1, b1, a2, b2);
    double tiempo2 = tiempoEstimado(distancia2, 45.0);
    generarInforme("Ruta-B3", distancia2, tiempo2);
    return 0;
}
