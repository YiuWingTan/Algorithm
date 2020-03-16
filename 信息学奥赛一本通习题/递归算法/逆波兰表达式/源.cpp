
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

char a[55];

double f()
{
	cin >> a;

	if (a[0] == '+')
		return f() + f();
	 if (a[0] == '-')
		return f() - f();
	 if (a[0] == '*')
		return f()*f();
	 if (a[0] == '/')
		return f() / f();
	return atof(a);

}


int main()
{

	printf("%f\n",f());
	//system("pause");
	return 0;
}




