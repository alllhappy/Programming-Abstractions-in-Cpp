#include<iostream>
#include<string>
#include<cctype>
#include"tokenScanner.h"
#include"fsm.h"
#define SINGLE_QUOTE_CODE 39
#define DOUBLE_QUOTE_CODE 34
TokenScanner::TokenScanner(){
    /*empty*/
    cp=0;
    ignoreWhiteSpaceFlag=false;
    scanStringsFlag=false;
    scanNumberFlag=false;
    numberStateFSM = fsm(6);
    numberStateFSM.currState=0;
    numberStateFSM.setInitState(0);
    numberStateFSM.makeFinalState(1);
    numberStateFSM.makeFinalState(2);
    numberStateFSM.makeFinalState(5);
    numberStateFSM.insertTransition(0,1,'D'); //D represent digit
    numberStateFSM.insertTransition(1,1,'D'); //D represent digit
    numberStateFSM.insertTransition(1,2,'.'); //. represent decimal
    numberStateFSM.insertTransition(1,3,'E'); //E represent exponent
    numberStateFSM.insertTransition(2,3,'E'); //D represent digit
    numberStateFSM.insertTransition(2,2,'D'); //D represent digit
    numberStateFSM.insertTransition(3,5,'D'); //D represent digit
    numberStateFSM.insertTransition(3,4,'+'); //+ represent plus exponent power
    numberStateFSM.insertTransition(3,4,'-'); //D represent minum exponent power
    numberStateFSM.insertTransition(4,5,'D'); //D represent digit
    numberStateFSM.insertTransition(5,5,'D'); //D represent digit
}

TokenScanner::TokenScanner(std::string str){
    setInput(str);
    int cp=0;
    bool ignoreWhiteSpaceFlag=false;
    bool scanStringsFlag=false;
    bool scanNumberFlag=false;
}

void TokenScanner::setInput(std::string str){
    buffer=str;
    cp=0;
}

bool TokenScanner::hasMoreTokens(){
    if(ignoreWhiteSpaceFlag) skipWhiteSpace();
    return cp<buffer.length();
}

std::string TokenScanner::nextToken(){
    if(saves.size()>0){
        std::string tk=saves.top();
        saves.pop();
        return tk;
    }
    if(ignoreWhiteSpaceFlag) skipWhiteSpace();
    if(cp>=buffer.length()) return "";

    else if(scanStringsFlag && (buffer[cp]==DOUBLE_QUOTE_CODE|| buffer[cp]==SINGLE_QUOTE_CODE)){ //ascii 34=" 39='
        char flag=buffer[cp];
        //edge case use of single quotion mark like -> your's
        int start=cp;
        cp++;
        while(cp<buffer.length() && buffer[cp]!=flag){
            cp++;
        }
        cp++;
        return buffer.substr(start,cp-start+1);
    }
    else if(scanNumberFlag && isdigit(buffer[cp])){
        //now traverse in graph
        int cpTemp=cp;
        std::string number;
        numberStateFSM.currState=0;
        while(cp<buffer.length() && numberStateFSM.currState!=-1){
           char ch = buffer[cp];

            if(isdigit(ch)) ch='D';
            else if(ch=='e') ch='E';
            int prevState = numberStateFSM.currState;
            numberStateFSM.setState(ch);
            if(numberStateFSM.currState==-1){
                numberStateFSM.currState = prevState;
                break;
            }
            number.push_back(buffer[cp]);
            cp++;
        }
        //now cp is on invalid character
        if(numberStateFSM.validState()) return number;
        while(cp< buffer.length() && isalnum(buffer[cp])){
            cp++;
        }
        return buffer.substr(cpTemp,cp-cpTemp);
        
    }
    else if(isalnum(buffer[cp])){
        int start = cp;
        while(cp< buffer.length() && isalnum(buffer[cp])){
            cp++;
        }
        return buffer.substr(start,cp-start);
    }
    else{
        return std::string(1,buffer[cp++]);
    }
}

void TokenScanner::ignoreWhitespace(){
    ignoreWhiteSpaceFlag=true;
}

void TokenScanner::skipWhiteSpace(){
    while(cp<buffer.length() && isspace(buffer[cp])){
        cp++;
    }
}

void TokenScanner::scanNumbers(){
    //TODO
    scanNumberFlag=true;
    
}
void TokenScanner::addOperator(std::string op){
    // TOOD
}

void TokenScanner:: saveToken(std::string tk){
    saves.push(tk);
}

void TokenScanner::scanStrings(){
    scanStringsFlag=true; //m
    //how to make it false, it works once and becomes false in nextToken, or always on once on.
    // https://chatgpt.com/s/t_69aa6e7f8f34819197aa9273d2ff802d
}

