#include<iostream>

int permutations(int n , int k);
int main() {
    std:: cout<<permutations(52,2);
    return 0;
}
int permutations(int n,int k){
    if(n<=k || n<=0 || k<=0){
        return -1;
    }

    int ans=1;
    int diff= n-k;
    for(int i=n;i>diff;i--){
        ans*=i;
    }
    return ans;

}