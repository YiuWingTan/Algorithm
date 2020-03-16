#include<iostream>

using namespace std;
void add()
{
	while (cin >> a1 >> b1)
	{
		int lena = strlen(a1), lenb = strlen(b1);
		int pa = 0, pb = 0;
		while (pa < lena&&a1[pa++] == '0');
		while (pb < lenb&&b1[pb++] == '0');
		pa--; pb--;

		for (int i = 0; i < lena - pa; i++) a[i] = a1[lena - i - 1] - '0';
		for (int i = 0; i < lenb - pb; i++) b[i] = b1[lenb - i - 1] - '0';
		lena -= pa; lenb -= pb;

		int x = 0;
		int max = lena > lenb ? lena : lenb;
		for (int i = 0; i < max; i++)
		{
			c[i] = (a[i] + b[i] + x);
			x = c[i] / 10;
			c[i] %= 10;
		}

		if (x != 0) c[max++] = x;

		for (int i = max - 1; i >= 0; i--)
			cout << c[i];
		cout << endl;

		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(0));

	}
}

char a1[201];
char b1[201];
int a[201];
int b[201];

int c[201];



void sub()
{
	while (cin >> a1 >> b1)
	{
		int lena = strlen(a1), lenb = strlen(b1);
		
		for (int i = 0; i < lena; i++) a[i] = a1[lena - i - 1] - '0';
		for (int i = 0; i < lenb; i++) b[i] = b1[lenb - i - 1] - '0';
		

		int x = 0;
		for (int i = 0; i < lena; i++)
		{
			if (a[i] < b[i])
			{
				a[i] += 10;
				a[i + 1]--;
			}
			a[i] -= b[i];
		}

		//É¾³ýÇ°µ¼0
		lena--;
		while (lena >= 0 && a[lena] == 0) --lena;

		for (int i = lena; i >= 0; i--) cout << a[i];
		cout << endl;

		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(0));

	}
}

int main()
{
	
	sub();

	return 0;
}
