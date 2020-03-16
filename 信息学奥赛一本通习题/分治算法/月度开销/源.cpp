
#include<iostream>

using namespace std;

int arr[1000000];

//判断是否可行
bool judge(int value,int n,int m)
{
	int count = 1;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (sum+arr[i] <= value) sum += arr[i];
		else {
			sum = arr[i];
			count++;
		}
	}
	return count<=m;
}


int main()
{
	int left = 0, right = 0;
	int N, M;
	cin >> N >> M;


	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (arr[i] > left) left = arr[i];
		right += arr[i];
	}


	while (left <= right)
	{
		int mid = left+ (right - left) / 2;

		if (judge(mid,N,M))
		{
			//可行
			right = mid - 1;
		}
		else {
			//不可行
			left = mid + 1;
		}

	}

	cout << left << endl;

	return 0;
}




