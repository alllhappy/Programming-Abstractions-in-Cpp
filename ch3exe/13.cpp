/*Devise a rule that 
determines what suffix should be added to each number, and then use this rule 
to write a function createOrdinalForm(n) that returns the ordinal form of 
the number n as a string.*/
#include<iostream>
#include<string>

std::string createOrdinalForm(int n);
int main() {
    std::cout<<createOrdinalForm(1)<<std::endl;
    std::cout<<createOrdinalForm(2)<<std::endl;
    std::cout<<createOrdinalForm(3)<<std::endl;
    std::cout<<createOrdinalForm(4)<<std::endl;
    std::cout<<createOrdinalForm(100)<<std::endl;
    std::cout<<createOrdinalForm(17)<<std::endl;
    return 0;
}

std::string createOrdinalForm(int n){

   std::string numString= std::to_string(n);
   if(n==1){
    return numString+="st";
   }
   else if(n==2){
    return numString+="nd";
   }
   else if(n==3){
    return numString+="rd";
   }
   else{
    numString+="th";
   }
   return numString;
}
