

#include<iostream>

using namespace std;


int n;
int a[100];


int main()
{
	cin >> n;
	int total = 0;
	int tmp = 0;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		total += a[i];
	}

	total /= n;

	
	for (int i = 0; i < n; i++)
		a[i] -= total;

	int i = 0, j = n-1;

	while (i < n&&a[i] == 0) i++;
	while (j >= 0 && a[j] == 0) j--;

	for (; i < j;)
	{
		a[i + 1] += a[i];
		a[i] = 0;
		count++;
		while (i < j&&a[i] == 0)i++;
		
	}

	cout << count << endl;

	return 0;
}


