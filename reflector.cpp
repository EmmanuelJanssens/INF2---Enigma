#include <algorithm>
#include "reflector.h"
#include "utility.h"

using namespace std;

Reflector::Reflector():
id(ID_RF::UKW_A)
{

}
Reflector::Reflector(ID_RF id):
id(id)
{
    (string&)reflectorWiring = EnigmaData::ReflectorWirings[(unsigned)id];
}

Reflector Reflector::operator=(const Reflector&ref)
{
    (ID_RF&)this->id = ref.id;
    (string&)this->reflectorWiring = ref.reflectorWiring;
}
void Reflector::debug()
{
    cout<<"reflector   : "<<EnigmaData::ReflectorIDtext[(unsigned)id]<<endl; 
    cout<<"wiring      : "<<EnigmaData::ReflectorWirings[(unsigned)id]<<endl;

<<<<<<< HEAD
char Reflector::getChar(char c) const
=======
}
char Reflector::getChar(char c)
>>>>>>> 4f5480008562ed01a84b33825bddfd4ab66362f4
{
    int pos = reflectorWiring.find(c);

<<<<<<< HEAD
}

string Reflector::getRfWiring() const {
  return reflectorWiring;
}
=======
    if(EnigmaData::isDebug)
    {
        debug();
        cout<<"result    : "<<c<<"=>"<<EnigmaData::entry[pos]<<endl<<endl;
    }
    return EnigmaData::entry[pos];
}
>>>>>>> 4f5480008562ed01a84b33825bddfd4ab66362f4
