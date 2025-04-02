#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Proyecto {
public:
    Proyecto(const string& nombre) : nombre(nombre) {}
    string getNombre() const { return nombre; }
private:
    string nombre;
};
class Comentario {
public:
    Comentario(const string& texto) : texto(texto) {}
    string getTexto() const { return texto; }
private:
    string texto;
};
class Archivo {
public:
    Archivo(const string& nombre) : nombre(nombre) {}
    string getNombre() const { return nombre; }
private:
    string nombre;
};
class IProyectoManager {
public:
    virtual void agregarProyecto(const string& nombre) = 0;
    virtual void mostrarProyectos() = 0;
    virtual ~IProyectoManager() {}
};
class ProyectoManager : public IProyectoManager {
public:
    void agregarProyecto(const string& nombre) override {
        proyectos.push_back(Proyecto(nombre));
    }

    void mostrarProyectos() override {
        for (int i = 0; i < proyectos.size(); ++i) {
            cout << "Proyecto: " << proyectos[i].getNombre() << endl;
        }
    }
private:
    vector<Proyecto> proyectos;
};
class IComentarioManager {
public:
    virtual void agregarComentario(const string& texto) = 0;
    virtual void mostrarComentarios() = 0;
    virtual ~IComentarioManager() {}
};
class ComentarioManager : public IComentarioManager {
public:
    void agregarComentario(const string& texto) override {
        comentarios.push_back(Comentario(texto));
    }

    void mostrarComentarios() override {
        for (int i = 0; i < comentarios.size(); ++i) {
            cout << "Comentario: " << comentarios[i].getTexto() << endl;
        }
    }
private:
    vector<Comentario> comentarios;
};

class IArchivoManager {
public:
    virtual void agregarArchivo(const string& nombre) = 0;
    virtual void mostrarArchivos() = 0;
    virtual ~IArchivoManager() {}
};
class ArchivoManager : public IArchivoManager {
public:
    void agregarArchivo(const string& nombre) override {
        archivos.push_back(Archivo(nombre));
    }
    void mostrarArchivos() override {
        for (int i = 0; i < archivos.size(); ++i) {
            cout << "Archivo: " << archivos[i].getNombre() << endl;
        }
    }
private:
    vector<Archivo> archivos;
};
class ProyectoApp {
public:
    ProyectoApp(IProyectoManager* proyectoManager, IComentarioManager* comentarioManager, IArchivoManager* archivoManager)
        : proyectoManager(proyectoManager), comentarioManager(comentarioManager), archivoManager(archivoManager) {}
    void agregarProyecto(const string& nombre) {
        proyectoManager->agregarProyecto(nombre);
    }
    void mostrarProyectos() {
        proyectoManager->mostrarProyectos();
    }
    void agregarComentario(const string& texto) {
        comentarioManager->agregarComentario(texto);
    }
    void mostrarComentarios() {
        comentarioManager->mostrarComentarios();
    }
    void agregarArchivo(const string& nombre) {
        archivoManager->agregarArchivo(nombre);
    }
    void mostrarArchivos() {
        archivoManager->mostrarArchivos();
    }
private:
    IProyectoManager* proyectoManager;
    IComentarioManager* comentarioManager;
    IArchivoManager* archivoManager;
};

int main() {
    ProyectoManager proyectoManager;
    ComentarioManager comentarioManager;
    ArchivoManager archivoManager;

    ProyectoApp app(&proyectoManager, &comentarioManager, &archivoManager);

    int opcion;
    do {
        cout << "\n--- Gestion de Proyectos ---" << endl;
        cout << "1. Agregar Proyecto" << endl;
        cout << "2. Mostrar Proyectos" << endl;
        cout << "3. Agregar Comentario" << endl;
        cout << "4. Mostrar Comentarios" << endl;
        cout << "5. Agregar Archivo" << endl;
        cout << "6. Mostrar Archivos" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();
        string entrada;
        switch(opcion) {
            case 1:
                cout << "Ingrese el nombre del proyecto: ";
                getline(cin, entrada);
                app.agregarProyecto(entrada);
                break;
            case 2:
                cout << "Proyectos:" << endl;
                app.mostrarProyectos();
                break;
            case 3:
                cout << "Ingrese el comentario: ";
                getline(cin, entrada);
                app.agregarComentario(entrada);
                break;
            case 4:
                cout << "Comentarios:" << endl;
                app.mostrarComentarios();
                break;
            case 5:
                cout << "Ingrese el nombre del archivo: ";
                getline(cin, entrada);
                app.agregarArchivo(entrada);
                break;
            case 6:
                cout << "Archivos:" << endl;
                app.mostrarArchivos();
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    } while (opcion != 0);

    return 0;
}





