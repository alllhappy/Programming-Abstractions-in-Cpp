/*Without using the built-in string method substr, implement a free function 
substr(str, pos, n) that returns the substring of str beginning at position 
pos and containing at most n characters. */
#include<iostream>
#include<string>
#include"../daily/error.h" // provide the file to linker

std:: string substr(std::string str,int pos, int n);
int main() {
    // std::cout<<substr("Hello World",15,3)<<std::endl; // will give error
    std::cout<<substr("Hello World",2,3)<<std::endl;
    std::cout<<substr("Hello World",2,15)<<std::endl;
    
    return 0;
}
std:: string substr(std::string str,int pos, int n){
    int size=str.length();
    if(pos>(size-1)){
        error("Position is out of range for the string");
    }
    std:: string modifiedString="";
    int loopCond;
    if(n+pos>size){
        loopCond=size;
    }
    else{
        loopCond= n+pos ;
    }
    for(int i=pos;i<loopCond;i++){
        modifiedString+=str[i];
    }
    return modifiedString;
}

