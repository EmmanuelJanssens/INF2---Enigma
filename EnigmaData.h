#ifndef ENIGMADATA_H
#define ENIGMADATA_H

#include <iostream>
#include <string>
#include <vector>


enum class ID_RT {I = 0, II, III, IV, V};
// RT for Rotor

enum class ID_RF{UKW_A = 0, UKW_B, UKW_C};
// RF for Reflector


class EnigmaData
{
    public:

    static std::string entry;
    static std::vector<std::string> RotorWirings ;
    static std::vector<std::string> RotorIDtext ;

    static std::vector<std::string> ReflectorWirings;
    static std::vector<std::string> ReflectorIDtext ;

    static bool isDebug ;

};



#endif /* EnigmaData_h */