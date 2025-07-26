/*To implement a Caesar cipher, you should first define a function 
string encodeCaesarCipher(string str, int shift); 
that returns a new string formed by shifting every letter in str forward the 
number of letters indicated by shift, cycling back to the beginning of the ote that the transformation applies only to letters; any other characters are 
copied unchanged to the output.  Moreover, the case of letters is unaffected: 
lowercase letters come out as lowercase, and uppercase letters come out as 
uppercase.  You should also write your program so that a negative value of 
shift means that letters are shifted toward the beginning of the alphabet */

#include<iostream>
#include<string>

std::string encodeCaesarCipher(std::string str, int shift);
char encodeSingleChar(char original, int shift);
int main() {
    std::cout<<encodeCaesarCipher("This is a secret message",13)<<std::endl;
    std::cout<<encodeCaesarCipher("IBM 9000",-1)<<std::endl;
    std::cout<<encodeCaesarCipher("Karan Sharma 28/05/2005",-200)<<std::endl;


}   

/*encodes the entire line by encoding sinlge char alphaberts*/
std::string encodeCaesarCipher(std::string str, int shift){
    std::string encodedSentence="";
    for(int i=0;i<str.size();i++){
        if(isalpha(str[i])){
            if(islower(str[i])){
                encodedSentence+=tolower(encodeSingleChar(str[i],shift));
            }
            else{
                // is upper
                encodedSentence+=encodeSingleChar(str[i],shift);
            }
        }
        else{
            encodedSentence+=str[i];
        }
    }
    return encodedSentence;
}

// returns alphabetical character after encoding in uppercase only
/*for negative shift it converts negative into positve equivalent then call the same funciton to solve poistive case*/
char encodeSingleChar(char original, int shift){
    const int Zascii=90;
    const int Aascii=65;
    char encoded;
    if(shift>0){
        shift=shift%26;
        int shifted= int(toupper(original))+shift;  // original + (0 ... 25) only
        // std::cout<<"shifted"<<shifted<<std::endl;
        if(shifted>Zascii){
            int NumberofLettersTillZ= Zascii - int(toupper(original));
            shift-=NumberofLettersTillZ;
            encoded=Aascii+shift-1;
        }
        else{
            encoded= char(shifted);
        }
    }
    else{
        // shift is negative
        // convert into postive
        int modShift= abs(shift)%26;
        int positiveShift= 26- modShift;
        encoded=encodeSingleChar(original,positiveShift);
    }
    return encoded;
}
