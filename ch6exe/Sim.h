#ifndef SIM
#define SIM

#include<vector>
#include"GRectangle.h"
class Sim{
    //private varialbe
    private:
    int N_ACROSS;
    int N_DOWN;
    int DELTA;
    std::vector<Gpoint> v;//contins the points
     //method populate the points  in vector v
    void findPoints();


    public:
    //constructor
    Sim();
    Sim(int across,int down,int delta);

    //getter
    int getAcross();
    int getDown();
    int getDelta();

    std::vector<Gpoint> getPoints();

    //setter
    void setAcross(int n);
    void setDown(int n);
    void setDelta(int n);

    void runSimulation();
    
};
#endif