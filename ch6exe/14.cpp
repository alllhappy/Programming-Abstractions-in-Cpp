#include<iostream>
#include"tokenScanner.h"

int main() {
    TokenScanner scanner;
    scanner.scanStrings();
    scanner.ignoreWhitespace();
    std::string ipString="As Kanika Kapoor said 'yeh duniya pittal di' haha";
    std::string ipString2="\"Chak De India song\" belongs to the movie Chak de India";

    scanner.setInput(ipString);
    while(scanner.hasMoreTokens()){
        std::cout<<scanner.nextToken()<<"\n";
    }
    std::cout<<"\n";
    scanner.setInput(ipString2);
    while(scanner.hasMoreTokens()){
        std::cout<<scanner.nextToken()<<"\n";
    }

    std::cout<<"\n";
    // std::string ipString3="Krsna's album your's truely belongs to the movie Chak de India"; //will give problems
    // scanner.setInput(ipString3);
    // while(scanner.hasMoreTokens()){
    //     std::cout<<scanner.nextToken()<<"\n";
    // }
    return 0;
}