/*implementaitioon file for card.h*/

#include<iostream>
#include"card.h"

Card::Card(){
    rank=-1;
    st=ND;
}

Card::Card(std::string initSt){
    //last character is Suit
    //in all cases 2 size strings, except 10S case
    //deciding suit

        switch (initSt[initSt.size()-1])
        {
        case 'C':
            st=CLUBS;
            break;
        case 'D':
            st=DIAMONDS;
            break;
        case 'H':
            st=HEARTS;
            break;
        case 'S':
            st=SPADES;
            break;
        default:
            st=ND;
            
            break;
        }
    

    //rank
    if(initSt.size()==2){
        switch (initSt[0])
        {
        case 'A':
            rank=1;
            break;
        case 'J':
            rank=11;
            break;
        case 'Q':
            rank=12;
            break;
        case 'K':
            rank=13;
            break;
        case '2':
            rank=2;
            break;
        case '3':
            rank=3;
            break;
        case '4':
            rank=4;
            break;
        case '5':
            rank=5;
            break;
        case '6':
            rank=6;
            break;
        case '7':
            rank=7;
            break;
        case '8':
            rank=8;
            break;
        case '9':
            rank=9;
            break;
        default:
            rank=-1;
            break;
        }
    }
    if(initSt.size()==3){
        if(initSt[0]=='1' && initSt[1]=='0'){
            rank=10;
        }
        else rank=-1;
    }
    if(initSt.size()>3){
            rank=-1;
            st=ND;
        }
    
}

Card::Card(int r, Suit s){
    rank=r;
    st=s;
}

std::string Card::toString(){
    std::string s="NA";
    if(st==CLUBS) s="C";
    else if(st==DIAMONDS) s="D";
    else if(st==HEARTS) s="H";
    else if(st==SPADES) s="S";
    std::string rk="-1";
    if(rank==1) rk="A";
    else if(rank==11) rk="J";
    else if(rank==12) rk="Q";
    else if(rank==13) rk="K";
    else rk=std::to_string(rank);
    return rk+s;
}

int Card::getRank(){
    return rank;
}

Suit Card::getSuit(){
    return st;
}

std::ostream & operator<<(std::ostream &os,Card c){
    return os<<c.toString();
}
//implementaed just like direction
Suit operator++(Suit &st,int){
    Suit old=st;
    st= Suit(st+1);
    return old;
}