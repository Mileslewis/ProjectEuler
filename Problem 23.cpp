// Problem 23.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
/* Problem 23
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

*/

int sumdiv(int x)   // finds sum of divisors of x
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
	int p[6965];    //array to hold abundant numbers
	int k = 0; //index of array p
	for (int i = 12; i < 28124; i++)
	{
		int z = sumdiv(i); //check sum of all integers
		if (i < z )  //if abundant
		{
			p[k] = i;  //add to array p
			k++;
		}
	}
	bool b[28124] = { 0 };     //each element corresponds to whether that integer can be made from two abundant numbers
	for (int i = 0; i < 6965; i++) //for each abundant number
	{
		for (int j = i; j < 6965; j++) //add it to itself and then all higher abundant numbers
		{
			int y = p[i] + p[j];
			if (y < 28124)
			{
				b[y] = 1;         //for each number made from two abudant numbers set the bool at that value to true.
			}
		}
	}
	int tot = 0;
	for (int m = 0; m < 28124; m++)
	{
		if (b[m] == 0)
		{
			tot += m;         //add up all numbers which were not made from two abundant numbers
		}
	}
	std::cout << tot << "\n";

	//std::cout << k<<"\n"; //used to find size of array required
    return 0;
}

