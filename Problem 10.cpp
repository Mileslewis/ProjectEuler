// ProjectEuler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

/*solution for Problem 10: 
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.
*/

int main()
{
	int *p = new int[1000000]; //use new as requires a lot of memory
	int n = 0;  // n keeps track of how many primes we have (0 means 1 though as we start with 1)
	p[0] = 2; // 2 is the first prime
	for (int y = 3; y < 2000000; ++y) //for integers up to 2 million
	{
		int r = n;
		{
			for (int m = 0; m < r + 1; ++m) 
			{
				if (y%p[m] == 0) // Check if y is divisible by any of the previous primes.
				{
					break; // if so move on to the next y
				}
				else if (m == r) // if we have checked against all primes we have so far and is not divisble by any of them
				{
					p[m + 1] = y; // add it in as the next prime
					n = n + 1; // we now have 1 extra prime
				}

			}
		}
		
	}
	for (int q = n + 1; q < 1000000; q++)  // make sure the rest of the array after the primes is zeros
	{
		p[q] = 0;  
	}
	long long sum=0;
	for (int i = 0; i < 1000000; ++i)  // now add up all the primes.
	{
		//std::cout << p[i] << ", "; //debugging
		sum += p[i];
	}
	std::cout << sum;
	delete[] p;

	return 0;
}

