#include "funciones.h"

// Función para visualizar la asistencia de una sesión de clase
void visualizarAsistencia(Clase& clase, int sesion) {
    for (int i = 0; i < clase.sesiones.size(); i++) {
        if (clase.sesiones[i].numero == sesion) {
            for (int j = 0; j < clase.sesiones[i].asistencia.size(); j++) {
                Alumno alumno = clase.sesiones[i].asistencia[j];
                cout << "\tAlumno: " << alumno.nombre << endl;
                cout << "\tAsistencia: " << (alumno.asistencia ? "Asistio" : "No asistio") << endl;
                cout << "\tTardanza: " << (alumno.tardanza ? "Si" : "No") << endl;
            }
        }
    }
}

void calcularPorcentajeAsistencia(Clase& clase) {
    system("cls");

    if (clase.sesiones.size() > 0) {
        // Mapa para contar asistencias por alumno
        map<string, int> asistenciaPorAlumno;

        // Inicializar el mapa con los nombres de los alumnos
        for (const auto& sesion : clase.sesiones) {
            for (const auto& alumno : sesion.asistencia) {
                asistenciaPorAlumno[alumno.nombre] = 0;
            }
        }

        // Contar las asistencias
        for (const auto& sesion : clase.sesiones) {
            for (const auto& alumno : sesion.asistencia) {
                if (alumno.asistencia) {
                    asistenciaPorAlumno[alumno.nombre]++;
                }
            }
        }

        // Calcular y mostrar el porcentaje de asistencia
        for (const auto& alumno : asistenciaPorAlumno) {
            float porcentaje = (static_cast<float>(alumno.second) / clase.sesiones.size()) * 100;
            cout << "Alumno: " << alumno.first << " - Porcentaje de asistencia: " << porcentaje << "%" << endl;
        }
    } else {
        cout << "\tNo hay sesiones registradas." << endl;
    }
}
