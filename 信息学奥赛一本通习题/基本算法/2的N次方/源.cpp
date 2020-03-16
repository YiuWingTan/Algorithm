#include<iostream>

using namespace std;


int n2(int n,int c)
{
	if (c == 0) return 1;
	if (c == 1) return n;


	int k = c / 2;
	int re = n2(n,k);
	
	if (k + k < c) return re*re*n;
	else return re*re;
}

int a[200];
int b[200];


void slove()
{
	int N = 0;

	while (cin >> N)
	{
		if (N <= 30) {
			cout << n2(2, N) << endl;
			continue;
		}

		int n = n2(2,30);
		int k = 30;
		int j = 0;
		while (n >= 1) {
			a[j++] = n % 10;
			n /= 10;
		}

		while (k < N)
		{
			int x = 0;
			for (int i = 0; i < j; i++)
			{
				a[i] = (a[i] + a[i] + x);
				x = a[i] / 10;
				a[i] %= 10;
			}
			if (x != 0) { a[j++] = x; }
			k++;
		}

		for (int i = j - 1; i >= 0; i--) cout << a[i];
		cout << endl;

		memset(a,0,sizeof(a));
	}

}


int main()
{
	slove();

	
	return 0;

}

