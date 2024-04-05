// MathLibrary.h
#pragma once
#include <vector>
#include <iostream>

using namespace std;
namespace utilities
{
    class Arithmetic{
    public:

        
        vector <string> nombres{ "Leche","Huevos" };
        vector <int> cantidades{ 1,1 };
        vector <double> precios{ 3.3,5.5 };

        static double precioTotal();
        static void mostrarLista();
        static void eliminarProd(int pos);
        static void addModify(string nombreProd, int cantidadProd, double precioProd);

    private:
        int x;
    };
}