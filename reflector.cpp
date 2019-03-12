#include <algorithm>
#include "reflector.h"

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

void Reflector::operator=(const Reflector&ref)
{
    (ID_RF&)this->id = ref.id;
    (string&)this->reflectorWiring = ref.reflectorWiring;
}
void Reflector::debug()
{
    cout<<"reflector   : "<<EnigmaData::ReflectorIDtext[(unsigned)id]<<endl;
    cout<<"wiring      : "<<EnigmaData::ReflectorWirings[(unsigned)id]<<endl;

}
char Reflector::getChar(char c)
{
    int pos = reflectorWiring.find(c);

    if(EnigmaData::isDebug)
    {
        debug();
        cout<<"result    : "<<c<<"=>"<<EnigmaData::entry[pos]<<endl<<endl;
    }
    return EnigmaData::entry[pos];
}
