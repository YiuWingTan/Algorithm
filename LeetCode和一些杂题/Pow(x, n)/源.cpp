#include<iostream>
#include<vector>
using namespace std;

inline bool equal(double num1,double num2)
{
	if ((num1 - num2) < 0.000001 && (num1 - num2) > -0.000001)
		return true;
	return false;
}
int nabf(int n)
{
	return n > 0 ? n : -n;
}

double Pow(double x,int n) {

	if (n == 1||n == -1) return x;

	double val = Pow(x, n/2);

	if (n & 1 == 1)
	{
		//奇数
		return val*val*x;
	}
	return val*val;
}

double myPow(double x, int n) {
	if (n == 0) return 1.0;
	if (equal(x, 0.0)) return 0.0;
	
	double val = Pow(x,n);

	if (equal(val, 0)) return 0.0;

	if (n < 0)
	{
		val = 1.0 / val;
	}

	return val;
}

void text1()
{
	double x = 34.00515;
	int n = -3;
	double val = myPow(x,n);
	printf("Pow(%f,%d)的值为%f\n\n",x,n,val);
}
void text2()
{
	double x = 2.0;
	int n = -2;
	double val = myPow(x, n);
	printf("Pow(%f,%d)的值为%f\n\n", x, n, val);
}
void text3()
{
	double x = 1.0;
	int n = 0;
	double val = myPow(x, n);
	printf("Pow(%f,%d)的值为%f\n\n", x, n, val);
}

void text4()
{
	double x = 0;
	int n = 4;
	double val = myPow(x, n);
	printf("Pow(%f,%d)的值为%f\n\n", x, n, val);
}

int main()
{
	text1();
	text2();
	text3();
	text4();

	getchar();
	return 0;
}