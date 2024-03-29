// Problem 33.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

/* Problem 33

The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, find the value of the denominator.

*/

int main()
{
	for (double y = 2.0; y < 10.0; y = y + 1)  // check though all possible denominators
	{
		for (double x = 1.0; x < y; x = x + 1)  // check through all possible numerators
		{
			for (double i = 1.0; i < 10; i=i+1)  // select a digit to add on to the num/denom
			{
				if ((i * 10 + x) / (i * 10 + y) == x / y)    // add to each side of them and check if fraction is the same as original
				{
					std::cout << i * 10 + x << ", " << i * 10 + y << '\n';  // if so write them
					
				}
				if ((i * 10 + x) / (y * 10 + i) == x / y)
				{
					std::cout << i * 10 + x << ", " << y * 10 + i << '\n';
				
				}
				if ((x * 10 + i) / (i * 10 + y) == x / y)
				{
					std::cout << x * 10 + i << ", " << i * 10 + y << '\n';
					
				}
				if ((x * 10 + i) / (y * 10 + i) == x / y)
				{
					std::cout << x * 10 + i<< ", " << y* 10 + i << '\n';
					
				}
			}                     
		}
	}
	return 0;
}

