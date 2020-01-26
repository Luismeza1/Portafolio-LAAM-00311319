#include <iostream>
using namespace std;

int size = 0;

float mediana(int a[], int size);

int main(void) {
    cout << "digite la cantidad de elementos: "<<endl;
    cin >> size;
    int array [size];
    
    for (int i = 0; i < size; i++){
        cout << "Ingrese el valor del elemento "<< (i+1) <<endl;
        cin >> array[i];
    }
    
    mediana(array, size);
    
    return 0;
}

float mediana(int a[], int size){
    int x = 0;
    float res = 0;
    if (size % 2 == 0){
        x = (size/2) - 1;
        res = (a[x] + a[x+1])/ 2;
        cout << "La mediana es de un grupo de elementos par y es: "<<res<<endl;
    }
    else{
        x = (size/2) + (1/2);
        res = a[x];
        cout << "La mediana es de un grupo de elementos impar y es: "<<res<<endl;
    }
}