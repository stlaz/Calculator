/**
 * @file elementary_math.cpp
 * 
 * @brief All the mathematical functions used are to be found here
 * @author Stanislav Laznicka
 *  
 */

#include <cmath>

namespace CubeSoft {
	
	namespace Calculator {
		
		const double EUL = 2.7182818284590452354; /**< Euler's number */

		/** Counts the sum of two numbers
		 * @param a Summand
		 * @param b	Summand
		 * @return Sum of a and b
		 */
		double OP_PLUS(double a, double b) 
		{
			return a+b;
		}
		
		/** Counts the difference of two numbers
		 * @param a Minuend
		 * @param b Subtrahend
		 * @return Difference a-b
		 */
		double OP_MINUS(double a, double b)
		{
			return a-b;
		}

		/** Multiplies the input
		 * @param a multiplier
		 * @param b multiplier
		 * @return Multiplication
		 */
		double OP_MULTIPLY(double a, double b)
		{
			return a*b;
		}

		/** Counts the sum of two numbers
		 * @param a Divident
		 * @param b Divisor
		 * @return Fractopm a/b
		 */
		double OP_DIVIDE(double a, double b)
		{
			return a/b;
		}

		/** Counts a factorial of a number
		 * @param a The input to count factorial of
		 * @return Factorial of the input number
		 */
		unsigned long int OP_FACTORIAL(unsigned long int a)
		{
			if(a>1)
				return a*OP_FACTORIAL(a-1);
			else return 1;
		}

		/** Counts the power
		 * @param a Base
		 * @param b Exponent
		 * @return Power
		 */
		double OP_POWER(double a, unsigned long b)
		{
			for(;b>1;b--)
			a*=a;
			return a;
		}

		/** Counts the absolute value of two numbers' difference - it's a help function to logarithm
		 *
		 * 
		 * @return Absolute value of two numbers' difference
		 */
		double myAbs(double x, double y) {
			if((x-y) < 0)
				return y-x;
			else return x-y;
		}

		/** Counts a logarithm
		 * @param base The base of a logarithm
		 * @param x The number beeing logarithmized
		 * @param sigdig The number of signature digits to count the logarithm
		 * @return The logarithm output
		 */
		double OP_LOGARITHM(double base, double x, double sigdig)
		{
			if(x <= 0.0) {
				return NAN;
			}
			if(base > 1 && isinf(x))
				return INFINITY;
			if(base < 1 && isinf(x))
				return -INFINITY;
			if(isnan(x))
				return NAN;
			double t, s, sOld = -1, s2, s2old = -1, e=0.1;
			int count = 0, countBase = 0, countmin=0, countminB = 0;
			while(x > 2) {			// Divides the input so the later computing doesn't take that much time
				x /= EUL;
				count++;
			}
			while(x < 1) {			// Multiplying the input for same reasons as dividing it before
				x *= EUL;
				countmin++;
			}
			while(base > 2) {
				base /= EUL;
				countBase++;
			}
			while(base <= 1) {
				base *= EUL;
				countminB++;
			}
			for(int i=0; i <= sigdig; i++)          // Adjusting the precision given
				e /= 10;
			t = (x-1)/(x+1);
			s = 2*t;
			int N = 1;
			while(e <= myAbs(s, sOld)) {		// The counting itself, counts till the precion is right
				t *= ((x-1)/(x+1))*((x-1)/(x+1));
				sOld = s;
				s += 2*t/(2*N+1);
				N++;
			}
			t=(base-1)/(base+1);
			N = 1;
			s2 = 2*t;
			while(e <= myAbs(s2, s2old)) {
				t *= ((base-1)/(base+1))*((base-1)/(base+1));
				s2old = s2;
				s2 += 2*t/(2*N+1);
				N++;
			}
			return (s+count-countmin)/(s2+countBase-countminB);
		}
	}
}

/*** End of file elementary_math.cpp ***/
