#include <iostream>
#include <string>
using namespace std;

struct pedido{
    string apellido;
    int mesa;
    int tacos;
    int burritos;
    int tortas;
    int tiempo;
};

// Tipo de dato que contendran los nodos de la cola
typedef pedido T;
const T noValido = {{" "}, -1, -1, -1, -1, -1};

//Registros de nodo y de cola
struct nodo{
    T elemento;
    struct nodo* siguiente;
};

struct cola{
    nodo* frente;
    nodo* final;
};

//Prototipos de funciones para cola
void initialize(cola *q);
bool empty(cola *q);
T front(cola *q);
T back(cola *q);
void enqueue(cola *q, T x);
T dequeue(cola *q);
int size(cola *q);

//Registro taqueria
struct taqueria{
    cola colaPedidos;
    int tosHechos;
    int bHechos;
    int tasHechos;
};

//Asignamos el nombre al registro taqueria
taqueria losPotros;

//prototipos de funciones
void agregar();
void consultar();
void servir();
void vertodos();

int main(void){
    initialize(&losPotros.colaPedidos);
    losPotros.tosHechos = 0;
    losPotros.bHechos = 0;
    losPotros.tasHechos = 0;
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\n1. Agregar un pedido\n";
        cout << "2. Consultar el estado actual\n";
        cout << "3. Despachar un pedido\n";
        cout << "4. Ver todos los pedidos\n";
        cout << "5. Salir\n";
        cout << "Opcion elegida: ";
        cin >> opcion; cin.ignore();
        
        switch(opcion){
            case 1: agregar(); break;
            case 2: consultar(); break;
            case 3: servir(); break;
            case 4: vertodos(); break;
            case 5: continuar = false; break;
            default: cout << "Opcion invalida!\n"; break;
        }
        
    }while(continuar);
    
    return 0;
}
