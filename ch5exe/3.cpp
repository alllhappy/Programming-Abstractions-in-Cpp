/*Another common statistical measure is the standard deviation, which provides 
an indication of how much the values in a distribution x1, x2, x3, . . . , xn differ 
from the mean.
Write a function 
double stddev(Vector<double> & data); 
that returns the standard deviation of the data distribution. */
#include<iostream>
#include<vector>
#include<cmath>

double stddev(std::vector<double> &data);
double mean(std::vector<double> &data);

int main() {
    std::vector<double> data={3.7,2.3,5,5.5};
    double dev=stddev(data);
    std::cout<<dev;
    return 0;
}

double stddev(std::vector<double> &data){
    double xbar=mean(data);
    double sum=0;
    for(int i=0;i<data.size();i++){
        double change= xbar - data[i];
        sum+=(change*change);
    }
    return sqrt(sum/data.size());
}
double mean(std::vector<double> &data){
        double sum=0;
    for(int i=0;i<data.size();i++){
        sum+=data[i];
    }
    return sum/data.size();
}