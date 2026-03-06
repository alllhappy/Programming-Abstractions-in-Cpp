#include<iostream>
#include"rational.h"
#include"error.h"

/*pending implementaioin*/

int gcd(int x,int y);

Rational ::  Rational(){
    num=0;
    den=1;
}

Rational :: Rational(int n){//constructors and destructors dont return any value, they just initialze obsjects fields
    num=n;
    den=1;
}
Rational :: Rational(int a,int b){
    if(b==0) error("denominator cant be 0");
    if(a==0) Rational();
    else{
        int g=gcd(abs(a),abs(b));
        num=a/g;
        den= abs(b)/g;
        if(b<0) num= -num;
    }
}

std::string Rational::toString(){
     return std::to_string(num)+"/"+std::to_string(den);
}
Rational operator+(Rational a,Rational b){
    return Rational(a.num*b.den+b.num*a.den,a.den*b.den);
}
Rational operator-(Rational a,Rational b){
    return Rational(a.num*b.den-b.num*a.den,a.den*b.den);
}

Rational operator*(Rational a,Rational b){
    return Rational(a.num*b.num,a.den*b.den);
}

Rational operator/(Rational a,Rational b){
    return Rational(a.num*b.den,a.den*b.num);
}
std::ostream & operator<<(std::ostream &os,Rational r){
    return os<<r.toString();
}

int gcd(int x,int y){
    if(y==0) return x;
    return gcd(y, x%y);
}

bool operator==(Rational a,Rational b){
    if(a.num==b.num && b.den==a.den) return true;
    return false;
}
bool operator!=(Rational a, Rational b){
    return !(a==b);
}

bool operator<(Rational a, Rational b){
    //2 methods. equivalend denominators and cross multiplication method.
    //using cross mulitplication check
    if(a==b) return false;
    if(a.num*b.den > b.num*a.den) return false; //means acutally a>b
    return true;
}

bool operator<=(Rational a, Rational b){
    if(a==b) return true;
    return a<b;
}
bool operator>(Rational a,Rational b){
    if(a==b) return false;
    if(a.num*b.den > b.num*a.den) return true; //means acutally a>b
    return false;
}
bool operator>=(Rational a,Rational b){
    if(a==b) return false;
    return a>b;
}
void operator+=(Rational &a,Rational b){
    a= a+b;
}
void operator-=(Rational &a,Rational b){
    a= a-b;
}

void operator*=(Rational &a,Rational b){
    a= a*b;
}

void operator/=(Rational &a,Rational b){
    a= a/b;
}
Rational operator++(Rational &a){
    a=a+1;
    return a;    
}

Rational operator++(Rational &a,int){
    a=a+1;
    return a-1;    
}

Rational operator--(Rational &a){
    a=a-1;
    return a;    
}

Rational operator--(Rational &a,int){
    a=a-1;
    return a+1;    
}