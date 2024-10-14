#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <json.hpp>
#include <iomanip>
#include <vector>

using namespace std;

// Estructura para representar un alumno
struct Alumno {
    string nombre;
    string codigo;
    bool asistencia;
    bool tardanza;
};

// Estructura para representar una sesion de clases
struct Sesion {
    int numero;
    vector<Alumno> asistencia;
};

// Estructura para representar una clase
struct Clase {
    string nombre;
    string aula;
    vector<Sesion> sesiones;
};

// Estructura para representar un aula
struct Aula {
    string nombre;
    vector<Alumno> alumnos;
};


void registrarAula(vector<Aula>& aulas);
void registrarClase(vector<Clase>& clases, vector<Aula>& aulas);
void registrarSesion(Clase& clase, vector<Aula>& aulas);
void visualizarAsistencia(Clase& clase, int sesion);
void modificarAsistencia(Clase& clase, int sesion, string nombreAlumno);
void guardarDatos(const vector<Aula>& aulas, const vector<Clase>& clases);
void cargarDatos(vector<Aula>& aulas, vector<Clase>& clases);
void calcularPorcentajeAsistencia(Clase& clase);
int busquedaBinaria(const vector<Alumno>& arr, Alumno valor, int inicio, int fin);
void ordenacionBinaria(vector<Alumno>& arr, int n);
void buscarNombre(vector<Aula>& aulas);
#endif  // FUNCIONES_H