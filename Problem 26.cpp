// Problem 26.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

/* Problem 26

A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

1/2	= 	0.5
1/3	= 	0.(3)
1/4	= 	0.25
1/5	= 	0.2
1/6	= 	0.1(6)
1/7	= 	0.(142857)
1/8	= 	0.125
1/9	= 	0.(1)
1/10	= 	0.1
Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.

*/

/* First digit of decimal representation of 1/n is 10/n then if rem =10%n the second digit is 10*rem/n.
   Continuing like this gives us all the decimal representation. Any time a remainder repeats this will 
   lead to the sequence repeating.
 */

int main()
{
	int longest = 0;    // will store length of longest recursive series so far
	int longestno = 0;  // stores the integer this came from
	int r[1000];        // holds the remainders used to calculate the decimal representation for each 1/n
	for (int n = 4; n < 1000; n++)               // go through all integers
	{
		
			for (int k = 0; k < 1000; ++k)     // reset r[] to all 0's
			{
				r[k] = 0;
			}
		int i = 0;                            // current index
		int rem = 1;                          // 1%n always =1 so start with this
		int length = 0;                       // length of repeating series for n
		do
		{
			r[i] = rem;                       // store each remainder
			//std::cout << rem << "\n";       // debugging              
			rem = (10*rem)% n;               // new remainder
				int q = i;                   // temporarily holds current index
				for (int j = 0; j < q+1; j++)  // go through all the array elements we have added
				{
					if (r[j] == rem)          // if we have repetition
					{
					    length = i-j+1;       // store the length of repeating series
						
					}
					else if (j == q)          // if we have checked through all current remainders
					{
						++i;                   // move to the next index where we will store this one
					}
				}
		} 
		while (length==0);                   // if length >0 we have found a repetition (for non-recurring decimals 0 will repeat)
		if (length > longest)                // if length for n was longer than previous
		{
			longest = length;                // store the length of new longest found
			longestno = n;                   // store the integer it came from
		}
	}
	std::cout << longestno<<"\n";
	//std::cout << longest<<"\n";             // debugging
    return 0;
}

