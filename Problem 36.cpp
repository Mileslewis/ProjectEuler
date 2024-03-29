// Problem 36.cpp : Defines the entry point for the console application.
//
/* Problem 36
The decimal number, 585 = 1001001001 (binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)
*/

#include "stdafx.h"
#include <iostream>

bool checkPalindromic(int x)      // check if number is palindromic in base 10
{
	if (x < 10)
	{
		return true;
	}
	else if (x < 100)
	{
		if (x % 10 == x / 10)
		{
			return true;
		}
		else
			return false;
	}
	else if (x < 1000)
	{
		if (x % 10 == x / 100)
		{
			return true;
		}
		else
			return false;
	}
	else if (x < 10000)
	{
		if ((x % 10 == x / 1000)&((x / 10) % 10 == (x % 1000) / 100))
		{
			return true;
		}
		else
			return false;
	}
	else if (x < 100000)
	{
		if ((x % 10 == x / 10000)&((x / 10) % 10 == (x % 10000) / 1000))
		{
			return true;
		}
		else
			return false;
	}
	else if (x < 1000000)
	{
		if ((x % 10 == x / 100000)&((x / 10) % 10 == (x % 100000) / 10000)&((x / 100) % 10 == (x % 10000) / 1000))
		{
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

bool checkBinary(int n)    // check if number is palindromic in binary
{
	int binary[20] = { 0 };
	int t = n;
	int i = 0;
	do
	{
		binary[i++] = t % 2;
		t = t / 2;
	} while (t > 0);
	for (int m = 0; m < i; m++)
	{
		if (binary[m] != binary[(i - 1) - m])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	long int sum = 0;
	for (int n = 1; n < 1000000; n+=2)   // only use odd numbers as must not end in 0 in both bases
	{
		if (checkPalindromic(n))
		{
			if (checkBinary(n))
			{
				//std::cout << n << ", ";   // debugging
				sum += n;           // if it is palindromic in both bases add it to total sum
			}
		}
		
	}
	std::cout << sum << "    ";
    return 0;
}

