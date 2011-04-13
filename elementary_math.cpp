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
