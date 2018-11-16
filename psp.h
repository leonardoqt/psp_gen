#ifndef PSP
#define PSP

class psp;
class wfc;

class psp
{
private:
	double a,b,c;
	double r0,z;
	int ll;
public:
	void get_abc(double, double);
	void exceed(double);
	double V(double);
	void get_abc_psi(double, double, double, double);
	double psi(int, double);
};

class wfc
{
public:
	int num;
	double *r, *psi;
	double rc, R0, R1, R2;

	wfc();
	void init(int ll, int, double*, double*);
	void get_012(double);
};
#endif
