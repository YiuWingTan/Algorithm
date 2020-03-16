#include<cstdio>
#include<iostream>
#include <algorithm>
using namespace std;

int f[100001];

int main()
{
	int N;
	cin >> N;

	while (N > 0)
	{
		int n;
		cin >> n;

		for (int i = 1; i <= n; ++i) scanf("%d",&f[i]);
		
		f[2] = max(f[1],f[2]);

		for (int i = 3; i <= n; ++i)
			f[i] = max(f[i-1],f[i]+f[i-2]);

		printf("%d\n",f[n]);

		--N;
	}


	return 0;
}


