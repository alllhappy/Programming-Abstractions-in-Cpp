/*
Implement the saveToken method for the TokenScanner class. This 
method saves the specified token so that subsequent calls to nextToken
return the saved token without consuming any additional characters from the 
input. Your implementation should allow clients to save multiple tokens, 
which are then returned so that the last token saved is the first token returned.
*/

#include<iostream>
#include"tokenScanner.h"

int main() {
    std::string ipString="I am Karan. I live in Delhi.";
    
    TokenScanner scanner;
    scanner.ignoreWhitespace();
    scanner.addOperator(".");
    scanner.setInput(ipString);
    scanner.saveToken("HAHA");
    std::cout<<scanner.nextToken()<<"\n"; //HAHA
    std::cout<<scanner.nextToken()<<"\n";// I
    std::cout<<scanner.nextToken()<<"\n";//am
    scanner.saveToken("2ndTOKEN");
    while(scanner.hasMoreTokens()){
        std::cout<<scanner.nextToken()<<"\n";
    }
    return 0;
}