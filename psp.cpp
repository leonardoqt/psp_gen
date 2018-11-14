#include <cmath>
#include "psp.h"

void psp :: get_abc(double R0, double Z)
{
	r0 = R0;
	z = Z;
	b = 1.278465/r0/r0;
	a = -z*exp(b*r0*r0)/(2*b*pow(r0,3));
	c = -z*(2*b*r0*r0-1)/(2*b*pow(r0,3));
}

void psp :: exceed(double lambda)
{
	b = lambda * b;
	a = -z*exp(b*r0*r0)/(2*b*pow(r0,3));
	c = -z*(2*b*r0*r0-1)/(2*b*pow(r0,3));
}

double psp :: V(double x)
{
	if (x <= r0)
		return a*exp(-b*x*x) + c;
	else
		return -z/x;
}
