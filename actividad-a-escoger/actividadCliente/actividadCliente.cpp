// MathClient.cpp
// compile with: cl /EHsc MathClient.cpp /link MathLibrary.lib

#include <iostream>
#include "utilities.h"
#include <vector>
#include <cstdlib>


#include <algorithm>
#include <cctype>
#include <string>


using namespace std;
using namespace utilities;

char asciitolower(char in) {
    if (in <= 'Z' && in >= 'A')
        return in - ('Z' - 'z');
    return in;
}


int main()
{
    int opc = -1;
    
    while (opc != 0)
    {
        cout << "1. Mostrar lista\n2. Anadir o modificar producto\n3. Eliminar producto\n0. Salir\n>>> ";
        cin >> opc;
        system("cls");
        if (opc > 0 && opc < 5)
        {
            if (opc == 1) {
                Arithmetic::mostrarLista();
                cout << "Precio estimado: " << Arithmetic::precioTotal() << "$\n\n";
                system("pause");
                system("cls");

            }else if (opc == 2) {
                string nombreProd;
                int cantidadProd;
                double precioProd;


                transform(nombreProd.begin(), nombreProd.end(), nombreProd.begin(), asciitolower);;




                cout << "Introduce el nombre del producto: ";
                cin >> nombreProd;
                cout << "Introduce la cantidad: ";
                cin >> cantidadProd;
                cout << "Introduce el precio estimado: ";
                cin >> precioProd;
              
                
                Arithmetic::addModify(nombreProd, cantidadProd, precioProd);

                system("cls");

            }else if (opc == 3) {
                int pos;
                cout << "Introduce la posicion del producto: ";
                cin >> pos;
                Arithmetic::eliminarProd(pos);

                cout << "\nSe ha eliminado correctamente\n\n";
                system("pause");
                system("cls");
            }
        }
        else {
            cout << "Opcion no valida\n\n";
            opc = -1;
        }
    }

    return 0;
}