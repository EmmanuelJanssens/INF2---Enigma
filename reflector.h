#ifndef REFLECTOR_H
#define REFLECTOR_H
#include <string>
#include <vector>
#include "EnigmaData.h"

class Reflector{
public:

    Reflector();

    char getChar(char c) const;
    std::string getRfWiring() const;

private:
    std::string reflectorWiring;
    ID_RF id;
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
