#include <iostream>
using namespace std;

void encontrar(int *i, int *f, int n);

int main(void)
{
    int arr[10], numero;
    for (int i = 0; i < 10; i++)
    {
        cout << "Ingrese el valor " << i + 1 << " del arreglo: ";
        cin >> arr[i];
    }
    cout << "\nIngrese el numero a buscar: ";
    cin >> numero;
    encontrar(arr, arr + 10, numero);
    return 0;
}

void encontrar(int *i, int *f, int n)
{
    if (i < f)
    {
        if (*i == n)
        {
            cout << *i << " concuerda con el numero buscado\n";
            cout << "\nSe encontro el numero" << endl;
        }
        else
        {
            cout << *i << " no es igual a " << n << endl;
            encontrar(i + 1, f, n);
        }
    }
    else
    {
        cout << "\nNo se encontro el numero\n";
    }
}