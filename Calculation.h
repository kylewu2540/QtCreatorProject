#ifndef CALCULATION_H
#define CALCULATION_H

#include <vector>
using namespace std;

int factorial(int n);
double variance(vector<double> &arr, double mean);
double standardDeviation(double variance);
double computeMean(vector<double> &arr);
double computeMode(vector<double> &arr);
double computeRange(vector<double> &arr);
double computeMedian(vector<double> &arr);
int computeCombination(int n, int r);
int computePermutation(int n, int r);
vector<int> solveTwoSystemOfEquation(vector<int> &arrOne, vector<int> &arrTwo);
vector<int> solveThreeSystemOfEquation(vector<int> &arrOne, vector<int> &arrTwo, vector<int> &arrThree);
vector<int> findXIntercepts(vector<int> &arrOne);
bool isValidTriangle(double a, double b, double c);



#endif // CALCULATION_H
