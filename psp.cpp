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

void psp :: get_abc_psi(double x0, double R0, double R1, double R2)
{
	r0 = x0;
	b = (R1-R2*x0)/(2*R1*x0*x0);
	a = -exp(b*x0*x0)*R1/(2*b*x0);
	c = -(-R1-2*b*R0*x0)/(2*b*x0);
}

double psp :: psi(int ll, double x)
{
	return (a*(exp(-b*x*x)) + c)*pow(x,ll+1);
}




wfc :: wfc()
{
	num = 0;
	r = nullptr;
	psi = nullptr;
}

void wfc :: init(int ll, int NN, double* xx, double* ww)
{
	if (num != 0)
	{
		delete[] r;
		delete[] psi;
	}
	num = NN;
	r = new double[num];
	psi = new double[num];

	for(int t1=0; t1<num; t1++)
	{
		r[t1] = xx[t1];
		psi[t1] = ww[t1] / pow(xx[t1],ll+1);
	}
}

void wfc :: get_012(double x0)
{
	int rc_ind;
	double dh;
	double c10=-49.0/20,c11=6.0,c12=-15.0/2,c13=20.0/3,c14=-15.0/4,c15=6.0/5,c16=-1.0/6;
	double c20=469.0/90,c21=-223.0/10,c22=879.0/20,c23=-949.0/18,c24=41,c25=-201.0/10,c26=1019.0/180,c27=-7.0/10;
	double H1, H2;
	for(int t1=0; t1<num; t1++)
		if(r[t1] > x0)
		{
			rc_ind = t1;
			rc = r[t1];
			break;
		}
	dh = log(r[rc_ind]) - log(r[rc_ind-1]);
	
	R0 = psi[rc_ind];
	H1 = (c10*psi[rc_ind]+c11*psi[rc_ind+1]+c12*psi[rc_ind+2]+c13*psi[rc_ind+3]+c14*psi[rc_ind+4]+c15*psi[rc_ind+5]+c16*psi[rc_ind+6])/dh;
	H2 = (c20*psi[rc_ind]+c21*psi[rc_ind+1]+c22*psi[rc_ind+2]+c23*psi[rc_ind+3]+c24*psi[rc_ind+4]+c25*psi[rc_ind+5]+c26*psi[rc_ind+6]+c27*psi[rc_ind+7])/dh/dh;

	R1 = H1 / rc;
	R2 = (H2-H1) / rc / rc;
}
