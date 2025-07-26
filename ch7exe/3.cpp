/*Write a recursive function getTitiusBodeDistance(k) that calculates 
the expected distance between the sun and the kth planet, numbering outward 
from Mercury starting with 1.  Test your function by writing a program that 
displays the distances to each of these planets in tabular form. */
#include<iostream>
double getTitiusBodeDistance(int k);
int helperRecursive(int i);
void printRecursively(int i,int k);
int main() {
    printRecursively(1,8);
    
    return 0;
}
double getTitiusBodeDistance(int k){
    int bk= helperRecursive(k);
    double dk= (4+bk)/double(10);
    return dk;
}

int helperRecursive(int i){
    if(i==1) return 1;
    
    if(i==2) return 3;

    return 2*helperRecursive(i-1);

}

// i should be greater than 1
void printRecursively(int i,int k){
    if(i>k) return;
    std::cout<<getTitiusBodeDistance(i)<<" AU"<<std::endl;
    printRecursively(i+1,k);
}