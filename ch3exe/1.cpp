/*Implement the function endsWith(str, suffix), which returns true if 
str ends with suffix.  Like its startsWith counterpart, the endsWith 
function should allow the second argument to be either a string or a character. 
*/
#include<iostream>
#include<string>

bool endsWith(std::string str, std::string suffix);
bool endsWith(std::string str,char suffix);

int main() {
    bool ans=endsWith("tokyo",'o');
    std::cout<<ans;
    return 0;
}

bool endsWith(std::string str, std::string suffix){
    int n=str.length();
    int cnt=1;
    for(int i=suffix.length()-1;i>=0;i--){
        if(str[n-cnt]!=suffix[i]) return false;
        cnt++;
    }
    return true;
}
bool endsWith(std::string str, char suffix){
    std::string suffixStr="";
    suffixStr+=suffix;
    bool ans=endsWith(str,suffixStr);
    return ans;
}
