#include <iostream>
using namespace std;

int buscarA(int A[], int search, int high, int low);

int main(){
    int A[8] = {1, 3, 4, 5, 17, 18, 31, 33}, numero, pos;
    
    cout << "Ingrese el numero a buscar en el arreglo: ";
    cin >> numero;
    
    pos = buscarA(A, numero,  7, 0);

    if(pos == -1){
        cout << "El numero no se encontro en el Arreglo\n";
    }
    else{
        cout << "El numero se encuentra en la posicion " << pos + 1 << "\n";
    }
    return 0;
}

int buscarA(int A[], int search, int high, int low){
    int mid = (low + high) / 2, elemento;

    if (low > high){
        return -1;
    }
    else if(A[mid] == search){
        return mid;
    }
    else if(search < A[mid]){
        elemento = buscarA(A, search, mid - 1, low);
        return elemento;
    }
    else if(search > A[mid]){
        elemento = buscarA(A, search, high, mid + 1);
        return elemento;
    }
}