/*
Write the files combinatorics.h and combinatorics.cpp for a library 
that exports the functions permutations and combinations.  When you 
write the implementation, make sure to rewrite the code for the combinations 
function so that it uses the efficiency enhancements suggested for permutations 
in exercise 9. 
*/

#include<iostream>
#include"combinatorics.h"


int main() {

    std::cout<< permutations(6,2)<<std::endl;
    std :: cout<< combinations(6,2)<<std::endl;
    return 0;
}