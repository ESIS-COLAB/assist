#include "funciones.h"
#include <sstream>

using namespace std;

void cargarDatos(vector<Profesor>& profesores, vector<Alumno>& alumnos, vector<Asistencia>& asistencias, vector<Clase>& clases) {
    ifstream archivo("datos.txt");
    if (archivo.is_open()) {
        string linea;
        bool profesoresSection = false;
        bool alumnosSection = false;
        bool asistenciasSection = false;
        bool clasesSection = false;

        while (getline(archivo, linea)) {
            if (linea == "Profesores:") {
                profesoresSection = true;
                alumnosSection = false;
                asistenciasSection = false;
                clasesSection = false;
            } else if (linea == "Alumnos:") {
                profesoresSection = false;
                alumnosSection = true;
                asistenciasSection = false;
                clasesSection = false;
            } else if (linea == "Asistencias:") {
                profesoresSection = false;
                alumnosSection = false;
                asistenciasSection = true;
                clasesSection = false;
            } else if (linea == "Clases:") {
                profesoresSection = false;
                alumnosSection = false;
                asistenciasSection = false;
                clasesSection = true;
            } else {
                if (profesoresSection) {
                    Profesor profesor;
                    profesor.nombre = linea;
                    profesores.push_back(profesor);
                } else if (alumnosSection) {
                    Alumno alumno;
                    stringstream ss(linea);
                    getline(ss, alumno.nombre, ',');
                    getline(ss, alumno.ciclo, ',');
                    alumnos.push_back(alumno);
                } else if (asistenciasSection) {
                    Asistencia asistencia;
                    stringstream ss(linea);
                    getline(ss, asistencia.alumno, ',');
                    getline(ss, asistencia.clase, ',');
                    getline(ss, asistencia.asistencia, ',');
                    asistencias.push_back(asistencia);
                } else if (clasesSection) {
                    Clase clase;
                    stringstream ss(linea);
                    getline(ss, clase.asignatura, ',');
                    getline(ss, clase.profesor, ',');
                    getline(ss, clase.fecha, ',');
                    getline(ss, clase.hora, ',');
                    clases.push_back(clase);
                }
            }
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}