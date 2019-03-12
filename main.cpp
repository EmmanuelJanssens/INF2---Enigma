//test 123
#include <iostream>
#include "enigma.h"
#include "reflector.h"
#include "rotor.h"
#include "EnigmaData.h"
// #include "utility.h"

using namespace std;

string EnigmaData::entry = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
std::vector<std::string> EnigmaData::RotorWirings = {"EKMFLGDQVZNTOWYHXUSPAIBRCJ", "AJDKSIRUXBLHWTMCQGZNPYFVOE", "BDFHJLCPRTXVZNYEIWGAKMUSQO", "ESOVPZJAYQUIRHXLNFTGKDCMWB", "VZBRGITYUPSDNHLXAWMJQOFECK"};

std::vector<std::string> EnigmaData::RotorIDtext = {"I", "II", "III", "IV", "V"};

std::vector<std::string> EnigmaData::ReflectorWirings = {"EJMZALYXVBWFCRQUONTSPIKHGD", "YRUHQSLDPXNGOKMIEBFZCWVJAT", "FVPJIAOYEDRZXWGCTKUQSBNMHL"};
std::vector<std::string> EnigmaData::ReflectorIDtext = {"UKW_A", "UKW_B", "UKW_C"};

bool EnigmaData::isDebug = false;

int main() {

  Enigma  enigma   (Rotor(ID_RT::II,'C','F'),
                    Rotor(ID_RT::IV,'K','K'),
                    Rotor(ID_RT::I,'M','R'),
                    Reflector(ID_RF::UKW_B));

  enigma.decode("MDXMDAORNSLZBJTCDSABGHLVWA");
  //enigma.decode("B");

  /*Rotor  rotor(ID_RT::I,'C','F');

  for(int i = 0; i < 27; i++)
  {
    rotor.rotate();
  }*/
  return 0;
}
