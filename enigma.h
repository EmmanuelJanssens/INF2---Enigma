/*
-----------------------------------------------------------------------------------
Laboratoire : 02
Fichier     : enigma.h
Groupe      : Labo_02_H
Auteur(s)   : Emmanuel Janssens, Johann Werkle, Gabrielle Thurnherr
Date        : 14.03.2019

But         : contient la classe Enigma qui permet d'obtenir une machine Enigma
              formée de ses composants (3 rotors et un reflector)

Remarque(s) : -

Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
*/

#ifndef ENIGMA_H
#define ENIGMA_H

#include <string>
#include <vector>
#include "reflector.h"
#include "rotor.h"



class Enigma{
public:

    //constructeur
    Enigma(Rotor Left,Rotor Middle, Rotor Right, Reflector reflector);

    /**
     * [decode permet de décoder/encoder des messages]
     */
    void decode(const std::string& str);

    /**
     * [update fait tourner les retors et vérifie l'état des notchs]
     */
    void update();

    // setters
    void setRightRotor( const Rotor& rotor );
    void setMiddleRotor( const Rotor& rotor );
    void setLeftRotor( const Rotor& rotor );
    void setReflector( const Reflector& ref );



private:
    Rotor right;
    Rotor middle;
    Rotor left;
    Reflector reflector;

};

#endif /* ENIGMA_H */
