/*
-----------------------------------------------------------------------------------
Laboratoire : 02
Fichier     : rotor.cpp
Groupe      : Labo_02_H
Auteur(s)   : Emmanuel Janssens, Johann Werkle, Gabrielle Thurnherr
Date        : 14.03.2019

But         : Voir le fichier rotor.h

Remarque(s) : -

Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
*/

#include "rotor.h"
#include <algorithm>
using namespace std;
// constructeur par défaut
Rotor::Rotor()
:id(ID_RT::I),notch('A'),startPos('A')
{

}

// constructeur standard
Rotor::Rotor(const ID_RT& id, char startOffset, char notch)
:id(id),notch(notch),startPos(0)
{
    (char&)this->notch = toupper(notch);
    (int&)this->startPos = toupper(startOffset - ASCII_OFFSET);
    this->currentPos = 0;
    this->rotorWiring = EnigmaData::RotorWirings.at(toupper((unsigned)id));

    std::rotate(rotorWiring.begin(),rotorWiring.begin()+this->startPos,rotorWiring.end());

    if(EnigmaData::isDebug)
    {
        cout<<*this<<endl;
        cout<<endl;
    }
}

char Rotor::convertChar(char c,bool reverse) const
{
    //On récupère le caractère correspondant dans la chaîne de caractère spécifique
    // au rotor et affichage éventuel des données
    long pos = 0;
    string result = "result    : ";
    char creturn;
    if(reverse)
        //Pour quand on revient du réflecteur
    {
        pos = rotorWiring.find(c);
        if(EnigmaData::isDebug)
        {

            result += c;
            result += "=>" ;
            result += EnigmaData::entry.at(pos);
        }
        creturn = EnigmaData::entry.at(pos);
    }
    else
        //Pour quand on va jusqu'au réflecteur
    {
        pos = EnigmaData::entry.find(c);
        creturn = rotorWiring.at(pos);
        result += rotorWiring.at(pos);
        result += "<=";
        result += c;
    }
    if(EnigmaData::isDebug)
    {
        cout<<*this;
        cout << result << endl<< endl ;
    }
    return creturn;
}
void Rotor::rotate()
{
    std::rotate(rotorWiring.begin(),rotorWiring.begin()+1,rotorWiring.end());

    currentPos++;
    if(currentPos > 26)
        //Si on fait un tour complet avec le rotor, on recommence au début
        // de la chaîne de caractère
        currentPos = 0;
}

bool Rotor::wasAtNotch()
{
    if(EnigmaData::entry.at(((this->startPos+currentPos)%26)) == notch +1)
        // On vérifie si on a atteint le notch fixé à la création de l'objet
    {
        return true;
        // Le rotor suivant devra faire une rotation
    }
    return false;
}

void Rotor::operator=(const Rotor& rotor)
{

    rotorWiring = rotor.rotorWiring;
    (ID_RT&)id = rotor.id;
    (char&)notch = rotor.notch;
    (int&)startPos = rotor.startPos;
    currentPos = currentPos;
}

ostream& operator<<(ostream& lhs, const Rotor& rhs)
{
    // pour pouvoir afficher un rotor en cout
    lhs <<"rotor id   : "<<EnigmaData::RotorIDtext.at((unsigned)rhs.id)<<endl
        <<"entry      : "<<EnigmaData::entry<<endl
        <<"def wiring : "<<EnigmaData::RotorWirings.at((unsigned)rhs.id)<<endl
        <<"position   : "<<EnigmaData::entry.at(((rhs.startPos+rhs.currentPos)%26))<<endl
        <<"pos wiring : "<<rhs.rotorWiring<<endl
        <<"notch      : "<<rhs.notch<<endl;
    return lhs;

}
