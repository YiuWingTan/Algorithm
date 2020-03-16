#include<vector>
#include<iostream>

using namespace std;


int a[10000];

int main()
{
	int n;

	while (cin >> n )
	{
		for (int i = 0; i < n; i++) cin >> a[i];
		int count = 0;
		bool ischange = false;
		for (int i = 0; i < n; i++)
		{
			ischange = false;
			for (int j = 0; j < n - i-1; j++)
			{
				if (a[j] > a[j + 1]) {
					int tmp = a[j];
					a[j] = a[j+1];
					a[j + 1] = tmp;
					ischange = true;
					count++;
				}
			}

			if (!ischange) break;
		}

		cout << count<<endl;
		

	}

	return 0;
}

