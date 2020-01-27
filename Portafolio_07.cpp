#include <iostream>
#include <string>
using namespace std;

//Definicion del nodo
struct libro{
    string nombre;
    string autor;
    string colorP;
};
typedef struct libro Libro;

struct nodo{
    Libro elemento;
    struct nodo *siguiente;
};
typedef struct nodo *Pila;

//Prototipos de funciones
void initialize(Pila *s);
bool empty(Pila *s);
void push(Pila *s, Libro e);
Libro pop(Pila *s);
Libro top(Pila *s);

//Programa principal
int main(void){
    //Creando pila de libros vacia
    Pila pilaDeLibros;
    initialize(&pilaDeLibros);

    //Apilando libros
    bool continuar = true;
    do{
        char opcion = 's';
        cout << "\nDesea apilar otro plato? (s/n): ";
        cin >> opcion; cin.ignore();

        if(opcion == 's' || opcion == 'S'){
            Libro unLibro;
            cout << "Nombre del libro: "; getline(cin, unLibro.nombre);
            cout << "Autor del libro: "; getline(cin, unLibro.autor);
            cout << "Color del libro: "; getline(cin, unLibro.colorP);
            push(&pilaDeLibros, unLibro);
        }
        else if(opcion == 'n' || opcion == 'N'){
            continuar = false;
        }
        else{
            cout << "Opcion no valida!" << endl;
        } 
    }while(continuar);
 
    //Desapilando Libros
    cout << "\nDesapilando libros..." << endl;
    while(!empty(&pilaDeLibros)){
        //Obtener el libro de encima sin sacarlo de la pila
        Libro libroTop = top(&pilaDeLibros);
        cout << "Libro: " << libroTop.nombre;
        cout << ", " << libroTop.autor;
        cout << ", " << libroTop.colorP << endl;

        //Sacando libro de la pila
        pop(&pilaDeLibros);
    }
    cout << "Pila de libros vacia." << endl;

    return 0;
}

//Implementacion de funciones
void initialize(Pila *s){
    *s = NULL;
}

bool empty(Pila *s){
    return *s == NULL;
}

void push(Pila *s, Libro e){
    struct nodo *unNodo = new struct nodo;
    unNodo->elemento = e;
    unNodo->siguiente = *s;

    *s = unNodo;
}

Libro pop(Pila *s){
    if(!empty(s)){
        struct nodo *unNodo = *s;
        Libro e = (*s)->elemento;
        *s = (*s)->siguiente;
        delete(unNodo);
        return e;
    }
    else
        return{{" "},{" "},{" "}};    
}

Libro top(Pila *s){
    if(!empty(s))
        return (*s)->elemento;
    else
        return{{" "},{" "},{" "}};
}
