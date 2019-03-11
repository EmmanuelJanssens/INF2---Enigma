#ifndef ENIGMA_H
#define ENIGMA_H

#include <string>
#include <vector>
#include "reflector.h"
#include "rotor.h"



class Enigma{
public:
    
    Enigma(Rotor Left,Rotor Middle, Rotor Right, Reflector reflector);

    void decode(const std::string& str);

    void update();

    void setRightRotor( const Rotor& rotor );
    void setMiddleRotor( const Rotor& rotor );
    void setLeftRotor( const Rotor& rotor );

    void setReflector( const Reflector& ref );



private:
    Rotor right;
    Rotor middle;
    Rotor left;
    Reflector reflector;
    
};

#endif /* ENIGMA_H */
