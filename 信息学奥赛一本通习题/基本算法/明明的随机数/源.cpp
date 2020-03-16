#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int a[10001];

int main()
{

	int n;

	memset(a,0,sizeof(a));
	cin >> n;
	int k;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		++a[k];
	}

	int count = 0;
	for (int i = 1; i <= 1000; i++)
	{
		if (a[i] != 0) count++;
	}
	cout <<count <<endl;

	for (int i = 1; i <= 1000; i++)
	{
		if (a[i] != 0)cout << i << " ";
	}

	//system("pause");
	return 0;
}





