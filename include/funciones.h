// funciones.h
#ifndef FUNCIONES_H 
#define FUNCIONES_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Aqui ira el INDICE de funciones a utilizar en main.cpp
// Las modificaciones de cada funciones se realizara en src

// Estructuras para las tablas
struct Profesor {
    string nombre;
};

struct Alumno {
    string nombre;
    string ciclo;
};

struct Asistencia {
    string alumno;
    string clase;
    string asistencia; // "Asistió", "No asistió", "Tardanza"
};

struct Clase {
    string asignatura;
    string profesor;
    string fecha;
    string hora;
};

// Funciones para trabajar con las tablas
void agregarProfesor(vector<Profesor>& profesores);
void agregarAlumno(vector<Alumno>& alumnos);
void agregarAsistencia(vector<Asistencia>& asistencias);
void agregarClase(vector<Clase>& clases);

void modificarProfesor(vector<Profesor>& profesores);
void modificarAlumno(vector<Alumno>& alumnos);
void modificarAsistencia(vector<Asistencia>& asistencias);
void modificarClase(vector<Clase>& clases);

void guardarDatos(vector<Profesor>& profesores, vector<Alumno>& alumnos, vector<Asistencia>& asistencias, vector<Clase>& clases);
void cargarDatos(vector<Profesor>& profesores, vector<Alumno>& alumnos, vector<Asistencia>& asistencias, vector<Clase>& clases);


#endif // FUNCIONES_H
