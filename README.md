# csce440-hw1-interpolation-functions
CSCE 440 Homework 1


Numerical Analysis
CSCE 440/840 Homework 1 Fall 2021
1. (undergraduates: 10 points, graduates: 0 points (skip this)) Determine the
number of iterations required to solve f(x) = x
3 − 17x
2 + 6x + 5.5 = 0 with the
accuracy |p − pn| < 10−25 using a1 = 0 and b1 = 16 of the bisection method.
Air Pressure
SN T AP
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
Air pressure is the weight of the atmosphere pressing down on the earth. It is instrumental
in weather observations, since its fluctuation indicates the movement of weather fronts and
systems. Liquid mercury (Hg) is commonly used in a barometer to measure air-pressure
changes in inches (in.). A barometer reading of 30 inches (Hg) is considered normal. Strong
high pressure could register as high as 30.70 inches, whereas low pressure associated with a
hurricane can dip below 27.30 inches. As a very general rule, approaching weather systems
1
- such as cold and warm fronts, tropical waves and rain - are usually associated with low
atmospheric pressure. Consider the following data from a set of four weather stations ,
where SN is the station identification number, T is time in days and AP is the air pressure
per day in inches. For Questions 2-4, show all the calculation steps including
tables where needed.
2. (10 points) (1) Find the Lagrange interpolating polynomial for the 4th station. (2)
Use the Lagrange interpolating polynomial to estimate the AP of the 4th weather
station at T = 10.
3. (10 points) Use Neville’s Method to estimate the AP of the 4th weather station at
T = 10.
4. (10 points) Use Newton’s Divided Differences Method (1) to find the interpolating
polynomial for the 4th weather station. (2) Use the Newton interpolating polynomial
to estimate the AP of the 4th weather station at T = 10.
For Questions 5-7, write MATLAB scripts or a program in some high level
language. Do not use any packages with interpolation functions. Please give
detailed comments in your code.
5. (20 points) Write a program to (1) find the Lagrange interpolating polynomials
for each of the weather stations. (2) Use the Lagrange interpolating polynomials to
estimate the AP for each of the weather stations at T = 10.
6. (20 points) Write a program that (1) implements Neville’s Method and (2) estimate
the AP for each of the weather stations at T = 10.
7. (20 points) Write a program that (1) implements Newton’s Divided Differences
Method and (2) estimate the AP for each of the stations at T = 10.
Bonus Question
8. (undergraduates: 5 bonus points, graduates: 10 points (required)) Prove
Newton’s Method for root finding does not converge for function f(x) = x
3 − 5x and
p0 = 1.
2
