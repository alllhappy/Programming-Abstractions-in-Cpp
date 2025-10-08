/*, write a function
void reverseQueue(Queue<string> & queue);
that reverses the elements in the queue. Remember that you have no access to 
the internal representation of the queue and must therefore come up with an 
algorithm—presumably involving other structures—that accomplishes the 
task*/

#include<iostream>
#include<stack>
#include<queue>
#include<string>

void reverseQueue(std::queue<std::string> &queue);
void printQ(std::queue<std::string> q);
int main() {
    std::queue<std::string> q;
    q.push("hi");
    q.push("I");
    q.push("am");
    q.push("good");

    reverseQueue(q);
    printQ(q);
    return 0;
}

void reverseQueue(std::queue<std::string> &q){
    //will push all the elements in stack then again push all the elements from stack into queu
    std::stack<std::string> st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
}
void printQ(std::queue<std::string> q){
    while(!q.empty()){
        std::cout<<q.front()<<std::endl;
        q.pop();
    }
}