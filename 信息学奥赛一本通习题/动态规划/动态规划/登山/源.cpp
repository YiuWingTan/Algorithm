#include<iostream>
using namespace std;

int dp_a[1000];
int dp_b[1000];

int a[1000];
int b[1000];

int main()
{
	int N,tmp;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		b[N-1-i]=a[i] = tmp;
	}

	int max = 0;

	dp_b[0]= dp_a[0] = 1;

	for (int i = 1; i < N; i++)
	{
		int max_a = 0,max_b = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (a[j] < a[i] && max_a < dp_a[j]) max_a = dp_a[j];
			if (b[j] < b[i] && max_b < dp_b[j]) max_b = dp_b[j];
		}
		dp_a[i] = max_a + 1;
		dp_b[i] = max_b + 1;
	}

	//选出最大的
	for (int i = 0; i < N; i++)
	{
		if (dp_a[i] + dp_b[N-1-i] - 1 > max) max = dp_a[i] + dp_b[N - 1 - i] - 1;
	}

	cout << max << endl;

	return 0;
}


