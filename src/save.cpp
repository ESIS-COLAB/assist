#include "funciones.h"

void guardarDatos(const vector<Aula>& aulas, const vector<Clase>& clases) {
    nlohmann::json datos;

    for (const auto& aula : aulas) {
        nlohmann::json aulaJson;
        aulaJson["nombre"] = aula.nombre;
        aulaJson["alumnos"] = {};
        for (const auto& alumno : aula.alumnos) {
            nlohmann::json alumnoJson;
            alumnoJson["nombre"] = alumno.nombre;
            alumnoJson["codigo"] = alumno.codigo;
            aulaJson["alumnos"].push_back(alumnoJson);
        }
        datos["aulas"].push_back(aulaJson);
    }

    for (const auto& clase : clases) {
        nlohmann::json claseJson;
        claseJson["nombre"] = clase.nombre;
        claseJson["aula"] = clase.aula;
        claseJson["sesiones"] = {};
        for (const auto& sesion : clase.sesiones) {
            nlohmann::json sesionJson;
            sesionJson["numero"] = sesion.numero;
            sesionJson["asistencia"] = {};
            for (const auto& alumno : sesion.asistencia) {
                nlohmann::json alumnoJson;
                alumnoJson["nombre"] = alumno.nombre;
                alumnoJson["asistencia"] = alumno.asistencia;
                alumnoJson["tardanza"] = alumno.tardanza;
                sesionJson["asistencia"].push_back(alumnoJson);
            }
            claseJson["sesiones"].push_back(sesionJson);
        }
        datos["clases"].push_back(claseJson);
    }

    ofstream archivo("datos.json");
    archivo << datos.dump(4);
    archivo.close();
    cout << "\tDatos guardados con exito" << endl;
}
