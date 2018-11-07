#include <iostream>
#include <cstdlib>
#include <string>
#include "deck.h"


using namespace std;

Deck::Deck() {
    myIndex = 0;

    //filling up the deck
    for (int rank = 1; rank < 14; rank++)
    {
        myCards[rank - 1] = Card(rank % 13, Card::spades);
    }

    for (int rank = 14; rank < 27; rank++)
    {
        myCards[rank - 1] = Card(rank % 13, Card::hearts);
    }

    for (int rank = 27; rank < 40; rank++)
    {
        myCards[rank - 1] = Card(rank % 13, Card::diamonds);
    }

    for (int rank = 40; rank < 53; rank ++)
    {
        myCards[rank - 1] = Card(rank%13, Card::clubs);
    }
}

void Deck::shuffle ()
{
    int totalCards = size();

    //no point in shuffling if you have
    //1 or 2 cards
    if ((totalCards == 0) || (totalCards == 1))
    {
        return;
    }

    int shuffleLoop = 0;
    //I randomize the cards by how many cards
    //are in the Deck
    for(shuffleLoop = 0; shuffleLoop < totalCards; shuffleLoop++)
    {
        int rand1 = 0;
        int rand2 = 0;
        //Want to make sure rand1 and rand2 are different
        while(rand1 == rand2)
        {

            rand1 = rand() % totalCards;
            rand2 = rand() % totalCards;
        }

        //this is how I interchange the cards
        Card temp = myCards [rand1];
        myCards [rand1] = myCards [rand2];
        myCards [rand2] = temp;
    }
}

Card Deck::dealCard ()
{
    if (myIndex < 52)
    {
        Card currentCard = myCards [myIndex];
        myIndex ++;
        return currentCard;
    }
}

int Deck:: size () const
{
    return SIZE - myIndex;
}