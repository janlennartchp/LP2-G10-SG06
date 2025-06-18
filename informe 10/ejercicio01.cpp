#include <iostream>
using namespace std;
template <typename T>
void ordenarEImprimir(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "Arreglo ordenado: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {
    int opcion;
    do {
        cout << "\n==== MENÚ: Ordenamiento con Función Plantilla ====" << endl;
        cout << "1. Ordenar enteros" << endl;
        cout << "2. Ordenar decimales" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        if (opcion == 1) {
            int arr[] = {7, 4, 1, 9, 2};
            ordenarEImprimir(arr, 5);
        } else if (opcion == 2) {
            float arr[] = {3.2, 1.5, 6.8, 2.9};
            ordenarEImprimir(arr, 4);
        }
    } while (opcion != 3);
    return 0;
}