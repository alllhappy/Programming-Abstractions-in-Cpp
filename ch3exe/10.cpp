/*Write a function 
string replaceAll(string str, char c1, char c2); 
that returns a copy of str with every occurrence of c1 replaced by c2.  For 
example, calling 
Once you have coded and tested this function, write an overloaded version 
string replaceAll(string str, string s1, string s2); 
that replaces all instances of the string s1 with the replacement string s2.
*/

#include<iostream>
#include<string>

std::string replaceAll(std::string str, char c1, char c2);
std::string replaceAll(std::string str, std::string s1, std::string s2);
int main() {
    std::cout<<replaceAll("nannies",'n','d')<<std::endl;
    std::cout<<replaceAll("nannies","na","xz")<<std::endl;
    return 0;
}

std::string replaceAll(std::string str, char c1, char c2){
    std::string modifiedStr="";
    for(int i=0;i<str.length();i++){
        if(str[i]==c1){
            modifiedStr+=c2;
        }
        else{
            modifiedStr+=str[i];
        }
    }
    return modifiedStr;
}

std::string replaceAll(std::string str, std::string s1, std::string s2){
    
    int n=s1.length();
    for(int i=0;i<str.length();i++){
        if(str.substr(i,n)==s1){
            str.replace(i,n,s2);
        }
    }
    return str;
}

