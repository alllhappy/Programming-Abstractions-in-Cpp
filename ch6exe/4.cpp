#include<iostream>
#include<graphics.h>
#include"Sim.h"

// g++ 4.cpp GRectangle.cpp -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
int main() {
    int gd=DETECT;
    int gm;
    initgraph(&gd,&gm,(char*)"");
    cleardevice();
    Sim s2= Sim(50,30,67);
    setcolor(2);
    // s2.setAcross(100); s2.setDown(100);
    while(true){
        for(int i=0;i<100;i++){
        s2.setDelta(i);
        s2.runSimulation();
        cleardevice();
   }
    }

    getch();
    return 0;
}