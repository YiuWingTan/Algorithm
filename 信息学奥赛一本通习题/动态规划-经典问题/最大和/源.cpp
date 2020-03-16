
#include<iostream>
#include<algorithm>
using namespace std;

int maxl[50002];
int maxr[50002];

int arr[50002];
int main()
{
	int N;
	cin >> N;

	while (N > 0)
	{
		int T;
		cin >> T;

		for (int i = 1; i <= T; i++)
		{
			cin >> arr[i];

		}
		maxr[T + 1] = -10000;
		maxl[0] = -10000;

		for (int i = 1; i <= T; i++)
		{
			maxl[i] = max(maxl[i - 1] + arr[i], arr[i]);
			maxr[T - i + 1] = max(maxr[T - i + 2] + arr[T - i + 1], arr[T - i + 1]);
		}

		//改变maxl和maxr的意义
		int max_left = -10000;
		int max_right = -10000;
		for (int i = 1; i <= T; i++)
		{
			maxl[i] = max(maxl[i - 1], maxl[i]);
			maxr[T - i + 1] = max(maxr[T - i + 1], maxr[T - i + 2]);
		}




		int result = -10000;

		for (int i = 1; i <= T; i++)
		{
			result = max(result, maxr[i] + maxl[i]);
		}

		cout << result-1 << endl;
		N--;
	}


	return 0;
}

