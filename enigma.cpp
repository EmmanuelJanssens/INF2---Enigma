#include "enigma.h"



Enigma::Enigma(Rotor left, Rotor middle, Rotor right, Reflector reflector)
{
    this->left = left;
    this->middle = middle;
    this->right = right;
    this->reflector = reflector;
}

void Enigma::setRightRotor( const Rotor& rotor )
{
    this->right = rotor;
}
void Enigma::setMiddleRotor( const Rotor& rotor )
{
    this->middle = rotor;
}
void Enigma::setLeftRotor( const Rotor& rotor )
{
    this->left = rotor;
}
void Enigma::setReflector( const Reflector& reflector )
{
    this->reflector = reflector;
}

void Enigma::decode(const string& str)
{
    string result = "";
    for(size_t i = 0; i < str.length(); i++)
    {
         update();
        {
            char r = right.getChar(str.at(i), false);
            char m = middle.getChar(r,false);
            char l = left.getChar(m,false);
            char reflected = reflector.getChar(l);
            l = left.getChar(reflected, true);
            m = middle.getChar(l,true);
            r = right.getChar(m,true);

            //char forth = left.getChar( middle.getChar( right.getChar( str[i],false),false),false);
            //char back = right.getChar( middle.getChar( left.getChar( relfected,true),true),true);
            result += r;

        }
    }

    cout<<result<<endl;
}


void Enigma::update()
{

    right.rotate();

    if(right.isAtNotch())
    {
        middle.rotate();
            if(middle.isAtNotch())
            {
                left.rotate();
            }
    }

}
