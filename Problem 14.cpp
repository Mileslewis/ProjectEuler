// Problem14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
/* Solution to problem 14:
The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/

int main()
{
	int m = 0;
	int r = 0;
	for (int x = 1; x < 1000000; ++x) //go through all numbers up to 1 million
	{
		int n = 1;   // n is length of chain for x
		long long y = x; // need long long as y may far exceed 1 million
		do
		{
			++n;
			if (y % 2 == 0)      
			{
				y = y/2;
				//std::cout << y<<"\n";  //debugging 
			}
			else
			{
				y = (3*y + 1);
				//std::cout << y<<"\n"; //debugging
			}

		} 
		while (y > 1);
		if (n >= m)
		{
			m = n;   // store max langth of chain
			r = x;   // store which number it belonged to
		}
		
	}
	std::cout << r<<"\n";  
	//std::cout << m<<"\n"; //debugging
    return 0;
}

