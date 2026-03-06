#include<iostream>
#include"fsm.h"


fsm::fsm(){

}
fsm::fsm(int n){
    initState=0;
    currState=0;
    totalStates=n;
    finalState=std::vector<bool> (n,false);
    adj=std::vector<std::vector<std::pair<int,char>>> (n);
}

void fsm::setInitState(int i){
    initState=i;

}
void fsm::makeFinalState(int i){
    if(i>=0 && i<totalStates) finalState[i]=true;
}
void fsm::insertTransition(int from,int to,char ch){
    if(from>=0 && from<totalStates && to>=0 && to<totalStates) adj[from].push_back({to,ch});
}

bool fsm::validState(){
    if(finalState[currState]) return true;
    return false;
}
void fsm::setState(char ch){
    for(int i=0;i<adj[currState].size();i++){
        std::pair<int,char> nextState=adj[currState][i];
        if(nextState.second==ch){
            currState=nextState.first;
            return;
        }
    }
    currState=-1; //error code for this ch the state does not exist
    return;
}