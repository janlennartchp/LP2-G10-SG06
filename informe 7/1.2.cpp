#include <iostream>
#include <string>
#include <algorithm>

class CadenaPersonal {
private:
    std::string texto;
public:
    // Constructor
    CadenaPersonal(const std::string& str) : texto(str) {}
    // Sobrecarga del operador ==
    bool operator==(const CadenaPersonal& otra) const {
        std::string texto1 = texto;
        std::string texto2 = otra.texto;
        // Convertir ambos textos a minúsculas para la comparación
        std::transform(texto1.begin(), texto1.end(), texto1.begin(), ::tolower);
        std::transform(texto2.begin(), texto2.end(), texto2.begin(), ::tolower);

        return texto1 == texto2;
    }
    // Método para mostrar el contenido (opcional)
    void mostrar() const {
        std::cout << texto << std::endl;
    }
};
// Ejemplo de uso
int main() {
    CadenaPersonal cadena1("Hola Mundo");
    CadenaPersonal cadena2("hola mundo");
    if (cadena1 == cadena2) {
        std::cout << "Las cadenas son iguales (sin importar mayúsculas)." << std::endl;
    } else {
        std::cout << "Las cadenas son diferentes." << std::endl;
    }
    return 0;
}
