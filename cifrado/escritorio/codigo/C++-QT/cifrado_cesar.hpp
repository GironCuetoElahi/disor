//
//  cifrado_cesar.hpp
//  CifradoC++
//
//  Created by ITO on 12/15/18.
//  Copyright © 2018 Elahi Giron Cueto. All rights reserved.
//


#ifndef CIFRADO_CESAR_HPP
#define CIFRADO_CESAR_HPP


#include <string>
using namespace std;

class Cesar
{
private:
    string abecedario = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
    string texto;
    int semilla;
public:
    Cesar(string,int);
    string cifrar();
    string decifrar();
};

#endif 
