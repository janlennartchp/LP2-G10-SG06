#include <iostream>
#include <string>
using namespace std;
template <typename T>
class Recipiente {
    T* datos;
    int tam;
public:
    Recipiente(T arr[], int n) {
        tam = n;
        datos = new T[tam];
        for (int i = 0; i < tam; i++)
            datos[i] = arr[i];
    }
    void mostrar() {
        cout << "Contenido del recipiente: ";
        for (int i = 0; i < tam; i++)
            cout << datos[i] << " ";
        cout << endl;
    }
    ~Recipiente() {
        delete[] datos;
    }
};
int main() {
    int opcion;
    do {
        cout << "\n==== MENÚ: Clase Recipiente ====" << endl;
        cout << "1. Recipiente de enteros" << endl;
        cout << "2. Recipiente de cadenas" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        if (opcion == 1) {
            int nums[] = {5, 10, 15};
            Recipiente<int> r(nums, 3);
            r.mostrar();
        } else if (opcion == 2) {
            string palabras[] = {"hola", "mundo", "templates"};
            Recipiente<string> r(palabras, 3);
            r.mostrar();
        }
    } while (opcion != 3);

    return 0;
}