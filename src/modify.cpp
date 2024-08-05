#include "funciones.h" //Archivo de funciones.h

// Función para modificar la asistencia de un alumno
void modificarAsistencia(Clase& clase, int sesion, string nombreAlumno) {
    for (int i = 0; i < clase.sesiones.size(); i++) {
        if (clase.sesiones[i].numero == sesion) {
            for (int j = 0; j < clase.sesiones[i].asistencia.size(); j++) {
                Alumno& alumno = clase.sesiones[i].asistencia[j];
                if (alumno.nombre == nombreAlumno) {
                    cout << "\tIngrese la nueva asistencia del alumno " << alumno.nombre << " (1 = asistió, 2 = no asistió, 3 = tardanza): ";
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
                }
            }
        }
    }
}