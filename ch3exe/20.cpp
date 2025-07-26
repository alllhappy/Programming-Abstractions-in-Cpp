/*Write a function 
int findDNAMatch(string s1, string s2, int start = 0); 
that returns the first position at which the DNA strand s1 can attach to the 
strand s2.  As in the find method for the string class, the optional start 
parameter indicates the index position at which the search should start.  If 
there is no match, findDNAMatch should return –1. 
*/
#include<iostream>
#include<string>

int findDNAMatch(std::string s1, std::string s2,int start=0); 
bool isValid(char a,char b);
int main() {
    std::cout<<findDNAMatch("TAACGGTACGTC","TTGCC");
    return 0;
}
int findDNAMatch(std::string s1, std::string s2,int start){
    for(int i=start;i<s1.length();i++){
        int flag=1;
        std::string test=s1.substr(i,s2.length());
        if(test.length()==s2.length()){
            for(int j=0;j<s2.length();j++){
            if(!isValid(test[j],s2[j])) {
                flag=-1;
                break;}}
        }
        if(flag==1) return i;
    }
    return -1;
}

bool isValid(char a,char b){
    if(a=='T' && b=='A') return true;
    if(a=='A' && b=='T') return true;
    if(a=='G' && b=='C') return true;
    if(a=='C' && b=='G') return true;
    return false;
}