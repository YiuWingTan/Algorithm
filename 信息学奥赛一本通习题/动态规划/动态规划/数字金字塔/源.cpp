

#include<iostream>
using namespace std;

int arr[1000];
int tmp[1000];

inline int max(int i, int j)
{
	return i > j ? i : j;
}

inline int min(int i, int j)
{
	return i > j ? j : i;
}

int main()
{

	int N;
	cin >> N;
	cin >> arr[0];
	int result = arr[0];
	for (int i = 0; i < N-1; i++)
	{
		for (int j = 0; j <= i + 1; j++) {
			cin >> tmp[j];
			tmp[j] = max(arr[max(0, j - 1)], arr[j]) + tmp[j];
		}

		for (int j = 0; j <= i + 1; j++)
		{
			arr[j] = tmp[j];
			if (result < arr[j]) result = arr[j];
		}

	}

	cout << result << endl;

	return 0;
}


