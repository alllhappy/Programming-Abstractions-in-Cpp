/*Using the definition of keys for letter-substitution ciphers as described in the 
preceding problem, write a function invertKey that takes an encryption key 
and returns the 26-letter key necessary to decrypt a message encoded with that 
encryption key.*/
#include<iostream>
#include<string>

std::string invertKey(std::string key);
int main() {
    std::cout<<invertKey("QWERTYUIOPASDFGHJKLZXCVBNM");
    return 0;
}

std::string invertKey(std::string key){
    std:: string inversekey=std::string(26,'#');
    for(int i=0;i<26;i++){
        int index=key[i]-'A';
        inversekey[index]= 'A'+ i;
    }
    
    return inversekey;
}