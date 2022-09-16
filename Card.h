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
/*int checkVectorArrayInt(vector<int> &a)
{
    size_t n = 0;
    vector<int>::iterator it;
    it = a.begin();
    if (a.size()>0)


    {
        for (size_t i = 0U; i < a.size(); ++i)
        {
            for (size_t j = i+1; j < a.size(); ++j)
            {
                if (a[i] == a[j])
                {
                    a.erase(it +j);
                    j--;
                }

            }
        } n = a.size();
    }a.clear();

    return n;

}*/
/*int checkVectorArrayInt(vector<int> &a)
{
    vector<int>b;
    size_t n = 0;
    vector<int>::iterator it;
    it = b.begin();
    b.assign( a.begin(), a.end());

    if (b.size()>0)
    {
        for (size_t i = 0U; i < b.size(); ++i)
        {
            for (size_t j = i+1; j < b.size(); ++j)
            {
                if (b[i] == b[j])
                {
                    b.erase(it +j);
                    j--;
                }

            }
        } n = b.size();
    }b.clear();

    return n;

}*/
