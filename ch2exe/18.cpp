/*prints a ying yang symbol*/
#include<iostream>
#include<graphics.h>
const int radius=200;
void ConcCircles(int x ,int y,colors outerColor);
void BackFill(int col);
int main() {

    int gd=DETECT;
    int gm;
    initgraph(&gd,&gm,(char*)"");
    BackFill(colors::RED);
    int cX=getmaxx()/2;
    int cY=getmaxy()/2;
    setfillstyle(SOLID_FILL,colors::BLACK);
    sector(cX,cY,270,90,radius,radius); // right half circle filled with black 
    setfillstyle(SOLID_FILL,colors::WHITE);
    sector(cX,cY,90,270,radius,radius);//left half circle
    ConcCircles(cX,cY-(radius/2),colors::WHITE); // upper conc circle
    ConcCircles(cX,cY+(radius/2),colors::BLACK); //lower conc circle
    getch();
    return 0;
}

void ConcCircles(int x ,int y,colors outerColor){
    colors innerColor;

    if(outerColor==colors::BLACK){
        innerColor=colors::WHITE; 
    }
    else{
        innerColor=colors::BLACK;
    }
    
    setfillstyle(SOLID_FILL,outerColor);
    fillellipse(x,y,radius/2,radius/2);
    setfillstyle(SOLID_FILL,innerColor);
    fillellipse(x,y,radius/20,radius/20);
    setcolor(outerColor);
    // for border of outer circle
    ellipse(x,y,0,360,radius/2,radius/2);


}
void BackFill(int col){
    int xMax = getmaxx() ;//finding centre x-ordinate of screen
    int yMax = getmaxy() ;//finding centre y-ordinate of screen
    setcolor(col);
    for(int y=0;y<yMax;y++){
        line(0,y,xMax,y);
    }
}

