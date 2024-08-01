#include <iostream>
#include "funciones.h"
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    bool salir=0; // valor establecido para la salida del usuario
    int op; // opcion dentro del menu
    
    do
    {   
        system("cls");
        cout<<"\n\n-----------SISTEMA DE ASISTENCIA-----------\n\n"; //
        cout << "Opciones disponibles: \n";
        cout << "1) Load.\t\t2) Save.\n3) Modificar.\t4) Insertar.\n5) Exit.\n";
        cout << "Opcion: "; cin>>op;
        system("cls");

        switch (op)
        {
        case 1: // Abrir fichero con el contenido guardado del sistema de asistencia 
        
            break;
        case 2: // Guardar fichero del sistema de asistencia
        
            break;
        case 3: // Modificar fichero del sistema de asistencia
        
            break;
        case 4:// Insertar datos (en las tablas) del sistema de asistencia
        
            break;
        case 5: // sailr
            cout<<"Gracias por usar el programa. \n";
            system("pause");
            salir=1;
            break;
        
        default:
            cout<<"Valor incorrecto, presiona cualquier tecla para volver a seleccionar. \n";
            system("pause");
            break;
        }

    }while (salir==0);

    return 0;
}
