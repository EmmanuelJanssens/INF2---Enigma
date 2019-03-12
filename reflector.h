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

/**

 public:
   Reflector(const ID_RF& id,const std::string& reflectorWiring);

   std::string getRfWiring() const;
   char getChar(char) const;

 private:
     const ID_RF id;
     const std::string reflectorWiring;
 };


 Reflector::Reflector(const ID_RF& id,const string& reflectorWiring)
 :id(id), reflectorWiring(reflectorWiring) { }
 */
