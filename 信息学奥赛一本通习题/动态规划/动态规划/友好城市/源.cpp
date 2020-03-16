
#include<iostream>
using namespace std;

struct Point
{
	int x1;
	int x2;
};

Point x[5000];
int dp[5000];




int cmp(int a,int b)
{
	return a - b;
}

void qSort(Point* arr,int lo,int hi)
{
	if (lo >= hi) return;

	int k = lo,i = lo+1,j = hi;

	while (i <= j)
	{
		int tmp_cmp = cmp(arr[k].x1,arr[i].x1);
		if (tmp_cmp<0) swap(arr[i],arr[j--]);
		else if (tmp_cmp>0) swap(arr[k++],arr[i++]);
		else i++;
	}

	qSort(arr,lo,k-1);
	qSort(arr,j+1,hi);

}


int main()
{
	int N;
	cin >> N;

	

	for (int i = 0; i < N; i++)
	{
		cin >> x[i].x1>>x[i].x2;
	}
	qSort(x,0,N-1);

	dp[0] = 1;

	int max = 0;
	for (int i = 1; i < N; i++)
	{
		dp[i] = 1;
		int tmp_max = 0;
		for (int j = i-1; j >=0; j--)
		{
			if (x[j].x1 < x[i].x1 && x[j].x2 < x[i].x2&&dp[j]>tmp_max)
			{
				tmp_max = dp[j];
			}
		}

		dp[i] += tmp_max;
		if (dp[i] > max) max = dp[i];

	}
	
	cout << max << endl;


	return 0;
}


