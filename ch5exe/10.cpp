/*Given such a grid of mine locations, write a function 
void fixCounts(Grid<bool> &mines,Grid<int>&counts); 
that creates a grid of integers storing the number of mines in each neighborhood.  
The neighborhood of a location includes the location itself and the eight adjacent 
locations, but only if they are inside the boundaries of the grid.  The reference 
parameter counts is used to store the result.  Your job in this exercise is to make 
sure that it has the same size as the mines grid and then to assign to each element 
an integer between 0 and 9*/

#include<iostream>
#include<vector>

void fixCounts(std::vector<std::vector<bool>> &mines, std::vector<std::vector<int>> &counts);
bool isValid(int i,int j,int rows,int cols); // checks wheter i,j are in grid or not
int main() {
    std::vector<std::vector<bool>> mines={
        {1,0,0,0,0,1},
        {0,0,0,0,0,1},
        {1,1,0,1,0,1},
        {1,0,0,0,0,0},
        {0,0,1,0,0,0},
        {0,0,0,0,0,0}
    };

    std::vector<std::vector<int>> counts;
    fixCounts(mines,counts);

    for( int i=0 ; i< counts.size(); i++){
       for(int j=0;j<counts[i].size();j++){
            std::cout<<counts[i][j]<<" ";
       }
       std::cout<<std::endl;
    }

    return 0;
}
void fixCounts(std::vector<std::vector<bool>> &mines, std::vector<std::vector<int>> &counts){
    //for every point on matrix check its 8neighbourrs
    counts=std::vector<std::vector<int>>(mines.size(),std::vector<int>(mines[0].size(),0));
    std::vector<int> dirX={0,-1,-1,0,1,1,1,0,-1}; //current pos+ adj 8 direction total 9 cells
    std::vector<int> dirY={0,0,1,1,1,0,-1,-1,-1};
    for(int i=0;i<mines.size();i++){
        for(int j=0;j<mines[0].size();j++){
            for(int k=0;k<9;k++){
                int nbrX= i+dirX[k];
                int nbrY= j+dirY[k];
                if(isValid(nbrX,nbrY,counts.size(),counts[0].size()) && mines[nbrX][nbrY]==true) counts[i][j]++;
            }
        }
    }
}

bool isValid(int i,int j,int rows,int cols){
    if(i<0 || j<0 || i>=rows || j>=cols) return false;
    return true;
}