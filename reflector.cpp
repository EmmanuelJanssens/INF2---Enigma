/*
-----------------------------------------------------------------------------------
Laboratoire : 02
Fichier     : reflector.cpp
Groupe      : Labo_02_H
Auteur(s)   : Emmanuel Janssens, Johann Werkle, Gabrielle Thurnherr
Date        : 14.03.2019

But         : Voir le fichier reflector.h

Remarque(s) : -

Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
*/

#include <algorithm>
#include "reflector.h"

using namespace std;
// constructeur par défaut
Reflector::Reflector():
id(ID_RF::UKW_A)
{

}

// constructeur standard
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

char Reflector::getChar(char c)
{
    //On récupère le caractère correspondant dans la chaîne de caractère spécifique
    // au reflector
    long pos = reflectorWiring.find(c);
    if(EnigmaData::isDebug)
    {
        cout<<*this;
        cout<<"result    : "<<c<<"=>"<<EnigmaData::entry.at(pos)<<endl<<endl;
    }
    return EnigmaData::entry.at(pos);
}
ostream& operator<<(ostream& lhs, const Reflector& rhs)
{
        // pour pouvoir afficher un réflector en cout
    lhs <<"reflector   : "<<EnigmaData::ReflectorIDtext.at((unsigned)rhs.id)<<endl
        <<"wiring      : "<<EnigmaData::ReflectorWirings.at((unsigned)rhs.id)<<endl;

    return lhs;

}
