
/*string integerToString(int n);
Converts an integer into the corresponding string of digits. For example, calling integerToString(123) returns the string "123".
Usage:
string s = integerToString(n);*/
#include<iostream>
#include<string>

#include<algorithm>

std::string integerToString(int n);
void intToStr(int n, std::string &st);

int main() {
    std::cout<<integerToString(78);
    return 0;
}

std::string integerToString(int n){
    std::string st="";
    intToStr(n,st);
    // this string contains in reverse order
    
    std::reverse(st.begin(),st.end());
    
    return st;
}

void intToStr(int n, std::string &st){
    if(n==0) return;
    int r= n%10;
    char num= r+48; // 48 is ascii of 1
    st.push_back(num);
    intToStr(n/10,st);

}