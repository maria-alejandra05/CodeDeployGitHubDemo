#include <iostream>
#include "Circulo.h"
#include "Cuadrado.h"
#include "Triangulo.h"
#include "Pentagono.h"


#include <vector>

#include <string.h>

using namespace std;

int main(){
    vector<Geometrica*> vFig;
    int tipo = 0;

    float radio;
    float lado;
    float altura;
    float base;

    Geometrica* pG;

    char condition = 'S';

    while (condition == 'S') {
        cout << "Figura para crear Circulo(1), Cuadrado(2), Triangulo(3) o "
                "Pentagono(4)" << endl;
        cin >> tipo;
        switch (tipo) {

        case 1:

            cout << "Ingrese el radio: ";
            cin >> radio;
            pG = new Circulo( radio );
            break;
        case 2:
            cout << "Ingrese el lado: ";
            cin >> lado;
            pG = new Cuadrado( lado );
            break;
        case 3:
            cout << "Ingrese el base: ";
            cin >> base;
            cout << "ahora la altura: ";
            cin >> altura;
            pG = new Triangulo( base, altura );
            break;
        case 4:
            cout << "Ingrese el lado: ";
            cin >> lado;
            pG = new Pentagono( lado );
            break;
        default:
            cout << "Por favor lea bien" << endl;
            continue;
            break;
        }
        vFig.push_back( pG );
        while(true){
            cout << "Ha realizado " << vFig.size() << " Figuras" << endl;
            cout << "¿Que desea? Continuar (S) - Terminar (N) - En MAYUSCULAS." << endl;

            cin >> condition;

            if(condition != 'S' && condition != 'N')
            {
                cout << "Lea atentamente, Porfavor." << endl;
                continue;
            }
            else
            {
                break;
            }

        }
     }

    for (int i = 0; i < vFig.size(); i++){
        cout << "Figura: " << vFig.at(i)->nameClass() << ", Perímetro: " << vFig.at(i)->perimetro() << " y área: " << vFig.at(i)->area() << endl;
    }

    for (int i = 0; i < vFig.size(); i++){
        delete vFig.at(i);
    }


    return 0;
}
