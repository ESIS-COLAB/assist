#include<iostream>
#include<fstream>
using namespace std;

void error();

struct asistencia {
    int codigo;
    string nombre;
    char presencia;
};

int main() {
    int n,valor2;
    asistencia* alumno=nullptr;
    int valor1=0;

    do {
        cout<<"Quieres registrar datos de un nuevo estudiante o quieres pasar lista? \n\tRegistrar(1)\n\tAsistencia(2)\n\tMostrarLista(3)\n\tSalir(4)\n";
        cin>>n;cin.ignore();

        switch(n) {
            case 1: {
                ofstream escritura;
                ifstream verificador;

                verificador.open("Asistencia.txt",ios::in);
                escritura.open("Asistencia.txt",ios::app);

                if(escritura.is_open()&&verificador.is_open()) {
                    cout<<"Esta bien"<<endl;

                    cout<<"Ingrese la cantidad de estudiantes en el curso: ";
                    cin>>valor1;cin.ignore();

                    alumno=new asistencia[valor1];

                    for(int i=0;i<valor1;i++) {
                        cout<<"Ingrese su codigo universitario: ";
                        cin>>alumno[i].codigo;
                        cin.ignore();
                        cout<<"Ingrese el nombre del estudiante (con espacios): ";
                        getline(cin,alumno[i].nombre);
                    }

                    for(int i=0;i<valor1;i++) {
                        escritura<<alumno[i].codigo<<" "<<alumno[i].nombre<<endl;
                    }

                    escritura.close();
                    verificador.close();
                } else {
                    error();
                }

                break;
            }
            case 2: {
                if(alumno==nullptr) {
                    cout<<"No se han registrado estudiantes aún. Por favor, registre primero.\n";
                    break;
                }

                cout<<"Ingrese el numero de estudiantes que se registraron: ";
                cin>>valor2;cin.ignore();

                for(int i=0;i<valor2;i++) {
                    cout<<"Cual es el estado del alumno "<<alumno[i].nombre<<" (P/A/T): ";
                    cin>>alumno[i].presencia;
                }

                break;
            }
            case 3: {
                if(alumno==nullptr) {
                    cout<<"No se han registrado estudiantes aún. Por favor, registre primero.\n";
                    break;
                }

                cout<<"Ingrese el numero de estudiantes que se registraron: ";
                cin>>valor2;cin.ignore();

                cout<<"Aqui esta la lista:\n";
                cout<<"ID\t\tNombre\t\tPresencia\n";
                cout<<"------------------------------------\n";

                for(int i=0;i<valor2;i++) {
                    cout<<alumno[i].codigo<<"\t";
                    cout<<alumno[i].nombre<<"\t";
                    cout<<alumno[i].presencia<<"\n";
                }

                break;
            }
            default:
                if(n!=4)
                    cout<<"Opción no válida.\n";
                break;
        }
    } while(n!=4);

    if(alumno!=nullptr) {
        delete[] alumno;
    }

    return 0;
}

void error() {
    cout<<"No se abrió el archivo correctamente. Por favor, revise la ubicación y creación del archivo (Asistencia.txt).\n";
}