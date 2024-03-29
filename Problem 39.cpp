// Problem 39.cpp : Defines the entry point for the console application.
//
/* Problem 39
If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p ≤ 1000, is the number of solutions maximised?
*/

#include "stdafx.h"
#include <iostream>


int main()
{
	int array[1001] = { 0 };       // array to hold number of solutions for perimeter
	for (int n = 5; n < 500; n++)   // n is hypotenuse up to half total perimeter
	{
		for (int m = 1; m < n; m++)   // m is largest other side which must be less than n
		{
			for (int l = 1; l < m; l++)  // l is smallest side which must be less than m
			{
				if (n*n == m * m + l * l)  // check if pythagorian triple
				{
					if (n + m + l < 1001)  // check if perimeter <=1000
					{
						array[n + m + l]++;  // if so add one to number of solutions at that perimeter
					}
					
				}
			}
		}
	}
	int maximised = 0;
	for (int i = 0; i < 1001; i++)    // check through array for highest number of solutions
	{
		if (array[i] > array[maximised])
		{
			maximised = i;
		}
	}
	std::cout << maximised << '\n';  // print answer
    return 0;
}

