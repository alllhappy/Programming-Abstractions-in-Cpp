#include<iostream>
#include"Sim.h"
#include<graphics.h>

Sim::Sim(){
    N_ACROSS=10;
    N_DOWN=10;
    DELTA=10;
}
Sim::Sim(int across,int down,int delta){
    N_ACROSS=across;
    N_DOWN=down;
    DELTA=delta;
}

int Sim::getAcross(){
    return N_ACROSS;
}
int Sim::getDown(){
    return N_DOWN;
}
int Sim::getDelta(){
    return DELTA;
}
std::vector<Gpoint> Sim::getPoints(){
    return v;
}

void Sim::setAcross(int n){
    N_ACROSS=n;
}

void Sim::setDown(int n){
    N_DOWN=n;
}
void Sim::setDelta(int n){
    DELTA=n;
}

void Sim::findPoints(){
    //window is x inc in right dir, y inc in down direction
    //          
    v.clear();
    Gpoint origin= Gpoint(0,0); //1st peg //pegs at border of window
    int D= getmaxx()/(N_ACROSS-1);
    int W=getmaxy()/(N_DOWN-1);
    // std::cout<<D<<" "<<W<<std::endl;
    for(int i=0;i<N_ACROSS;i++){
        v.push_back(Gpoint(origin.getX()+i*D,origin.getY()));
    }
    Gpoint tr=v[N_ACROSS-1];
    for(int i=1;i<N_DOWN;i++){
        v.push_back(Gpoint(tr.getX(),abs(long(tr.getY()-i*W))));
    }

    Gpoint br=v.back();
    for(int i=1;i<N_ACROSS;i++){
        v.push_back(Gpoint(br.getX()-i*D,br.getY()));
    }

    Gpoint bl=v.back();
    for(int i=1;i<N_DOWN-1;i++){
        v.push_back(Gpoint(bl.getX(),abs(long(bl.getY()-i*W))));
    }
}
void Sim:: runSimulation(){

    findPoints();
    // for( int i=0 ; i< v.size(); i++){
    //    std::cout<<v[i].toString()<<std::endl;
    // }
    // line(v[0].getX(),v[0].getY(),v[N_ACROSS+N_DOWN-2].getX(),v[N_ACROSS+N_DOWN-2].getY());//diagonal line
    int i=0;
    int n=v.size();
    int j=(i+DELTA)%n;
    while(j!=0){
        delay(10);
        line(v[i].getX(),v[i].getY(),v[j].getX(),v[j].getY());
        i=j;
        j=(i+DELTA)%n;
    }

}