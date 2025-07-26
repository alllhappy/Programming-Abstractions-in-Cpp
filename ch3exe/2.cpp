/*The strlib.h function exports a function trim(str) that returns a new 
string formed by removing all whitespace characters from the beginning and 
end of str.  Write the corresponding implementation. */
#include<iostream>
#include<string>

std::string trim(std::string str);
int main() {
    std::string str="   helo Worlsd  ";
    std::cout<<trim(str)<<std::endl;
    return 0;
}

std::string trim(std::string str){
    while(true){
        bool flagBegin=0;
        bool flagEnd=0;
        char startChar=str[0];
        char endChar=str[str.length()-1];
        if(isspace(startChar)){
            str.erase(0,1);
        }
        else{
            flagBegin=1;
        }

        if(isspace(endChar)) {
            str.erase(str.length()-1,1);
        }
        else{
            flagEnd=1;
        }

        if(flagBegin &&flagEnd) break;
    }
    return str;
}

