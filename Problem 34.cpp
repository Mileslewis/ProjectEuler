// Problem 34.cpp : Defines the entry point for the console application.
//

/* Problem 34

145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: as 1! = 1 and 2! = 2 are not sums they are not included.
*/


#include "stdafx.h"
#include <iostream>

int findfact(int x)         // returns the factorial of input
{
	switch (x)
	{

	case 0:
		return 1;
	case 1:
		return 1;
	case 2:
		return 2;
	case 3:
		return 6;
	case 4:
		return 24;
	case 5:
		return 120;
	case 6:
		return 720;
	case 7:
		return 5040;
	case 8:
		return 40320;
	case 9:
		return 362880;
	default:
		return 0;
	}
}

int main()
{
	long totalsum = 0;         // holds the sum of all numbers satisfying conditions
	for (long n = 10; n < 3000000; n++)
	{
		long sum = 0;       // sum of factorials of digits of n
		long temp = n;     // creates copy of n for use
		do
		{
			sum += findfact(temp % 10);  // sum of factorial of last digit added on
			temp = temp/ 10;             // get rid of last digit
		} 
		while (temp > 0);                // until we have no more number left
		if (sum == n)                   // if sum of factorials of n = n
		{
			totalsum += sum;            // add it on
		}
		
	}
	std::cout << totalsum << "   ";     // print answer
    return 0;
}

