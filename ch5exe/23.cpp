/*In Scrabble, knowing the two-letter word list is important because those short 
words make it easy to “hook” a new word into tiles already on the board. 
Another list that Scrabble experts memorize is the list of three-letter words 
that can be formed by adding a letter to the front or back of a two-letter word. 
Write a program that generates this list.*/

#include<iostream>
#include<string>
#include<set>
#include<fstream>

void findWords(std::set<std::string> &words2,std::set<std::string> &words3);
void showSet(std::set<std::string> &words);
int main() {
    std::set<std::string> words2;
    std::set<std::string> words3;
    findWords(words2,words3);
    std::cout<<"2words list are"<<std::endl;
    showSet(words2);
    std::cout<<std::endl;
    std::cout<<"3 letter words are"<<std::endl;
    showSet(words3);
    return 0;
}

void findWords(std::set<std::string> &words2,std::set<std::string> &words3){
    std::ifstream infile;
    infile.open("EnglishWords.txt");
    std::string word="";
    while(getline(infile,word)){
        if(word.size()==2) words2.insert(word);
        if(word.size()==3) words3.insert(word);
    }
    infile.close();
}
void showSet(std::set<std::string> &words){
    for(auto it=words.begin();it!=words.end();it++){
        std::cout<< *it<<std::endl;
    }
}