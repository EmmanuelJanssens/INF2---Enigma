/*
-----------------------------------------------------------------------------------
Laboratoire : 02
Fichier     : rotor.h
Groupe      : Labo_02_H
Auteur(s)   : Emmanuel Janssens, Johann Werkle, Gabrielle Thurnherr
Date        : 14.03.2019

But         : contient la classe Rotor qui permet d'obtenir les rotors de la machine Enigma

Remarque(s) : -

Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
*/

#ifndef ROTOR_H
#define ROTOR_H
#include <string>
#include <vector>
#include "EnigmaData.h"




class Rotor
{
public:
    //constructeurs
    Rotor();
    Rotor(const ID_RT& id,char currentPosition, char notch);

    /**
     * [rotate fait tourner le rotorWiring de droite à gauche et incrémente la position actuelle du rotor]
     */
    void rotate();
    /**
     * [convertChar description]
     * @param  reverse [description]
     */
    char convertChar(char c,bool reverse) const;
    bool wasAtNotch();
    void debug() const;
    friend std::ostream& operator<<(std::ostream& lhs, const Rotor& rhs);
    
    void operator=(const Rotor&rotor);
private:
    std::string rotorWiring;
    const ID_RT id;
    const char notch;
    const int startPos;
    int currentPos;
};

#endif /* ROTOR_H */
