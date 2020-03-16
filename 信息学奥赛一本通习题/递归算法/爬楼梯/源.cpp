

#include<iostream>

using namespace std;

int a[31] = {0,1,2};

int climb(int n)
{
	if (a[n] != 0) return a[n];

	return a[n] = climb(n-1) + climb(n-2);
}


int main()
{
	int n;
	while (cin >> n)
	{


		cout << climb(n)<<endl;

	}

	return 0;
}



