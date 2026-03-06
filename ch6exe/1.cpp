/*Define a simple Domino class that represents a traditional domino. Your 
class should export the following entries:
• A default constructor that creates the 0-0 domino
• A constructor that takes the number of dots on each side
• A toString method that creates a string representation of the domino
• Two getter methods named getLeftDots and getRightDots

Write the domino.h interface and the domino.cpp implementation that 
export this class. As with the examples in the text, all instance variables 
should be private to the class, and the interface should overload the <<
operator so that it is possible to print a string representation of a domino.
Test your implementation of the Domino class by writing a program that 
creates a full set of dominos from 0-0 up to 6-6 and then displays those 
dominos on the console. A full set of dominos contains one copy of each 
possible domino in that range, disallowing duplicates that result from flipping 
a domino over. A domino set, therefore, has a 4-1 domino but not a separate 
1-4 domino
*/


#include<iostream>
#include<vector>
#include"domino.h"

// command to compile - g++ 1.cpp domino.cpp 

int main() {

    std::vector<Domino> v;
    for(int i=0;i<=6;i++){
        v.push_back(Domino(i,i));
        for(int j=i+1;j<=6;j++){
            v.push_back(Domino(i,j));
        }
    }

    //ideally size should be 28
    std::cout<<"Domino set size is "<<v.size()<<"\n";

    for(int i=0;i<v.size();i++){
        std::cout<<v[i]<<"\n";
    }
    
    return 0;
}