#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<vector<int>> note;

void combineResult(vector<vector<int>> &result,vector<int> &arr,int begin,int n,int k)
{

	for (int i = begin; i <= n -k+1;)
	{
		arr[arr.size() - k] = i++;
		
		if (k > 1)
		{
			combineResult(result, arr, i, n, k - 1);
		}
		else
		{
			result.push_back(arr);
		}
	}


}

vector<vector<int>> combine(int n, int k) {

	vector<vector<int>> result;

	if (n == 0) return result;
	if (k == 0)
	{
		result.push_back(vector<int>{});
		return result;
	}

	vector<int> arr;
	for (int i = 1; i <= k; i++)
	{
		arr.resize(k);
		combineResult(result, arr, 1, n, k);
	}
	
	return result;
}

int main()
{
	int n = 4;
	int k = 2;
	auto result = combine(n, k);

	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j];
		}
		cout << endl;
	}


	getchar();
	return 0;
}