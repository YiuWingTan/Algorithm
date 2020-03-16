
#include<iostream>
#include<stdio.h>
using namespace std;

int arr[10000];
int e = 1;

bool isOk(int n,int k,int val)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		count += (arr[i] / val);
	}

	return count >= k;
}


int main()
{
	int n;
	int k;
	int max = -10000;;
	cin >> n;
	cin >> k;


	for (int i = 0; i < n; i++)
	{
		float tmp;
		cin >>tmp;
		arr[i] = (int)(tmp * 100.0f+0.5f);
		if (arr[i] > max) max = arr[i];
	}

	double left = 0,right = max+1;

	while (left + e < right)
	{
		int mid = (left + right) /2;
		if (isOk(n, k, mid))
		{
			left = mid;
		}
		else right = mid;
	}

	if (left < e) printf("0.00\n");
	else
	printf("%.2lf\n",left/100.0f);

	return 0;
}


