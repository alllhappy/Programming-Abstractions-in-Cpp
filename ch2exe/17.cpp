
/*Checkboard creation of 8x8 with side of each square as sqWidth*/
#include<iostream>
#include<graphics.h>
#include<vector>

void Filledsquare(int topX,int topY,int width,int height,colors col);
void squareCircle(int topX,int topY,int width,int height,colors sqColor, colors cColor);
void squareRow(int topX,int topY,int rowNo);
void circleSquareRow(int topX,int topY,int rowNo,bool startSq);
const int sqWidth=450/8;
int main() {
    int gd=DETECT;
    int gm;
    initgraph(&gd,&gm,(char*)"");
    

    for(int i=0;i<8;i++){;
        if(i==3 || i==4){
            squareRow(0,i*sqWidth,i);
        }
        else{
            bool stSquare;
            if(i&1){
                // odd row
                stSquare=false;
            }
            else{
                //even row
                stSquare=true;
            }
            circleSquareRow(0,i*sqWidth,i,stSquare);
        }
   
    }

    getch();

    return 0;
}

/*draws a colored square whose top corner coordinates are given, with given side and color */
void Filledsquare(int topX,int topY,int width,int height,colors col){  
    rectangle(topX,topY,topX+width,topY+height);
    setfillstyle(SOLID_FILL, col);
    floodfill(topX + 1, topY + 1,getmaxcolor());

}
/*draws a colored square which have filled circle of color cColor inside it. the circle is of radius 0.45*sqWidth */
void squareCircle(int topX,int topY,int width,int height,colors sqColor, colors cColor){
    Filledsquare(topX,topY,width,height,sqColor);
    setfillstyle(SOLID_FILL,cColor);
    fillellipse(topX+sqWidth/2,topY+sqWidth/2,sqWidth*0.45,sqWidth*0.45);
}

/*prints a square Row of 8 squares only and starting sqcolor is decided on basis of rowNO*/
void squareRow(int topX,int topY,int rowNo){
  
    bool oddRow=rowNo&1;
    for(int i=0;i<8;i++){
    colors sqcolor;
        if(oddRow){
            if(i&1){
                sqcolor=colors::WHITE;
            }
            else{
                sqcolor=colors::DARKGRAY;
            }
        }
        else{
            if(i&1){
                sqcolor=colors::DARKGRAY;
            }
            else{
                sqcolor=colors::WHITE;
            }
        }
        Filledsquare(i*sqWidth,topY,sqWidth,sqWidth,sqcolor);
    }
}

/* Draws a row which have alternate circles, starting sqcontains circle or not depends on startSq*/
void circleSquareRow(int topX,int topY,int rowNo,bool startSq){
    bool oddRow=rowNo&1;
    colors cColor;
    if(rowNo<=2){
        cColor=colors::RED;
    }
    else{
        cColor=colors::BLACK;
    }
    bool startingWithSquare=startSq;
    for(int i=0;i<8;i++){
    colors sqcolor;
        if(oddRow){
            if(i&1){
                sqcolor=colors::WHITE;
            }
            else{
                sqcolor=colors::DARKGRAY;
            }
        }
        else{
            if(i&1){
                sqcolor=colors::DARKGRAY;
            }
            else{
                sqcolor=colors::WHITE;
            }
        }
        if(startingWithSquare){
            Filledsquare(i*sqWidth,topY,sqWidth,sqWidth,sqcolor);
        
        }
        else{
            squareCircle(i*sqWidth,topY,sqWidth,sqWidth,sqcolor,cColor);
        }
        startingWithSquare = !startingWithSquare;
    }
}
