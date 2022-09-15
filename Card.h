#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED
#pragma once


#endif // CARD_H_INCLUDED

class Card
{
public:
enum class e_suit { Diamonds = 'D', Hearts = 'H', Clubs = 'C', Spades = 'S' };
enum class e_value  { two = 2,three = 3,four = 4,five = 5,six = 6,seven = 7,eight =8,
                      nine =9,ten =10,Jack = 10,Queen = 10,King = 10,Ace = 1};
//============================================================================================================

e_suit c_suit;
e_value c_value;
bool c_upPosition = 0;
    Card (){}
    Card (e_suit suit , e_value value, bool upPosition) : c_suit(suit), c_value(value), c_upPosition(upPosition){}
    void Flip()
    {
        c_upPosition = !c_upPosition;
    };
    e_value GetValue()
    {
        //cout << " ' "<< static_cast <char> (c_suit) << " ' ";
        //cout << static_cast <int> (c_value) << " ' " <<  c_upPosition << " ' " << endl;
        return c_value;
    };

};
