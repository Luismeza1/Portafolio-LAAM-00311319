#include <iostream>
using namespace std;

void imprimirArreglo(int* array, int size, int aux);

int main(void){
    int size = 0;
    int *array;
    cout << "Ingrese el tamaño del arreglo: "; cin >> size;

    array = new int [size];
    for(int i = 0; i < size; i++){
        cout << "\nIngrese el elemento " << i+1 <<" del arreglo: ";
        cin >> array[i]; 
    }

    cout << "\nImprimiendo arreglo: "<<endl;
    imprimirArreglo(array, size, 0);
    
    return 0;
}

void imprimirArreglo(int* array, int size, int aux){
    if(size == aux){
        return;
    }
    else{
        cout << "Elemento " << aux+1 << ": " << array[aux] << endl;
        imprimirArreglo(array, size, aux + 1);        
    }
}