/*
-----------------------------------------------------------------------------------
Laboratoire : 02
Fichier     : main.cpp
Groupe      : Labo_02_H
Auteur(s)   : Emmanuel Janssens, Johann Werkle, Gabrielle Thurnherr
Date        : 14.03.2019

But         : Dans ce laboratoire, nous avons comme but de répliquer une machine Enigma.
              Nous devons être capable d'encoder et de décoder des messages cryptés.

Remarque(s) : -

Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
*/

#include <iostream>
#include "enigma.h"
#include "reflector.h"
#include "rotor.h"
#include "EnigmaData.h"

using namespace std;

const string EnigmaData::entry = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::vector<std::string> EnigmaData::RotorWirings = {"EKMFLGDQVZNTOWYHXUSPAIBRCJ", "AJDKSIRUXBLHWTMCQGZNPYFVOE", "BDFHJLCPRTXVZNYEIWGAKMUSQO", "ESOVPZJAYQUIRHXLNFTGKDCMWB", "VZBRGITYUPSDNHLXAWMJQOFECK"};

const std::vector<std::string> EnigmaData::RotorIDtext = {"I", "II", "III", "IV", "V"};

const std::vector<std::string> EnigmaData::ReflectorWirings = {"EJMZALYXVBWFCRQUONTSPIKHGD", "YRUHQSLDPXNGOKMIEBFZCWVJAT", "FVPJIAOYEDRZXWGCTKUQSBNMHL"};
const std::vector<std::string> EnigmaData::ReflectorIDtext = {"UKW_A", "UKW_B", "UKW_C"};

bool EnigmaData::isDebug = true;

int main() {
  Enigma  enigma   (Rotor(ID_RT::II,'C','F'),
                    Rotor(ID_RT::IV,'K','K'),
                    Rotor(ID_RT::I,'M','R'),
                    Reflector(ID_RF::UKW_B));

  enigma.decode("M");
  //enigma.decode("B");

  /*Rotor  rotor(ID_RT::I,'C','F');

  for(int i = 0; i < 27; i++)
  {
    rotor.rotate();
  }*/
  return EXIT_SUCCESS;
}
