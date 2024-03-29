// Problem 30.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <iostream>

/* Problem 30

Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

1634 = 14 + 64 + 34 + 44
8208 = 84 + 24 + 04 + 84
9474 = 94 + 44 + 74 + 44
As 1 = 14 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.

*/

int power5(int x)  //function for finding 5th power of integer
{
	return x * x*x*x*x;
}

int main()
{
	int totalsum = 0;
	for (int i = 2; i < 354295; i++)   // 354294=9^5*6 which is maximum sum of 5th powers of 6 digit number could reach (7*9^9<1000000)
	{
		int sum = 0;
		sum += power5(i / 100000);    // add up 5th power of each digit
		int j = i % 100000;
		sum += power5(j / 10000);
		j = j % 10000;
		sum += power5(j/ 1000);
		j = j % 1000;
		sum += power5(j / 100);
		j = j % 100;
		sum += power5(j / 10);
		j = j % 10;
		sum += power5(j);
		if (sum == i)              // check if sum is same as starting number
		{
			//std::cout << i<<", ";  // debugging
			totalsum += sum;  // get sum of numbers which met ctiteria.
		}
	}
	std::cout << totalsum << " ";
    return 0;
}

