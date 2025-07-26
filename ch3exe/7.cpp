/*string removeCharacters(string str, string remove); 
that returns a new string consisting of the characters in str after removing all 
instances of the characters in remove. */

#include<iostream>
#include<string>
void removeCharacters(std::string &str, std::string remove);
int main() {
    std::string input="counterrevolutionaries";
    removeCharacters(input, "aeiou");
    std::cout<<input<<std::endl;
    return 0;
}

void removeCharacters(std::string &str, std::string remove){
    for(int i=0;i<str.length();i++){
        char curr=str[i];
        if(remove.find(curr)!=std::string::npos){
           //remove that character
           str.erase(i,1); //deletes character at that position
           i--;
        }
    }
}