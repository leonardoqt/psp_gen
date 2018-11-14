#include <iostream>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <cmath>
#include "psp.h"

using namespace std;

int main()
{
	int num, NN;
	double zz, dh;
	double *r0;
	double **r, **v, **psi;
	psp pp;
	string tmp;
	stringstream ss;

	getline(cin,tmp);
	getline(cin,tmp);
	cin>>NN>>NN>>NN>>NN>>NN;
	while(tmp.find("Here follows") == string::npos)
		getline(cin,tmp);
	getline(cin,tmp);
	cout<<tmp<<endl;
	ss << (tmp);
	ss>>zz>>num;
	ss.str("");
	ss.clear();

	r0 = new double[num];
	r = new double*[num];
	v = new double*[num];
	psi = new double*[num];
	for(int t1=0; t1<num; t1++)
	{
		r[t1] = new double[NN];
		v[t1] = new double[NN];
		psi[t1] = new double[NN];
	}

	for(int t1=0; t1<10; t1++)
	{
		getline(cin,tmp);
		cout<<tmp<<endl;
	}

	for(int t1=0; t1<num; t1++)
	{
		getline(cin,tmp);
		ss << (tmp);
		ss>>NN>>dh;
		ss.str("");
		ss.clear();
		for(int t2=0; t2<NN; t2++)
		{
			cin>>tmp>>r[t1][t2]>>psi[t1][t2]>>v[t1][t2];
			getline(cin,tmp);
		}
	}

	while(tmp.find("Pseudo") == string::npos)
		getline(cin,tmp);
	cin>>num;
	for(int t1=0; t1<num; t1++)
		cin>>r0[t1];

	// start calculating psp
	for(int t1=0; t1<num; t1++)
	{
		pp.get_abc(r0[t1]+0.2,zz);
		pp.exceed(pow(1.5,t1));
		cout<<setw(5)<<NN<<setw(25)<<setprecision(15)<<scientific<<dh<<endl;
		for(int t2=0; t2<NN; t2++)
			cout<<setw(5)<<t2+1<<setw(25)<<setprecision(15)<<scientific<<r[t1][t2]<<setw(25)<<setprecision(15)<<scientific<<psi[t1][t2]<<setw(25)<<setprecision(15)<<scientific<<pp.V(r[t1][t2])<<endl;
	}

	cout<<endl;
	cout<<"########################################################"<<endl;
	for(int t1=0; t1<num; t1++)
		cout<<r0[t1]+0.2<<endl;
	return 0;
}
