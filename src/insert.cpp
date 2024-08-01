#include "funciones.h"
#include <sstream>

using namespace std;

// Funciones para agregar elementos a las tablas
void agregarProfesor(vector<Profesor>& profesores) {
    Profesor profesor;
    cout << "Ingrese el nombre del profesor: ";
    cin >> profesor.nombre;
    profesores.push_back(profesor);
}

void agregarAlumno(vector<Alumno>& alumnos) {
    Alumno alumno;
    cout << "Ingrese el nombre del alumno: ";
    cin >> alumno.nombre;
    cout << "Ingrese el ciclo del alumno: ";
    cin >> alumno.ciclo;
    alumnos.push_back(alumno);
}

void agregarAsistencia(vector<Asistencia>& asistencias) {
    Asistencia asistencia;
    cout << "Ingrese el nombre del alumno: ";
    cin >> asistencia.alumno;
    cout << "Ingrese el nombre de la clase: ";
    cin >> asistencia.clase;
    cout << "Ingrese la asistencia (Asistió, No asistió, Tardanza): ";
    cin >> asistencia.asistencia;
    asistencias.push_back(asistencia);
}

void agregarClase(vector<Clase>& clases) {
    Clase clase;
    cout << "Ingrese el nombre de la asignatura: ";
    cin >> clase.asignatura;
    cout << "Ingrese el nombre del profesor: ";
    cin >> clase.profesor;
    cout << "Ingrese la fecha de la clase: ";
    cin >> clase.fecha;
    cout << "Ingrese la hora de la clase: ";
    cin >> clase.hora;
    clases.push_back(clase);
}





