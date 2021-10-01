/**
 * main.cpp
 * Newtons Divided Difference Interpolation
 * 
 * Class: CSCE 440
 * Author: David Ryan
 * Data: 9/30/2021
 */

#include <iostream>

using namespace std;

struct xyMap
{
    int x;
    int y;
};

// Function to find the product term
double calcAlpha(int i, double solveFor, double x[])
{
    double pro = 1;
    for (int j = 0; j < i; j++)
    {
        pro = pro * (solveFor - x[j]);
    }
    return pro;
}

// Function for calculating
// divided difference table
void dividedDifferencesTable(double x[], double y[][10], int len)
{
    for (int i = 1; i < len; i++)
    {
        for (int j = 0; j < len - i; j++)
        {
            y[j][i] = (y[j][i - 1] - y[j + 1]
                                      [i - 1]) /
                      (x[j] - x[i + j]);
        }
    }
}

// Function for applying Newton's
// divided difference formula
double dividedDifferences(double solveFor, double x[],
                   double y[][10], int len)
{
    double sum = y[0][0];

    for (int i = 1; i < len; i++)
    {
        sum = sum + (calcAlpha(i, solveFor, x) * y[0][i]);
    }
    return sum;
}

// Driver Function
int main()
{
    // number of inputs given
    int len = 4;
    double value, sum, y[10][10];
    double x[] = {6, 8, 12, 14};

    //xyMap firstValues[] = {{7, 30}, {9, 30}, {11, 29}, {13, 30}, {15, 31}, {17, 30}, {19, 30}, {21, 29}, {23, 30}}; // len = 9

    //xyMap secondValues[] = {{4, 29}, {6, 29}, {8, 30}, {9, 31}, {11, 30}, {13, 30}, {14, 29}, {16, 28}, {20, 29}};  // len = 9

    //xyMap thirdValues[] = {{8, 30}, {12, 31}, {15, 30}, {16, 29}};                                                  // len = 4

    xyMap fourthValues[] = {{6, 29}, {8, 29}, {12, 30}, {14, 31}}; // len = 4

    /**
        Data points

        1 7 30
        1 9 30
        1 11 29
        1 13 30
        1 15 31
        1 17 30
        1 19 30
        1 21 29
        1 23 30

        2 4 29
        2 6 29
        2 8 30
        2 9 31
        2 11 30
        2 13 30
        2 14 29
        2 16 28
        2 20 29

        3 8 30
        3 12 31
        3 15 30
        3 16 29

        4 6 29
        4 8 29
        4 12 30
        4 14 31
     */


    y[0][0] = 29;
    y[1][0] = 29;
    y[2][0] = 30;
    y[3][0] = 31;

    // calculating divided difference table
    dividedDifferencesTable(x, y, len);

    // value to be interpolated
    double solveFor = 10;

    // printing the value
    cout << "\nValue at " << solveFor << " is "
         << dividedDifferences(solveFor, x, y, len) << endl;
    return 0;
}