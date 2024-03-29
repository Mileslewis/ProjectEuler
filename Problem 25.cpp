// Problem 25.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
/*Problem 25

The Fibonacci sequence is defined by the recurrence relation:

Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
Hence the first 12 terms will be:

F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144
The 12th term, F12, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
*/

int main()
{
	int x[1000] = { 1 };                // 2 arrays to hold each digit of our last 2 fibonacci numbers generated
	int y[1000] = { 1 };                 // 2 arrays to hold each digit of our last 2 fibonacci numbers generated
	int n = 3;                          //current fibonacci number
	for (int q=0;q<100000;q++)           //repeat many times
	{
		for (int i = 0; i <1000; i++)   //go through each element of the arrays
		{
			int temp = x[i] + y[i];     //add corresponding elements together
			if (temp > 9)
			{
				++x[i + 1];            // if 10 or more carry one over to the next element
				x[i] = temp - 10;      //and repace that element with that digit of the next fibonnaci number
			}
			else
			{
				x[i] = temp;           //if less than 10 repace that element with that digit of the next fibonnaci number
			}

		}                             // x is now the next fibonacci number
		if (x[999] > 0)               // if x has 1000 digits
		{
			std::cout << n;           // print which number we are on
			return 0;                 // end the program after this
		}
		++n;                         // we are now on the next number
		
		
		for (int i = 0; i <1000; i++) //same again but now y will be the next fibonacci number
		{
			int temp = x[i] + y[i];
			if (temp > 9)
			{
				++y[i + 1];
				y[i] = temp - 10;
			}
			else
			{
				y[i] = temp;
			}

		}
		if (y[999] > 0)
		{
			std::cout << n;
			return 0;
		}
		++n;

	}
    return 0;
}

