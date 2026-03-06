#ifndef _rational_h
#define _rational_h
#include<string>
#include<iostream>
class Rational{

    private:
    /*prinvate variables*/
    int num;int den;

    /*private methods*/
    // int gcd(int a,int b); //can also remove private methods if dont want to include in class
    // and just declare and use them in implementation file if want, then they will not come in header file
    // https://chatgpt.com/share/6960013c-56c0-8009-976f-e99e592febf5

    public:
    /*constructors*/
    Rational();
    Rational(int n);
    Rational(int n,int d);

    /*public methods*/
    std::string toString();

    friend Rational operator+(Rational a,Rational b);
    friend Rational operator-(Rational a,Rational b);
    friend Rational operator*(Rational a,Rational b);
    friend Rational operator/(Rational a,Rational b);
    
    friend bool operator==(Rational a,Rational b);
    friend bool operator!=(Rational a,Rational b);
    friend bool operator<=(Rational a,Rational b);
    friend bool operator<(Rational a,Rational b);
    friend bool operator>=(Rational a,Rational b);
    friend bool operator>(Rational a,Rational b);
    friend void operator+=(Rational &a,Rational b);
    friend void operator-=(Rational &a,Rational b);
    friend void operator*=(Rational &a,Rational b);
    friend void operator/=(Rational &a,Rational b);
};
std::ostream & operator<<(std::ostream &os,Rational r);
Rational operator+(Rational a,Rational b);
Rational operator-(Rational a,Rational b);
Rational operator*(Rational a,Rational b);
Rational operator/(Rational a,Rational b);

bool operator==(Rational a,Rational b);
bool operator!=(Rational a, Rational b);
bool operator<(Rational a, Rational b);
bool operator<=(Rational a, Rational b);
bool operator>(Rational a,Rational b);
bool operator>=(Rational a,Rational b);

void operator+=(Rational &a,Rational b);
void operator-=(Rational &a,Rational b);
void operator*=(Rational &a,Rational b);
void operator/=(Rational &a,Rational b);

Rational operator++(Rational &a); //prefix form
Rational operator++(Rational &a,int); //suffix form
Rational operator--(Rational &a); //suffix form
Rational operator--(Rational &a,int); //suffix form

#endif