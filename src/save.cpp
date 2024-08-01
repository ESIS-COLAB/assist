#include "funciones.h"
#include <sstream>

using namespace std;

// Funciones para guardar y cargar datos
void guardarDatos(vector<Profesor>& profesores, vector<Alumno>& alumnos, vector<Asistencia>& asistencias, vector<Clase>& clases) {
    ofstream archivo("datos.txt");
    if (archivo.is_open()) {
        archivo << "Profesores:" << endl;
        for (int i = 0; i < profesores.size(); i++) {
            archivo << profesores[i].nombre << endl;
        }
        archivo << "Alumnos:" << endl;
        for (int i = 0; i < alumnos.size(); i++) {
            archivo << alumnos[i].nombre << "," << alumnos[i].ciclo << endl;
        }
        archivo << "Asistencias:" << endl;
        for (int i = 0; i < asistencias.size(); i++) {
            archivo << asistencias[i].alumno << "," << asistencias[i].clase << "," << asistencias[i].asistencia << endl;
        }
        archivo << "Clases:" << endl;
        for (int i = 0; i < clases.size(); i++) {
            archivo << clases[i].asignatura << "," << clases[i].profesor << "," << clases[i].fecha << "," << clases[i].hora << endl;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}