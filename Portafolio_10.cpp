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

void initialize(cola *q){
    q->frente = NULL;
    q->final = NULL;
}

bool empty(cola *q){
    return (q->frente == NULL) ? true : false;
}

T front(cola *q){
    if(empty(q)){
        cout << "Underflow!" << endl;
        return noValido;
    }
    return (q->frente)->elemento;
}

T back(cola *q){
    if(empty(q)){
        cout << "Underflow!" << endl;
        return noValido;
    }
    return (q->final)->elemento;
}

void enqueue(cola *q, T x){
    nodo *unNodo = new nodo;
    unNodo->elemento = x;
    unNodo->siguiente = NULL;
    
    if(q->final==NULL)
        q->frente = unNodo;
    else
        (q->final)->siguiente = unNodo;
        
    q->final = unNodo;
}

T dequeue(cola *q){
    if(empty(q)){
        cout << "Underflow!" << endl;
        return noValido;
    }
    nodo *unNodo = q->frente;
    T x = unNodo->elemento;
    q->frente = unNodo->siguiente;
    if(q->frente==NULL)
        q->final = NULL;
    delete(unNodo);
    return x;
}

int size(cola *q){
    cola colaTemporal;
    initialize(&colaTemporal);
    
    int contador = 0;
    // Transfiriendo desde q hasta colaTemporal
    while(!empty(q)){
        T elemento = dequeue(q);
        enqueue(&colaTemporal, elemento);
        contador++;
    }
    // Transfiriendo desde colaTemporal hasta q
    while(!empty(&colaTemporal)){
        T elemento = dequeue(&colaTemporal);
        enqueue(q, elemento);
    }
    return contador;
}

// Funciones 
void agregar(){
    // Solicitar datos del pedido
    pedido unPedido;
    cout << "Digite su apellido: "; getline(cin, unPedido.apellido);
    cout << "Numero de la mesa: "; cin >> unPedido.mesa; cin.ignore();
    cout << "Cantidad de tacos: "; cin >> unPedido.tacos; cin.ignore();
    cout << "Cantidad de burritos: "; cin >> unPedido.burritos; cin.ignore();
    cout << "Cantidad de tortas: "; cin >> unPedido.tortas; cin.ignore();
    unPedido.tiempo = (unPedido.tacos+unPedido.burritos+unPedido.tortas) * 90;
    
    // Agregar a la cola
    enqueue(&losPotros.colaPedidos, unPedido);
    // Modificar contadores
    losPotros.tosHechos += (unPedido.tacos);
    losPotros.bHechos += (unPedido.burritos);
    losPotros.tasHechos += (unPedido.tortas);
}

void consultar(){
    cout << "Pedidos en espera: " << size(&losPotros.colaPedidos) << endl;
    cout << "Total de tacos hechos: " << losPotros.tosHechos << endl;
    cout << "Total de burritos hechos: " << losPotros.bHechos << endl;
    cout << "Total de tortas hechas: " << losPotros.tasHechos << endl;
}

void servir(){
    pedido pedidoDespachado = dequeue(&losPotros.colaPedidos);
    cout << "Familia " << pedidoDespachado.apellido << " su pedido esta listo\n";
    cout << "Se encuentran en la mesa " << pedidoDespachado.mesa << endl;
}

void vertodos(){
    cola colaTemporal;
    initialize(&colaTemporal);
    
    
    while(!empty(&losPotros.colaPedidos)){
        pedido unPedido = dequeue(&losPotros.colaPedidos);
        enqueue(&colaTemporal, unPedido);
        
        cout << "Info del pedido: " << unPedido.apellido << ", ";
        cout << "Tacos: " << unPedido.tacos << ", ";
        cout << "Burritos: " << unPedido.burritos << ", ";
        cout << "Tortas: " << unPedido.tortas << "\n\n";
    }
    
    while(!empty(&colaTemporal)){
        T elemento = dequeue(&colaTemporal);
        enqueue(&losPotros.colaPedidos, elemento);
    }
}

