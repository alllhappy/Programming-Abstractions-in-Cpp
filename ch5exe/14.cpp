/*
Write a program that checks whether the bracketing operators (parentheses, 
brackets, and curly braces) in a string are properly matched. As an example of 
proper matching, consider the string

If you go through the string carefully, you discover that all the bracketing 
operators are correctly nested, with each open parenthesis matched by a close 
parenthesis, each open bracket matched by a close bracket, and so on.
*/
#include<iostream>
#include<stack>
#include<string>

bool checkBrackets(std::string s);
bool checkStack(char opening,char closing,std::string st);
int main() {
    std::string exp= "{ s = 2 * (a[2] + 3); x = (1 + (2)); }}";
    std::cout<<checkBrackets(exp);
    return 0;
}

bool checkBrackets(std::string s){
    //push in stack if encounters opening , if encounter close then  pop the top, 3 different stack for 3 different brackets
    bool brac1=checkStack('(',')',s);
    bool brac2=checkStack('{','}',s);
    bool brac3=checkStack('[',']',s);
    return (brac1 &&brac2 &&brac3);
}

bool checkStack(char opening,char closing,std::string s){
    std::stack<char> st;
    for(int i=0;i<s.size();i++){
        if(s[i]==opening) st.push(s[i]);
        else if(s[i]==closing){
            if(st.size()>=1){
                st.pop();
            }
            else return false;
        }
    }
    if(st.size()!=0) return false;
    return true;
}
