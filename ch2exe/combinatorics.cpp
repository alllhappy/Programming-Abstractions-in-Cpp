#include<iostream>
#include"combinatorics.h"


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
int combinations(int n,int k){
    int permutation= permutations(n,k);
    for(int i=k; i>1;i--){
        permutation/=i;
    }
    return permutation;
}