#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include "Calculation.h"
using namespace std;

int factorial(int n)
{
    if(n > 1)
      return n * factorial(n - 1);
    else
      return 1;
}

double variance(vector<double> &arr, double mean)
{

}

double standardDeviation(double variance)
{

}

double computeMean(vector<double> &arr)
{
    int sum = accumulate(arr.begin(), arr.end(), 0.0);

    return sum / arr.size();
}

double computeMode(vector<double> &arr)
{

}

double computeRange(vector<double> &arr)
{
    auto minimum = min_element(arr.begin(), arr.end());
    auto maximum = max_element(arr.begin(), arr.end());
    return *maximum - *minimum;
}

double computeMedian(vector<double> &arr)
{

}

int computeCombination(int n, int r)
{
    return factorial(n) / (factorial(n - r) * factorial(r));
}

int computePermutation(int n, int r)
{
    return factorial(n) / factorial(n - r);
}

vector<int> solveTwoSystemOfEquation(vector<int> &arrOne, vector<int> &arrTwo)
{

}

vector<int> solveThreeSystemOfEquation(vector<int> &arrOne, vector<int> &arrTwo, vector<int> &arrThree)
{

}

vector<int> findXIntercepts(vector<int> &arrOne)
{

}

bool isValidTriangle(double a, double b, double c)
{

}


