#include <iostream>
#include <string>
using namespace std;

class Empleado {
public:
    int ClaveEmpleado;
    string Nombre;
    string Domicilio;
    float Sueldo;
    string ReportaA;

Empleado() : ClaveEmpleado(0), Nombre(""), Domicilio(""), Sueldo(0.0), ReportaA("") {}

    Empleado(int claveEmpleado, const string& nombre, const string& domicilio, float sueldo, const string& reportaA) :
        ClaveEmpleado(claveEmpleado), Nombre(nombre), Domicilio(domicilio), Sueldo(sueldo), ReportaA(reportaA) {}

    void Imprime() {
        cout << "ClaveEmpleado: " << ClaveEmpleado << endl;
        cout << "Nombre: " << Nombre << endl;
        cout << "Domicilio: " << Domicilio << endl;
        cout << "Sueldo: " << Sueldo << endl;
        cout << "ReportaA: " << ReportaA << endl;
    }

    void CambiaDomic(const string& nuevoDomicilio) {
        Domicilio = nuevoDomicilio;
    }

    void CambiaReportaA(const string& nuevoReportaA) {
        ReportaA = nuevoReportaA;
    }

    void ActualSueldo(float nuevoSueldo) {
        Sueldo = nuevoSueldo;
    }
};
template <typename T>
class Pila {
private:
    T* datos;
    int capacidad;
    int tamanio;

public:
    Pila(int capacidad) : capacidad(capacidad), tamanio(0) {
        datos = new T[capacidad];
    }

    ~Pila() {
        delete[] datos;
    }

    bool vacia() const {
        return tamanio == 0;
    }

    bool llena() const {
        return tamanio == capacidad;
    }

    void push(const T& elemento) {
        if (llena()) {
            cout << "La pila esta llena." << endl;
        } else {
            datos[tamanio++] = elemento;
        }
    }

    void pop() {
        if (vacia()) {
            cout << "La pila esta vacia." << endl;
        } else {
            tamanio--;
        }
    }

    T top() const {
        if (vacia()) {
            cout << "La pila esta vacia." << endl;
            // Return a default-constructed T object
            return T();
        } else {
            return datos[tamanio - 1];
        }
    }
};

int main() {
    const int CAPACIDAD = 10;
    Pila<Empleado> pila(CAPACIDAD);

    int opcion;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            int claveEmpleado;
            string nombre, domicilio, reportaA;
            float sueldo;
            cout << "Dame la clave del empleado: ";
            cin >> claveEmpleado;
            cout << "Dame el nombre del empleado: ";
            cin.ignore();
            getline(cin, nombre);
            cout << "Dame el domicilio del empleado: ";
            getline(cin, domicilio);
            cout << "Dame el sueldo del empleado: ";
            cin >> sueldo;
            cout << "Dame a quien reporta el empleado: ";
            cin.ignore();
            getline(cin, reportaA);
            pila.push(Empleado(claveEmpleado, nombre, domicilio, sueldo, reportaA));
            break;
        }
        case 2:
            pila.pop();
            break;
        case 3: {
            Empleado empleado = pila.top();
            empleado.Imprime();
            cout << endl;
            break;
        }
        case 4:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion invalida." << endl;
        }
    } while (opcion != 4);

    return 0;
}
