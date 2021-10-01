#include <iostream>

// C++ program for implementation of Lagrange's Interpolation

using namespace std;

// To represent a data point corresponding to x and y = f(x)
struct Data
{
	int x, y;
};

// function to interpolate the given data points using Lagrange's formula
// xi corresponds to the new data point whose value is to be obtained
// n represents the number of known data points
double interpolate(Data f[], int xi, int n)
{
	double result = 0; // Initialize result

	for (int i=0; i<n; i++)
	{
		// Compute individual terms of above formula
		double term = f[i].y;
		for (int j=0;j<n;j++)
		{
			if (j!=i) {

                cout << " (x - " << f[j].x << ")/(" << f[i].x << " - " << f[j].x << ")"
                     << " * " << term << endl;

				term = term*(xi - f[j].x)/double(f[i].x - f[j].x);
            }
		}

		// Add current term to result
		result += term;
	}

	return result;
}

// driver function to check the program
int main()
{
	// creating an array of 4 known data points
	Data f[] = {{6,29}, {8,29}, {12,30}, {14,31}};

// 4 6 29
// 4 8 29
// 4 12 30
// 4 14 31




	// Using the interpolate function to obtain a data point
	// corresponding to x=3
	cout << endl << "Value of f(3) is : " << interpolate(f, 10, 5) << endl;

	return 0;
}







// /**
//  * Lagrange interpolation method 
//  * 
//  * CSCE 440
//  * David Ryan
//  * 9/30/2021
//  */

// #include <iostream>
// // #include<conio.h>

// using namespace std;

// struct Pair
// {
//     int x;
//     int y;
// };

// double lagrange(int point, Pair values[], int len)
// {

//     double result = 0;

//     for (int i = 0; i < len; i++)
//     {

//         double term = values[i].y;
//         for (int j = 0; j < len; j++)
//         {
//             if (j != i && values[i].x != values[j].x)
//             {

//                 cout << " (x - " << values[j].x << ")/(" << values[i].x << " - " << values[j].x << ")"
//                      << " * " << term;

//                 term = ((point - values[j].x) / (double)(values[i].x - values[j].x)) * term;
//             }
//         }

//         if (i < len - 1)
//         {
//            // cout << "  +  " << endl;
//         }

//         result += term;
//     }

//     cout << endl;

//     return result;
// }

// int main()
// {

//     Pair firstValues[] = {{7, 30}, {9, 30}, {11, 29}, {13, 30}, {15, 31}, {17, 30}, {19, 30}, {21, 29}, {23, 30}}; // len = 9
//     Pair secondValues[] = {{4, 29}, {6, 29}, {8, 30}, {9, 31}, {11, 30}, {13, 30}, {14, 29}, {16, 28}, {20, 29}};  // len = 9
//     Pair thirdValues[] = {{8, 30}, {12, 31}, {15, 30}, {16, 29}};                                                  // len = 4
//     Pair fourthValues[] = {{8, 29}, {8, 29}, {12, 30}, {14, 31}};                                                  // len = 4

//     Pair fourthValuesEdit[] = {{8, 29}, {12, 30}, {14, 31}};

//     /**

// 1 7 30
// 1 9 30
// 1 11 29
// 1 13 30
// 1 15 31
// 1 17 30
// 1 19 30
// 1 21 29
// 1 23 30

// 2 4 29
// 2 6 29
// 2 8 30
// 2 9 31
// 2 11 30
// 2 13 30
// 2 14 29
// 2 16 28
// 2 20 29

// 3 8 30
// 3 12 31
// 3 15 30
// 3 16 29

// 4 6 29
// 4 8 29
// 4 12 30
// 4 14 31



// */

//     int solveFor = 10;

//     double result = lagrange(solveFor, fourthValues, 4);
//     cout << "f(" << solveFor << ") = " << result << endl;

//     double resultEdit = lagrange(solveFor, fourthValuesEdit, 3);
//     cout << "f(" << solveFor << ") = " << resultEdit << endl;

//     return 0;
// }
