// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "Card.h"
#include "Player.h"
#include "Deck.h"

using namespace std;

void dealHand(Deck &d, Player &p, int numCards);


// PROTOTYPES for functions used by this demonstration program:
int main( )
{
    //initializing
    int numCards = 7;

    Player p1("Joe");
    Player p2("Jane");

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    //cout << p1.getName() <<" has : " << p1.showHand() << endl;
    //cout << p2.getName() <<" has : " << p2.showHand() << endl;

    //gamePlay
    bool gameOver = false;
    Player *currentPlayer = &p1; //pointer to currentPlayer
    Player *otherPlayer = &p2; //pointer to otherPlayer
    Player *winner;




    while (gameOver == false)
    {
        cout << (*currentPlayer).getName() << "'s turn " << endl;
        cout << p1.getName() <<" has : " << p1.showHand() << endl;
        cout << p1.getName() <<"'s book has: " << p1.showBooks() << endl;
        cout << p2.getName() <<" has : " << p2.showHand() << endl;
        cout << p2.getName() <<"'s book has: " << p2.showBooks() << endl;

        //first, check to see if any pairs
        Card book1;
        Card book2;
        if ((*currentPlayer).checkHandForBook(book1, book2))
        {
            (*currentPlayer).removeCardFromHand(book1);
           // cout << (*currentPlayer).getName() <<" has : " << (*currentPlayer).showHand() << endl;
            (*currentPlayer).removeCardFromHand(book2);
           // cout << (*currentPlayer).getName() <<" has : " << (*currentPlayer).showHand() << endl;
            (*currentPlayer).bookCards(book1,book2);
        }




        //if currentHand is empty, take card from deck and pass turn to next player
        if ((*currentPlayer).getHandSize() == 0) {
            Card newCard = d.dealCard();
            (*currentPlayer).addCard(newCard);

            if ((currentPlayer) == &p1)
            {
                currentPlayer = &p2;
                otherPlayer = &p1;
            }

            else if ((currentPlayer) == &p2)
            {
                currentPlayer = &p1;
                otherPlayer = &p2;
            }
        }

        else
        {
            Card currentCard = (*currentPlayer).chooseCardFromHand();
            cout << (*currentPlayer).getName() << " asks - Do you have a " << currentCard.rankString(currentCard.getRank()) << "?" << endl;

            //checks to see if other player has card of same rank

            //if other player has card of same rank:
            if ((*otherPlayer).rankInHand(currentCard))
            {
                cout << (*otherPlayer).getName() << " says - Yes. I have a " << currentCard.rankString(currentCard.getRank()) << "." << endl;

                //Transfer all cards of that rank to other player
                while ((*otherPlayer).cardInHand(currentCard))
                {
                    Card transferCard = (*otherPlayer).removeCardFromHand(currentCard);
                    (*currentPlayer).addCard (transferCard);
                    cout << (*currentPlayer).getName() << " books the " << transferCard.rankString(transferCard.getRank()) << "." << endl;
                }

            }

            //if other player does not have card of same rank, then current payer draws a card and turn switches
            else
            {
                cout << (*otherPlayer).getName() << " says - Go Fish" << endl;
                Card goFishCard = d.dealCard ();
                (*currentPlayer).addCard (goFishCard);
                cout << (*currentPlayer).getName() << " draws " << goFishCard.toString() << endl;

                if ((*currentPlayer).checkHandForBook(book1, book2))
                {
                    (*currentPlayer).removeCardFromHand(book1);
                    (*currentPlayer).removeCardFromHand(book2);
                    (*currentPlayer).bookCards(book1,book2);
                }

                if ((currentPlayer) == &p1)
                {
                    currentPlayer = &p2;
                    otherPlayer = &p1;
                }

                else if ((currentPlayer) == &p2)
                {
                    currentPlayer = &p1;
                    otherPlayer = &p2;
                }
            }
        }

        //check to see if game is over
        if ((*currentPlayer).getBookSize() + (*otherPlayer).getBookSize() == 52)
        {
            gameOver = true;
            if ((*currentPlayer).getBookSize() > (*otherPlayer).getBookSize())
                winner = currentPlayer;
            else
                winner = otherPlayer;
        }

        cout << endl << endl;




    }

    cout << (*winner).getName() << " is the winner." << endl;
    return EXIT_SUCCESS;

}


void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}