/*
Write a program to simulate the following experiment, which was included in 
the 1957 Disney film Our Friend the Atom, to illustrate the chain reactions 
involved in nuclear fission. The setting for the experiment is a large cubical 
box, the bottom of which is completely covered with 625 mousetraps arranged 
to form a square grid 25 mousetraps on a side. Each of the mousetraps is 
initially loaded with two ping-pong balls. At the beginning of the simulation, 
an additional ping-pong ball is released from the top of the box and falls on 
one of the mousetraps. That mousetrap springs and shoots its two ping-pong 
balls into the air. The ping-pong balls bounce around the sides of the box and 
eventually land on the floor, where they are likely to set off more mousetraps.
In writing this simulation, you should make the following simplifying 
assumptions:
• Every ping-pong ball that falls always lands on a mousetrap, chosen 
randomly by selecting a random row and column in the grid. If the trap is 
loaded, its balls are released into the air. If the trap has already been 
sprung, having a ball fall on it has no effect.
• Once a ball falls on a mousetrap—whether or not the trap is sprung—that 
ball stops and takes no further role in the simulation.
• Balls launched from a mousetrap bounce around the room and land again 
after a random number of simulation cycles have gone by. That random 
interval is chosen independently for each ball and is always between one 
and four cycles.
Your simulation should run until there are no balls in the air. At that point, 
your program should report how many time units have elapsed since the 
beginning, what percentage of the traps have been sprung, and the maximum 
number of balls in the air at any time in the simulation
*/

// command to compile:  g++ 18.cpp random.cpp -o 18 
#include<iostream>
#include<vector>
#include"random.h"
#define SIDE 25
#define SIMULATIONCYCLES 4


void runSimulation(int &time,int &sprung,int &maxBallsInAir);
void showOutput(int time,int sprung,int maxBallsInAir);

int main() {
    int time=0;
    int sprung=0;
    int maxBallsInAir=0;
    runSimulation(time,sprung,maxBallsInAir);
    showOutput(time,sprung,maxBallsInAir);
    return 0;
}

void runSimulation(int &time,int &sprung,int &maxBallsInAir){
    std::vector<std::vector<int>> grid(SIDE,std::vector<int>(SIDE,2)); //intially every cell has 2 ball
    // a data structure to keep record of balls ready to fall at t,t+1,t+2,t+4 ,at any instant only these 4 values need
    vector<int> ballInAir(SIMULATIONCYCLES,0);//represents t+0,t+1,t+2,t+3balls in air
    ballInAir[0]=1; // 1 ball intially
    time=0;
    //loop should run until there is no ball in air --> means above array is 
    while(true){
        //select the cell randomly at which it will fall for each ball in air as it will fall
        int currBalls=*ballInAir.begin();
        maxBallsInAir=max(maxBallsInAir,currBalls);
        ballInAir.erase(ballInAir.begin()); //erase current second balls so now 0 index stores next second balls
        ballInAir.push_back(0);//for time+4 second
        
        for(int i=0;i<currBalls;i++){
            int row= randomInteger(0,SIDE-1);
            int col=randomInteger(0,SIDE-1);
            //make it fall means check if this cell  has balls or not to set in air
            if(grid[row][col]!=0){
                // means it has balls to set in air so, also it can make take 1 to 4 time to return back, and not necessarily
                //the ball will come back in next second. it can be at t+0, t+1,t+2,t+3 ,t+4 , at this point 0th index represents
                //time+1 second balls
                sprung++;
                for(int j=0;j<2;j++){
                    int timeOffset =randomInteger(0,ballInAir.size()-1); //0,1,2,3,4as offsets // 0 will now stand for t+0(next second) ,
                    ballInAir[timeOffset]++;
                }
               grid[row][col]=0;// as current cell is used now
            }
           
        }
        time++;
        //check wheter the there is any ball in air or not
        // cout<<time<<endl;
        bool noBallInAir=true;
        for(int i=0;i<ballInAir.size();i++){
            if(ballInAir[i]) noBallInAir=false;
        }
        if(noBallInAir) break;
    }
    
}
void showOutput(int time,int sprung,int maxBallsInAir){
    std::cout<<"time elapsed : " << time <<endl;
    double sprungPercent= (double(sprung)/(SIDE*SIDE))*100;
    std::cout<<"sprung % : "<< sprungPercent<<endl;
    // std::cout<<"sprung  : "<< sprung<<endl;
    std::cout<<"maxBallsInAir at any time t : "<< maxBallsInAir<<endl;
}