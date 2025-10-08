/*MAGIC SQUARE 
 Your program 
should work for square grids of any size.  If you call isMagicSquare with a 
grid in which the number of rows and columns are different, it should simply 
return false. 
*/
#include<iostream>
#include<vector>

bool isMagicSquare(std::vector<std::vector<int>> &sq);
int main() {
    std::vector<std::vector<int>> test1={{8,1,6},{3,5,7},{4,9,2}};
    std::vector<std::vector<int>> test2={{8,1,6},{3,5,7},{1,9,2}};

    std::cout<<isMagicSquare(test1)<<"\n"<<isMagicSquare(test2);
    return 0;
}
bool isMagicSquare(std::vector<std::vector<int>> &sq){
    //now check if it is a square.
    if(sq.size()!=sq[0].size()) return false; // rows != col

    //find sum of rows, sum of cols ,//2 digonals only in sq 
    int n=sq.size();
    int rowSum=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            sum+=sq[i][j];
        }
        if(i==0){
            //first time assignment of rowSum so no need to check
            rowSum=sum;
        }
        else if(rowSum !=sum) return false;
    }

    //same for columns
    int colSum=0;
    for(int i=0;i<sq.size();i++){
        int sum=0;
        for(int j=0;j<sq.size();j++){
            sum+=sq[j][i];
        }
        if(i==0){
            //first time assignment of rowSum so no need to check
            if(sum!=rowSum) return false; //first column sum is not equal to earlier calculated colsum so return false as no 
            //need to check subsequent cols
            colSum=sum;
        }
        else if(colSum !=sum) return false;
    }

    //now here colSum == rowSum and all rows and cols have same sum
    //now check diagonals
    //diagonals will have n elements only
    int diagonalSum1=0;
    for(int i=0;i<n;i++){ // top left to bottom right diagonal
        diagonalSum1+=sq[i][i];
    }
    if(diagonalSum1!=rowSum) return false;
    //now check second diagonal , top right to bottom left
    int k=0;
    int j=n-1;
    int diagonalSum2=0;
    for(int i=0;i<n;i++){
        diagonalSum2+=sq[k][j];
        k++;
        j--;
    }
    if(diagonalSum2!=diagonalSum1) return false;
    return true;
}
