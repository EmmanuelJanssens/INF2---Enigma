#ifndef REFLECTOR_H
#define REFLECTOR_H
#include <string>
#include <vector>
#include "EnigmaData.h"




class Reflector{
public:

    Reflector();    
    Reflector(ID_RF id);

    char getChar( char c);

    void debug();

    Reflector operator=(const Reflector&ref);
private:
    const std::string reflectorWiring;
    const ID_RF id;
};

#endif /* REFLECTOR_H */
