#ifndef PSP
#define PSP

class psp;

class psp
{
private:
	double a,b,c;
	double r0,z;
public:
	void get_abc(double, double);
	void exceed(double);
	double V(double);
};
#endif
