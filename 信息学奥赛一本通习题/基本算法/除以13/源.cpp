#include<iostream>
using namespace std;

char a1[100];
short a[100];
short c[100];
int main()
{
	int n = 13;

	cin >> a1;
	
	int lena = strlen(a1);

	for (int i = 0; i < lena; i++) a[i] = a1[i] - '0';

	int x = 0;

	for (int i = 0; i < lena; i++)
	{
		x = x * 10 + a[i];
		if (x >= n)
		{
			c[i] = x / n;
			x %= n;
		}
		else c[i] = 0;
		
	}
	int start = 0;
	while (start < lena&&c[start] == 0) start++;;
		
	for (int i = start; i < lena; i++) cout << c[i];
	cout << endl;
	cout << x<<endl;
	getchar();
	getchar();
	return 0;
}

