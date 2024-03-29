// Problem 32.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

/* Problem 32
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
*/

bool checkpan(int i, int j, int k, int l, int m, int r, int s, int t, int u)   // check if digits are all digits 1-9.
{
	if (i == j || i == k || i == l || i == m || i == r || i == s || i == t || i == u||i==0)
	{
		return false;
	}
	else if (j == k || j == l || j == m || j == r || j == s || j == t || j == u || j == 0)
	{
		return false;
	}
	else if (k == l || k == m || k == r || k == s || k == t || k == u || k == 0)
	{
		return false;
	}
	else if (l == m || l == r || l == s || l == t || l == u || l == 0)
	{
		return false;
	}
	else if (m == r || m == s || m == t || m == u || m == 0)
	{
		return false;
	}
	else if (r == s || r == t || r == u || r == 0)
	{
		return false;
	}
	else if (s == t || s == u || s == 0)
	{
		return false;
	}
	else if (t == u || t == 0)
	{
		return false;
	}
	else if (u==0)
	{
		return false;
	}
	else return true;
}


int main()
{
	int sum = 0;
	for (int i = 1; i < 10; i++)        // cycle through all possible digits for multiplier and multiplicand
	{
		for (int j = 1; j < 10; j++)
		{
			for (int k = 1; k < 10; k++)
			{
				for (int l = 1; l < 10; l++)
				{
					for (int m = 1; m < 10; m++)
					{
							int n = i * ((1000 * j)+(100 * k)+(10 * l)+m);    // find product
								if (n < 10000)                                // if over 10000 will be 10 digits total
								{
									int r = n / 1000;                        // separate the digits of product
									int s = (n % 1000) / 100;
									int t = (n % 100) / 10;
									int u = (n % 10);
									if (checkpan(i,j,k,l,m,r,s,t,u))         // check if pandigital
									{
										//std::cout << i << ",    "<<j << ", " << k << ", " << l << ", " << m << ",   " << r << ", " << s << ", " << t << ", " << u << '\n'; //debugging
										sum += n;   // if pandigital add to sum
									}
								}
								n = (10 * i + j)*(100 * k + 10 * l + m);     // repeat process with 2 digit multiplicand and 3 digit multiplier
								if (n < 10000)
								{
									int r = n / 1000;
									int s = (n % 1000) / 100;
									int t = (n % 100) / 10;
									int u = (n % 10);
									if (checkpan(i,j,k,l,m,r,s,t,u))
									{
										//std::cout << i << ", " << j << ",     " << k << ", " << l << ", " << m << ",   " << r << ", " << s << ", " << t << ", " << u << '\n'; //debugging
										sum += n;
									}
								}
					}
				}
			}
		}
	}
	std::cout << sum-5796-5346 << ", ";   //take off duplicates
    return 0;
}

