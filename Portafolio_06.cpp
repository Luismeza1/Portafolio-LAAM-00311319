#include <iostream>
#include <string>
#include <stack> 
using namespace std;

struct libro{
    string nombre;
    string autor;
    string colorP;
};
typedef struct libro Libro;

int main(void){
    //Creando pila de libros vacia
    stack<Libro> pilaDeLibros;

    //Apilando Libros
    bool continuar = true;
    do{
        char opcion = 's';
        cout << "\nCantidad de libros actual: " << pilaDeLibros.size();
        cout << "\nDesea apilar otro libro? (s/n): ";
        cin >> opcion; cin.ignore();
         
        if(opcion == 's' || opcion == 'S'){
            Libro unLibro;
            cout << "Nombre del libro: "; getline(cin, unLibro.nombre);
            cout << "Autor del libro: "; getline(cin, unLibro.autor);
            cout << "Color del libro: "; getline(cin, unLibro.colorP);
            pilaDeLibros.push(unLibro);
        }
        else if(opcion == 'n' || opcion == 'N'){
            continuar = false;
        }
        else{
            cout << "Opcion no valida!" << endl;
        }

    }while(continuar);
    
    //Desapilando libros
    cout << "\nDesapilando libros..." << endl;
    while(!pilaDeLibros.empty()){
        //Obtener el libro de encima (sin sacarlo de la pila)
        Libro libroTop = pilaDeLibros.top();
        cout << "Libro: " << libroTop.nombre;
        cout << ", " << libroTop.autor;
        cout << ", " << libroTop.colorP << endl;

        //Sacando libro de la pila
        pilaDeLibros.pop();
    }
    cout << "Pila de libros vacia." << endl;

    return 0;
}

