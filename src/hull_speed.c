#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// do not change anything above this comment

double hullSpeed(double lgth)
{
	// here you will compute the hull speed for the specified boat length,
	// implementing the numerical computation in GNU Assembly Language
	// through use of FPU instructions (do NOT call sqrt() from math.h)
	double result, multiplier = 1.34;

	__asm__(
		"	fldl	%[lgthIn]	\n" //Load lgth into floating point stack
		"	fsqrt			\n" //Sqrt value on top of stack
		"	fldl	%[multiplier]	\n" //Load multiplier with value of 1.34 into stack
		"	fmulp			\n" //Multiple the two values in the stack
		"	fstpl	%[result]	\n" // store the result
		: [result]	"=m"	(result)	//Outputs
		: [lgthIn]	"m"	(lgth),		//Inputs
		  [multiplier]	"m"	(multiplier)
		);
	return result;
}

// do not change anything below this comment, except for printing out your name

double hullSpeedC(double lgth)
{
	// this C implementation of the hull speed computation is provided
	// so you can compare its correct results with the results of your code

	return 1.34 * sqrt(lgth);
}

int main (int argc, char **argv)
{
	double	lgth;
	double	hullSpd, hullSpdC;

	printf("CS201 - Assignment 02 - Adam La Fleur\n");
	if (argc != 2) {
		printf("need 1 argument: boat length\n");
		return -1;
		}
	lgth = atof(argv[1]);
	hullSpd = hullSpeed(lgth);
	hullSpdC = hullSpeedC(lgth);

	printf("hullSpeed(%.0f) = %.3f, %.3f\n", lgth, hullSpd, hullSpdC);

	return 0;
}
