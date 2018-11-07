#include <iostream>
#include <string>
#include <cstdlib>
#include "card.h"


using namespace std;

Card::Card()
{
    myRank = 'A';
    mySuit = spades;
}

Card::Card(int rank, Suit s)
{
    myRank = rank;
    mySuit = s;
}

string Card::toString () const
{
    return (rankString(myRank)) + suitString(mySuit);
}

bool Card::sameSuitAs(const Card& c) const
{
    return (suitString(mySuit) == suitString(c.mySuit));
}


int Card::getRank() const
{
    return myRank;
}

string Card::suitString(Suit s) const
{
    string suit = "";
    if (s == spades)
        suit = "s";
    else if (s == hearts)
        suit = "h";
    else if (s == diamonds)
        suit = "d";
    else if (s == clubs)
        suit = "c";
    return suit;

}

string Card::rankString(int r) const
{
    string rank = "";
    if (r == 1)
        rank = "A";
    else if (r == 2)
        rank = "2";
    else if (r == 3)
        rank = "3";
    else if (r == 4)
        rank = "4";
    else if (r == 5)
        rank = "5";
    else if (r == 6)
        rank = "6";
    else if (r == 7)
        rank = "7";
    else if (r == 8)
        rank = "8";
    else if (r == 9)
        rank = "9";
    else if (r == 10)
        rank = "J";
    else if (r == 11)
        rank = "Q";
    else if (r == 12)
        rank = "K";
    return rank;
}


bool Card::operator == (const Card& rhs) const
{
    int thisRank  = this -> myRank;
    int thatRank = rhs.myRank;
    return (thisRank == thatRank); //compares only rank, not suit

}

bool Card::operator != (const Card& rhs) const
{
    return (getRank() != rhs.getRank());
}

ostream& operator << (ostream& out, const Card& c)
{
    out << c.toString () << endl;
}

