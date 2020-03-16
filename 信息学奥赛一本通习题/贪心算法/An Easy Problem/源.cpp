#include<iostream>

using namespace std;

int a[1000000];
int b[32];

void decompse(int val)
{
	int i = 0;
	
	while (val > 0)
	{
		int k = val % 2;
		val /= 2;
		b[i++] = k;
	}
}

void getNum(int j)
{
	int n = 0;
	int k = 1;

	for (int i = 0; i < 32; i++)
	{
		n += k * b[i];
		k *= 2;
	}
	a[j] = n;
}

int main()
{
	int n;
	int k = 0;
	while (cin >> n)
	{
		if (n == 0) break;
		memset(b, 0, sizeof(b));
		decompse(n);
		int j = 0, num = 0;
		while (j < 32 && b[j] == 0)j++;
		while (j + 1 < 32 && b[j + 1] == 1) { j++; num++; }

		b[j+1] = 1;

		memset(b,0,sizeof(int)*(j+1));

		for (int i = 0; i < num; i++)
			b[i] = 1;

		getNum(k++);

	}

	for (int i = 0; i < k; i++)
		cout << a[i]<<endl;


	return 0;
}


