#include <iostream>
#include "elementary_math.h"

int main(void) 
{
	double x = 5, y = 10;
	unsigned long int z = 2;
	std::cout << plus(x,y) << " " << minus(x,y) << " "  << multiply(x,y) << " "  << divide(x,y) << " "  << factorial(z) << " "  << exponent(x, z);
	std::cout << std::endl;
	return 0;
}
