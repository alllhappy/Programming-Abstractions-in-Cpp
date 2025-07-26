/*easter date algortihm by gauss*/
#include<iostream>
#include<string>

void findEaster(int year, std::string & month, int & day);

int main() {
    std::string month;
    int day=0;
    int year;
    std::cout<<"enter year : ";
    std::cin>>year;
    findEaster(year,month,day);
    std::cout<<"Date of easter is "<< day<<" " << month ;
    return 0;
}

void findEaster(int year, std::string & month, int & day){
    int a= year%19;
    int b=year%4;
    int c=year%7;
    int d= (19*a+23)%30;
    int temp;
    if(year>=1700 && year<=1799){
        temp=2*b+ 4*c+6*d+3;
    }
    else if(year>=1800 && year<=1899){
        temp=2*b+ 4*c+6*d+4;
    }
    else{
        std::cout<<"the year is not b/w 1700 to 1899";
        return;
    }
    int e=temp%7;
    if(d+e>9){
        month = "April";
        day= d+e-9;
    }
    else{
        month="March";
        day=22+d+e;
    }

}
