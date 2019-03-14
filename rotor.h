/*
-----------------------------------------------------------------------------------
Laboratoire : 02
Fichier     : rotor.h
Groupe      : Labo_02_H
Auteur(s)   : Emmanuel Janssens, Johann Werkle, Gabrielle Thurnherr
Date        : 14.03.2019

But         : Voir le main.cpp

Remarque(s) : -

Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
*/

#ifndef ROTOR_H
#define ROTOR_H
#include <string>
#include <vector>
#include "EnigmaData.h"

using namespace std;



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
     * [getWiring description]
     */
    // std::string getWiring();

    /**
     * [getChar convertit un caractère entré en son caractère correspondant]
     * @param  reverse [permet de savoir si on part du reflecteur ou si on en sort]
     */
    char getChar(char c,bool reverse);

    /**
     * [wasAtNotch indique qu'on a passé le notch]
     */
    bool wasAtNotch();

    /**
     * [debug description]
     */
    void debug();
private:
    string rotorWiring;
    ID_RT id;
    char notch;
    int startPos;
    int currentPos;
};

#endif /* ROTOR_H */
