#include<iostream>
#include<vector>

using namespace std;

short a[10000] = {1,1};
short c[10000];
short fa[10000];

int main()
{
	int n;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		//进行阶乘
		for (int j = 1; j <= a[0]; j++)
		{
			a[j] = a[j] * i + fa[j];
			fa[j] = 0;

			if (a[j] >= 10)
			{
				fa[j + 1] = a[j] / 10;
				a[j] %= 10;
				if (j == a[0]) ++a[0];
			}
		}

		//进行求和
		c[0] = a[0]>c[0]?a[0]:c[0];
		int x = 0;
		for (int j = 1; j <= c[0]; j++) {

			c[j] = c[j] + a[j]+x;
			x = c[j] / 10;
			c[j] %= 10;
		}
		if (x > 0)
		{
			c[0]++;
			c[c[0]] = x;
		}
	}

	for (int i = c[0]; i > 0; i--) cout << c[i];
	cout << endl;
	return 0;
}




