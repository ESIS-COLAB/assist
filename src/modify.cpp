#include "funciones.h"
#include <sstream>

using namespace std;

// Funciones para modificar elementos de las tablas
void modificarProfesor(vector<Profesor>& profesores) {
    int indice;
    cout << "Ingrese el índice del profesor a modificar: ";
    cin >> indice;
    if (indice >= 0 && indice < profesores.size()) {
        cout << "Ingrese el nuevo nombre del profesor: ";
        cin >> profesores[indice].nombre;
    } else {
        cout << "Índice inválido." << endl;
    }
}

void modificarAlumno(vector<Alumno>& alumnos) {
    int indice;
    cout << "Ingrese el índice del alumno a modificar: ";
    cin >> indice;
    if (indice >= 0 && indice < alumnos.size()) {
        cout << "Ingrese el nuevo nombre del alumno: ";
        cin >> alumnos[indice].nombre;
        cout << "Ingrese el nuevo ciclo del alumno: ";
        cin >> alumnos[indice].ciclo;
    } else {
        cout << "Índice inválido." << endl;
    }
}

void modificarAsistencia(vector<Asistencia>& asistencias) {
    int indice;
    cout << "Ingrese el índice de la asistencia a modificar: ";
    cin >> indice;
    if (indice >= 0 && indice < asistencias.size()) {
        cout << "Ingrese el nuevo nombre del alumno: ";
        cin >> asistencias[indice].alumno;
        cout << "Ingrese el nuevo nombre de la clase: ";
        cin >> asistencias[indice].clase;
        cout << "Ingrese la nueva asistencia (Asistió, No asistió, Tardanza): ";
        cin >> asistencias[indice].asistencia;
    } else {
        cout << "Índice inválido." << endl;
    }
}

void modificarClase(vector<Clase>& clases) {
    int indice;
    cout << "Ingrese el índice de la clase a modificar: ";
    cin >> indice;
    if (indice >= 0 && indice < clases.size()) {
        cout << "Ingrese el nuevo nombre de la asignatura: ";
        cin >> clases[indice].asignatura;
        cout << "Ingrese el nuevo nombre del profesor: ";
        cin >> clases[indice].profesor;
        cout << "Ingrese la nueva fecha de la clase: ";
        cin >> clases[indice].fecha;
        cout << "Ingrese la nueva hora de la clase: ";
        cin >> clases[indice].hora;
    } else {
        cout << "Índice inválido." << endl;
    }
}