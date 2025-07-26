/*Write a function obenglobish that takes an English word and returns its 
Obenglobish equivalent, using the translation rule given above.*/

// error in case of gooiest
#include<iostream>
#include<string>

std::string obenglobish(std::string word);
bool isVowel(char a);

int main() {
     while (true) { 
      std::string word;
      std::cout<<"enter word ";
      std::getline(std::cin,word); 
      if (word == "") break; 
      std::string trans = obenglobish(word); 
      std::cout << word << " -> " << trans << std::endl; 
   } 
   return 0;
    return 0;
}
// add ob beore vowel + 2 additional rules . ob should be added before every vowel in the 
/*English word except 
• Vowels that follow other vowels 
• An e that occurs at the end of the word */
std::string obenglobish(std::string word){
    std::string modified="";
    for(int i=0;i<word.size();i++){
        if(isVowel(word[i])){
            if(i==word.size()-1 && word[i]=='e'){
                modified+=word[i]; // just add it
                continue;
            }
            else if(i!=word.size()-1 && isVowel(word[i+1]) ){
                if(word[i]==word[i+1]){
                    // then add ob and string
                    modified+="ob";
                    modified+=word[i];
                    continue;
                }

                modified+=word[i];
                continue;
            }
            modified+="ob";
        }
        modified+=word[i];
    }
    return modified;
}

bool isVowel(char a){
    if(a=='a' || a=='e'||a=='i'|| a=='o' || a=='u') return true;
    return false;
}