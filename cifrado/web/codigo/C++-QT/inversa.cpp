//
//  inversa.cpp
//  CifradoC++
//
//  Created by ITO on 12/15/18.
//  Copyright © 2018 Elahi Giron Cueto. All rights reserved.
//


#include "inversa.hpp"

Inverso::Inverso(string entrada)
{
    this->texto=entrada;
}

string Inverso::invertir()
{
    string *copia=new string(texto);
    int tamanio=copia->size();
    string *nuevo=new string();


    for(int i = tamanio-1; i>= 0; i--)
    {
        nuevo+=copia->at(i);
    }

    return *nuevo;
}


string Inverso::cifrar(){
    return invertir();
}

string Inverso::decifrar(){
    return invertir();
}
