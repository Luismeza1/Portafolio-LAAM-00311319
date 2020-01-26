#include <iostream>
using namespace std;

int addNumbers(int limit, int aux);

int main(void) {
    int n;
    cout << "Ingrese el limite de numeros a sumar: ";
    cin >> n;
    cout << "\nTotal suma: "<< addNumbers(n, 1) << endl;
    return 0;
}

int addNumbers(int limit, int aux){
    if(aux == limit){
        return aux;
    }
    else{
        return aux + addNumbers(limit, aux + 1);
    }
}