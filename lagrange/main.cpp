/**
 * main.cpp
 * Lagrange Interpolation
 * 
 * Class: CSCE 440
 * Author: David Ryan
 * Data: 9/30/2021
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


double lagrange(xyMap values[], int len, int solveFor)
{
    double result = 0; 

    for (int i = 0; i <= len; i++)
    {
  
        double term = values[i].y;
        for (int j = 0; j <= len; j++)
        {
            if (j != i)
                term = (solveFor - values[j].x) / (double)(values[i].x - values[j].x) * term;
        }


        result += term;
    }

    return result;
}


int main()
{


    xyMap firstValues[] = {{7, 30}, {9, 30}, {11, 29}, {13, 30}, {15, 31}, {17, 30}, {19, 30}, {21, 29}, {23, 30}}; // len = 9
    
    //xyMap secondValues[] = {{4, 29}, {6, 29}, {8, 30}, {9, 31}, {11, 30}, {13, 30}, {14, 29}, {16, 28}, {20, 29}};  // len = 9
    
    //yMap thirdValues[] = {{8, 30}, {12, 31}, {15, 30}, {16, 29}};                                                  // len = 4
    
    //xyMap fourthValues[] = {{6, 29}, {8, 29}, {12, 30}, {14, 31}};                                                  // len = 4

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


    cout << "Using Lagrange method of interpolation:" << endl;
    cout << "f(" << solveFor << ") = " << lagrange(firstValues, 9, solveFor) << endl;

    return 0;
}
