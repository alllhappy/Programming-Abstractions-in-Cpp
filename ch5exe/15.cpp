/*
Write a function
void roll(Stack<char> & stack, int n, int k)
that implements the roll(n, k) operation on the specified stack. Your 
implementation should check that n and k are both nonnegative and that n is 
not larger than the stack size; if either of these conditions is violated, your 
implementation should call error with the message
roll: argument out of range
Note, however, that k can be larger than n, in which case the roll operation 
continues through more than a complete cycle.
*/

#include<iostream>
#include<stack>
#include<vector>
#include<cstdlib>

void roll(std::stack<char> &st,int n, int k);
void printStack(std::stack<char> st);
int main() {
    std::stack<char> test1;
    test1.push('A');test1.push('B');test1.push('C');test1.push('D');
    // roll(test1,4,1);
    roll(test1,3,2);
    // roll(test1,2,4);
    printStack(test1);
    return 0;
}

void roll(std::stack<char> &st,int n,int k){
    if(n<0 || k<0){
        std::cerr<<""<<std::endl;
        exit(EXIT_FAILURE);
    }
    // now we will use a vector and stack is given, push top n elemnts in vector
    //then take the first element and append it to vector and remove it from front.--> repeat this k times
    //now start pushing into given stack from last index of vectosr
    std::vector<char> v;
    while(n--){
        v.push_back(st.top());
        st.pop();
    }
    //now do rolling k times
    while(k--){
        v.push_back(v[0]);;
        v.erase(v.begin());
    }
    //now just push it in given stack
    for(int i=v.size()-1;i>=0;i--){
        st.push(v[i]);
    }
}

void printStack(std::stack<char> st){
    std::cout<<"top->"<< st.top()<<std::endl;
    st.pop();
    while(!st.empty()){
        std::cout<<"     "<<st.top()<<std::endl;
        st.pop();
    }
}