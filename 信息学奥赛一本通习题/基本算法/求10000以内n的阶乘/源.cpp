#include<iostream>
#include<vector>

using namespace std;

short a[50000] = {1,1}, fa[50000];

int main()
{
	int target = 0;

	cin >> target;
	
	for (int n = 1; n <= target; n++)
	{
		for (int i = 1; i <= a[0]; i++)
		{
			a[i] = a[i] * n + fa[i];
			fa[i] = 0;
			if (a[i] >= 10)
			{
				fa[i + 1] += a[i] / 10;
				a[i] %= 10;
				if (i == a[0]) ++a[0];
			}
		}
	}

	for (int i = a[0]; i >0; i++)printf("%d",a[i]);
	printf("\n");
	a[0] = 1;
	a[1] = 1;;

	return 0;
}

