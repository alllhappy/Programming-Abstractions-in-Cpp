/*
Defines a Card class suitable for representing a standard playing card, which 
is identified by two components: a rank and a suit. The rank is stored as an 
integer between 1 and 13 in which an ace is a 1, a jack is an 11, a queen is a 
12, and a king is 13. The suit is one of the four constants in the following 
enumeration type
The Card class should export the following methods:
• A default constructor that creates a card that can later be assigned a value
• A constructor that takes a short string name like "10S" or "JD"
• A constructor that takes separate values for the rank and the suit
• A toString method that returns the short string representation of the card
• The getter methods getRank and getSuit
Write the card.h interface and the card.cpp implementation necessary 
to export the Card class
*/

#include<iostream>
#include"card.h"

//command to compile g++ 2.cpp card.cpp

int main() {
    for(Suit suit=CLUBS;suit<=SPADES;suit++){
        for(int rank=ACE;rank<=KING;rank++){
            std::cout<<" "<<Card(rank,suit);
        }
        std::cout<<"\n";
    }

    std::cout<<Card("KC")<<"\n";
    std::cout<<Card("KCds")<<"\n";
    return 0;
}