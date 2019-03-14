/*
-----------------------------------------------------------------------------------
Laboratoire : 02
Fichier     : reflector.cpp
Groupe      : Labo_02_H
Auteur(s)   : Emmanuel Janssens, Johann Werkle, Gabrielle Thurnherr
Date        : 14.03.2019

But         : Voir le main.cpp

Remarque(s) : -

Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
*/

#include <algorithm>
#include "reflector.h"

using namespace std;

Reflector::Reflector():
id(ID_RF::UKW_A)
{

}
Reflector::Reflector(const ID_RF& id):
id(id)
{
    (string&)reflectorWiring = EnigmaData::ReflectorWirings.at(toupper((unsigned)id));
}

void Reflector::operator=(const Reflector&ref)
{
    (ID_RF&)this->id = ref.id;
    (string&)this->reflectorWiring = ref.reflectorWiring;
}
void Reflector::debug()
{
    cout<<"reflector   : "<<EnigmaData::ReflectorIDtext.at((unsigned)id)<<endl;
    cout<<"wiring      : "<<EnigmaData::ReflectorWirings.at((unsigned)id)<<endl;

}
char Reflector::getChar(char c)
{
    long pos = reflectorWiring.find(c);

    if(EnigmaData::isDebug)
    {
        debug();
        cout<<"result    : "<<c<<"=>"<<EnigmaData::entry.at(pos)<<endl<<endl;
    }
    return EnigmaData::entry.at(pos);
}
ostream& operator<<(ostream& lhs, const Reflector& rhs)
{
    lhs <<"reflector   : "<<EnigmaData::ReflectorIDtext.at((unsigned)rhs.id)<<endl
        <<"wiring      : "<<EnigmaData::ReflectorWirings.at((unsigned)rhs.id)<<endl;

    return lhs;
    
}

