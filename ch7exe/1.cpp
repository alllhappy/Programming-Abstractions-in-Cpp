/*Spherical objects, such as cannonballs, can be stacked to form a pyramid with 
one cannonball at the top, sitting on top of a square composed of four 
cannonballs, sitting on top of a square composed of nine cannonballs, and so 
forth.  Write a recursive function cannonball that takes as its argument the 
height of the pyramid and returns the number of cannonballs it contains.  Your 
function must operate recursively and must not use any iterative constructs, 
such as while or for. */
#include<iostream>

int cannonBalls(int height);

int main() {
    int x=cannonBalls(2);
    std::cout<<x<<std::endl;
    return 0;
}

int cannonBalls(int height) {
    if (height == 1) {
        return 1;
    } else {
        return height * height + cannonBalls(height - 1);
    }
}
