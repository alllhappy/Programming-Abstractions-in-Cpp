#ifndef TOKEN_SCANNER_H
#define TOKEN_SCANNER_H

#include<string>
#include<stack>
#include"fsm.h"
class TokenScanner{
    private:
    std::string buffer;
    std::stack<std::string> saves;
    int cp;
   
    bool ignoreWhiteSpaceFlag;
    bool scanStringsFlag;
    bool scanNumberFlag;
    void skipWhiteSpace();
    fsm numberStateFSM;

    public:
    TokenScanner();
    TokenScanner(std::string str);    
    void setInput(std::string str);
    bool hasMoreTokens();
    std::string nextToken();
    void ignoreWhitespace();
    void scanNumbers();
    void addOperator(std::string op);
    void saveToken(std::string tk);
    void scanStrings();
};

#endif