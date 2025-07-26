#include<iostream>
#include<vector>

std::vector<std::vector<int>> pascalTriangle(int rows);
void pascalTriangleHelper(int rows,std::vector<std::vector<int>> &ans,int &i);
std::vector<int> pascalTriangleRow(int n ,std::vector<std::vector<int>> triangle);
void rowSum(int &index ,std::vector<int> &currRow, std::vector<int> upperRow );
int main() {
    std::vector<std::vector<int>> triangle=pascalTriangle(5);
    for( int i=0 ; i< triangle.size(); i++){
       for( int j=0 ; j< triangle[i].size(); j++){
          std::cout<< triangle[i][j]<<" ";
       }
       std::cout<<std::endl;
    }
    return 0;
}

/*Wrapper function around pascalTriangleHelper fn to provide neccessary variablest to it*/
std::vector<std::vector<int>> pascalTriangle(int rows){
    std::vector<std::vector<int>> ans;
    if(rows==0) return ans;
    int i=1;
    pascalTriangleHelper(rows,ans,i);
    return ans;
}

/* this function pushes a single row of pascal triangle in the final answer*/
void pascalTriangleHelper(int rows,std::vector<std::vector<int>> &ans,int &i){
    if(i>rows){
        return;
    }
    std::vector<int> row=pascalTriangleRow(i,ans);
    i++;
    ans.push_back(row);
    pascalTriangleHelper(rows,ans,i);
    
}
/*calculates a single row based on value of row value, nth row is obtained with the help
 of n-1 th row
*/
std::vector<int> pascalTriangleRow(int n ,std::vector<std::vector<int>> triangle){
    // if n is row then triangle will help to see n-1 row for caluclationk of next row
    std::vector<int> row;
    if(n==1){
        row.push_back(1);
        return row;
    }
    if(n==2){
        row.push_back(1);
        row.push_back(1);
        return row;
    }
    // n will go from 3 to rows here
    // each row will contain starting and ending 1
    std::vector<int> upperRow=triangle[n-2];
    int index=0;
    rowSum(index,row,upperRow);
    
    return row;

}

/*calculates the rowvalue by summing the individual values of upperRow and pushes in currRow*/
void rowSum(int &index ,std::vector<int> &currRow, std::vector<int> upperRow ){
    if(index==upperRow.size()){
        currRow.push_back(1);
        return;
    }

    // if index b/w 0 and upperRow.size()-1
    if(index==0){
        currRow.push_back(1);   
    }
    else{
        int prevIndex=index-1;
        int sum=upperRow[index]+upperRow[prevIndex];
        currRow.push_back(sum);
    }

    index++;
    rowSum(index,currRow,upperRow);
}