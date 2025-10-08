/*
The resize method in the Grid class resets the dimensions of the grid but 
also initializes every element of the grid to its default value.  Write a function 
void reshape(Grid<int> & grid, int nRows, int nCols); 
that resizes the grid but fills in the data from the original grid by copying 
elements in the standard row-major order (left-to-right/top-to-bottom). 
If the new grid does not include enough space for all of the original values, the 
values at the bottom of the grid are simply dropped.  For example, if you call
Conversely, if there are not enough elements in the original grid to fill the 
available space, the entries at the end should simply retain their default values
*/

#include<iostream>
#include<vector>

void reshape(std::vector<std::vector<int>> &grid,int nRows,int nCols);
void print2dVector(std::vector<std::vector<int>> &grid);
int main() {
    std::vector<std::vector<int>> grid={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    reshape(grid,4,3); // equal element case
    print2dVector(grid);
    std::cout<<"///////////////////////"<<std::endl;
    reshape(grid,2,5); // 2nd case where the resulting vector occupies less space
    print2dVector(grid);

    std::cout<<"///////////////////////"<<std::endl;
    reshape(grid,6,4); // 3rd case where the resulting vector occupies more space
    print2dVector(grid);
    return 0;
}
void reshape(std::vector<std::vector<int>> &grid,int nRows,int nCols){
    //push all elements in a 1s vector then insert it in that order in grid
    std::vector<int> temp;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            temp.push_back(grid[i][j]);
        }
    }
    //now resize grid with default value as 0 and now insert elements in it from te
    grid= std::vector<std::vector<int>>(nRows,std::vector<int>(nCols,0));
    int cnt=0;
    for(int i=0;i<nRows;i++){
        for(int j=0;j<nCols;j++){
            if(cnt>=temp.size()) return; // less elements in temp so all other will default to -1
            grid[i][j]=temp[cnt];
            cnt++;
        }
    }
}

void print2dVector(std::vector<std::vector<int>> &grid){
       for( int i=0 ; i< grid.size(); i++){
       for (int j = 0; j < grid[0].size(); j++){
            std::cout<<grid[i][j]<<" ";
       }
       std::cout<<std::endl;
    }
}