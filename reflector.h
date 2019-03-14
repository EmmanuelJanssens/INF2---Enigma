/*
-----------------------------------------------------------------------------------
Laboratoire : 02
Fichier     : reflector.h
Groupe      : Labo_02_H
Auteur(s)   : Emmanuel Janssens, Johann Werkle, Gabrielle Thurnherr
Date        : 14.03.2019

But         : Voir le main.cpp

Remarque(s) : -

Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
*/

#ifndef REFLECTOR_H
#define REFLECTOR_H
#include <string>
#include <vector>
#include "EnigmaData.h"
using namespace std;
class Reflector{
public:
    //constructeurs
    Reflector();
    Reflector(const ID_RF& id);

    /**
     * [getChar couvertit le char correspondant du reflecteur]
     */
    char getChar( char c);

    /**
     * [debug description]
     */
    void debug();

    /**
     * [permet d'affecter des valeurs aux constantes]
     */
    void operator=(const Reflector&ref);
    friend ostream& operator<<(ostream& lhs, const Reflector& rhs);
private:
    const string reflectorWiring;
    const ID_RF id;
};

#endif /* REFLECTOR_H */
