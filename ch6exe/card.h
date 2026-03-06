#ifndef CARD_H
#define CARD_H


#include<string>
#include<iostream>

enum Suit {CLUBS,DIAMONDS,HEARTS,SPADES,ND};//0,1,2,3,4 //means ND is not defined
#define ACE 1
#define JACK 11
#define QUEEN 12
#define KING 13

class Card{
    private :
    int rank;
    Suit st;

    public:
    //constructors
    Card();
    Card(std::string init);
    Card(int r,Suit s);

    //methods
    std::string toString();

    //getters
    int getRank();
    Suit getSuit();

};

std::ostream & operator<<(std::ostream &os,Card c);

Suit operator++(Suit &st,int);
#endif