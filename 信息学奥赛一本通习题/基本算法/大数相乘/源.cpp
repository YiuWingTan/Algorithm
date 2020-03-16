#include<iostream>

using namespace std;



char a1[200];
char b1[200];
short a[200];
short b[200];

short c[50000];

int main()
{
	cin >> a1>>b1;

	int lena = strlen(a1),lenb = strlen(b1);
	int lenc = 0;
	for (int i = 0; i < lena; i++) a[i] = a1[lena - i - 1] - '0';
	for (int i = 0; i < lenb; i++) b[i] = b1[lenb - i - 1] - '0';

	for (int i = 0; i < lenb; i++)
	{
		int x = 0;
		for (int j = 0; j < lena; j++)
		{
			c[i+j] += a[j] * b[i] + x;

			x = c[i+j]/10;
			c[i + j] %= 10;
			
		}
		c[lena + i] = x;
	}

	lenc = lena + lenb;
	for (int i = lenc - 1; i >= 0 && c[i] == 0; i--) lenc--;
	for (int i = lenc - 1; i >= 0; i--) cout << c[i];
	cout << endl;
	
	return 0;
}

