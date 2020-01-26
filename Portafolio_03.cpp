#include <string>
#include <iostream>

using namespace std;

struct pais{
    string nombre;
    string capital;
    int population;
    float promedio;
};

void totalPopulation(pais p[5]);
void mostCapital(pais p[5]);

int main() {
    struct pais p1[5];
    
    for (int i=0; i<5; i++){
        cout <<"Ingrese el nombre del país "<<i+1<<endl;
        cin >> p1[i].nombre;
        getline (cin, p1[i].nombre);
        cout <<"Ingrese el nombre de la capital del país "<<i+1<<endl;
        getline (cin, p1[i].capital);
        cout <<"Ingrese la población estimada del país "<<i+1<<endl;
        cin >> p1[i].population;
    }
    cout << "\n\nResumen de datos del continente:"<<endl;
    totalPopulation(p1);
    mostCapital(p1);
    return 0;
}

void totalPopulation(pais p[5]){
    int tp = 0;
    tp = p[0].population + p[1].population + p[2].population + p[3].population + p[4].population;
    cout << "La población total del continente es: " << tp <<endl;
}

void mostCapital(pais p[5]){
    int r = 0;
    string n = " ";
    
    for(int i = 0; i < 5; i++){
        if(r < p[i].population){
            r = p[i].population;
            n = p[i].capital;            
        }
    }
    cout << "La capital con más poblacion es: "<< n << " poblacion: " << r << endl;       
}