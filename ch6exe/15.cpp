/*
scan numbers using finite state machine simulation
*/

#include<iostream>
#include"tokenScanner.h"
// command to compile-> 15.cpp tokenScanner.cpp fsm.cpp
int main() {
    TokenScanner scanner;
    scanner.scanNumbers();
    scanner.ignoreWhitespace();
    std::string ipString="hahahahha 34. value of pi is 3.14. this is an exponent 3E+9  sep 3.48E+9 ha 3ee9 3E+ 3.EE";
    scanner.setInput(ipString);
    while(scanner.hasMoreTokens()){
        std::cout<<scanner.nextToken()<<"\n";
    }
    return 0;
}