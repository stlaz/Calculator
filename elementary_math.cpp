#include <cmath>

const double EUL = 2.7182818284590452354;

double plus(double a, double b) 
{
	return a+b;
}

double minus(double a, double b)
{
	return a-b;
}

double multiply(double a, double b)
{
	return a*b;
}

double divide(double a, double b)
{
	return a/b;
}

unsigned long int factorial(unsigned long int a)
{
	if(a>1)
		return a*factorial(a-1);
	else return 1;
}

double exponent(double a, unsigned long b)
{
	for(;b>1;b--)
		a*=a;
	return a;
}

double myAbs(double x, double y) {			// Pomocna fce pro vypocet abs. hodnoty pri odcitani
	if((x-y) < 0)
		return y-x;
	else return x-y;
}

double logax(double base, double x, double sigdig)		// Vypocet logaritmu
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
	while(x > 2) {			// Deleni hodnoty x pro rychlejsi konvergenci rady
		x /= EUL;
		count++;
	}
	while(x < 1) {			// Nasobeni hodnoty x pro rychlejsi konvergenci rady
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
	for(int i=0; i <= sigdig; i++)          // Prizpusobovani zadane presnosti
		e /= 10;
	t = (x-1)/(x+1);
	s = 2*t;
	int N = 1;
	while(e <= myAbs(s, sOld)) {		// cyklus pocitajici na danou presnost
		t *= ((x-1)/(x+1))*((x-1)/(x+1));
		sOld = s;
		s += 2*t/(2*N+1);
		N++;
	}
	t=(base-1)/(base+1);
	N = 1;
	s2 = 2*t;
	while(e <= myAbs(s2, s2old)) {		// cyklus pocitajici na danou presnost
		t *= ((base-1)/(base+1))*((base-1)/(base+1));
		s2old = s2;
		s2 += 2*t/(2*N+1);
		N++;
	}
	return (s+count-countmin)/(s2+countBase-countminB);
}
