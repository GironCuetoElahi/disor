//
//  inversa.hpp
//  CifradoC++
//
//  Created by ITO on 12/15/18.
//  Copyright © 2018 Elahi Giron Cueto. All rights reserved.
//


#ifndef INVERSA_HPP
#define INVERSA_HPP

#include<string>
using namespace std;


class Inverso
{
private:
    string texto;
    string invertir();
public:
    Inverso(string);
    string cifrar();
    string decifrar();

};

#endif // INVERSO_HPP
