/*Write a function createRegularPlural(word) that returns the plural of 
word formed by following these standard English rules: 
a. 
If the word ends in s, x, z, ch, or sh, add es to the word. 
b. If the word ends in a y preceded by a consonant, change the y to ies. 
c. In all other cases, add just an s. */
#include<iostream>
#include<string>

std::string createRegularPlural(std::string word);

int main() {
    std:: string pluralForm=createRegularPlural("ape");
    std::cout<<pluralForm<<std::endl;
    std::cout<<createRegularPlural("glass")<<std::endl;
    std::cout<<createRegularPlural("Blitz")<<std::endl;
    std::cout<<createRegularPlural("abolish")<<std::endl;
    std::cout<<createRegularPlural("baby")<<std::endl;
    std::cout<<createRegularPlural("toy")<<std::endl;
    return 0;
}
std::string createRegularPlural(std::string word){
    int n=word.length();
    std::string lastTwo= word.substr(n-2);
    if(word[n-1]== 's' || word[n-1]=='x' || word[n-1]=='z' || lastTwo=="sh"|| lastTwo=="ch") word+="es";
    else if(word[n-1]=='y'){
        if(!(word[n-2]=='a' || word[n-2]=='e' || word[n-2]=='i' || word[n-2]=='o' || word[n-2]=='u')){
            word.pop_back();
            word+="ies";
        }
        else{
        word.push_back('s');
        }
    }
    else{
        word.push_back('s');
    }
    return word;
}