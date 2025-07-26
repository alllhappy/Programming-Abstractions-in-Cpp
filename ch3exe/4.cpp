/*Implement a function capitalize(str) that returns a string in which the 
initial character is capitalized (if it is a letter) and all other letters are converted 
to lowercase.  Characters other than letters are not affected.  For example, both 
capitalize(BOOLEAN) and capitalize(boolean) should return 
the string Boolean*/

#include<iostream>
#include<string>
#include<cctype>

std::string capitalize(std::string str);
int main() {
    std::cout<<capitalize("BPPP")<<std::endl;
    std::cout<<capitalize("1ffflsSD")<<std::endl;
    std::cout<<capitalize("BLddkf")<<std::endl;
    return 0;
}

std::string capitalize(std::string str){
    std::string modified="";
    modified+=toupper(str[0]); // toupper() returns same character if not a alphabetic letter
    for(int i=1;i<str.length();i++){
        modified+=tolower(str[i]);
    }
    return modified;
}