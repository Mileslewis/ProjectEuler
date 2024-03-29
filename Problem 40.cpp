// Problem 40.cpp : Defines the entry point for the console application.
//
/* Problem 40
An irrational decimal fraction is created by concatenating the positive integers:

0.123456789101112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If dn represents the nth digit of the fractional part, find the value of the following expression.

d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000
*/

#include "stdafx.h"
#include <iostream>

int sizeOf(int x)  // finds number of digits in x
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
	else
		return 0;
}

int main()
{
	int n = 0;        // counts which digit we are on
	int i = 1;
	while (n + sizeOf(i) < 100)  // until we reach 100
	{
		//std::cout << sizeOf(i) << ", " << i<<", ";   // debugging
		n += sizeOf(i++);    // add on number of digits in i to n and increase i by 1
	}
	std::cout << i << ", " <<100- n << '\n';   // prints out which integer we are on and which digit of it will give us d100                       
	while (n + sizeOf(i) < 1000)
	{
		n += sizeOf(i++);
	}
	std::cout << i << ", " <<1000- n << '\n';
	while (n + sizeOf(i) < 10000)
	{
		n += sizeOf(i++);
	}
	std::cout << i << ", " <<10000- n << '\n';
	while (n + sizeOf(i) < 100000)
	{
		n += sizeOf(i++);
	}
	std::cout << i << ", " << 100000-n << '\n';
	while (n + sizeOf(i) < 1000000)
	{
		n += sizeOf(i++);
	}
	std::cout << i << ", " <<1000000- n << '\n';
	return 0;
}

