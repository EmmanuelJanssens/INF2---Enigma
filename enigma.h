#ifndef ENIGMA_H
#define ENIGMA_H

#include <string>
#include <vector>
#include "reflector.h"
#include "rotor.h"

using namespace std;


class Enigma{
public:
    
private:
    Rotor right;
    Rotor middle;
    Rotor left;
    Reflector reflector;
    
};

#endif /* ENIGMA_H */
