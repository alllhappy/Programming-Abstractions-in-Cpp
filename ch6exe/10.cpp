/*
Write a program that checks the spelling of all words in a file. Your program 
should use the TokenScanner class to reads tokens from an input file and 
then look up each word in the lexicon stored in the file EnglishWords.dat
introduced in Chapter 5. If the word does not appear in the lexicon, your 
program should print a message to that effect. If, for example, you run the 
program on a file containing the text of this paragraph, the SpellCheck
program would produce the following output:
*/
#include<iostream>
#include<fstream>
#include<unordered_map>
#include"tokenScanner.h"
#include"../ch4exe/input.h"


int main() {
    std::ifstream infile;
    promptUserForFile(infile);
    std::string str;
    TokenScanner sc;
    std::ifstream reference;
    reference.open("EnglishWords.txt");
    //make in map 
    std::string tmp;
    //creaating map for dictinary quick lookup
    std::unordered_map<std::string,int> mp;
    while(reference>>tmp){
        mp[tmp]=1;
    }

    while(getline(infile,str)){
        sc.setInput(str);
        // std::cout<<str<<"\n";
        while(sc.hasMoreTokens()){
            std::string curr=sc.nextToken();
            //search the word in file//searching in map now
            if(isalpha(curr[0])==false) continue;
            std::string currL;
            for(int i=0;i<curr.size();i++){
                currL.push_back(tolower(curr[i]));
            }
            if(mp.find(currL)==mp.end()){
                std::cout<<"'"<<curr<<"'"<<"is not in dictionary"<<"\n";
            }
        }
    }
    infile.close();
    reference.close();
    return 0;
}