/* you can easily write a method that 
checks to see whether a proposed solution follows the Sudoku rules against 
duplicating values in a row, column, or outlined 3!3 square.  Write a function 
bool checkSudokuSolution(Grid<int> & puzzle); 
that performs this check and returns true if the puzzle is a valid solution.  
Your program should check to make sure that puzzle contains a 9!9 grid of 
integers and report an error if this is not the case.*/

#include<iostream>
#include<vector>

/*it will return true even if it is partially filled with values and each number which is present is preset once in a row,col,box*/

bool checkSudokuSolution(std::vector<std::vector<char>>& board);
bool checkSubMatrix(int i,int j, std::vector<std::vector<char>> &board);
int main() {
    std::vector<std::vector<char>> sudoku={
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
};
    std::cout<<checkSudokuSolution(sudoku);
    return 0;
}

bool checkSudokuSolution(std::vector<std::vector<char>>& board) {
        if(board.size()!=9 || board[0].size()!=9) return false;
        // brute force only -- first checking all rowwise,
        // then checking all column wise , // then checking all submatrices
        std::vector<bool> visited(10,false); // so that mapping 1 2 3 ..9 and not 0 1 2 ..8
         int n=9;
        // checking row wise
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int index= board[i][j] - '0';
                    if(visited[index]==false) visited[index]=true;
                    else return false;
                }
            }
            visited= std::vector<bool>(10,false);
        }
        //  std::cout<<"row passed"<<endl;
        visited= std::vector<bool>(10,false);
        // check column wise
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[j][i]!= '.'){
                    int index= board[j][i] - '0';
                    if(visited[index]==false) visited[index]=true;
                    else return false;
                }
            }
             visited= std::vector<bool>(10,false);
        }
        // std::cout<<"column passed"<<endl;

        // checking submatrices
        // will have starting index for 3x3 search
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                // now starting index is i,j
                bool check=checkSubMatrix(i,j,board);
                if(check==false)return false;
            }
        }       
        return true;
    }

    bool checkSubMatrix(int i,int j, std::vector<std::vector<char>> &board){
        std::vector<bool> visited(10,false);
        for(int k=i;k<i+3;k++){
            for(int m=j;m<j+3;m++){
                if(board[k][m]!='.'){
                    int index= board[k][m] - '0';
                    if(visited[index]==false) visited[index]=true;
                    else return false;
                }
            }
        }
        return true;
    }