#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct actividad{
    string titulo;
    string hora;
    int duracion;
};
typedef struct actividad Actividad;

struct agenda{
    queue <Actividad> colaActividad;
    int cantidadRealizadas;
};
typedef struct agenda Agenda;

void insertar();
void consultar();
void borrar();
void borrarTodas();

Agenda a1;

int main(void) {
    a1.cantidadRealizadas = 0;

    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\n1. Insertar una actividad a la agenda"<< endl;
        cout << "2. Consultar todas las actividades del dia"<< endl;
        cout << "3. Borrar una actividad de la agenda" << endl;
        cout << "4. Borrar todas las actividades" << endl;
        cout << "5. Salir" << endl;
        cout << "Su opcion: "; cin >> opcion;
        cin.ignore();

        switch(opcion){
            case 1: insertar(); break;
            case 2: consultar(); break;
            case 3: borrar(); break;
            case 4: borrarTodas(); break;
            case 5: continuar = false; break;
            default: cout << "Opcion no valida!\n"; break;
        }

    }while(continuar);

    return 0;
}

void insertar(){
    //Solicitar datos de la actividad
    Actividad unaActividad;
    cout << "Ingrese el nombre de la actividad: "; getline(cin, unaActividad.titulo);
    cout << "Ingrese la hora de inicio de la actividad: "; getline(cin, unaActividad.hora);
    cout << "Ingrese la duracion en minutos de la actividad: ";
    cin >> unaActividad.duracion; cin.ignore();

    //Agregar a la cola
    a1.colaActividad.push(unaActividad);
    //Modificar contadores
    a1.cantidadRealizadas++;
}

void consultar(){
    cout << "\n\nActividades actuales en cola: " << a1.colaActividad.size() << endl;
    cout << "Total de actividades realizadas en el dia: " << a1.cantidadRealizadas << endl;
    while(!a1.colaActividad.empty()){
        Actividad actividadLista = a1.colaActividad.front();
        cout << "\nTitulo de la actividad: " << actividadLista.titulo << endl;
        cout << "Hora de inicio: " << actividadLista.hora << endl;
        cout << "Duracion en minutos: " << actividadLista.duracion << endl;
        //Sacarlo para que se pueda imprimir la siguiente actividad  
        a1.colaActividad.pop();      
    }
    cout << "Lista de actividades vacia\n";
}

void borrar(){
    a1.colaActividad.back();
    a1.colaActividad.pop();
    cout << "Ultima actividad borrada"<< endl;
}

void borrarTodas(){
    for(int i = 0; i < a1.cantidadRealizadas; i++){
        a1.colaActividad.front();
        a1.colaActividad.pop();
    }
    cout << "Todas las actividades borradas" << endl;

}