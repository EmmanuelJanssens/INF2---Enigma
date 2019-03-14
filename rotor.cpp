#include "rotor.h"
#include <algorithm>
using namespace std;

Rotor::Rotor()
{

}

Rotor::Rotor(ID_RT id, char startOffset, char notch)
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

void Rotor::debug()
{
    cout<<"rotor id   : "<<EnigmaData::RotorIDtext.at((unsigned)id)<<endl;
    cout<<"entry      : "<<EnigmaData::entry<<endl;
    cout<<"def wiring : "<<EnigmaData::RotorWirings.at((unsigned)id)<<endl;
    cout<<"position   : "<<EnigmaData::entry.at(((this->startPos+currentPos)%26))<<endl;
    cout<<"pos wiring : "<<this->rotorWiring<<endl;
    cout<<"notch      : "<<this->notch<<endl;

}

char Rotor::getChar(char c,bool reverse)
{

    if(reverse)
    {
        long pos = rotorWiring.find(c);
        if(EnigmaData::isDebug)
        {
            cout<<endl;
            debug();
            cout<<"result    : "<<c<<"=>"<<EnigmaData::entry.at(pos)<<endl<<endl;
        }
        return EnigmaData::entry.at(pos);
    }
    else
    {
        long pos = EnigmaData::entry.find(c);
        if(EnigmaData::isDebug)
        {
            cout<<endl;
            debug();
            cout<<"result    : "<<rotorWiring.at(pos)<<"<="<<c<<endl<<endl;
        }

        return rotorWiring.at(pos);
    }
}

void Rotor::rotate()
{

    std::rotate(rotorWiring.begin(),rotorWiring.begin()+1,rotorWiring.end());

    currentPos++;
    if(currentPos > 26)
        currentPos = 0;

}

bool Rotor::isAtNotch()
{
    if(EnigmaData::entry.at(((this->startPos+currentPos)%26)) == notch +1  )
    {

        return true;
    }
    return false;
}
