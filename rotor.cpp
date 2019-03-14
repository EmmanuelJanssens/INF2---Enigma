/*
-----------------------------------------------------------------------------------
Laboratoire : 02
Fichier     : rotor.cpp
Groupe      : Labo_02_H
Auteur(s)   : Emmanuel Janssens, Johann Werkle, Gabrielle Thurnherr
Date        : 14.03.2019

But         : Voir le main.cpp

Remarque(s) : -

Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
*/

#include "rotor.h"
#include <algorithm>
using namespace std;

Rotor::Rotor()
{

}

Rotor::Rotor(const ID_RT& id, char startOffset, char notch)
{
    this->id = id;
    this->notch = toupper(notch);
    this->startPos = toupper(startOffset - ASCII_OFFSET);
    this->currentPos = 0;
    this->rotorWiring = EnigmaData::RotorWirings.at(toupper((unsigned)id));

    std::rotate(rotorWiring.begin(),rotorWiring.begin()+this->startPos,rotorWiring.end());

    if(EnigmaData::isDebug)
    {
        debug();
        cout<<endl;
    }
}

void Rotor::debug() const
{
    cout<<"rotor id   : "<<EnigmaData::RotorIDtext.at((unsigned)id)<<endl;
    cout<<"entry      : "<<EnigmaData::entry<<endl;
    cout<<"def wiring : "<<EnigmaData::RotorWirings.at((unsigned)id)<<endl;
    cout<<"position   : "<<EnigmaData::entry.at(((this->startPos+currentPos)%26))<<endl;
    cout<<"pos wiring : "<<this->rotorWiring<<endl;
    cout<<"notch      : "<<this->notch<<endl;

}

char Rotor::convertChar(char c,bool reverse) const
{
    long pos = 0;
    string result = "result    : ";
    char creturn;
    if(reverse)
    {
        pos = rotorWiring.find(c);
        if(EnigmaData::isDebug)
        {
            cout<<endl;
            debug();
            result += c;
            result += "=>" ;
            result += EnigmaData::entry.at(pos);
        }
        creturn = EnigmaData::entry.at(pos);
    }
    else
    {
        pos = EnigmaData::entry.find(c);
        creturn = rotorWiring.at(pos);
        result += rotorWiring.at(pos);
        result += "<=";
        result += c;
    }
    if(EnigmaData::isDebug)
    {
        cout<<endl;
        debug();
        cout << result ;
    }
    return creturn;
}
void Rotor::rotate()
{

    std::rotate(rotorWiring.begin(),rotorWiring.begin()+1,rotorWiring.end());

    currentPos++;
    if(currentPos > 26)
        currentPos = 0;

}

bool Rotor::wasAtNotch()
{
    if(EnigmaData::entry.at(((this->startPos+currentPos)%26)) == notch +1  )
    {

        return true;
    }
    return false;
}

ostream& operator<<(ostream& lhs, const Rotor& rhs)
{
    lhs <<"rotor id   : "<<EnigmaData::RotorIDtext.at((unsigned)rhs.id)<<endl
        <<"entry      : "<<EnigmaData::entry<<endl
        <<"def wiring : "<<EnigmaData::RotorWirings.at((unsigned)rhs.id)<<endl
        <<"position   : "<<EnigmaData::entry.at(((rhs.startPos+rhs.currentPos)%26))<<endl
        <<"pos wiring : "<<rhs.rotorWiring<<endl
        <<"notch      : "<<rhs.notch<<endl;
    return lhs;
    
}
