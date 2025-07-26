/*function acronym that takes a string and returns the acronym formed from 
that string.  To ensure that your function treats hyphenated compounds like 
self-contained as two words, it should define the beginning of a word as any 
alphabetic character that appears either at the beginning of the string or after a 
nonalphabetic character.*/
#include<iostream>
#include<string>

/*creates short form*/
std::string acronym(std::string fullForm);
int main() {
    std::cout<<acronym("Acquired Immune Deficiency Syndrome")<<std::endl;
    std::cout<<acronym("self-contained underwater breathing apparatus")<<std::endl;

    
    return 0;
}
std::string acronym(std::string fullForm){
    std::string shortForm="";
    shortForm+=fullForm[0];
    for(int i=1;i<fullForm.length();i++){
        char curr=fullForm[i];
        char prev=fullForm[i-1];
        if(isalpha(curr)&& (!isalpha(prev))){
            shortForm+=curr;
        }
    }
    return shortForm;
}