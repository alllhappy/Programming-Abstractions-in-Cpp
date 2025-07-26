/*Write a predicate function isSentencePalindrome(str) that returns 
true if the string str fits this definition of a sentence palindrome.*/
#include<iostream>
#include<string>

bool isSentencePalindrome(std::string str);

int main() {

    std::cout<<isSentencePalindrome("Salisbury moor, sir, is roomy. Rub Silas");
    return 0;
}

bool isSentencePalindrome(std::string str){
    int n=str.length();
    int start=0;
    int end= n-1;
    while(start<end){
        if(isalpha(str[start]) && isalpha(str[end])){
            char ls=tolower(str[start]);
            char le=tolower(str[end]);
            if(le!=ls){
                return false;
            }
            else{
                start++;
                end--;
            }
        }
        else if(!isalpha(str[start])) start++;
        else if(!isalpha(str[end])) end--;
    }
    return true;
}