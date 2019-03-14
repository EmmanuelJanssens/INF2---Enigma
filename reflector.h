#ifndef REFLECTOR_H
#define REFLECTOR_H
#include <string>
#include <vector>
#include "EnigmaData.h"
using namespace std;
class Reflector{
public:

    Reflector();
    Reflector(ID_RF id);

    char getChar( char c);

    void debug();

    void operator=(const Reflector&ref);
    friend ostream& operator<<(ostream& lhs, const Reflector& rhs);
private:
    const string reflectorWiring;
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
