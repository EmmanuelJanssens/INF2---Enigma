//test 123
#include <iostream>
#include "enigma.h"
#include "reflector.h"
#include "rotor.h"
#include "EnigmaData.h"
#include "utility.h"
using namespace std;

 std::vector<std::string> EnigmaData::RotorWirings = {"EKMFLGDQVZNTOWYHXUSPAIBRCJ", "AJDKSIRUXBLHWTMCQGZNPYFVOE", "BDFHJLCPRTXVZNYEIWGAKMUSQO", "ESOVPZJAYQUIRHXLNFTGKDCMWB", "VZBRGITYUPSDNHLXAWMJQOFECK"};
 std::vector<std::string> EnigmaData::RotorIDtext = {"I", "II", "III", "IV", "V"};

 std::vector<std::string> EnigmaData::ReflectorWirings = {"EJMZALYXVBWFCRQUONTSPIKHGD", "YRUHQSLDPXNGOKMIEBFZCWVJAT", "FVPJIAOYEDRZXWGCTKUQSBNMHL"};
 std::vector<std::string> EnigmaData::ReflectorIDtext = {"UKW_A", "UKW_B", "UKW_C"};

bool EnigmaData::isDebug = true;

int main() {


  Rotor rotor(ID_RT::I,'A','M');

  for(int i = 0; i < 4; i++)
    rotor.rotate();
  return 0;
}
