#include "funciones.h"

// Funcion para registrar un aula
void registrarAula(vector<Aula>& aulas) {
    Aula aula;
    cout << "\tIngrese el nombre del aula: ";
    cin >> aula.nombre;
    cout << "\tIngrese la cantidad de alumnos: ";
    int cantidad;
    cin >> cantidad;
    for (int i = 0; i < cantidad; i++) {
        Alumno alumno;
        cout << "\tIngrese el nombre del alumno " <<i+1<< ": ";
        cin >> alumno.nombre;
        cout << "\tIngrese el código del alumno " <<i+1<<": ";
        cin >> alumno.codigo;
        aula.alumnos.push_back(alumno);
    }
    aulas.push_back(aula);
}

// Funcion para registrar una clase
void registrarClase(vector<Clase>& clases, vector<Aula>& aulas) {
    Clase clase;
    cout << "\tIngrese el nombre de la clase: ";
    cin >> clase.nombre;
    cout << "\tSeleccione el aula para la clase: "<<endl;
    for (int i = 0; i < aulas.size(); i++) {
        cout << i + 1 << ". " << aulas[i].nombre << endl;
    }
    int seleccion;
    cin >> seleccion;
    clase.aula = aulas[seleccion - 1].nombre;
    clases.push_back(clase);
}

// Funcion para registrar una sesion de clase
void registrarSesion(Clase& clase, vector<Aula>& aulas) {
    Sesion sesion;
    sesion.numero = clase.sesiones.size() + 1;
    for (int i = 0; i < aulas.size(); i++) {
        if (aulas[i].nombre == clase.aula) {
            for (int j = 0; j < aulas[i].alumnos.size(); j++) {
                Alumno alumno = aulas[i].alumnos[j];
                cout << "\tIngrese la asistencia del alumno " << alumno.nombre << " (1 = asistio, 2 = no asistio, 3 = tardanza): ";
                int asistencia;
                cin >> asistencia;
                switch (asistencia) {
                    case 1:
                        alumno.asistencia = true;
                        alumno.tardanza = false;
                        break;
                    case 2:
                        alumno.asistencia = false;
                        alumno.tardanza = false;
                        break;
                    case 3:
                        alumno.asistencia = true;
                        alumno.tardanza = true;
                        break;
                }
                sesion.asistencia.push_back(alumno);
            }
        }
    }
    clase.sesiones.push_back(sesion);
}