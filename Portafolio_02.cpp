#include <iostream>
using namespace std;

void sumarMatriz(int a[2][2], int b[2][2]);

int main(void) {
    int A[2][2];
    int B[2][2];
    
    for (int  i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << "Matriz A" << endl;
            cout << "Ingrese el número a sumar fila: "<<i+1<<" columna: "<<j+1<<endl;
            cin >> A[i][j];
        }
    }
    
    for (int  i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << "Matriz B" << endl;
            cout << "Ingrese el número a sumar: \t fila: "<<i+1<<" columna: "<<j+1<<endl;
            cin >> B[i][j];
        }
    }
    
    sumarMatriz(A, B);
    return 0;
}

void sumarMatriz(int a[2][2], int b[2][2]) {
    cout << "\n\nLa suma de las matrices es: "<<endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << a[i][j] + b[i][j] << endl;
        }
    }

}