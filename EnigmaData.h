#ifndef EnigmaData_h
#define EnigmaData_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class ID_RT {I, II, III, IV, V};
// RT for Rotor

enum class ID_RF{UKW_A, UKW_B, UKW_C};
// RF for Reflector

vector<string> RotorWirings = {"EKMFLGDQVZNTOWYHXUSPAIBRCJ", "AJDKSIRUXBLHWTMCQGZNPYFVOE", "BDFHJLCPRTXVZNYEIWGAKMUSQO", "ESOVPZJAYQUIRHXLNFTGKDCMWB", "VZBRGITYUPSDNHLXAWMJQOFECK"};
vector<string> ReflectorWirings = {"EJMZALYXVBWFCRQUONTSPIKHGD", "YRUHQSLDPXNGOKMIEBFZCWVJAT", "FVPJIAOYEDRZXWGCTKUQSBNMHL"};
vector<string> RotorIDtext = {"I", "II", "III", "IV", "V"};
vector<string> ReflectorIDtext = {"UKW_A", "UKW_B", "UKW_C"};

bool isDebug = true;


#endif /* EnigmaData_h */
