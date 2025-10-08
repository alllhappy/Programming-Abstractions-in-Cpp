/*In statistics, a collection of data values is often referred to as a distribution.  
One of the primary goals of statistical analysis is to find ways to compress the 
complete set of data into summary statistics that express properties of the 
distribution as a whole.  The most common statistical measure is the mean, 
which is simply the traditional average.  For the distribution x1, x2, x3, . . . , xn, 
the mean is usually represented by the symbol .  Write a function 
double mean(Vector<double> & data); 
that returns the mean of the data in the vector.*/

#include<iostream>
#include<vector>

double mean(std::vector<double> &data);
int main() {
    std::vector<double> data={3.7,2.3,5,5.5};
    double avg=mean(data);
    std::cout<<avg;
    return 0;
}

double mean(std::vector<double> &data){
    double sum=0;
    for(int i=0;i<data.size();i++){
        sum+=data[i];
    }
    return sum/data.size();
}