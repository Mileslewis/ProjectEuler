// Problem 41.cpp : Defines the entry point for the console application.
//
/* Problem 41
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?
*/

#include "stdafx.h"
#include <iostream>
#include <math.h>

int sizeOf(long x)  // finds number of digits in x
{
	if (x < 10)
	{
		return 1;
	}
	else if (x < 100)
	{
		return 2;
	}
	else if (x < 1000)
	{
		return 3;
	}
	else if (x < 10000)
	{
		return 4;
	}
	else if (x < 100000)
	{
		return 5;
	}
	else if (x < 1000000)
	{
		return 6;
	}
	else if (x < 10000000)
	{
		return 7;
	}
	else
		return 0;
}

bool checkPan(long x)    // check if number is pandigital
{
	int n = sizeOf(x);
	bool DigitsUsed[10] = { 0 };    // up to maximum digits of 10
	do
	{
		if (DigitsUsed[x % 10]||(x%10==0)||x%10>n)   // Check if last digit has been used before, =0 or is larger than number of digits.
		{
			return false;
		}
		else
		{
			DigitsUsed[x % 10] = 1;                  // if not add it to digits used
			x /= 10;                                 // then chop off last digit
		}
	}
	while (x > 0);                                    // until whole number has been used
	return true;                                     // if so must be pandigital
}

bool checkPrime(long y)                             // checks if number is prime
{ 
	long double m = sqrt(y);                        // only need to check numbers up to sqrt y
	for (int p = 2; p <= m; p++)
	{
		if (y%p == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{

	
	for (long p = 7654321; p>10; p-=2)             // nine digits total sum would be 45 and 8 digits would be 36 so all numbers would divide by 9
	{                                              // therefore 7654321 is maximum possible
		if (checkPan(p))                           // check if pandigital
		{
			if (checkPrime(p))                     // check if prime
			{
				std::cout << p << '\n';            // if both print it
				return 0;                          // and end the program
			}
		}
	}
	
    return 0;
}

