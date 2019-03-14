/*
-----------------------------------------------------------------------------------
Laboratoire : 02
Fichier     : reflector.h
Groupe      : Labo_02_H
Auteur(s)   : Emmanuel Janssens, Johann Werkle, Gabrielle Thurnherr
Date        : 14.03.2019

But         : contient la classe reflector qui correspond au réflecteur de la machine Enigma

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

<<<<<<< HEAD
    /**
     * [debug ]
     */
    void debug();

=======
 
>>>>>>> 215fd028b5369af9ce52ccd989734be7c6eed51c
    /**
     * [permet d'affecter des valeurs aux constantes]
     */
    void operator=(const Reflector&ref);

    /**
     * surcharge de l'opérateur de flux
     */
    friend ostream& operator<<(ostream& lhs, const Reflector& rhs);
private:
    const string reflectorWiring;
    const ID_RF id;
};

#endif /* REFLECTOR_H */
