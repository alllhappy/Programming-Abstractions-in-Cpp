/*draws rainbow*/
#include<iostream>
#include<graphics.h>
#include<vector>

void filledArc(int col,int stRadius,int x,int y);
void BackFill(int col);


int main() {

    int gd=DETECT;
    int gm;
    initgraph(&gd,&gm,(char*)"");
    setfillstyle(1,2);

    int x = getmaxx() / 2;//finding centre x-ordinate of screen
    int y = getmaxy() / 2;//finding centre y-ordinate of screen
    std::cout<<x<<" "<<y;

    BackFill(colors::CYAN);
    // line(0,0+1,getmaxx(),getmaxy()+1);
    std::vector<int> rainbowColors= {COLOR(128,0,255),colors:: BLUE,colors::GREEN,colors::YELLOW,COLOR(255,165,0),colors::RED} ;//violet ,blue
    
   
    for (int i=0; i<6; i++)
    {

        // function for some time
        delay(10);
        // making of arc with fixed centre and increasing radius
        std::cout<<rainbowColors[i]<<std::endl;
        filledArc(rainbowColors[i],50+i*20,x,y);
       
    }

    getch();
}


/* takes param color , startRadius for drawing arc, and center x,y . The width of filled arc will be 20*/
void filledArc(int col,int stRadius,int x ,int y){
    setcolor(col);
    for(int i=stRadius;i<=stRadius+20;i++){
        arc(x,y,0,180,i);
    }
}

/*fills complete background of screen with specific color*/
void BackFill(int col){
    int xMax = getmaxx() ;//finding centre x-ordinate of screen
    int yMax = getmaxy() ;//finding centre y-ordinate of screen
    setcolor(col);
    for(int y=0;y<yMax;y++){
        line(0,y,xMax,y);
    }
}
