﻿// Problem 21.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

/* Problem 21
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.

*/

int sumdiv(int x)    //finds sum of all divisors of x
{
	int sum = 0;
	for (int j = 1; j < x; j++)
	{
		if (x%j == 0)
			sum += j;
	}
	return sum;
}

int main()
{
	int d[10000];
	d[0] = 0;
	d[1] = 0;
	for (int i = 2; i < 10000; i++)
	{
		d[i] = sumdiv(i);    //record sum of divisors of numbers in an array at corresponding index
	}
	int ans = 0;
	for (int k = 2; k < 10000; k++)   // for each integer
	{
		int t = d[k];    
		if (t < 10000)
		{
			if ((k == d[t])&(t!=k))   //check for an amicable pair but make sure it isn't the same number twice
			{
				ans += k;    //add it to the total
				//std::cout << k << "\n"; //used for debugging
			}
		}
		
		//std::cout << d[k] << ", ";  //used for debugging
	}
	std::cout << ans<<"\n";
    return 0;
}

