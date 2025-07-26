/*implement a function 
string addCommas(string digits); 
that takes a string of decimal digits representing a number and returns the 
string formed by inserting commas at every third position, starting on the 
right.  */
#include<iostream>
#include<string>

std::string addCommasIND(std::string digits);
std::string addCommasUSA(std::string digits);
void reverse(std::string &str);
int main() {
    std::cout<<"USA system"<<std::endl;
    std::cout<<addCommasUSA("1000000")<<std::endl;
    std::cout<<addCommasUSA("10")<<std::endl;
    std::cout<<addCommasUSA("100")<<std::endl;
    std::cout<<addCommasUSA("1000")<<std::endl;
    std::cout<<addCommasUSA("1001111000000000")<<std::endl;

    std::cout<<"IND system"<<std::endl;
    std::cout<<addCommasIND("1000000")<<std::endl;
    std::cout<<addCommasIND("10")<<std::endl;
    std::cout<<addCommasIND("100")<<std::endl;
    std::cout<<addCommasIND("1000")<<std::endl;
    std::cout<<addCommasIND("1001111000000000")<<std::endl;

    return 0;
}

// for indian system
std::string addCommasIND(std::string digits){
    std::string modifiedStr="";
    int n=digits.length();
    int cnt=0;
    for(int i=n-1;i>=0;i--){
        modifiedStr+=digits[i];
        if(modifiedStr.size()%3==0 && i!=0){
            modifiedStr+=',';
        }
    }
    // reverse the modified stirng
    reverse(modifiedStr);
    return modifiedStr;
}
std::string addCommasUSA(std::string digits){
    std::string modifiedStr="";
    int n=digits.length();
    int cnt=0;
    for(int i=n-1;i>=0;i--){
        modifiedStr+=digits[i];
        cnt++;
        if(cnt%3==0 && i!=0){
            modifiedStr+=',';
        }
        
    }
    // reverse the modified stirng
    reverse(modifiedStr);
    return modifiedStr;
}
void reverse(std::string &str){
    int n=str.size();
    int start=0;
    int end =n-1;
    while(start<end){
        std::swap(str[start],str[end]);
        start++;
        end--;
    }
}