#ifndef _FSM_
#define _FSM_
#include<vector>

class fsm{
    private:
    int initState;
    int totalStates;
    std::vector<bool> finalState;
    std::vector<std::vector<std::pair<int,char>>> adj;
    
    public:
    int currState;
    fsm();
    fsm(int n);
    void setInitState(int node);
    void insertTransition(int from,int to,char ch);
    void makeFinalState(int i);
    bool validState();
    void setState(char ch);


};
#endif