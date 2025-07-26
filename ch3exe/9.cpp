/*so that 
bookkeeper would be written as bokeper and committee would become comite.  
Write a function removeDoubledLetters(str) that returns a new string in 
which any duplicated characters in str have been replaced by a single copy.*/
#include<iostream>
#include<string>

std::string removeDoubeldLetters(std::string str);
int main() {
    std::cout<<removeDoubeldLetters("bookkeeper")<<std::endl;
    std::cout<<removeDoubeldLetters("committee")<<std::endl;
    return 0;
}

std::string removeDoubeldLetters(std::string str){
    std::string modifiedStr="";
    for(int i=0;i<str.length()-1;i++){
        if(str[i]!=str[i+1]){
            modifiedStr+=str[i];
        }
    }
    modifiedStr.push_back(str[str.length()-1]);
    return modifiedStr;
}
