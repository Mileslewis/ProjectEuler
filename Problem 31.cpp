// Problem 31.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

/* Problem 31

In the United Kingdom the currency is made up of pound (£) and pence (p). There are eight coins in general circulation:

1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).
It is possible to make £2 in the following way:

1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
How many different ways can £2 be made using any number of coins?

*/

int using2p(int x)
{
	if (x >= 2)
	{
		return using2p(x - 2)+1;
	}
	else return 1;
}

int using5p(int x)
{
	if (x >= 5)
	{
		return using5p(x - 5) + using2p(x - 2) + 1;
	}
	else if (x >= 2)
	{
		return using2p(x - 2) + 1;
	}
	else return 1;
}

int using10p(int x)
{
	if (x >= 10)
	{
		return using10p(x-10)+ using5p(x - 5) + using2p(x - 2) + 1;
	}
	else if (x >= 5)
	{
		return using5p(x - 5) + using2p(x - 2) + 1;
	}
	else if (x >= 2)
	{
		return using2p(x - 2) + 1;
	}
	else return 1;
}

int using20p(int x)
{
	if (x >= 20)
	{
		return using20p(x-20)+ using10p(x - 10) + using5p(x - 5) + using2p(x - 2) + 1;
	}
	else if (x >= 10)
	{
		return using10p(x - 10) + using5p(x - 5) + using2p(x - 2) + 1;
	}
	else if (x >= 5)
	{
		return using5p(x - 5) + using2p(x - 2) + 1;
	}
	else if (x >= 2)
	{
		return using2p(x - 2) + 1;
	}
	else return 1;
}

int using50p(int x)
{
	if (x >= 50)
	{
		return using50p(x-50)+ using20p(x - 20) + using10p(x - 10) + using5p(x - 5) + using2p(x - 2) + 1;
	}
	else if (x >= 20)
	{
		return using20p(x - 20) + using10p(x - 10) + using5p(x - 5) + using2p(x - 2) + 1;
	}
	else if (x >= 10)
	{
		return using10p(x - 10) + using5p(x - 5) + using2p(x - 2) + 1;
	}
	else if (x >= 5)
	{
		return using5p(x - 5) + using2p(x - 2) + 1;
	}
	else if (x >= 2)
	{
		return using2p(x - 2) + 1;
	}
	else return 1;
}

int using100p(int x)
{
	if (x >= 100)
	{
		return using100p(x - 100) + using50p(x - 50) + using20p(x - 20) + using10p(x - 10) + using5p(x - 5) + using2p(x - 2) + 1;
	}
	else if (x >= 50)
	{
		return using50p(x - 50) + using20p(x - 20) + using10p(x - 10) + using5p(x - 5) + using2p(x - 2) + 1;
	}
	else if (x >= 20)
	{
		return using20p(x - 20) + using10p(x - 10) + using5p(x - 5) + using2p(x - 2) + 1;
	}
	else if (x >= 10)
	{
		return using10p(x - 10) + using5p(x - 5) + using2p(x - 2) + 1;
	}
	else if (x >= 5)
	{
		return using5p(x - 5) + using2p(x - 2) + 1;
	}
	else if (x >= 2)
	{
		return using2p(x - 2) + 1;
	}
	else return 1;
}



int main()
{
	std::cout << using100p(200) + 1 << "  ";
    return 0;
}

