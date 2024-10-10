#include "funciones.h"
// Función para visualizar la asistencia de una sesión de clases
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









void swap(Alumno& a, Alumno& b) {
    Alumno temp = a;
    a = b;
    b = temp;
}

// Función para ordenar un vector de Alumnos utilizando quicksort
void quicksort(vector<Alumno>& alumnos, int izquierda, int derecha) {
    int i = izquierda;
    int j = derecha;
    Alumno pivote = alumnos[(izquierda + derecha) / 2];

    while (i <= j) {
        while (alumnos[i].nombre < pivote.nombre) {
            i++;
        }
        while (alumnos[j].nombre > pivote.nombre) {
            j--;
        }
        if (i <= j) {
            swap(alumnos[i], alumnos[j]);
            i++;
            j--;
        }
    }

    if (izquierda < j) {
        quicksort(alumnos, izquierda, j);
    }
    if (i < derecha) {
        quicksort(alumnos, i, derecha);
    }
}

void buscarNombre(vector<Aula>& aulas) {
    string seleccion;
    string indice;
    cout << "Introduce los indices del nombre: ";
    cin >> indice;

    vector<Alumno> coincidencias;
    for (int i = 0; i < aulas.size(); i++) {
        // Ordenar la lista de alumnos en la aula actual
        quicksort(aulas[i].alumnos, 0, aulas[i].alumnos.size() - 1);

        // Buscar el índice en la lista de alumnos ordenada
        int izquierda = 0;
        int derecha = aulas[i].alumnos.size() - 1;
        while (izquierda <= derecha) {
            int medio = (izquierda + derecha) / 2;
            if (aulas[i].alumnos[medio].nombre.find(indice) != string::npos) {
                // Encontramos un nombre que contiene el índice
                coincidencias.push_back(aulas[i].alumnos[medio]);
                // Buscamos otros nombres que contengan el índice en la misma aula
                int j = medio - 1;
                while (j >= 0 && aulas[i].alumnos[j].nombre.find(indice) != string::npos) {
                    coincidencias.push_back(aulas[i].alumnos[j]);
                    j--;
                }
                j = medio + 1;
                while (j < aulas[i].alumnos.size() && aulas[i].alumnos[j].nombre.find(indice) != string::npos) {
                    coincidencias.push_back(aulas[i].alumnos[j]);
                    j++;
                }
                break;
            } else if (aulas[i].alumnos[medio].nombre < indice) {
                izquierda = medio + 1;
            } else {
                derecha = medio - 1;
            }
        }
    }

    if (coincidencias.empty()) {
        cout << "No se encontró ningún nombre con el índice '" << indice << "'" << endl;
        system("pause");
    } else {
        cout << "Se encontraron los siguientes nombres con el índice '" << indice << "':" << endl;
        for (int i = 0; i < coincidencias.size(); i++) {
            cout << i + 1 << ". " << coincidencias[i].nombre << endl;
        }

        int opcion;
        cout << "Seleccione una opción:" << endl;
        cout << "1. Buscar otra vez" << endl;
        cout << "2. Seleccionar nombre" << endl;
        cout <<"Opcion:";   cin >> opcion;

        if (opcion == 1) {
            buscarNombre(aulas);
        } else if (opcion == 2) {
            cout << "Seleccione el nombre que desea ver los datos: ";
            cin >> seleccion;

            // Buscar alumno con el nombre seleccionado
            for (int i = 0; i < aulas.size(); i++) {
                for (int j = 0; j < aulas[i].alumnos.size(); j++) {
                    if (aulas[i].alumnos[j].nombre == seleccion) {
                        cout << "Nombre: " << aulas[i].alumnos[j].nombre << endl;
                        cout << "Código: " << aulas[i].alumnos[j].codigo << endl;
                        cout << "Aula: " << aulas[i].nombre << endl;
                        break;
                    }
                }
            }
        }
    }
}