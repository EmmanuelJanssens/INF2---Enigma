#ifndef ROTOR_H
#define ROTOR_H
#include <string>
#include <vector>
#include "EnigmaData.h"




class Rotor
{
public:
     Rotor();

    Rotor( ID_RT id,char currentPosition, char notch);

    void rotate();
    std::string getWiring();
    char convertChar(char c,bool reverse) const;
    bool isAtNotch();
    void debug() const;
    friend std::ostream& operator<<(std::ostream& lhs, const Rotor& rhs);
private:
    std::string rotorWiring;
    ID_RT id;
    char notch;
    int startPos;
    int currentPos;
};

#endif /* ROTOR_H */
