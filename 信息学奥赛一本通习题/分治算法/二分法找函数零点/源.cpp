#include<iostream>
#include<stdio.h>
using namespace std;

double mine = 1e-7;

inline double f(double x)
{
	return x*x*x*x*x - 15.0 * x*x*x*x + 85.0 * x*x*x - 225.0 * x*x + 274.0 * x - 121.0;
}

inline bool cmp(double a)
{
	if (a< mine) return true;
	return false;
}


int main()
{
	double left = 1.5;
	double right = 2.4;
	double mid = (left + right) / 2;

	while (left+mine<right)
	{
		 mid = (left + right) / 2;
		double fmid = f(mid);

		if (fmid > 0.0)
		{
			left = mid;
		}
		else  {
			right = mid;
		}
	}

	printf("%.6lf\n",(left+right)/2.0);

	return 0;
}
