#ifndef REFLECTOR_H
#define REFLECTOR_H
#include <string>
#include <vector>
#include "EnigmaData.h"




class Reflector{
public:
    
    Reflector();

    char getChar( char c);
private:
    std::string reflectorWiring;
    ID_RF id;


    
};

#endif /* REFLECTOR_H */
