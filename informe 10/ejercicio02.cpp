#include <iostream>
using namespace std;
template <typename T>
class Ordenador {
    T* arr;
    int n;
public:
    Ordenador(T a[], int tam) {
        n = tam;
        arr = new T[n];
        for (int i = 0; i < n; i++)
            arr[i] = a[i];
    }
    void ordenarEImprimir() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        cout << "Arreglo ordenado (método): ";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    ~Ordenador() {
        delete[] arr;
    }
};
int main() {
    int opcion;
    do {
        cout << "\n==== MENÚ: Ordenamiento con Método Plantilla ====" << endl;
        cout << "1. Ordenar enteros" << endl;
        cout << "2. Ordenar flotantes" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        if (opcion == 1) {
            int datos[] = {8, 3, 5, 1, 9};
            Ordenador<int> obj(datos, 5);
            obj.ordenarEImprimir();
        } else if (opcion == 2) {
            double datos[] = {2.4, 7.1, 1.5, 6.9};
            Ordenador<double> obj(datos, 4);
            obj.ordenarEImprimir();
        }
    } while (opcion != 3);
    return 0;
}