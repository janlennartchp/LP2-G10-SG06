#include <iostream>
#include <string>
using namespace std;

class INotificacion {
 public:
    virtual void enviarNotificacion(const string& mensaje) = 0;
    virtual ~INotificacion() {}
};

class NotificacionCorreo : public INotificacion {
 public:
    void enviarNotificacion(const string& mensaje) override {
        cout << "Enviando correo: " << mensaje << endl;
    }
};

class NotificacionSMS : public INotificacion {
 public:
    void enviarNotificacion(const string& mensaje) override {
        cout << "Enviando SMS: " << mensaje << endl;
    }
};

class SistemaNotificaciones {
 private:
    INotificacion* notificacion;

 public:
    SistemaNotificaciones(INotificacion* notificacion) {
        this->notificacion = notificacion;
    }

    void notificar(const string& mensaje) {
        notificacion->enviarNotificacion(mensaje);
        cout << "Notificacion enviada con exito" << endl;
    }
};

int main() {
    NotificacionCorreo correo;
    NotificacionSMS sms;

    SistemaNotificaciones sistemaCorreo(&correo);
    sistemaCorreo.notificar("Tienes un nuevo mensaje!");

    SistemaNotificaciones sistemaSMS(&sms);
    sistemaSMS.notificar("Tienes un nuevo SMS!");

    return 0;
}


