#ifndef random_h
#define random_h
using namespace std;

int randomInteger(int low, int high);
double randomReal(double low, double high);
bool randomChance(double p);
void setRandomSeed(int seed);

#endif