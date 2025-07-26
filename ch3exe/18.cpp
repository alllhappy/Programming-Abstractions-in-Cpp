/*Write a program that implements encryption using a letter-substitution 
cipher.  */ 
// Key should be 26 letter string in UPPERCASE;
#include<iostream>
#include<string>

std::string encodedSentence(std::string mssg , std::string key);
char encodedChar(char orginal,std::string key); 
int main() {
    std::cout<<encodedSentence("Workers of The World Unite!","QWERTYUIOPASDFGHJKLZXCVBNM")<<std::endl;
    std::cout<<encodedSentence("Vgkatkl gy Zit Vgksr Xfozt!","KXVMCNOPHQRSZYIJADLEGWBUFT"); // testing generated inveretd key
    return 0;
}

std::string encodedSentence(std::string mssg, std::string key){
    if(key.length()<26){
        return "KEY INVALID";
    }
    
    std::string modified="";
    for(int i=0;i<mssg.length();i++){
        if(isalpha(mssg[i])){
            // encode it and
            modified+=encodedChar(mssg[i],key);
        }
        else{
            modified+=mssg[i];
        }
    }
    return modified;
}

// convertes both uppercase and lowercase in corresponding
char encodedChar(char original, std::string key){
    const int Aascii=65;
    const int aascii=97;
    int baseAscii= (original==toupper(original)) ? Aascii : aascii;
    int index= original - baseAscii; // b/w o to 25
    if(baseAscii==97){
        return tolower(key[index]);
    }
    return key[index];
}