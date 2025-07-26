/*

*/

#include<iostream>
using namespace std;

int main() {

    int x;
    int sum=0;
    cout<<"enter value : ";
    cin>>x;
    for(int i=0;i<=x;i++){ //TC -- O(x)
        sum+=i;
    }
    cout<<sum<<endl;

    int sum2= x*(x+1)/2; // TC -- O(1) because x is an integer  // checked at TC AI
    // https://www.perplexity.ai/search/using-namespace-std-int-main-i-OJgDWCgjQzqqPgxQ021cwg#0
    cout<<sum2<<endl;

    return 0;
}