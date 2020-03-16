

#include<iostream>

using namespace std;


int arr[1000000];

bool judge(int n,int m,int tar)
{
	int count = 0;
	int prev = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] - prev < tar)
		{
			//¿¼ÂÇÒÆ³ıµÚi¸ö
			count++;
		}
		else {
			prev = arr[i];
		}
	}


	return count <= m;
}


int main()
{
	int L, N, M;

	cin >> L >> N >> M;

	for (int i = 1; i <=N; i++) cin >> arr[i];
	arr[0] = 0; arr[N + 1] = L;
	N += 2;

	int  left = 0, right = L;


	while (left <= right)
	{
		int mid = left + (right - left)/2;
		if (judge(N, M, mid))
		{
			left = mid + 1;
			
		}
		else right = mid - 1;

	}

	cout << right<<endl;

	return 0;
}


