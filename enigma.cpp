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
    for(int i = 0; i < str.length(); i++)
    {
        right.rotate();
        {
            result += 
            right.getChar( 
                    middle.getChar(
                        left.getChar(
                            reflector.getChar(
                                left.getChar(
                                    middle.getChar(
                                        right.getChar(
                                            str[i]
                                        )
                                    )
                                )
                            )
                        )
                    )
            );
        }
        update();
    }
}


void Enigma::update()
{
    if(right.isAtNotch())
        middle.rotate();
    if(middle.isAtNotch())
        left.rotate();
}