#include "funciones.h"

void cargarDatos(vector<Aula>& aulas, vector<Clase>& clases) {
    ifstream archivo("datos.json");
    nlohmann::json datos;
    archivo >> datos;
    archivo.close();

    for (const auto& aulaJson : datos["aulas"]) {
        Aula aula;
        aula.nombre = aulaJson["nombre"];
        for (const auto& alumnoJson : aulaJson["alumnos"]) {
            Alumno alumno;
            alumno.nombre = alumnoJson["nombre"];
            alumno.codigo = alumnoJson["codigo"];
            aula.alumnos.push_back(alumno);
        }
        aulas.push_back(aula);
    }

    for (const auto& claseJson : datos["clases"]) {
        Clase clase;
        clase.nombre = claseJson["nombre"];
        clase.aula = claseJson["aula"];
        for (const auto& sesionJson : claseJson["sesiones"]) {
            Sesion sesion;
            sesion.numero = sesionJson["numero"];
            for (const auto& alumnoJson : sesionJson["asistencia"]) {
                Alumno alumno;
                alumno.nombre = alumnoJson["nombre"];
                alumno.asistencia = alumnoJson["asistencia"];
                alumno.tardanza = alumnoJson["tardanza"];
                sesion.asistencia.push_back(alumno);
            }
            clase.sesiones.push_back(sesion);
        }
        clases.push_back(clase);
    }

    cout << "Datos cargados con exito" << endl;
}
