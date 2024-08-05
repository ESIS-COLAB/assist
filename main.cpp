#include funciones.h

int main() {
    bool salirMenu=0;
    int seleccion, sesion, opcion;
    string nombreAlumno;
    vectorAula aulas;
    vectorClase clases;

    while (salirMenu==0) {
        system(cls);
        cout  ttBienvenido!  endlendl;
        cout  tMenu  endl;
        cout  t1. Load.  endl;
        cout  t2. Save  endl;
        cout  t3. Registros  endl;
        cout  t4. Asistencia  endl;
        cout  t5. Salir  endl endl;
        cout  tElije una opcion ; cin  opcion;

        switch (opcion) {
            case 1  CARGAR DATOS
                system(cls);
                cargarDatos(aulas, clases);
                system(pause);
                break;

            case 2  GUARDAR DATOS
                system(cls);
                guardarDatos(aulas, clases);
                system(pause);
                break;

            case 3  MENU PARA HACER REGISTROS DE AULA Y CLASE
                system(cls);
                do {
                    system(cls);
                    cout  ttREGISTROS   endlendl;
                    cout  t1. Registrar aula  endl;
                    cout  t2. Registrar clase  endl;
                    cout  t3. Salir  endlendl;
                    cout  tElije una opcion ; cin  opcion;
                    switch (opcion) {
                        case 1  REGISTRO DEL AULA (LISTA DE ALUMNOS)
                            system(cls);
                            registrarAula(aulas);
                            system(pause);
                            break;

                        case 2  REGISTRO DE CLASE
                            system(cls);
                            if (aulas.size()0)
                            {
                                registrarClase(clases, aulas);
                                system(pause);
                            }else{
                                cout  No hay aulas registradas.   endl;
                            }
                            break;

                        case 3  SALIR AL MENU PRINCIPAL
                            break;

                        default
                            cout  Valor incorrecto.  endl;  REPETIR EL SUB MENU
                            system(pause);
                            break;
                    }
                } while (opcion != 3);  INICIAR EL MENU
                break;
            case 4  MENU DE LA ASISTENCIA EN SESIONES
                system(cls);
                do {
                    system(cls);
                    cout  ttASISTENCIA  endlendl;
                    cout  t1. Anadir sesion de clase  endl;
                    cout  t2. Visualizar asistencia  endl;
                    cout  t3. Modificar clase  endl;
                    cout  t4. Calcular porcentaje de asistencia  endl;
                    cout  t5. Salir  endlendl;
                    cout  tElije una opcion ; cin  opcion;
                    switch (opcion) {
                        case 1  AnADIR SESION DE CLASE
                            system(cls);
                            if (clases.size()  0) {  VERIFICA SI HAY CLASES REGISTRADAS PARA CREAR UNA SESION
                                cout  tSeleccione la clase para registrar sesion   endl;

                                for (int i = 0; i  clases.size(); i++) {  NOMBRA LAS CLASES EXISTENTES
                                    cout  endl i + 1  .   clases[i].nombre;
                                }

                                cout  tElije una opcion ; cin  seleccion;
                                registrarSesion(clases[seleccion - 1], aulas);
                            } else {
                                cout  tNo hay clases registradas  endl;
                            }

                            system(pause);
                            break;

                        case 2  VISUALIZAR ASISTENCIA
                            system(cls);
                            if (clases.size()  0) {
                                cout  tSeleccione la clase para visualizar asistencia   endl;  ESCOGE UNA CLASE PARA VER LA LISTA DE ASISTENCIAS

                                for (int i = 0; i  clases.size(); i++) {  NOMBRA LAS CLASES EXISTENTES
                                    cout endl t i + 1  .   clases[i].nombre;
                                }
                                cout  endltElije una opcion ; cin  seleccion;
                                system(cls);
                                Clase& clase = clases[seleccion - 1];

                                if (clase.sesiones.size()  0) {  VERIFICA SI HAY SESIONES REGISTRADAS
                                    cout  tSeleccione la sesion para visualizar asistencia   endlendl;  SELECCIONA UNA SESIÓN PARA VER LA LISTA DE ASISTENCIA

                                    for (int i = 0; i  clase.sesiones.size(); i++) {  NOMBRA LAS SESIONES DE LA CLASE ELEGIDA
                                        cout t i + 1  . Sesion   clase.sesiones[i].numero  endl;
                                    }
                                    cout  tElije una opcion ; cin  sesion;
                                    cout   endl;
                                    visualizarAsistencia(clase, sesion);
                                    cout  endl;
                                } else {
                                    cout  tNo hay sesiones registradas para esta clase  endl;
                                }
                            } else {
                                cout  tNo hay clases registradas  endl;
                            }

                            system(pause);
                            break;

                        case 3  MODIFICAR ASISTENCIA
                            system(cls);
                            if (clases.size()  0) {  VERIFICA SI HAY CLASES PARA MODIFICAR LA ASISTENCIA
                                cout  tSeleccione la clase para modificar asistencia   endl;  SELECCIONA UNA CLASE A LA CUAL CAMBIAR

                                for (int i = 0; i  clases.size(); i++) {  NOMBRA LAS CLASES
                                    cout ti + 1  .   clases[i].nombre  endl;
                                }
                                cout  tElije una opcion ; cin  seleccion;
                                Clase& clase = clases[seleccion - 1];
                                system(cls);
                                if (clase.sesiones.size()  0) {  VERIFICA SI HAY SESIONES DE LA CLASE ELEGIDA PARA MODIFICAR ASISTENCIA
                                    cout  tSeleccione la sesion para modificar asistencia   endl;  ESCOGE UNA SESIÓN DE LA CLASE ASIGNADA PARA MODIFICAR

                                    for (int i = 0; i  clase.sesiones.size(); i++) {  NOMBRA LAS SESIONES DE LA CLASE
                                        cout t i + 1  . Sesion   clase.sesiones[i].numero  endl;
                                    }
                                    cout  tElije una opcion ; cin  sesion;

                                    cout  tIngrese el nombre del alumno para modificar asistencia ; cin  nombreAlumno;
                                    modificarAsistencia(clase, sesion, nombreAlumno);
                                } else {
                                    cout  tNo hay sesiones registradas para esta clase  endl;
                                }
                            } else {
                                cout  tNo hay clases registradas  endl;
                            }
                            system(pause);
                            break;
                        case 4  CALCULAR PORCENTAJE DE ASISTENCIA
                            system(cls);
                            if (clases.size()  0) {
                                cout  tSeleccione la clase para calcular porcentaje de asistencia nn;
                                
                                for (int i = 0; i  clases.size(); i++) {
                                    cout  endl  t i + 1  .   clases[i].nombre;
                                }
                                cout  endl tElije una opcion ; cin  seleccion;
                                calcularPorcentajeAsistencia(clases[seleccion - 1]);
                            } else {
                                cout  tNo hay clases registradas  endl;
                            }
                            system(pause);
                            break;
                        case 5  SALIR DEL SUBMENU
                            break;

                        default
                            system(cls);
                            cout  tValor incorrecto  endl;
                            system(pause);
                            break;
                    }
                }while (opcion != 4);  REPETIR EL SUB MENU SIEMPRE QUE NO SEA SALIR
                break;

            case 5  SALIR DEL PROGRAMA
                system(cls);
                cout  Gracias por su visita  endl;
                system(pause);
                salirMenu=1;
                break;

            default
            system(cls);
                cout tVuelva ingresar un valor disponible en el menu  endl; 
                system(pause);
                break;
        }
    }
    system(cls);
}