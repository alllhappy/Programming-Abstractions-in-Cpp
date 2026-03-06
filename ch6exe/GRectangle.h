/*Grectangle & Gpoint interface*/

#ifndef G_RECTANGLE
#define G_RECTANGLE

#include<string>
#include<vector>

class Gpoint{
    private:
    double X;
    double Y;

    public:
    //constructor
    Gpoint();
    Gpoint(double x,double y);

    //getter
    double getX();
    double getY();

    //methods
    std:: string toString();
};


class GRectangle{
    private:
    double X;
    double Y;
    double W;
    double H;

    public:

    //constructor
    GRectangle();
    GRectangle(double x,double y,double width,double height);

    //getter
    double getX();
    double getY();
    double getWidth();
    double getHeight();

    //methods
    bool isEmpty();
    bool contains(Gpoint pt);
    bool contains(double x,double y);

    std::string toString();


};

#endif