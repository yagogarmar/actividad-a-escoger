#include "utilities.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

namespace utilities
{   
    Arithmetic obj;

    void Arithmetic::mostrarLista() {
        
        int i = 0;
        
        while (i < obj.nombres.size())
        {
            cout << i +1 <<". " << obj.nombres[i] << " x" << obj.cantidades[i] << " " << obj.precios[i] << "$/u\n";
            i++;
        }
        cout <<"\n";
    
    }

    void Arithmetic::eliminarProd(int pos) {
        obj.nombres.erase(obj.nombres.begin()+ pos-1);
        obj.cantidades.erase(obj.cantidades.begin() + pos-1);
        obj.precios.erase(obj.precios.begin() + pos-1);

    }

    void Arithmetic::addModify(string nombreProd, int cantidadProd, double precioProd) {
        int i = 0;
        bool val = true;

        string comp1 = nombreProd;
        string comp2;

        transform(comp1.begin(), comp1.end(), comp1.begin(),
            [](unsigned char c) { return std::tolower(c); });


        while (i < obj.nombres.size())
        {
            comp2 = obj.nombres[i];
            transform(comp2.begin(), comp2.end(), comp2.begin(),
                [](unsigned char c) { return std::tolower(c); });


            if (comp1 == comp2)
            {
                obj.cantidades[i] = cantidadProd;
                obj.precios[i] = precioProd;
                val = false;
            }
            i++;
        }
        if (val)
        {
            obj.nombres.push_back(nombreProd);
            obj.cantidades.push_back(cantidadProd);
            obj.precios.push_back(precioProd);
        }


        
    
    }

    double Arithmetic::precioTotal(){

        int i = 0;
        double total = 0;


        while (i < obj.precios.size())
        {
            
            total += obj.precios[i] * obj.cantidades[i];
            i++;
        }


        return total;
    }
}