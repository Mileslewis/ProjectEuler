// Problem 15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
/* Solution to Problem 15:
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?
*/

long long steps(int x,int  y)
{
	if ((x < 0) || (y < 0))
	{
		return 0;  // off the edge of the square
	}
		else if ((x == 0)||(y ==0))  
	{
		return 1;      // only one path to get anywhere along the left or top side.
	}
		else if (x == y)  
		{
			return 2 * (steps(x - 1, y)); // due to symmetry
		}
		else 
			return (steps(x - 1, y) + steps(x, y - 1)); // when you reach a point you must have come from one to the left or above
}

int main()
{
	//std::cout << steps(20, 20)<<"\n";
	long long sum = 0;
	for (int i = 0; i < 21; ++i) // add together the number of steps required to get to each 'halfway' spot squared as there are same number of options to get to finish as to get to each square.
	{
		long long s = steps(i, 20 - i);
		sum += s * s;
	}
	std::cout << sum;
    return 0;
}

