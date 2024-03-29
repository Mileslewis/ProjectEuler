// Problem 16.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

/* Problem 16

215 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 21000?
*/

int main()
{
	int p[400];
	for (int r = 0; r < 400; r++)
	{
		p[r] = 0;
	}
	p[0] = 1;
	
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 399; j >=0; j--)
		{
			if (p[j] < 5)
			{
				p[j] = 2*p[j];
			}
			else
			{
				++p[j + 1];
				p[j] = p[j] * 2 - 10;
			}
		}
	}
	int sum = 0;
	for (int k = 0; k < 400; k++)
	{
		sum += p[k];
	}
	std::cout << sum;
    return 0;
}

