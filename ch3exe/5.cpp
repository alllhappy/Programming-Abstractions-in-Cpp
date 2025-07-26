/*In most word games, each letter in a word is scored according to its point 
value, which is inversely proportional to its frequency in English words.  In 
Scrabble™, the points are allocated as follows:For example, the word FARM is worth 9 points in Scrabble: 4 for the F, 1 
each for the A and the R, and 3 for the M.  Write a program that reads in words 
and prints out their score in Scrabble, not counting any of the other bonuses 
that occur in the game.  You should ignore any characters other than uppercase 
letters in computing the score.  In particular, lowercase letters are assumed to 
represent blank tiles, which can stand for any letter but have a score of 0. */ 
#include<iostream>
#include<string>

int scrabble(std::string word);
int main() {
    std::cout<<scrabble("FARM")<<std::endl;
    std::cout<<scrabble("FaRM")<<std::endl;
    return 0;
}
int scrabble(std::string word){
    int score=0;
    for(int i=0;i<word.length();i++){
        char curr=word[i];
        if(isupper(curr)){

            if(curr=='A'|| curr=='E'|| curr=='I'||curr=='L'
                ||curr=='N'|| curr=='O'|| curr=='R' || curr=='S'||
                 curr=='T'|| curr=='U'){
                    score+=1;
                }
            else if( curr=='D'|| curr=='G') score+=2;
            else if(curr=='B'|| curr=='C'|| curr=='M'|| curr=='P') score+=3;
            else if(curr=='K') score+=5;
            else if(curr=='J' || curr=='X') score+=8;
            else if(curr=='Q'|| curr=='Z') score+=10;
            else{
                score+=4;
            }
        }
    }
    return score;
}
