/**
 * main.cpp
 * Newtons Divided Difference Interpolation
 * 
 * Class: CSCE 440
 * Author: David Ryan
 * Data: 9/31/2021
 * 
 * compiled with: g++ -std=c++11 -Wall main.cpp -o ???Values.out
 */

#include <iostream>

using namespace std;

struct xyMap
{
    int x;
    int y;
};

// generates the terms needed based on the particular step of the sum
double calcTermStep(int i, double solveFor, double x[])
{
    double term = 1;
    for (int j = 0; j < i; j++)
    {
        // each step gets progressively more terms
        term = term * (solveFor - x[j]);
    }
    return term;
}


void generateTable(double x[], int len, double y[][9])
{
    for (int i = 1; i < len; i++)
    {
        for (int j = 0; j < len - i; j++)
        {
            // inserting values based on divided difference formula
            // the only row that matters is y[0][1,2,3,4,5,6...]
            // but the rest of the rows must be calculated to determin the top row
            y[j][i] = (y[j][i - 1] - y[j + 1]
                                      [i - 1]) /
                      (x[j] - x[i + j]);
        }
    }
}

double dividedDifferences(double solveFor, int len, double x[],
                          double y[][9])
{
    double sum = y[0][0];

    for (int i = 1; i < len; i++)
    {
        // summing individual terms
        sum = sum + (calcTermStep(i, solveFor, x) * y[0][i]);
    }
    return sum;
}

// Driver Function
int main()
{
    // number of inputs given

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

    // insert y values into 2d array
    int len = 4;

    double y[9][9];

    for (int i = 0; i < len; i++)
    {
        y[i][0] = fourthValues[i].y;
    }

    double x[len];

    // insert x values into refernce array
    for (int i = 0; i < len; i++)
    {
        x[i] = fourthValues[i].x;
    }

    // generating divided difference table
    generateTable(x, len, y);

    // value to be interpolated
    double solveFor = 10;

    cout << "Using Newton's Divided Differences method of interpolation:" << endl;
    cout << "f(" << solveFor << ") = " << dividedDifferences(solveFor, len, x, y) << endl;

    return 0;
}