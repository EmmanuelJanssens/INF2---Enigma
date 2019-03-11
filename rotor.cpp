#include "rotor.h"

using namespace std;

Rotor::Rotor()
{

}

Rotor::Rotor(ID_RT id, char startOffset, char notch)
{
    this->id = id;
    this->notch = notch;

    this->startPos = (startOffset - ASCII_OFFSET);

    this->currentPos = 0;

    this->rotorWiring = "";
    for(int i = this->startPos ; i < 26 ; i++)
    {
        rotorWiring += EnigmaData::RotorWirings[(unsigned)id][i];
    }
    for(int i = 0; i < this->startPos; i++)
    {
        rotorWiring += EnigmaData::RotorWirings[(unsigned)id][i];
   
    }
    cout<<EnigmaData::RotorWirings[(unsigned)id]<<endl;
    cout<<rotorWiring<<endl;
}

char Rotor::getChar(char c)
{

}

string Rotor::getWiring()
{

}

void Rotor::rotate()
{
    cout<<rotorWiring[currentPos]<<" "<<rotorWiring<<endl;

    if(rotorWiring[currentPos] == notch )
    {
        currentPos = startPos;
        cout<<"At notch"<<endl;
    }

    char last = rotorWiring.at(25);

    rotorWiring.insert(rotorWiring.begin(),last);
    rotorWiring.resize(26);

    currentPos++;
}

bool Rotor::isAtNotch() const
{

}