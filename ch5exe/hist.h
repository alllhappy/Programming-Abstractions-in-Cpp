#ifndef HIST_H
#define HIST_H

#include<vector>

extern int rangeMax;
extern int rangeMin;
extern int size;
void setRange(int min ,int max); //set min and max value for observations
void setSize(int size); // set size for Range of if 0-9 then range is 10
void showHistogram(std::vector<int> &freq); // displays histogram sideways
void showHistogramVertical(std::vector<int> &freq); //show histogram like traditional histogram
#endif