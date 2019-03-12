#ifndef ROTOR_H
#define ROTOR_H
#include <string>
#include <vector>
#include "EnigmaData.h"
// #include "utility.h"
using namespace std;



class Rotor
{
public:
     Rotor();

    Rotor( ID_RT id,char currentPosition, char notch);

    void rotate();
    std::string getWiring();
    char getChar(char c,bool reverse);
    bool isAtNotch();

    void debug();
private:
    string rotorWiring;
    ID_RT id;
    char notch;
    int startPos;
    int currentPos;
};

#endif /* ROTOR_H */
