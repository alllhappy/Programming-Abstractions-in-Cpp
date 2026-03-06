/*implmentation of 3.h*/

#include<iostream>
#include"GRectangle.h"

Gpoint:: Gpoint(){
    X=0;Y=0;
}

Gpoint::Gpoint(double x,double y){
    X=x; Y=y;
}

double Gpoint::getX(){
    return X;
}

double Gpoint::getY(){
    return Y;
}

std::string Gpoint::toString(){
    return "("+std::to_string(X)+","+std::to_string(Y)+")";
}


GRectangle::GRectangle(){
    X=0;Y=0;W=0;H=0;
}
GRectangle::GRectangle(double x,double y,double width,double height){
    X=x;Y=y;W=width;H=height;
}

double GRectangle::getX(){
    return X;
}

double GRectangle::getY(){
    return Y;
}
double GRectangle::getHeight(){
    return H;
}
double GRectangle::getWidth(){
    return W;
}

bool GRectangle::isEmpty(){
    if(W==0 || H==0) return true;
    return false;
}

bool GRectangle::contains(double x,double y){
    /*
        +-----------    + ->(X,Y) top left , top right=(X+W,Y), bottom left=(X,Y+H), bottom Right=(X+W,Y+H)
        |          |
        ------------
        on border also true
    */
    Gpoint tl= Gpoint(X,Y);
    Gpoint tr= Gpoint(X+W,Y);
    Gpoint bl= Gpoint(X,Y-H);
    Gpoint br= Gpoint(X+W,Y-H);
    if(x>=tl.getX() && x<=tr.getX() && y>=bl.getY() && y<=tl.getY()){
        return true;
    }
    return false;
}

bool GRectangle::contains(Gpoint pt){
    GRectangle::contains(pt.getX(),pt.getY());
}

std::string GRectangle::toString(){
    return "("+std::to_string(X)+","+std::to_string(Y)+","+std::to_string(W)+","+std::to_string(H)+")";
}