/*to be able to design an effective algorithm and write the necessary code.  If you 
were asked to implement the sqrt function without using the library version, 
there are many strategies you could adopt.  One of the easiest strategies to 
understand is successive approximation in which you make a guess at the 
solution and then refine that guess by choosing new values that move closer to 
the solution. */

#include<iostream>


double sqrt(double x);
double sqrt(int x);
//this is overloading same name but different 
int main() {
     double x;
    while(true){
        std::cout<<"enter number :";
        std::cin>>x;
        if(x<0){
            break;
        }
        std::cout<<"sqrt is :"<<sqrt(x)<<std::endl;
        
    }
    return 0;
}

 double sqrt(double x){
    
     double start=0;
     double end=x;
    
     double g=0;
     double temp;
    while(true){
        temp=g; // stores old value of g
        g = (start+end)/2;
        if(g==temp){
            break;
        }
        else if(g*g>x){
            end=g;
        }
        else{
            start=g;
        }
    }
    return g;
}
double sqrt(int x){

}