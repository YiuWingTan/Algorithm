#include<iostream>
#include<vector>

using namespace std;

int compare(vector<int>&a,vector<int>&b)
{
	return a[0] * a[0] + a[1] * a[1] - b[0] * b[0] + b[1] * b[1];
}

int partion(vector<vector<int>>&arr,int lo,int hi)
{
	int i, k, j;
	i = lo + 1, j = hi, k = lo;

	while (i < j)
	{
		int ans = compare(arr[i],arr[k]);

		if (ans > 0)
		{
			swap(arr[i++],arr[j--]);
		}
		else if (ans < 0)
		{
			swap(arr[i++],arr[k++]);
		}
		else i++;
	}

	return k;
}


vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {

	if (points.size() >= K) return points;
	vector<vector<int>> result;
	K--;
	int lo = 0, hi = points.size()-1;

	while (true)
	{
		int k = partion(points,lo,hi);

		if (k > K)
		{
			hi = k - 1;
		}
		else if (k < K)
		{
			lo = k + 1;
		}
		else break;
	}

	for (int i = 0; i < K; i++)
		result.push_back(points[i]);
	return result;
}

int main()
{


	getchar();
	return 0;
}
