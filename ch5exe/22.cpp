/*
Section 3.6 defines the function isPalindrome that checks whether a word 
reads identically forward and backward. Use that function together with the 
English lexicon to print out a list of all words that are palindromes.
*/

#include<iostream>
#include<string>
#include<set>
#include<fstream>


bool isPalindrome(std::string word);
int main() {
    std::ifstream infile;
    infile.open("EnglishWords.txt");
    std::set<std::string> words;
    std::string currWord;
    while(getline(infile,currWord)){
        words.insert(currWord);
    }
    infile.close();
    //now check all palindrome or not in all words
    for(auto it=words.begin();it!=words.end();it++){
        if(isPalindrome(*it)){
            std::cout<<*it<<std::endl;
        }
    }
    return 0;
}
bool isPalindrome(std::string word){
    int s=0;
    int e=word.size()-1;
    while(s<e){
        if(word[s]!=word[e])return false;
        s++;
        e--;
    }
    return true;
}