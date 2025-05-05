#include <iostream>
using namespace std;
class Vector2D {
private:
    float x, y;
public:
    Vector2D(float _x = 0, float _y = 0) : x(_x), y(_y) {}

    Vector2D operator+(const Vector2D& otro) {
        return Vector2D(x + otro.x, y + otro.y);
    }
    Vector2D operator-(const Vector2D& otro) {
        return Vector2D(x - otro.x, y - otro.y);
    }

    void mostrar() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};
int main() {
    Vector2D v1(3, 4);
    Vector2D v2(1, 2);
    Vector2D suma = v1 + v2;
    Vector2D resta = v1 - v2;
    cout << "Vector 1: "; v1.mostrar();
    cout << "Vector 2: "; v2.mostrar();
    cout << "Suma: "; suma.mostrar();
    cout << "Resta: "; resta.mostrar();
    return 0;
}
