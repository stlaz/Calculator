#include <iostream>
#include "elementary_math.h"

using namespace CubeSoft::Calculator;

int main(void) 
{
	double x = 5, y = 10;
	unsigned long int z = 2;
	std::cout << OP_PLUS(x,y) << " " << OP_MINUS(x,y) << " "  << OP_MULTIPLY(x,y) << " "  << OP_DIVIDE(x,y) << " ";
	std::cout << OP_FACTORIAL(z) << " "  << OP_POWER(x, z) << std::endl;
	std::cout << OP_LOGARITHM(100, 10, 8);
	std::cout << std::endl;
	return 0;
}
