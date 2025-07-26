/* Complete the implementation of the simpio.h interface by implementing the 
functions getReal and getLine. 
*/
#include<iostream>
#include<sstream>
#include<string>
std::string getLine(std::string prompt="");
double getReal(std::string prompt="");
std::string trimWhite(std::string str);

int main() {
    std::string line=getLine("enter line:");
    std::cout<<line<<std::endl;

    double x=getReal("enter double");
    std::cout<<x+10.00;
    return 0;
}

std::string getLine(std::string prompt){
    char ch;
    std::string line="";
    std::cout<<prompt<<" ";
    while(true){
        ch=std::cin.get();
        if(ch=='\n') break;
        line.push_back(ch);
    }
    return line;
}

// imp trick to validate inputs
double getReal(std::string prompt){
    while(true){
        std::cout<<prompt<<": ";
        std::string str;
        getline(std::cin,str);
        std::cout<<str<<std::endl;
        if(str.size()==0){
            std::cout<<"no input , try again"<<std::endl;
            continue;
        }
        // Trim whitespace from both ends
        std::string trimmed=trimWhite(str);
        // https://copilot.microsoft.com/shares/VoNG76UdjLKygVbovTR4j
        std::istringstream stream(trimmed);
        double value;
        char extra;
        if (stream >> value && !(stream >> extra)) {
            return value;
        } else {
            std::cout << "Illegal floating-point number. Try again.\n";
        }

    }
}

std::string trimWhite(std::string str){
    std::string ans;
    for(int i=0;i<str.size();i++){
        if(str[i]!=' ') ans.push_back(str[i]);
    }
    return ans;
}
