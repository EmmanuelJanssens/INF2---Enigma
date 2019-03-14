/*
-----------------------------------------------------------------------------------
Laboratoire : 02
Fichier     : enigmaData.h
Groupe      : Labo_02_H
Auteur(s)   : Emmanuel Janssens, Johann Werkle, Gabrielle Thurnherr
Date        : 14.03.2019

But         : contient les données propres nécessaire à la machine Enigma

Remarque(s) : -

Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
*/

#ifndef ENIGMADATA_H
#define ENIGMADATA_H

#include <iostream>
#include <string>
#include <vector>

#define ASCII_OFFSET 65

enum class ID_RT {I = 0, II, III, IV, V};
// RT for Rotor

enum class ID_RF{UKW_A = 0, UKW_B, UKW_C};
// RF for Reflector


class EnigmaData
{
    public:

    //alphabet par défaut
    static std::string entry;
    //chaines de caractère propres au rotor
    static std::vector<std::string> RotorWirings ;
    //correspondance entre les id et les strings
    static std::vector<std::string> RotorIDtext ;

    //chaines de caractère propres au reflecteur
    static std::vector<std::string> ReflectorWirings;
    //correspondance entre les id et les strings
    static std::vector<std::string> ReflectorIDtext ;

    //permet d'afficher le mode debuggage ou pas
    static bool isDebug ;

};



#endif /* EnigmaData_h */
