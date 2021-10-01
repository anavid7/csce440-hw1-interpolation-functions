/**
 * main.cpp
 * Naville's Interpolation
 * 
 * Class: CSCE 440
 * Author: David Ryan
 * Data: 9/30/2021
 */

#include <iostream>

using namespace std;

struct xyMap
{
    double x;
    double y;
};

double navilles(xyMap values[], int len, int solveFor)
{

    double result = 0;

    for (int j = 1; j < len; j++)
    {
        for (int i = len - 1; i >= j; i--)
        {
            values[i].y = ((solveFor - values[i - j].x) * values[i].y - (solveFor - values[i].x) * values[i - 1].y) / (values[i].x - values[i - j].x);
        }
    }

    result = values[len - 1].y;

    return result;
}

int main()
{

    //xyMap firstValues[] = {{7, 30}, {9, 30}, {11, 29}, {13, 30}, {15, 31}, {17, 30}, {19, 30}, {21, 29}, {23, 30}}; // len = 9

    //xyMap secondValues[] = {{4, 29}, {6, 29}, {8, 30}, {9, 31}, {11, 30}, {13, 30}, {14, 29}, {16, 28}, {20, 29}};  // len = 9

    //xyMap thirdValues[] = {{8, 30}, {12, 31}, {15, 30}, {16, 29}};                                                  // len = 4

    xyMap fourthValues[] = {{6, 29}, {8, 29}, {12, 30}, {14, 31}};                                                    // len = 4

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

    int solveFor = 10;

    cout << "Using Naville's method of interpolation:" << endl;
    cout << "f(" << solveFor << ") = " << navilles(fourthValues, 9, solveFor) << endl;

    return 0;
}
