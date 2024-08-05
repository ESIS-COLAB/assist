#include "funciones.h"

// Definición de códigos de escape para colores
#define RESET       "\033[0m"
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"
#define BOLDBLACK   "\033[1m\033[30m"
#define BOLDRED     "\033[1m\033[31m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDYELLOW  "\033[1m\033[33m"
#define BOLDBLUE    "\033[1m\033[34m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define BOLDCYAN    "\033[1m\033[36m"
#define BOLDWHITE   "\033[1m\033[37m"

// Ancho del terminal para el marco
const int TERMINAL_WIDTH = 80;

using namespace std;

void imprimirMarco(const string &titulo) {
    system("cls"); // Borra la pantalla (función específica de Windows)
    cout << BOLDCYAN << "+" << string(TERMINAL_WIDTH - 2, '-') << "+" << RESET << endl;
    cout << BOLDGREEN << "|" << titulo << string(TERMINAL_WIDTH - titulo.size() - 2, ' ') << "|" << RESET << endl;
    cout << BOLDCYAN << "+" << string(TERMINAL_WIDTH - 2, '-') << "+" << RESET << endl;
}

void mostrarMenuPrincipal() {
    imprimirMarco("BIENVENIDO");
    cout << BOLDYELLOW << "|" << setw(TERMINAL_WIDTH - 2) << left << "1. Cargar datos" << "|" << RESET << endl;
    cout << BOLDYELLOW << "|" << setw(TERMINAL_WIDTH - 2) << left << "2. Guardar datos" << "|" << RESET << endl;
    cout << BOLDYELLOW << "|" << setw(TERMINAL_WIDTH - 2) << left << "3. Registros" << "|" << RESET << endl;
    cout << BOLDYELLOW << "|" << setw(TERMINAL_WIDTH - 2) << left << "4. Asistencia" << "|" << RESET << endl;
    cout << BOLDYELLOW << "|" << setw(TERMINAL_WIDTH - 2) << left << "5. Salir" << "|" << RESET << endl;
    cout << BOLDCYAN << "+" << string(TERMINAL_WIDTH - 2, '-') << "+" << RESET << endl;
    cout << BOLDCYAN << "Elija una opcion: " << RESET;
}

void mostrarMenuRegistros() {
    imprimirMarco("REGISTROS");
    cout << BOLDYELLOW << "|" << setw(TERMINAL_WIDTH - 2) << left << "1. Registrar aula" << "|" << RESET << endl;
    cout << BOLDYELLOW << "|" << setw(TERMINAL_WIDTH - 2) << left << "2. Registrar clase" << "|" << RESET << endl;
    cout << BOLDYELLOW << "|" << setw(TERMINAL_WIDTH - 2) << left << "3. Salir" << "|" << RESET << endl;
    cout << BOLDCYAN << "+" << string(TERMINAL_WIDTH - 2, '-') << "+" << RESET << endl;
    cout << BOLDCYAN << "Elija una opcion: " << RESET;
}

void mostrarMenuAsistencia() {
    imprimirMarco("ASISTENCIA");
    cout << BOLDYELLOW << "|" << setw(TERMINAL_WIDTH - 2) << left << "1. Anadir sesion de clase" << "|" << RESET << endl;
    cout << BOLDYELLOW << "|" << setw(TERMINAL_WIDTH - 2) << left << "2. Visualizar asistencia" << "|" << RESET << endl;
    cout << BOLDYELLOW << "|" << setw(TERMINAL_WIDTH - 2) << left << "3. Modificar asistencia" << "|" << RESET << endl;
    cout << BOLDYELLOW << "|" << setw(TERMINAL_WIDTH - 2) << left << "4. Calcular porcentaje de asistencia" << "|" << RESET << endl;
    cout << BOLDYELLOW << "|" << setw(TERMINAL_WIDTH - 2) << left << "5. Salir" << "|" << RESET << endl;
    cout << BOLDCYAN << "+" << string(TERMINAL_WIDTH - 2, '-') << "+" << RESET << endl;
    cout << BOLDCYAN << "Elija una opcion: " << RESET;
}

int main() {
    bool salirMenu = false;
    int seleccion, sesion, opcion;
    string nombreAlumno;
    vector<Aula> aulas;
    vector<Clase> clases;

    while (!salirMenu) {
        mostrarMenuPrincipal();
        cin >> opcion;

        switch (opcion) {
            case 1: // CARGAR DATOS
                system("cls");
                cargarDatos(aulas, clases);
                system("pause");
                break;

            case 2: // GUARDAR DATOS
                system("cls");
                guardarDatos(aulas, clases);
                system("pause");
                break;

            case 3: // MENU PARA HACER REGISTROS DE AULA Y CLASE
                do {
                    mostrarMenuRegistros();
                    cin >> opcion;
                    switch (opcion) {
                        case 1: // REGISTRO DEL AULA (LISTA DE ALUMNOS)
                            system("cls");
                            registrarAula(aulas);
                            system("pause");
                            break;

                        case 2: // REGISTRO DE CLASE
                            system("cls");
                            if (!aulas.empty()) {
                                registrarClase(clases, aulas);
                                system("pause");
                            } else {
                                cout << RED << "No hay aulas registradas." << RESET << endl;
                                system("pause");
                            }
                            break;

                        case 3: // SALIR AL MENU PRINCIPAL
                            break;

                        default:
                            cout << RED << "Valor incorrecto." << RESET << endl;
                            system("pause");
                            break;
                    }
                } while (opcion != 3);
                break;

            case 4: // MENU DE LA ASISTENCIA EN SESIONES
                do {
                    mostrarMenuAsistencia();
                    cin >> opcion;
                    switch (opcion) {
                        case 1: // Anadir sesion de clase
                            system("cls");
                            if (!clases.empty()) {
                                cout << BOLDCYAN << "Seleccione la clase para registrar sesion: " << RESET << endl;
                                for (int i = 0; i < clases.size(); i++) {
                                    cout << BOLDYELLOW << " " << i + 1 << ". " << clases[i].nombre << RESET << endl;
                                }
                                cout << BOLDCYAN << "Elija una opcion: " << RESET; 
                                cin >> seleccion;
                                registrarSesion(clases[seleccion - 1], aulas);
                            } else {
                                cout << RED << "No hay clases registradas." << RESET << endl;
                            }
                            system("pause");
                            break;

                        case 2: // VISUALIZAR ASISTENCIA
                            system("cls");
                            if (!clases.empty()) {
                                cout << BOLDCYAN << "Seleccione la clase para visualizar asistencia: " << RESET << endl;
                                for (int i = 0; i < clases.size(); i++) {
                                    cout << BOLDYELLOW << " " << i + 1 << ". " << clases[i].nombre << RESET << endl;
                                }
                                cout << BOLDCYAN << "Elija una opcion: " << RESET; 
                                cin >> seleccion;
                                system("cls");
                                Clase& clase = clases[seleccion - 1];
                                if (!clase.sesiones.empty()) {
                                    cout << BOLDCYAN << "Seleccione la sesion para visualizar asistencia: " << RESET << endl;
                                    for (int i = 0; i < clase.sesiones.size(); i++) {
                                        cout << BOLDYELLOW << " " << i + 1 << ". Sesion " << clase.sesiones[i].numero << RESET << endl;
                                    }
                                    cout << BOLDCYAN << "Elija una opcion: " << RESET; 
                                    cin >> sesion;
                                    cout << endl;
                                    visualizarAsistencia(clase, sesion);
                                    cout << endl;
                                } else {
                                    cout << RED << "No hay sesiones registradas para esta clase." << RESET << endl;
                                }
                            } else {
                                cout << RED << "No hay clases registradas." << RESET << endl;
                            }
                            system("pause");
                            break;

                        case 3: // MODIFICAR ASISTENCIA
                            system("cls");
                            if (!clases.empty()) {
                                cout << BOLDCYAN << "Seleccione la clase para modificar asistencia: " << RESET << endl;
                                for (int i = 0; i < clases.size(); i++) {
                                    cout << BOLDYELLOW << " " << i + 1 << ". " << clases[i].nombre << RESET << endl;
                                }
                                cout << BOLDCYAN << "Elija una opcion: " << RESET; 
                                cin >> seleccion;
                                Clase& clase = clases[seleccion - 1];
                                system("cls");
                                if (!clase.sesiones.empty()) {
                                    cout << BOLDCYAN << "Seleccione la sesion para modificar asistencia: " << RESET << endl;
                                    for (int i = 0; i < clase.sesiones.size(); i++) {
                                        cout << BOLDYELLOW << " " << i + 1 << ". Sesion " << clase.sesiones[i].numero << RESET << endl;
                                    }
                                    cout << BOLDCYAN << "Elija una opcion: " << RESET;
                                    cin >> sesion;
                                    cout << BOLDCYAN << "Ingrese el nombre del alumno para modificar asistencia: " << RESET; 
                                    cin >> nombreAlumno;
                                    modificarAsistencia(clase, sesion, nombreAlumno);
                                } else {
                                    cout << RED << "No hay sesiones registradas para esta clase." << RESET << endl;
                                }
                            } else {
                                cout << RED << "No hay clases registradas." << RESET << endl;
                            }
                            system("pause");
                            break;

                        case 4: // CALCULAR PORCENTAJE DE ASISTENCIA
                            system("cls");
                            if (!clases.empty()) {
                                cout << BOLDCYAN << "Seleccione la clase para calcular porcentaje de asistencia: " << RESET << endl;
                                for (int i = 0; i < clases.size(); i++) {
                                    cout << BOLDYELLOW << " " << i + 1 << ". " << clases[i].nombre << RESET << endl;
                                }
                                cout << BOLDCYAN << "Elija una opcion: " << RESET; 
                                cin >> seleccion;
                                calcularPorcentajeAsistencia(clases[seleccion - 1]);
                            } else {
                                cout << RED << "No hay clases registradas." << RESET << endl;
                            }
                            system("pause");
                            break;

                        case 5: // SALIR DEL SUBMENU
                            break;

                        default:
                            system("cls");
                            cout << RED << "Valor incorrecto." << RESET << endl;
                            system("pause");
                            break;
                    }
                } while (opcion != 5);
                break;

            case 5: // SALIR DEL PROGRAMA
                system("cls");
                imprimirMarco("Gracias por su visita");
                system("pause");
                salirMenu = true;
                break;

            default:
                system("cls");
                imprimirMarco("Valor incorrecto, intente de nuevo");
                system("pause");
                break;
        }
    }
    system("cls");
    return 0;
}