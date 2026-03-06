#include<iostream>
#include<cstdlib>
#include<string>
#include"error.h"
using namespace std;

void error(string msg){
    cerr<<msg<<endl;
    exit(EXIT_FAILURE);
    // difference b/w exit and return  https://copilot.microsoft.com/shares/dbqUur9erpSCppBgPWDqc
}
